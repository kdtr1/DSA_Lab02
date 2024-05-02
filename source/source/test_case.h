#pragma once
#include <cmath>
#include <time.h>
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
}

//Generate random data number:
void generate_random_data_number(int& a, int& b) {
	srand((unsigned int)time(nullptr));
	a = rand() % 100;
	b = rand() % 100;
}

// Generate random array of data:
void generate_random_data(int* a, int n) {
	srand((unsigned int)time(nullptr));

	for (int i = 0; i < n; i++) {
		a[i] = rand() % n;
	}
}

// Generate data array in ascending order:
void generate_sorted_data(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
}

// Generate data array in reverse order (descending):
void generate_reverse_data(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = n - 1 - i;
	}
}

// Generates roughly ordered data array:
void generate_nearly_sorted_data(int* a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 10; i++) {
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(a[r1], a[r2]);
	}
}

void generate_data(int* a, int n, int data_type) {
	switch (data_type) {
	case 0:	// ngẫu nhiên
		generate_random_data(a, n);
		break;
	case 1:	// có thứ tự
		generate_sorted_data(a, n);
		break;
	case 2:	// có thứ tự ngược
		generate_reverse_data(a, n);
		break;
	case 3:	// gần như có thứ tự
		generate_nearly_sorted_data(a, n);
		break;
	default:
		cout << "Error: unknown data type!" << endl;
	}
}