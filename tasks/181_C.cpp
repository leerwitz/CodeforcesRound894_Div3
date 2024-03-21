#include <iostream>
#include <vector>

bool Is_good_number(long long int a, long long int b, long long int number);
bool compare(long long int a, long long int b);
long long int modular_multiplication(long long int a, long long int b);
long long int modular_addition(long long int a, long long int b);
long long int amount_of_remarkable_numbers(long long int a, long long int b, long long int length);
long long int number_of_combinations_for_the_current_number(long long int a, long long int b, long long int left_limit, long long int good_number, long long int length,
                                                            std::vector<long long int> factorial_array);
long long int pow(long long int variable, long long power);
std::vector<long long int> array_of_factorial();

bool Is_good_number(long long int a, long long int b, long long int number) {
    bool res = true;

    while (number > 0) {
        if (number % 10 != a && number % 10 != b) {
            res = false;
            break;
        }
        number /= 10;
    }

    return res;
}

bool compare(long long int a, long long int b) { return a > b; }

long long int amount_of_remarkable_numbers(long long int a, long long int b, long long int length) {
    long long int left_limit, right_limit, res = 0;

    std::vector<long long int> factorial_array = array_of_factorial();

    if (compare(a, b)) {
        left_limit = modular_multiplication(b, length);
        right_limit = modular_multiplication(a, length);
    } else {
        left_limit = modular_multiplication(a, length);
        right_limit = modular_multiplication(b, length);
    }

    for (long long int good_number = left_limit; good_number <= right_limit; ++good_number) {
        if (Is_good_number(a, b, good_number)) {
            res = modular_addition(res, number_of_combinations_for_the_current_number(a, b, left_limit, good_number, length, factorial_array));
        }
    }

    return res % 1000000007;
}

std::vector<long long int> array_of_factorial() {
    std::vector<long long int> res = std::vector<long long int>(1000001);
    res[0] = 1;
    for (long long int i = 1; i < 1000001; ++i) {
        res[i] = modular_multiplication(res[i - 1], i);
    }

    return res;
}

long long int modular_multiplication(long long int a, long long int b) { return a * b % 1000000007; }

long long int modular_addition(long long int a, long long int b) {
    if (a + b >= 1000000007) return a + b - 1000000007;
    return a + b;
}

long long int number_of_combinations_for_the_current_number(long long int a, long long int b, long long int left_limit, long long int good_number, long long int length,
                                                            std::vector<long long int> factorial_array) {
    long long int res = 0, max_number, min_number, difference_in_number, needed_difference, factorial_lenght;
    if (compare(a, b)) {
        max_number = a;
        min_number = b;
    } else {
        max_number = b;
        min_number = a;
    }

    factorial_lenght = factorial_array[length];

    difference_in_number = max_number - min_number;
    needed_difference = good_number - left_limit;
    if (needed_difference % difference_in_number == 0) {
        long long int amount_of_max = needed_difference / difference_in_number;
        long long int amount_of_min = length - amount_of_max;
        if (amount_of_max <= length) {
            res = pow(modular_multiplication(factorial_array[amount_of_max], factorial_array[amount_of_min]), 1000000005);
            res = modular_multiplication(res, factorial_lenght);
        }
    }

    return res % 1000000007;
}

long long int pow(long long int variable, long long power) {
    long long int current_multiplier = variable, result = 1;

    while (power != 0) {
        current_multiplier = current_multiplier % 1000000007;
        if (power % 2 == 1) {
            result = modular_multiplication(result, current_multiplier);
            --power;
        }
        current_multiplier = modular_multiplication(current_multiplier, current_multiplier);
        power /= 2;
    }

    return result % 1000000007;
}

int main() {
    long long int a, b, length;
    std::cin >> a >> b >> length;
    std::cout << amount_of_remarkable_numbers(a, b, length);

    return 0;
}