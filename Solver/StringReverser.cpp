//
// Created by matan on 1/20/20.
//

#include "StringReverser.h"

string StringReverser::solve(string problem) {
    string reverse = problem;
    unsigned int n = problem.length();
    for (int i = 0; i < n / 2; i++) {
        swap(reverse[i], reverse[n - i - 1]);
    }
    return reverse;

}