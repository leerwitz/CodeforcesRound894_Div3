#include <math.h>

#include <iostream>
#include <map>
#include <set>
#include <vector>
using llint = long long int;
long long pow(long long variable, long long power);

const llint MODULE = 7 + 1e9;
const llint max_num = 2e5 + 5, max_val = 2e5 + 5;

llint pow(llint variable, llint power) {
    llint current_multiplier = variable, result = 1;

    while (power != 0) {
        current_multiplier = current_multiplier;
        if (power % 2 == 1) {
            result *= current_multiplier;
            --power;
        }
        current_multiplier *= current_multiplier;
        power /= 2;
    }

    return result;
}

std::vector<llint> sieve_of_Eratosthenes(llint n) {
    std::vector<llint> prime(n + 1, 0);
    for (size_t i = 2; i <= n; ++i) {
        if (prime[i] == 0) {
            prime[i] = i;
            if (i > 10000) continue;
            for (size_t j = i * i; j <= n; j += i) {
                if (prime[j] == 0) prime[j] = i;
            }
        }
    }

    return prime;
}

void add(llint index, llint multiplier, std::vector<llint> prime, llint size, std::vector<std::map<llint, llint>> &map_of_prime_divisor, std::vector<std::multiset<llint>> &factor_of_prime_divisor,
         llint &answer) {
    llint current_factor, answer_factor, multiplier_factor, j = 2, old_min;
    while (multiplier != 1) {
        j = prime[multiplier];
        old_min = 0;
        current_factor = 0;
        if (prime[j]) {
            while (prime[multiplier] == j) {
                ++current_factor;
                multiplier /= j;
            }
            llint old_factor = map_of_prime_divisor[index][j];
            map_of_prime_divisor[index][j] += current_factor;
            if (factor_of_prime_divisor[j].size() == size) {
                if (old_factor != 0) {
                    old_min = *factor_of_prime_divisor[j].begin();
                }
            }
            std::multiset<llint>::iterator itr = factor_of_prime_divisor[j].find(old_factor);
            if (itr != factor_of_prime_divisor[j].end()) factor_of_prime_divisor[j].erase(itr);

            factor_of_prime_divisor[j].insert(old_factor + current_factor);
            if (factor_of_prime_divisor[j].size() == size) answer = (answer * pow(j, *factor_of_prime_divisor[j].begin() - old_min)) % MODULE;
        }
        ++j;
    }

    //    if(multiplier != 1){
    //     old_min = 0;
    //     current_factor = 1;
    //     llint old_factor = map_of_prime_divisor[index][multiplier];
    //     map_of_prime_divisor[index][multiplier] += current_factor;
    //     if(factor_of_prime_divisor[multiplier].size() == size){
    //         if(old_factor != 0){
    //             old_min = *factor_of_prime_divisor[multiplier].begin();
    //         }
    //     }
    //     std::multiset<llint>::iterator itr = factor_of_prime_divisor[multiplier].find(old_factor);
    //             if(itr != factor_of_prime_divisor[multiplier].end())
    //                     factor_of_prime_divisor[multiplier].erase(itr);

    //         factor_of_prime_divisor[multiplier].insert(old_factor + current_factor);
    //         if(factor_of_prime_divisor[multiplier].size() == size)
    //             answer = (answer * pow(multiplier,*factor_of_prime_divisor[multiplier].begin() - old_min)) % MODULE;

    // }
}

int main() {
    size_t size, number_of_operations, index, multiplier;
    std::cin >> size >> number_of_operations;
    std::vector<llint> array(size);
    llint gcd = 1;
    std::vector<llint> prime = sieve_of_Eratosthenes(max_val);
    std::vector<std::map<llint, llint>> map_of_prime_divisor = std::vector<std::map<llint, llint>>(max_num);
    std::vector<std::multiset<llint>> factor_of_prime_divisor = std::vector<std::multiset<llint>>(max_val);
    for (size_t i = 0; i < size; ++i) {
        std::cin >> multiplier;
        add(i, multiplier, prime, size, map_of_prime_divisor, factor_of_prime_divisor, gcd);
    }

    for (size_t i = 0; i < number_of_operations; ++i) {
        std::cin >> index >> multiplier;
        add(index - 1, multiplier, prime, size, map_of_prime_divisor, factor_of_prime_divisor, gcd);
        std::cout << gcd << '\n';
    }

    return 0;
}