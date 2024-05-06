#pragma once
#ifndef _TEST_CASE_H_
#define _TEST_CASE_H_
#include <cmath>
#include <time.h>
#include <random>
#include <algorithm>
using namespace std;

template <class T>
void swap(T& a, T& b) {
    T x = a;
    a = b;
    b = x;
}
void print(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

//Generate random data number:
void generate_random_data_number(int& a, int& b) {
    srand((unsigned int)time(nullptr));
    a = rand() % 100;
    b = rand() % a;
}

// Generate random array of data:
void generate_random_data(int*& a, int n) {
    a = new int[n];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < n; i++) {
        a[i] = dis(gen);
    }
}

// Generate data array in ascending order:
int* generate_sorted_data(int* a, int n) {
    int* res = new int[n];
    for (int i = 0; i < n; i++) {
        res[i] = a[i];
    }
    sort(res, res + n);
    return res;
}

// Generate data array in reverse order (descending):
int* generate_reverse_data(int* a, int n) {
    int* res = new int[n];
    for (int i = 0; i < n; i++) {
        res[i] = a[i];
    }
    sort(res, res + n, greater<int>());
    return res;
}

void generate_data(int*& a, int n, int data_type) {
    switch (data_type) {
    case 0: // random
        generate_random_data(a, n);
        cout << "Array after generating random data:" << endl;
        print(a, n);
        break;
    case 1: { // random ascending
        int* temp_1 = new int[n];
        generate_random_data(temp_1, n);
        int* ans = generate_sorted_data(temp_1, n);
        a = ans;
        cout << "Array after generating random data:" << endl;
        print(ans, n);
        break;
    }
    case 2: { // random descending
        int* temp_2 = new int[n];
        generate_random_data(temp_2, n);
        int* res = generate_reverse_data(temp_2, n);
        a = res;
        cout << "Array after generating random data:" << endl;
        print(res, n);
        break;
    }
    default:
        cout << "Error: unknown data type!" << endl;
    }
}

#endif 
