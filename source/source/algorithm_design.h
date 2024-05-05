#pragma once
#ifndef _ALGORITHM_DESIGN_H_
#define _ALGORITHM_DESIGN_H_
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
// Algorithm 1 (Brute-Force GCD):
int GCD_Brute_Force(int a, int b, long long& count_assign, long long& count_compare) {
    count_assign = 0, count_compare = 0;
    int gcd = 1;
    count_assign++; // Assign gcd = 1

    for (int i = 1; i <= min(a, b); i++) {
        count_compare += 3; // Compare in min (a,b)
        count_compare++; // Compare i <= min(a, b)
        count_assign++; // Assign i = 1, i = 2, ..., i = min(a,b)
        count_compare += 2; // Compare (a % i == 0) and (b % i == 0)
        if (a % i == 0 && b % i == 0) { // Compare (a % i == 0) and (b % i == 0)
            gcd = i;
            count_assign++; // Assign gcd = i
        }
    }
    count_compare += 4; // Compare i > min(a, b) and Compare in min (a,b)
    count_assign++; // Assign i = min(a,b) + 1
    return gcd;
}

// Algorithm 2 (Euclid's Algorithm):
int GCD_Euclid(int a, int b, long long& count_compare, long long& num_recursions) {
    count_compare++; // Compare (b == 0)
    if (b == 0)
        return a;
    else {
        num_recursions++; // Increase the recursion count by 1
        return GCD_Euclid(b, a % b, count_compare, num_recursions); // Recursion
    }
}


// (ii) Longest non decreasing subsequence: (LNDS)
// Algorithm 1 (Brute-Force Approach):
int LNDS_Brute_Force(int*& a, int n, long long& count_assign, long long& count_compare) {
    count_compare++; // Compare n == 0
    if (n == 0) {
        return 0;
    }

    int longest_length = 1; count_assign++;
    for (int i = 0; i < n; i++) {
        count_compare++; // Compare i < n
        count_assign++; // Assign i = 0, 1, 2, ..., n-1
        for (int j = i; j < n; j++) {
            count_compare++; // Compare j < n
            count_assign++; // Assign j = i, ..., n-1
            count_compare++;    // Compare i <= j
            bool is_non_decreasing = true;
            for (int k = i + 1; k <= j; k++) {
                count_compare++; // Compare k <= j
                count_assign++; // Assign k = i+1, ..., j
                count_compare++;    // Compare a[k] < a[k - 1]
                if (a[k] < a[k - 1]) {
                    is_non_decreasing = false;
                    count_assign++;
                    break;
                }
            }
            count_compare++; // Compare k > j
            count_assign++; // Assign k = j + 1
            count_compare++;
            if (is_non_decreasing) {
                count_assign++;
                longest_length = max(longest_length, j - i + 1);
                count_compare += 3;
            }
        }
        count_compare++; // Compare j = n
        count_assign++; // Assign j = n
    }
    count_compare++; // Compare i > n - 1
    count_assign++; // Assign i = n
    return longest_length;
}

// Algorithm 2 (Simple LIS):
int LNDS_simple(int*& a, int n, long long& count_assign, long long& count_compare) {
    count_assign = 0, count_compare = 0;
    count_compare++; // Compare n == 0
    if (n == 0) {
        return 0;
    }

    int longest_length = 1; int current_length = 1;
    count_assign += 2;
    for (int i = 0; i < n - 1; i++) {
        count_compare++; // Compare i < n - 1
        count_assign++; // Assign i = 0, 1, 2, ..., n-2
        count_compare++; // Compare a[i] <= a[i + 1]
        if (a[i] <= a[i + 1]) {
            current_length++; count_assign++;
            longest_length = max(longest_length, current_length);
            count_compare += 3; // Compare in max function
            count_assign++; // Assign longest_length 
        }
        else {
            current_length = 1;
            count_assign++;
        }
    }
    count_compare++; //Compare i > n - 1
    count_assign++; // Assign i = n
    return longest_length;
}


// (iii) Median of array:
void print_median(double* B, int n) {
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
}
// Algorithm 1 (Brute-Force Algorithm):
double* median_array_Brute_Force(int* a, int n, long long& count_assign, long long& count_compare) {
    //Sorted Part
    double* B = new double[n];
    count_assign++;//int i = 0
    for (int i = 0; i < n; i++) {
        count_assign++; // i++
        count_compare++;// i < N
        B[i] = 0; count_assign++;
    }
    count_compare++; //exit the loop

    count_assign++; //int i,j,k = 0
    for (int i = 0; i < n; i++) {
        count_assign++;//i++
        count_compare++;//i<n

        count_assign++; //int j = 0
        for (int j = 0; j <= i; j++) {
            count_assign++; // j++
            count_compare++; // j <= i

            count_assign++;//int k = j + 1
            for (int k = j + 1; k <= i; k++) {
                count_assign++; //k++
                count_compare++; //k<=i
                if (a[j] > a[k]) {
                    count_compare++; // a[j] > a[k]
                    swap(a[j], a[k]);
                    count_assign += 3; // Assignment
                }
            }
            count_compare++; //exit the loop
        }

        count_compare++; //exit the loop
        if ((i + 1) % 2 != 0) {
            count_compare++; // (i + 1) % 2 != 0
            B[i] = a[(i + 1) / 2];
            count_assign++;
        }
        else {
            B[i] = (a[i / 2] + a[i / 2 + 1]) * 1.0 / 2;
            count_assign++;
        }

        count_compare++; //exit the loop
    }
    return B;
}

// Algorithm 2 (Heap structure-priority queue):
double* median_array_Heap(int* arr, int n, long long& count_assign, long long& count_compare) {
    priority_queue<double> s;
    priority_queue<double, vector<double>, greater<double> > g;
    double* res = new double[n];

    int idx = 0; count_assign++;
    double med = arr[0]; count_assign++;
    s.push(arr[0]);


    res[idx] = med; count_assign++;
    idx++; count_assign++;

    count_assign++;// int i = 1
    for (int i = 1; i < n; i++) {
        count_assign++; // i++
        count_compare++;//i<n
        double x = arr[i]; count_assign++;
        if (s.size() > g.size()) {
            count_compare++;
            if (x < med) {
                count_compare++;
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);

            med = (s.top() + g.top()) / 2.0; count_assign++;
        }
        else if (s.size() == g.size()) {
            count_compare++;
            if (x < med) {
                count_compare++;
                s.push(x);
                med = (double)s.top();
                count_assign++;
            }
            else {
                g.push(x);
                med = (double)g.top();
                count_assign++;
            }
        }
        else {
            if (x > med) {
                count_compare++;
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);

            med = (s.top() + g.top()) / 2.0;
            count_assign++;
        }

        res[idx] = med;
        count_assign++;
        idx++;
        count_compare++;
    }
    count_compare++; //exit the loop
    return res;
}


// (iv) Count inversions:
// Algorithm 1 (Brute-Force Algorithm):
int count_inversions_Bruce_Force(int* a, int n, long long& count_assignments, long long& count_comparisons) {
    int inv_count = 0; count_assignments++;
    count_assignments++; // int i=0
    for (int i = 0; i < n - 1; i++) {
        count_assignments++;//i++
        count_comparisons++;//i<n

        count_assignments++; //int j=i+1
        for (int j = i + 1; j < n; j++) {
            count_comparisons++; // j < n
            count_assignments++; // j++
            if (a[i] > a[j]) { count_comparisons++;
                inv_count++;
                count_assignments ++;
            }
        }
    }
    count_comparisons++; // exit the loop
    return inv_count;
}

// Algorithm 2 (Divide and Conquer Algorithm):
// Count the number of inverse pairs in each sorted subarray:
int merge(int* a, int* temp, int left, int mid, int right, long long& count_assign, long long& count_compare) {
    count_assign = 0;
    count_compare = 0;
    int inv_count = 0; count_assign++;
    int i = left;   // Start of first subarray 
    count_assign++;
    int j = mid + 1;// Start of second subarray
    count_assign++;
    int k = left;   // Start of temporary array
    count_assign++;

    while (i <= mid && j <= right) {
        count_compare += 2;    // Count compare
        if (a[i] <= a[j]) { // Compare and count assignement
            count_compare++;
            temp[k++] = a[i++];
            count_assign += 2; //k++ == (k = k+1)
            count_assign++; // Assignement temp[k] = arr[i]
        }
        else {
            temp[k++] = a[j++];
            count_assign += 2;
            count_assign++; // Assignement temp[k] = arr[j]
            inv_count += (mid - i + 1); // Update the number of inverse pairs
            count_assign++;
        }
    }
    count_compare++; // exit the loop
    // Copy the remaining elements of the first subarray (if there are any)
    while (i <= mid) {
        count_compare++;
        temp[k++] = a[i++];
        count_assign += 2;
        count_assign++; // Assignement temp[k] = arr[i]
    }
    count_compare++; // exit the loop
    // Copy the remaining elements of the second subarray (if there are any)
    while (j <= right) {
        count_compare++;
        temp[k++] = a[j++];
        count_assign += 2;
        count_assign++; // Assignement temp[k] = arr[j]
    }
    count_compare++; // exit the loop
    // Copy the temporary array into the arr array
    count_assign++;
    for (i = left; i <= right; i++) {
        count_assign++;
        count_compare++;
        a[i] = temp[i];
        count_assign++; // Assignement arr[i] = temp[i]
    }
    count_compare++; // exit the loop
    return inv_count;
}
int merge_sort(int* a, int* temp, int left, int right, long long& count_assign, long long& count_compare) {
    int inv_count = 0;
    count_assign++;
    if (left < right) {
        count_compare++;
        int mid = left + (right - left) / 2;
        count_assign++;
        // Count the number of assignments and comparisons at each division step
        long long left_assign = 0, left_compare = 0;
        long long right_assign = 0, right_compare = 0;

        inv_count += merge_sort(a, temp, left, mid, left_assign, left_compare);
        inv_count += merge_sort(a, temp, mid + 1, right, right_assign, right_compare);
        // Count the number of assignments and comparisons when combining two sorted arrays
        count_assign += left_assign + right_assign;
        count_compare += left_compare + right_compare;
        count_assign += 2;
        inv_count += merge(a, temp, left, mid, right, count_assign, count_compare);
        count_assign++;
    }
    return inv_count;
}
int count_inversions_Divide_and_Conquer(int* a, int n, long long& count_assign, long long& count_compare) {
    int* temp = new int[n];
    int inversions = merge_sort(a, temp, 0, n - 1, count_assign, count_compare);
    count_assign++;
    delete[] temp;
    return inversions;
}

#endif 

