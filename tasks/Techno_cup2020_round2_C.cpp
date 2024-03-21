#include <iostream>
int get_high_bit(int value);
int get_quantity_p_binary_numbers(int number_n, int number_p);

int get_high_bit(int value) {
    if (value == 0) return -1000;
    int result = 1;
    result <<= 30;
    while (result > value) {
        result >>= 1;
    }
    return result;
}

int get_quantity_p_binary_numbers(int number_n, int number_p) {
    if (number_p + 1 > number_n) return -1;
    int result = 0, current_n, current_high_bit, number_of_1 = 0;

    while (number_n != 0) {
        current_n = number_n - (1 + result) * number_p;
        number_of_1 = 0;
        if (current_n < 0) return -1;
        for (int i = 0; i <= result; ++i) {
            current_high_bit = 0;
            if ((current_n == 0 && (result + 1 - i > (result + 1) / 2 - number_of_1)) || current_n != 0) {
                current_high_bit = get_high_bit(current_n);
            }
            current_n -= current_high_bit;
            if (current_high_bit == 1) ++number_of_1;
        }
        if (current_n == 0) number_n = 0;
        ++result;
    }

    return result;
}

int main() {
    int number_n, number_p;
    std::cin >> number_n >> number_p;
    std::cout << get_quantity_p_binary_numbers(number_n, number_p);

    return 0;
}