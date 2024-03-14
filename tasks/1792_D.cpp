#include <bits/stdc++.h>

#include <iostream>
#include <set>
#include <vector>

std::vector<std::vector<int>> reverse_transpositions(std::vector<std::vector<int>> all_transpositions);

std::vector<std::vector<int>> reverse_transpositions(std::vector<std::vector<int>> all_transpositions) {
    std::vector<std::vector<int>> res(all_transpositions.size());
    for (size_t i = 0; i < all_transpositions.size(); i++) {
        res[i].resize(all_transpositions[0].size());
        for (size_t j = 0; j < all_transpositions[0].size(); ++j) {
            res[i][all_transpositions[i][j]] = j;
        }
    }
    return res;
}

int main() {
    size_t number_of_input, transposition_length, number_of_transpositions;
    std::vector<std::vector<int>> all_transpositions;
    std::cin >> number_of_input;
    for (size_t i = 0; i < number_of_input; ++i) {
        std::cin >> number_of_transpositions >> transposition_length;
        all_transpositions.resize(number_of_transpositions);
        for (size_t j = 0; j < number_of_transpositions; ++j) all_transpositions[j].resize(transposition_length);

        for (size_t j = 0; j < number_of_transpositions; ++j)
            for (size_t k = 0; k < transposition_length; ++k) {
                std::cin >> all_transpositions[j][k];
                --all_transpositions[j][k];
            }
        std::vector<std::vector<int>> reverse_trans = reverse_transpositions(all_transpositions);
        int beauty = 0, current_beauty = 0;
        std::sort(reverse_trans.begin(), reverse_trans.end());
        for (size_t j = 0; j < all_transpositions.size(); ++j) {
            int reverse_index = std::lower_bound(reverse_trans.begin(), reverse_trans.end(), all_transpositions[j]) - reverse_trans.begin();
            beauty = 0, current_beauty = 0;
            if (reverse_index > 0) {
                for (size_t k = 0; k < all_transpositions[j].size(); ++k) {
                    if (all_transpositions[j][k] == reverse_trans[reverse_index - 1][k])
                        ++current_beauty;
                    else
                        break;
                }
                beauty = std::max<int>(beauty, current_beauty);
            }
            if (reverse_index < static_cast<int>(all_transpositions.size())) {
                current_beauty = 0;
                for (size_t k = 0; k < all_transpositions[j].size(); ++k) {
                    if (all_transpositions[j][k] == reverse_trans[reverse_index][k])
                        ++current_beauty;
                    else
                        break;
                }
                beauty = std::max<int>(beauty, current_beauty);
            }
            std::cout << beauty << " ";
        }
        std::cout << '\n';
    }

    return 0;
}