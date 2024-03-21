#include <iostream>
#include <vector>

std::vector<long long> get_vector_pow_p(const int p, size_t size);
std::vector<size_t> algorithm_Rabina_Karpa(std::string str, std::string substr, std::vector<long long> pow_p);
std::vector<size_t> get_max_substr(std::string str1, std::string str2, std::vector<long long> pow_p, size_t &first, size_t &last);

std::vector<size_t> algorithm_Rabina_Karpa(std::string str, std::string substr, std::vector<long long> pow_p) {
    long long cur_hash;
    std::vector<size_t> res;

    std::vector<long long> hash(str.length());
    for (size_t i = 0; i < hash.size(); ++i) {
        hash[i] = (static_cast<long long>(str[i]) - static_cast<long long>('a') + 1) * pow_p[i];
        if (i) hash[i] += hash[i - 1];
    }

    long long hash_substr = 0;
    for (size_t i = 0; i < substr.size(); ++i)

    {
        hash_substr += (static_cast<long long>(substr[i]) - static_cast<long long>('a') + 1) * pow_p[i];
    }

    for (size_t i = 0; i <= str.length() - substr.length(); ++i) {
        cur_hash = hash[i + substr.length() - 1];
        if (i) cur_hash -= hash[i - 1];
        if (cur_hash == hash_substr * pow_p[i]) res.push_back(i);
    }

    return res;
}

std::vector<long long> get_vector_pow_p(const int p, size_t size) {
    std::vector<long long> res(size);
    res[0] = 1;
    for (size_t i = 1; i < size; ++i) {
        res[i] = res[i - 1] * p;
    }
    return res;
}

std::vector<size_t> get_max_substr(std::string str1, std::string str2, std::vector<long long> pow_p, size_t &first, size_t &last) {
    size_t cur_length = (first + last) / 2;
    std::string cur_substr = str1.substr(0, cur_length + 1);
    std::vector<size_t> begining_of_substr = algorithm_Rabina_Karpa(str2, cur_substr, pow_p);
    if (begining_of_substr.size() == 0) {
        if (first == last) return begining_of_substr;
        begining_of_substr = get_max_substr(str1, str2, pow_p, first, cur_length);
    } else if (algorithm_Rabina_Karpa(str2, str1.substr(0, cur_length + 2), pow_p).size() == 0) {
        first = cur_length;
        last = cur_length;
        return begining_of_substr;
    } else {
        begining_of_substr = get_max_substr(str1, str2, pow_p, cur_length, last);
    }
    return begining_of_substr;
}

int main() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;

    const int p = 31;
    if (str1.length() == str2.length()) {
        if (str1 == str2) {
            std::cout << "it's a cyclic permutation";
            return 0;
        }
        std::vector<long long> pow_p = get_vector_pow_p(p, str1.length());
        size_t first = 0, last = str1.length() - 1, length_substr;
        length_substr = (first + last) / 2;
        std::vector<size_t> begining_of_substr = get_max_substr(str1, str2, pow_p, first, last);
        if (begining_of_substr.size() == 0)
            std::cout << "it's NOT a cyclic permutation";
        else {
            if (begining_of_substr[0] == 0) {
                if (str1 == str2)
                    std::cout << "it's a cyclic permutation";
                else
                    std::cout << "it's NOT a cyclic permutation";
            } else {
                if (str1.substr(last + 1, str1.size() - last - 1) == str2.substr(0, begining_of_substr[0]))
                    std::cout << "it's a cyclic permutation";
                else
                    std::cout << "it's NOT a cyclic permutation";
            }
        }
    } else {
        std::cout << "it's NOT a cyclic permutation";
    }

    return 0;
}