#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include "algorithm_design.h"
#include "operation_counting.h"
#include "test_case.h"
#include <iomanip>
#include <string>

int* copy_array(int* a, int n) {
    int* sub = new int[n];
    for (int i = 0; i < n; i++) {
        sub[i] = a[i];
    }
    return sub;
}

// Information of main menu:
void main_menu() {
    cout << "*************************************************************" << endl;
    cout << "*                        MAIN MENU                          *" << endl;
    cout << "*  1. Operation counting (Assignments and Comparisons)      *" << endl;
    cout << "*  2. Algorithm Design                                      *" << endl;
    cout << "*************************************************************" << endl;
}

// Information of menu of operation counting:
void menu_1() {
    cout << "*************************************************************" << endl;
    cout << "*                          MENU 1                           *" << endl;
    cout << "*  1. Sum half                                              *" << endl;
    cout << "*  2. Recursive square sum                                  *" << endl;
    cout << "*  0. Exit program Menu 1                                   *" << endl;
    cout << "*************************************************************" << endl;
}

// Information of menu of algorithm design:
void menu_2() {
    cout << "*************************************************************" << endl;
    cout << "*                          MENU 2                           *" << endl;
    cout << "*  1. Greatest common divisor                               *" << endl;
    cout << "*  2. Longest non decreasing subsequence                    *" << endl;
    cout << "*  3. Median of array                                       *" << endl;
    cout << "*  4. Count inversions                                      *" << endl;
    cout << "*  0. Exit program Menu 2                                   *" << endl;
    cout << "*************************************************************" << endl;
}

// Process menu of operation counting:
void process_menu_1() {
    int choice; bool continue_running = true;
    while (continue_running) {
        menu_1();
        cout << "Enter your choice: "; cin >> choice; cout << endl;

        while ((choice < 0 || choice > 2) || isalpha(choice) || cin.fail()) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice, please try again and re-enter your choice: ";
            cin >> choice; cout << endl;
        }

        switch (choice) {
        case 1: {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "1. Sum half: " << endl;
            cout << setw(10) << "n" << setw(15) << "Assignments" << setw(15) << "Comparisons" << endl;
            for (int n = 0; n <= 500; n += 25) {
                int assign_count_1 = 0, compare_count_1 = 0;
                sum_half(n, assign_count_1, compare_count_1);
                cout << setw(10) << n << setw(15) << assign_count_1 << setw(15) << compare_count_1 << endl;
            }
            cout << endl << endl;
            break;
        }
        case 2: {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "2. Recursive square sum : " << endl;
            cout << setw(10) << "n" << setw(15) << "Assignments" << setw(15) << "Comparisons" << endl;
            for (int n = 0; n <= 500; n += 25) {
                int compare_count_2 = 0;
                recursive_square_sum(n, compare_count_2);
                cout << setw(10) << n << setw(15) << compare_count_2 << endl;
            }
            cout << endl << endl;
            break;
        }
        case 0: {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "Exit program Menu 1" << endl << endl;
            continue_running = false;
            break;
        }
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    }
}

// Process menu of algorithm design:
void process_menu_2() {
    int choice; bool continue_running = true;
    srand((unsigned int)time(nullptr));
    int u = 21, v = 13;
    //generate_random_data_number(u, v);
    int n = 10;
    int* a = nullptr;
    int data_type = rand() % 3;
    while (continue_running) {
        menu_2();
        cout << "Enter your choice: "; cin >> choice; cout << endl;

        while ((choice < 0 || choice > 4) || isalpha(choice) || cin.fail()) {
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice, please try again and re-enter your choice: ";
            cin >> choice; cout << endl;
        }

        switch (choice) {
        case 1: {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "1. Greatest common divisor: " << endl;
            cout << "u = " << u << ", v = " << v << endl;
            long long count_assign_A_1 = 0, count_compare_A_1 = 0;
            long long count_assign_A_2 = 0, count_compare_A_2 = 0, count_recursions = 0;
            cout << setw(45) << "Result" << setw(17) << "Assignments" << setw(15) << "Comparisons" << endl;
            int res_A_1 = GCD_Brute_Force(max(u, v), min(u, v), count_assign_A_1, count_compare_A_1);
            int res_A_2 = GCD_Euclid(max(u, v), min(u, v), count_assign_A_2, count_compare_A_2, count_recursions);
            cout << "Algorithm 1 (Brute-Force Method):" << setw(10) << res_A_1 << setw(14) << count_assign_A_1 << setw(15) << count_compare_A_1 << endl;
            cout << "Algorithm 2 (Euclid's Algorithm):" << setw(10) << res_A_2 << setw(14) << count_assign_A_2 << setw(15) << count_compare_A_2 << endl;
            cout << endl << endl;
            break;
        }
        case 2: {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "2. Longest non decreasing subsequence: " << endl;
            generate_data(a, n, data_type);
            long long count_assign_B_1 = 0, count_compare_B_1 = 0;
            long long count_assign_B_2 = 0, count_compare_B_2 = 0;
            cout << setw(45) << "Result" << setw(17) << "Assignments" << setw(15) << "Comparisons" << endl;
            int res_B_1 = LNDS_Brute_Force(a, n, count_assign_B_1, count_compare_B_1);
            int res_B_2 = LNDS_Linear(a, n, count_assign_B_2, count_compare_B_2);
            cout << "Algorithm 1 (Brute-Force Approach):" << setw(8) << res_B_1 << setw(14) << count_assign_B_1 << setw(15) << count_compare_B_1 << endl;
            cout << "Algorithm 2 (Linear LNDS):" << setw(17) << res_B_2 << setw(14) << count_assign_B_2 << setw(15) << count_compare_B_2 << endl;
            delete[] a; cout << endl << endl;
            break;
        }
        case 3: {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "3. Median of array: " << endl;
            generate_data(a, n, data_type);
            int* sub_C_1 = copy_array(a, n);
            int* sub_C_2 = copy_array(a, n);
            long long count_assign_C_1 = 0, count_compare_C_1 = 0;
            long long count_assign_C_2 = 0, count_compare_C_2 = 0;
            cout << setw(66) << "Result" << setw(31) << "Assignments" << setw(15) << "Comparisons" << endl;
            double* B_1 = median_array_Brute_Force(sub_C_1, n, count_assign_C_1, count_compare_C_1);
            double* B_2 = median_array_Heap(sub_C_2, n, count_assign_C_2, count_compare_C_2);
            cout << "Algorithm 1 (Brute-Force Algorithm):" << setw(14); print_median(B_1, n); cout << setw(11) << count_assign_C_1 << setw(15) << count_compare_C_1 << endl;
            cout << "Algorithm 2 (Heap structure-priority queue):" << setw(6); print_median(B_2, n); cout << setw(11) << count_assign_C_2 << setw(15) << count_compare_C_2 << endl;
            delete[] a, B_1, B_2, sub_C_1, sub_C_2;
            cout << endl << endl;
            break;
        }
        case 4: {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "4. Count inversions: " << endl;
            generate_data(a, n, data_type);
            int* sub_D_1 = copy_array(a, n);
            int* sub_D_2 = copy_array(a, n);
            long long count_assign_D_1 = 0, count_compare_D_1 = 0;
            long long count_assign_D_2 = 0, count_compare_D_2 = 0;
            cout << setw(53) << "Result" << setw(17) << "Assignments" << setw(15) << "Comparisons" << endl;
            int res_D_1 = count_inversions_Bruce_Force(sub_D_1, n, count_assign_D_1, count_compare_D_1);
            int res_D_2 = count_inversions_Divide_and_Conquer(sub_D_2, n, count_assign_D_2, count_compare_D_2);
            cout << "Algorithm 1 (Brute-Force Algorithm):" << setw(15) << res_D_1 << setw(14) << count_assign_D_1 << setw(15) << count_compare_D_1 << endl;
            cout << "Algorithm 2 (Divide and Conquer Algorithm):" << setw(8) << res_D_2 << setw(14) << count_assign_D_2 << setw(15) << count_compare_D_2 << endl;
            delete[] a; cout << endl << endl;
            break;
        }
        case 0: {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "Exit program Menu 2" << endl << endl;
            continue_running = false;
            break;
        }
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    }
}

// Process main menu:
void process_main_menu() {
    main_menu();
    string character = "y";

    while ((character == "y") || (character == "Y")) {
        string choice;
        bool check = true;

        while (check) {
            cout << "Enter your option: "; getline(cin, choice); cout << endl;

            if (choice != "1" && choice != "2" || cin.fail()) {
                cout << "No option in MENU" << endl;
                cout << "Please try again and re-enter your choice: " << endl;
                check = true;
            }
            else
                check = false;
        }
        if (choice == "1") {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "1. Operation counting (Assignments and Comparisons):" << endl;
            process_menu_1();
            cin.ignore();
        }
        else if (choice == "2") {
            cout << "Your choice to choose is: " << choice << endl;
            cout << "2. Algorithm Design:" << endl;
            process_menu_2();
            cin.ignore();
        }

        // Handle Yes/No:
        cout << endl << "Program completed. Do you want to continue?" << endl;
        bool invalid = true;

        while (invalid) {
            cout << "If yes, enter y or Y (YES), otherwise enter n or N (NO): "; getline(cin, character);
            cout << endl << endl;
            if ((character == "n") || (character == "N")) {
                cout << "Exit program" << endl << endl;
                break;
            }
            else if ((character == "y") || (character == "Y")) {
                main_menu();
                invalid = false;
            }
            else {
                cout << "Invalid choice, please try again and re-enter your choice: " << endl;
                invalid = true;
            }
        }
    }
}

#endif 
