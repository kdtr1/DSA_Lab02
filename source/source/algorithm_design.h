#pragma once
#ifndef _Algorithm_Design_H_
#define _Algorithm_Design_H_
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// 2. Algorithm Design:
// (i) Greatest common divisor: (GCD)
// Algorithm 1 (Euclid's Algorithm):
int GCD_Euclid(int a, int b, long long& count_assign, long long& count_compare, long long& num_recursions) {
    if (b == 0) {
        count_compare++; // Compare (b == 0)
        return a;
    }
    else {
        count_compare++; // Compare (b == 0)
        count_assign++; // Assign a = b (gọi hàm đệ quy)
        count_assign++; // Assign b = a % b(gọi hàm đệ quy)
        count_compare++; // Compare (a % b)
        num_recursions++; // Increase the recursion count by 1
        return GCD_Euclid(b, a % b, count_assign, count_compare, num_recursions); // Đệ quy
    }
}

// Algorithm 2 (Simple Division):
int GCD_simple(int a, int b, long long& count_assign, long long& count_compare) {
    int gcd = 1; 
    count_assign++; // Assign gcd = 1

    for (int i = 1; i <= min(a, b); i++) { // Compare i <= min(a, b)
        count_compare += 4; 
        count_assign++;
        count_compare += 2;
        if (a % i == 0 && b % i == 0) { // Compare (a % i == 0) and (b % i == 0)
            gcd = i; 
            count_assign++; // Assign gcd = i
        }
    }
    count_compare += 4;
    count_assign++;
    return gcd;
}


// (ii) Longest increasing subsequence: (LIS)
// Algorithm 1 (Simple LIS):
int LIS_simple(int*& a, int n, long long& count_assign, long long& count_compare) {
    if (n == 0) {
        count_compare++;
        return 0;
    }

    int longest_length = 1; int current_length = 1;
    count_assign += 2;
    for (int i = 0; i < n - 1; i++) {
        count_compare++;    // Compare a[i] <= a[i + 1]
        if (a[i] <= a[i + 1]) {
            current_length++;
            longest_length = max(longest_length, current_length);
            count_compare += 3;
            count_assign++; // Assign longest_length 
        }
        else {
            current_length = 1;
            count_assign++;
        }
    }
    return longest_length;
}

// Algorithm 2 (Brute-Force Approach):
int LIS_Brute_Force(int*& a, int n, long long& count_assign, long long& count_compare) {
    if (n == 0) {
        count_compare++;
        return 0;
    }

    int longest_length = 1;
    count_assign++;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            count_compare++;    // Compare i <= j
            bool is_non_decreasing = true;
            for (int k = i + 1; k <= j; k++) {
                count_compare++;    // Compare a[k] < a[k - 1]
                if (a[k] < a[k - 1]) {
                    is_non_decreasing = false;
                    break;
                }
            }
            if (is_non_decreasing) {
                count_assign++;
                longest_length = max(longest_length, j - i + 1);
                count_compare += 3;
            }
        }
    }
    return longest_length;
}


// (iii) Median of array:
void print_median(int* B, int n) {
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
}
// Algorithm 1 (Brute Force Algorithm):
void calculate_median_Brute_Force(int* a, int n, int* B, long long& count_assign, long long& count_compare) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = j + 1; k <= i; k++) {
                count_compare++; // Comparison
                if (a[j] > a[k]) {
                    swap(a[j], a[k]);
                    count_assign++; // Assignment
                }
            }
        }
        if ((i + 1) % 2 != 0)
            B[i] = a[(i + 1) / 2];
        else
            B[i] = (a[i / 2] + a[i / 2 + 1]) / 2;
    }
}

// Algorithm 2 (Heap structure Algorithm):
void calculate_median_Heap(int* a, int n, int* B, long long& count_assign, long long& count_compare) {
    // Initialize two heaps: maxHeap and minHeap
    priority_queue<int> max_heap; // Heap stores the smallest elements
    priority_queue<int, vector<int>, greater<int>> min_heap; // Heap stores the largest elements

    for (int i = 0; i < n; i++) {
        // Insert elements into maxHeap or minHeap
        if (max_heap.empty() || a[i] <= max_heap.top()) {
            max_heap.push(a[i]);
            count_assign++; // Assign elements to maxHeap
        }
        else {
            min_heap.push(a[i]);
            count_assign++; // Assign elements to minHeap
        }

        // Balance the sizes of the two heaps
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
            count_assign += 2; // Assign elements to minHeap and remove elements from maxHeap
        }
        else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
            count_assign += 2; // Assign elements to maxHeap and remove elements from minHeap
        }

        // Calculate median
        if (max_heap.size() == min_heap.size()) {
            B[i] = (max_heap.top() + min_heap.top()) / 2;
            count_assign += 2; // Assign elements to array B
        }
        else {
            B[i] = max_heap.top();
            count_assign++; // Assign elements to array B
        }

        count_compare += 3; // Compare elements and check the size of maxHeap and minHeap
    }
}


// (iv) Count inversions:
// Algorithm 1 (Brute Force Algorithm):
int count_inversions_Bruce_Force(int* a, int n, long long& count_assignments, long long& count_comparisons) {
    int inv_count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            count_comparisons++;
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                inv_count++;
                count_assignments += 3;
            }
        }
    }
    return inv_count;
}

// Algorithm 2 (Divide and Conquer Algorithm):
// Count the number of inverse pairs in each sorted subarray:
int merge(int* a, int* temp, int left, int mid, int right, long long& count_assign, long long& count_compare) {
    int inv_count = 0;
    int i = left;   // Start of first subarray
    int j = mid + 1;// Start of second subarray
    int k = left;   // Start of temporary array

    while (i <= mid && j <= right) {
        count_compare++;    // Count compare
        if (a[i] <= a[j]) { // Compare and count assignement
            temp[k++] = a[i++];
            count_assign++; // Assignement temp[k] = arr[i]
        }
        else {
            temp[k++] = a[j++];
            count_assign++; // Assignement temp[k] = arr[j]
            inv_count += (mid - i + 1); // Update the number of inverse pairs
        }
    }

    // Copy the remaining elements of the first subarray (if there are any)
    while (i <= mid) {
        temp[k++] = a[i++];
        count_assign++; // Assignement temp[k] = arr[i]
    }
    // Copy the remaining elements of the second subarray (if there are any)
    while (j <= right) {
        temp[k++] = a[j++];
        count_assign++; // Assignement temp[k] = arr[j]
    }
    // Copy the temporary array into the arr array
    for (i = left; i <= right; i++) {
        a[i] = temp[i];
        count_assign++; // Assignement arr[i] = temp[i]
    }
    return inv_count;
}
int merge_sort(int* a, int* temp, int left, int right, long long& count_assign, long long& count_compare) {
    int inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count the number of assignments and comparisons at each division step
        long long left_assign = 0, left_compare = 0;
        long long right_assign = 0, right_compare = 0;

        inv_count += merge_sort(a, temp, left, mid, left_assign, left_compare);
        inv_count += merge_sort(a, temp, mid + 1, right, right_assign, right_compare);

        // Count the number of assignments and comparisons when combining two sorted arrays
        count_assign += left_assign + right_assign;
        count_compare += left_compare + right_compare;

        inv_count += merge(a, temp, left, mid, right, count_assign, count_compare);
    }
    return inv_count;
}
int count_inversions_Divide_and_Conquer(int* a, int n, long long& count_assign, long long& count_compare) {
    int* temp = new int[n];
    int inversions = merge_sort(a, temp, 0, n - 1, count_assign, count_compare);
    delete[] temp;
    return inversions;
}

#endif 

