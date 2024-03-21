#include <ctime>

#include "../update_RSA.hpp"

int main() {
    std::string jwt_token, signature, first_and_second_part_of_token, second_part_of_token, first_part_of_token;
    std::pair<std::string, std::string> string_public_key;
    std::pair<lnumber, lnumber> public_key;
    time_t current_time;
    __RSA rsa = __RSA();
    size_t begin_of_signature, begin_of_payload;
    std::cout << "Enter the token:";
    std::cin >> jwt_token;
    std::cout << "Enter the public key first number:";
    std::cin >> string_public_key.first;
    std::cout << "Enter the public key second number:";
    std::cin >> string_public_key.second;
    public_key.first = lnumber(string_public_key.first);
    public_key.second = lnumber(string_public_key.second);

    begin_of_signature = jwt_token.find_last_of('.') + 1;
    signature = jwt_token.substr(begin_of_signature, jwt_token.size() - begin_of_signature);
    first_and_second_part_of_token = jwt_token.substr(0, begin_of_signature - 1);
    rsa.message_decryption_electronic_signature(signature, public_key);

    begin_of_payload = first_and_second_part_of_token.find('.') + 1;
    second_part_of_token = first_and_second_part_of_token.substr(begin_of_payload, first_and_second_part_of_token.size() - begin_of_payload);
    first_part_of_token = first_and_second_part_of_token.substr(0, begin_of_payload - 1);
    rsa.message_decryption_electronic_signature(second_part_of_token, public_key);
    rsa.message_decryption_electronic_signature(first_part_of_token, public_key);
    signature[first_part_of_token.size()] = '.';
    first_and_second_part_of_token = first_part_of_token + '.' + second_part_of_token;

    if (signature == first_and_second_part_of_token) {
        size_t begin_time_of_creation = second_part_of_token.find_last_of('/') + 1;
        size_t begin_of_exp = second_part_of_token.find_last_of('/', begin_time_of_creation - 2) + 1;
        int time_of_creation = atoi(second_part_of_token.substr(begin_time_of_creation, second_part_of_token.size() - begin_time_of_creation).c_str());
        int exp = atoi(second_part_of_token.substr(begin_of_exp, begin_time_of_creation - begin_of_exp - 1).c_str());
        time(&current_time);
        if (current_time - time_of_creation < exp) {
            std::cout << "THE TOKEN IS VALID";
        } else
            std::cout << "THE TOKEN IS INVALID";
    } else
        std::cout << "THE TOKEN IS INVALID";

    return 0;
}

// 65537
// 3351951982485649274893506249551461531869841455148098344430890360930441007532050210730471885601707233153533137673307370903984057259642637399542161549046867
//:\27<E\25o&xJ,E8jI~,}ZALcaA%~|So\27O,;\28jNda-{\27CPWZEhOG}rW`BDk~57?T1{Z"`\25O<vDWj|#x\29;.0nI?3"E)\32s5sn-UE\253M}S#K\29?}!s@oW6bTNt\25\27C>978y\28/#C=&9@}K@v~'T2/"\28{Y)&P\261_#tsnza.8HH{'O?OA)FhE@c>#o\29<hgyob@\25@n*!:$GLQ\318\30e!dK?'SV|>cU'V\30u`YeMB"iVq#]e6]\30[$$%_7K