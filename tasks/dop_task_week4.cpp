#include <iostream>

int modulo_divide(int denominator, int numerator, int module);
int greatest_common_divisor(int a, int b, int &coefficient_a, int &coefficient_b);
void find_a_multiplier_for_a_number_to_modulo_the_remainder(int number, int &multiplier, int module, int remainder);

int modulo_divide(int denominator, int numerator, int module) {
    if (numerator % module == 0) return -1;
    return (denominator % module) / (numerator % module);
}

void find_a_multiplier_for_a_number_to_modulo_the_remainder(int number, int &multiplier, int module, int remainder) {
    int coefficient_module, gcd;

    gcd = greatest_common_divisor(number, module, multiplier, coefficient_module);

    if (remainder % gcd != 0) {
        std::cout << "multiplier doesn't exist";
    } else {
        multiplier *= remainder / gcd;
        while (multiplier < 0) multiplier += module;
    }
}

int greatest_common_divisor(int a, int b, int &coefficient_a, int &coefficient_b) {
    if (a % b == 0) {
        coefficient_a = 0;
        coefficient_b = 1;
        return b;
    }
    int new_coefficient_a, new_coefficient_b, res;
    res = greatest_common_divisor(b % a, a, new_coefficient_a, new_coefficient_b);
    coefficient_b = new_coefficient_a;
    coefficient_a = new_coefficient_b - b / a * new_coefficient_a;
    return res;
}

int main() {
    int x = -1, a, mod, remainder;

    std::cin >> a >> mod >> remainder;
    find_a_multiplier_for_a_number_to_modulo_the_remainder(a, x, mod, remainder);
    std::cout << x;

    return 0;
}