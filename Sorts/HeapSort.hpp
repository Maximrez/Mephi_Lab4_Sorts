#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

template<typename T>
class HeapNode {
public:
    T value;
    int count;
    HeapNode<T> *parent = nullptr;
    HeapNode<T> *left = nullptr;
    HeapNode<T> *right = nullptr;

    bool (*cmp)(const T &, const T &);

    HeapNode(T value1, HeapNode<T> *parent1, HeapNode<T> *left1, HeapNode<T> *right1, bool (*cmp)(const T &, const T &)) : value(value1), parent(parent1), left(left1), right(right1), count(1), cmp(cmp) {}

    HeapNode *search(T target) {
        if (target == value)
            return this;
        if (left) {
            if (target == left->value)
                return left;
            if (cmp(left->value, target)) {
                auto searched = left->search(target);
                if (searched) return searched;
            }
        }
        if (right) {
            if (target == right->value)
                return right;
            if (cmp(right->value, target)) {
                auto searched = right->search(target);
                return searched;
            }
        }
        return nullptr;
    }

    void insert(T target) {
        if (target == value) {
            count++;
            return;
        } else {
            if (!left) {
                left = new HeapNode<T>(target, this, nullptr, nullptr, cmp);
                if (right && (cmp(left->value, right->value))) swap(left, right);
                return;
            }
            if (!right) {
                right = new HeapNode<T>(target, this, nullptr, nullptr, cmp);
                if (left && (cmp(left->value, right->value))) swap(left, right);
                return;
            }
            if (target == left->value) {
                left->count = left->count + 1;
                return;
            }
            if (cmp(left->value, target)) {
                left->insert(target);
                return;
            }
            if (target == right->value) {
                right->count = right->count + 1;
                return;
            }
            if (cmp(right->value, target)) {
                right->insert(target);
                return;
            }
            auto *new_node = new HeapNode<T>(target, this, right, nullptr, cmp);
            right->parent = new_node;
            right = new_node;
            if (cmp(left->value, right->value))
                swap(left, right);
        }
    }

    ~HeapNode() {
        if (parent) {
            if (parent->left && parent->left == this) parent->left = nullptr;
            if (parent->right && parent->right == this) parent->right = nullptr;
            parent = nullptr;
        }
        parent = nullptr;
        if (left) {
            if (left->parent == this) left->parent = nullptr;
            left = nullptr;
        }
        if (right) {
            if (right->parent == this) right->parent = nullptr;
            right = nullptr;
        }
    }
};

template<typename T>
class Heap {
public:
    HeapNode<T> *root = nullptr;

    bool (*cmp)(const T &, const T &);

    explicit Heap(bool (*cmp)(const T &, const T &)) : root(nullptr), cmp(cmp) {}

    void insert(const T &target) {
        if (!root) {
            root = new HeapNode<T>(target, nullptr, nullptr, nullptr, cmp);
            return;
        }
        if (target == root->value) {
            root->count = root->count + 1;
        } else {
            if (cmp(root->value, target)) {
                root->insert(target);
            } else {
                auto *new_node = new HeapNode<T>(target, nullptr, root, nullptr, cmp);
                root->parent = new_node;
                root = new_node;
            }
        }
    }

    T getRoot() {
        if (!root)
            throw out_of_range("Index out of range");
        T rootValue = root->value;
        root->count = root->count - 1;
        if (root->count == 0) {
            HeapNode<T> *node = root;

            while (node->left && node->right) {
                if (cmp(node->left->value, node->right->value))
                    swap(node->left, node->right);
                swap(node->value, node->right->value);
                swap(node->count, node->right->count);
                node = node->right;
            }
            if (node->parent) {
                if (node->left) {
                    if (node->parent->right && node->parent->right == node) {
                        node->parent->right = node->left;
                        node->left->parent = node->parent;
                    }
                    if (node->parent->left && node->parent->left == node) {
                        node->parent->left = node->left;
                        node->left->parent = node->parent;
                    }
                }
                if (node->right) {
                    if (node->parent->right && node->parent->right == node) {
                        node->parent->right = node->right;
                        node->right->parent = node->parent;
                    }
                    if (node->parent->left && node->parent->left == node) {
                        node->parent->left = node->right;
                        node->right->parent = node->parent;
                    }
                }
            } else {
                if (!node->left && !node->right) {
                    root = nullptr;
                }
                if (node->left) {
                    root = node->left;
                }
                if (node->right) {
                    root = node->right;
                }
            }
            delete node;
        }
        return rootValue;
    }

    ~Heap() = default;
};

template<typename T>
Heap<T> heapify(Iterator<T> *iter, bool (*cmp)(const T &, const T &)) {
    Heap<T> heap(cmp);
    for (int i = 0; i < iter->getSize(); i++) {
        heap.insert(iter->get(i));
    }
    return heap;
}

template<typename T>
void heapSort(Iterator<T> *iter, bool (*cmp)(const T &, const T &)) {
    Heap<T> heap = heapify(iter, cmp);
    for (int i = 0; i < iter->getSize(); i++) {
        T val = heap.getRoot();
        iter->place(i, val);
    }
}