#include <iostream>
#include <string>

#include "Hashtable.hpp"

template <typename Key, typename Value>
size_t Hashtable<Key, Value>::hashFunction(const Key &x) const {
    int s = 1, result = 0;
    for (int i = 0; i < 3; ++i) {
        result += s * (int)pow(x + i, i);
        s *= s + 1;
    }

    return (size_t)abs(result);
}

int main() {
    Hashtable<int, int> map = Hashtable<int, int>(2);
    for (size_t i = 0; i < 100; i++) {
        map.inputValue(i, i * i);
    }

    Hashtable<int, int> map_other(map);

    for (int i = 0; i < 100; i += 9) {
        std::cout << map.getValue(i) << std::endl;
    }

    for (int i = 0; i < 100; i += 9) {
        std::cout << map_other.getValue(i) << std::endl;
    }

    return 0;
}