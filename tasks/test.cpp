#include "myLib.hpp"

int main() {
    lnumber a = lnumber("1505");
    lnumber b;
    std::string str2 = "rstdh\\01giug6uryrfvgvl jhvy\\45rte\\23wdfj\\hyesn\\2", str;
    str = get_number_string_from_string_99(str2);
    b = lnumber(str);
    std::cout << str << '\n' << b << '\n';
    str = get_string_from_lnumber_99(b);
    std::cout << str;

    return 0;
}
