#include <iostream>
#include <list>
#include <vector>

#include "myLib.hpp"

#define FILL_LIMIT 0.7

template <typename Key, typename Value>
class Hashtable {
   private:
    std::vector<std::list<std::pair<Key, Value>>> ArrayWithValue = std::vector<std::list<std::pair<Key, Value>>>();
    size_t size;
    size_t valid_size;
    double fill_factor;
    size_t getKey(const Key &key) const { return static_cast<size_t>(hashFunction(key) % this->size); }

    void resize() {
        if (fill_factor > FILL_LIMIT) {
            std::vector<std::list<std::pair<Key, Value>>> new_Array = std::vector<std::list<std::pair<Key, Value>>>(2 * size);
            auto old_Array = ArrayWithValue;
            ArrayWithValue = new_Array;
            this->size *= 2;
            for (size_t i = 0; i < old_Array.size(); i++) {
                for (auto j : old_Array[i]) {
                    inputValue(j);
                }
            }
        }
    }

    void updateFillFactor() { fill_factor = static_cast<double>(valid_size) / static_cast<double>(size); }

   public:
    Hashtable(size_t new_size) : size(new_size), valid_size(0), fill_factor(0) { ArrayWithValue.resize(new_size); }

    Hashtable() : Hashtable(10) {}
    Hashtable(const Hashtable &other) = default;

    ~Hashtable() {}

    size_t hashFunction(const Key &key) const;

    void inputValue(Key key, Value value) {
        if (!haveValue(key, value)) {
            auto element = std::pair<Key, Value>(key, value);
            this->ArrayWithValue[getKey(key)].push_back(element);
            ++valid_size;
            this->updateFillFactor();
            this->resize();
        }
    }

    void inputValue(const std::pair<Key, Value> &element) { this->inputValue(element.first, element.second); }

    bool haveValue(const Key &key, const Value &value) const {
        for (const std::pair<Key, Value> &i : this->ArrayWithValue[getKey(key)]) {
            if (i.first == key && i.second == value) return true;
        }

        return false;
    }

    bool haveValue(const std::pair<Key, Value> &element) const { return this->haveValue(element.first, element.second); }

    Value getValue(const Key &key) const {
        Value result;
        for (const std::pair<Key, Value> &i : this->ArrayWithValue[getKey(key)]) {
            if (i.first == key) {
                result = i.second;
                break;
            }
        }
        return result;
    }
};