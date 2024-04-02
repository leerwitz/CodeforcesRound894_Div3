#include <math.h>

#include <iostream>
#include <vector>

using l_l_int = long long int;

l_l_int get_binary_find_degree(l_l_int value, l_l_int min_degree, l_l_int max_degree, std::vector<l_l_int> &array_degree);
l_l_int get_bit_degree(l_l_int value);
l_l_int task_answer(std::vector<l_l_int> &arr, std::vector<l_l_int> &array_degree);

l_l_int get_binary_find_degree(l_l_int value, l_l_int min_degree, l_l_int max_degree, std::vector<l_l_int> &array_degree) {
    if (value == 0) return -1;
    l_l_int result = (max_degree + min_degree) / 2;
    if (array_degree[result] > value)
        result = get_binary_find_degree(value, min_degree, result, array_degree);
    else if (array_degree[result + 1] <= value)
        result = get_binary_find_degree(value, result, max_degree, array_degree);
    return result;
}

l_l_int get_bit_degree(l_l_int value) {
    l_l_int t = 1 << 30, result = 30;
    while (value < t) {
        --result;
        t >>= 1;
    }

    return result;
}

l_l_int task_answer(std::vector<l_l_int> &arr, std::vector<l_l_int> &array_degree) {
    l_l_int result = 0, size = 0;
    std::vector<l_l_int> arr_max_degree = std::vector<l_l_int>(34, 0);
    for (size_t i = 0; i < arr.size(); ++i) {
        ++arr_max_degree[get_binary_find_degree(arr[i], 0, 30, array_degree)];
    }

    for (size_t i = 0; i < arr_max_degree.size(); ++i) {
        result += (arr_max_degree[i] * (arr_max_degree[i] - 1)) / 2;
    }

    return result;
}

int main() {
    size_t number_of_inputs, array_size, degree_of_2 = 1;
    std::vector<l_l_int> array;
    std::cin >> number_of_inputs;
    std::vector<l_l_int> array_degree = std::vector<l_l_int>(34);

    for (size_t i = 0; i < array_degree.size(); ++i) {
        array_degree[i] = degree_of_2;
        degree_of_2 *= 2;
    }

    for (size_t i = 0; i < number_of_inputs; ++i) {
        std::cin >> array_size;
        array.resize(array_size);
        for (size_t j = 0; j < array_size; ++j) {
            std::cin >> array[j];
        }

        std::cout << task_answer(array, array_degree) << '\n';
    }

    return 0;
}