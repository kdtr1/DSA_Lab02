#pragma once
#ifndef _Operation_Counting_H_
#define _Operation_Counting_H_

// 1. Operation counting (Assignments and Comparisons):
// (i) Sum half:
int sum_half(int n, int& count_assign, int& count_compare) {
    int a = 0, i = n;
    count_assign += 2; // 2 assignments => a = 0 and i = n
    count_compare++;

    while (i > 0) {
        count_compare++; // i > 0 is a comparison
        a = a + i;
        i = i / 2;
        count_assign += 2; // 2 assignments => a = a + i and i = i / 2;
    }
    return a;
}


// (ii) Recursive square sum:
int recursive_square_sum(int n, int& count_compare) {
    // In the case of the following code, there is only comparison and no assignment
    count_compare++;
    if (n < 1)
        return 0;
    else
        return n * n + recursive_square_sum(n - 1, count_compare);
}

#endif 

