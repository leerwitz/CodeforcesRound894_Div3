#include <iostream>
#include <map>
#include <vector>
using llint = long long;

llint get_weight_all_substr(std::vector<llint> sequence);

llint get_weight_all_substr(std::vector<llint> sequence) {
    std::map<llint, llint> prefix_sum = std::map<llint, llint>();
    std::vector<llint> duplicate_count(sequence.size());
    duplicate_count[0] = 0;
    llint res = 0;
    prefix_sum[sequence[0]] = 1;
    for (size_t i = 1; i < duplicate_count.size(); ++i) {
        duplicate_count[i] = duplicate_count[i - 1];
        if (prefix_sum.find(sequence[i]) != prefix_sum.end()) {
            duplicate_count[i] += prefix_sum[sequence[i]];
            prefix_sum[sequence[i]] += i + 1;
        } else
            prefix_sum[sequence[i]] = i + 1;
        res += duplicate_count[i];
    }
    return res;
}

int main() {
    size_t number_of_inputs, size;
    std::cin >> number_of_inputs;
    std::vector<llint> sequence;
    for (size_t i = 0; i < number_of_inputs; ++i) {
        std::cin >> size;
        sequence.resize(size);
        for (size_t j = 0; j < size; ++j) std::cin >> sequence[j];
        std::cout << get_weight_all_substr(sequence) << '\n';
    }

    return 0;
}