#pragma once

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

const int MAX = 1000;

class RandomGenerator {
public:
    int n;

    explicit RandomGenerator(int n) : n(n) {};

    [[nodiscard]] vector<int> GenerateRandomVector() const {
        default_random_engine generator;
        auto seed = chrono::system_clock::now().time_since_epoch().count();
        generator.seed(seed);
        uniform_int_distribution<int> distribution(-MAX, MAX);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = distribution(generator);
        }
        return a;
    }

    [[nodiscard]] vector<int> GenerateSortedVector() const {
        vector<int> a = GenerateRandomVector();
        sort(a.begin(), a.end());
        return a;
    }

    [[nodiscard]] vector<int> GenerateReversedVector() const {
        vector<int> a = GenerateSortedVector();
        reverse(a.begin(), a.end());
        return a;
    }
};