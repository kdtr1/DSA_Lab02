#include "algorithm_design.h"
#include "operation_counting.h"
#include "test_case.h"
#include <iomanip>

void print_line(int n) {
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << endl;
}
void copy_array(int* a, int* sub, int n) {
    for (int i = 0; i < n; i++) {
        sub[i] = a[i];
    }
}

int main() {
    // 1. Operation counting (Assignments and Comparisons):
    cout << "1. Operation counting (Assignments and Comparisons):" << endl << endl;

    // (i) Sum half:
    cout << "(i) Sum half:" << endl;
    cout << setw(10) << "n" << setw(15) << "Assignments" << setw(15) << "Comparisons" << endl;
    for (int n = 0; n <= 500; n += 25) {
        int assign_count_1 = 0, compare_count_1 = 0;
        sum_half(n, assign_count_1, compare_count_1);
        cout << setw(10) << n << setw(15) << assign_count_1 << setw(15) << compare_count_1 << endl;
    }
    cout << endl;  print_line(100); cout << endl;

    // (ii) Recursive square sum:
    cout << "(ii) Recursive square sum:" << endl;
    cout << setw(10) << "n" << setw(15) << "Comparisons" << endl;
    for (int n = 0; n <= 500; n += 25) {
        int compare_count_2 = 0;
        recursive_square_sum(n, compare_count_2);
        cout << setw(10) << n << setw(15) << compare_count_2 << endl;
    }
    cout << endl;  print_line(100); cout << endl;


    // 2. Algorithm Design:
    cout << "2. Algorithm Design:" << endl << endl;
    srand((unsigned int)time(nullptr));

    // (i) GCD:
    cout << "(i) Greatest common divisor:" << endl;
    int u = 0, v = 0;
    generate_random_data_number(u, v);
    cout << "u = " << u << ", v = " << v << endl;
    long long count_assign_A_1 = 0, count_compare_A_1 = 0;
    long long count_assign_A_2 = 0, count_compare_A_2 = 0;
    long long count_recursions = 0;
    cout << setw(45) << "Result" << setw(17) << "Assignments" << setw(15) << "Comparisons" << endl;
    int res_A_1 = GCD_Bruce_Force(v, u, count_assign_A_1, count_compare_A_1);
    int res_A_2 = GCD_Euclid(v, u, count_assign_A_2, count_compare_A_2, count_recursions);
    cout << "Algorithm 1 (Simple Division):" << setw(13) << res_A_1 << setw(14) << count_assign_A_1 << setw(15) << count_compare_A_1 << endl;
    cout << "Algorithm 2 (Euclid's Algorithm):" << setw(10) << res_A_2 << setw(14) << count_assign_A_2 << setw(15) << count_compare_A_2 << endl;
    cout << endl;  print_line(100); cout << endl;

    int n = 10;
    int* a = new int[n];
    int data_type = rand() % 4;
    generate_data(a, n, data_type);

    // (ii) LIS:
    cout << "(ii) Longest increasing subsequence:" << endl;
    cout << "Array after generating random data:" << endl;
    print(a, n); cout << endl;
    int a_B[] = { 1, 2, 3, 2, 4, 5, 6, 3, 7 };
    int n_B = sizeof(a_B) / sizeof(a_B[0]);
    long long count_assign_B_1 = 0, count_compare_B_1 = 0;
    long long count_assign_B_2 = 0, count_compare_B_2 = 0;
    cout << setw(45) << "Result" << setw(17) << "Assignments" << setw(15) << "Comparisons" << endl;
    int res_B_1 = LIS_Brute_Force(a, n, count_assign_B_1, count_compare_B_1);
    int res_B_2 = LIS_simple(a, n, count_assign_B_2, count_compare_B_2);
    cout << "Algorithm 1 (Brute-Force Approach):" << setw(8) << res_B_1 << setw(14) << count_assign_B_1 << setw(15) << count_compare_B_1 << endl;
    cout << "Algorithm 2 (Simple LIS):" << setw(18) << res_B_2 << setw(14) << count_assign_B_2 << setw(15) << count_compare_B_2 << endl;
    cout << endl;  print_line(100); cout << endl;


    // (iii) Median of array:
    cout << "(iii) Median of array:" << endl;
    cout << "Array after generating random data:" << endl;
    print(a, n); cout << endl;
    int a_C[] = { 1, 20, 6, 4, 5 };
    int n_C = sizeof(a_C) / sizeof(a_C[0]);
    int* sub_C_1 = new int[n_C]; copy_array(a_C, sub_C_1, n_C);
    int* sub_C_2 = new int[n_C]; copy_array(a_C, sub_C_2, n_C);
    int* B_1 = new int[n_C]; int* B_2 = new int[n_C];
    long long count_assign_C_1 = 0, count_compare_C_1 = 0;
    long long count_assign_C_2 = 0, count_compare_C_2 = 0;
    cout << setw(53) << "Result" << setw(17) << "Assignments" << setw(15) << "Comparisons" << endl;
    calculate_median_Brute_Force(sub_C_1, n_C, B_1, count_assign_C_1, count_compare_C_1);
    calculate_median_Heap(sub_C_2, n_C, B_2, count_assign_C_2, count_compare_C_2);
    cout << "Algorithm 1 (Brute-Force Algorithm):" << setw(9); print_median(B_1, n_C); cout << setw(10) << count_assign_C_1 << setw(15) << count_compare_C_1 << endl;
    cout << "Algorithm 2 (Heap structure Algorithm):" << setw(6); print_median(B_2, n_C); cout << setw(10) << count_assign_C_2 << setw(15) << count_compare_C_2 << endl;
    delete[] B_1, B_2, sub_C_1, sub_C_2;
    cout << endl;  print_line(100); cout << endl;

    //(iv) Count inversions:
    cout << "(iv) Count inversions:" << endl;
    cout << "Array after generating random data:" << endl;
    print(a, n); cout << endl;
    int a_D[] = { 1, 3, 5, 4, 2 };
    int n_D = sizeof(a_D) / sizeof(a_D[0]);
    int* sub_D_1 = new int[n_C]; copy_array(a_D, sub_D_1, n_D);
    int* sub_D_2 = new int[n_C]; copy_array(a_D, sub_D_2, n_D);
    long long count_assign_D_1 = 0, count_compare_D_1 = 0;
    long long count_assign_D_2 = 0, count_compare_D_2 = 0;
    cout << setw(53) << "Result" << setw(17) << "Assignments" << setw(15) << "Comparisons" << endl;
    int res_D_1 = count_inversions_Bruce_Force(sub_D_1, n_D, count_assign_D_1, count_compare_D_1);
    int res_D_2 = count_inversions_Divide_and_Conquer(sub_D_2, n_D, count_assign_D_2, count_compare_D_2);
    cout << "Algorithm 1 (Brute-Force Algorithm):" << setw(15) << res_D_1 << setw(14) << count_assign_D_1 << setw(15) << count_compare_D_1 << endl;
    cout << "Algorithm 2 (Divide and Conquer Algorithm):" << setw(8) << res_D_2 << setw(14) << count_assign_D_2 << setw(15) << count_compare_D_2 << endl;
    cout << endl;  print_line(100); cout << endl;

    return 0;
}
