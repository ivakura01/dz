﻿#include <iostream>

int oct_lenght(int num) {
    if (num == 0) {
        return 1;
    }
    int result = 0;
    while (num != 0) {
        result += 1;
        num /= 8;
    }
    return result;
}


char* oct2str(int num) {
    int sup1;
    bool is_negative;
    if (num < 0) {
        sup1 = 2;
        is_negative = true;
        num = -num;
    }
    else {
        sup1 = 1;
        is_negative = false;
    }
    int lenght = 3;
    if (is_negative) {
        lenght += 1;
    }

    lenght += oct_lenght(num);

    char* result = new char[lenght];

    for (int index = lenght - 2; index > sup1; --index) {
        int rem = num % 8;
        char symbol = rem + 48;
        result[index] = symbol;
        num /= 8;
    }
    if (is_negative) {
        result[0] = '-';
        result[1] = '0';
        result[2] = 'd';
    }
    else {
        result[0] = '0';
        result[1] = 'd';
    }
    result[lenght - 1] = '\0';

    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << oct2str(n) << std::endl;
    return 0;
}