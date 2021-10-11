# Лабораторная работа №1 по курсу «Языки программирования и методы программирования»

Цель: требуется написать программу на C++ для сравнения различных алгоритмов сортировки для класса Sequence<T>.

Сравниваемые алгоритмы сортировок:
  
•	Быстрая сортировка
  
•	Пирамидальная сортировка
  
•	Сортировка слиянием
  
•	Метод простых вставок
  
•	Шейкерная сортировка

Был написан абстрактный класс Iterator<T>, наследником которого являются ArrayIterator<T> и ListIterator<T> - итераторы классов ArraySequence<T> и ListSequence<T> соответственно. Функционал классов-итераторов: получить элемент по индексу, поместить значение по индексу, управлять текущим узлом командами ++ (сдвинуть индекс на 1 вправо), -- (сдвинуть индекс на 1 влево), добавить или отнять int (сдвинуть индекс на int), получить значение в текущем узле и изменить в текущем узле. Реализации сортировок были выполнены с использованием итераторов одинаково для Array и List. Функции Iterator<T> и Sequence<T>, используемые в данной лабораторной работе, покрыты тестами. Был написан класс RandomGenerator, генерирующий случайно сгенерированные, отсортированные и отсортированные в обратном порядке массивы, из которых потом конструируется Sequence.

Был реализован пользовательский интерфейс для работы с программой. Были проведены сравнения времени работы для выбранных алгоритмов сортировок. Алгоритмы с асимптотической сложностью O(nlogn) (quick sort, heap sort и merge sort) тестировались с количеством элементов от 10000 до 100000 с шагом 5000, а алгоритмы с асимптотической сложностью O(n2) (insert sort и shaker sort) тестировались с количеством элементов от 200 до 5000с шагом 200. Тесты проводились при случайно сгенерированном массиве , отсортированном массиве и отсортированном в обратном порядке массиве. Время замерялось с помощью библиотеки chrono, графики были построены с помощью библиотеки matplotlib на Python.
