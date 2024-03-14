#include <ctime>

#include "update_RSA.hpp"

struct payload {
    std::string login;
    std::string password;
    const time_t exp = 300;
    time_t time_of_creation;
} typedef payload;

class token {
   private:
    std::string get_payload(payload second) {
        std::string result = second.login;
        result += '/' + second.password;
        result += '/' + std::to_string(second.exp);
        result += '/' + std::to_string(second.time_of_creation);
        return result;
    }

    std::pair<std::string, std::string> header = std::pair<std::string, std::string>("RSA", "JWT");
    payload second_part;
    __RSA rsa = __RSA();
    std::string signature;
    void get_signature() {
        this->signature = this->header.first + this->header.second + "." + get_payload(this->second_part);
        rsa.message_encryption_electronic_signature(this->signature);
    }

   public:
    token(std::string login, std::string password) {
        this->second_part.login = login;
        this->second_part.password = password;
        time(&this->second_part.time_of_creation);
        get_signature();
    };
    ~token(){};

    std::string get_token() {
        std::string first = this->header.first + this->header.second;
        rsa.message_encryption_electronic_signature(first);
        std::string second = get_payload(this->second_part);
        rsa.message_encryption_electronic_signature(second);

        std::string result = first + "." + second + "." + this->signature;
        return result;
    }

    std::pair<lnumber, lnumber> get_public_key() { return this->rsa.get_public_key(); }

    time_t get_time_of_creation() { return this->second_part.time_of_creation; }
};

int main() {
    token jwt_token = token("ivan", "pechechkin");

    std::cout << "TOKEN:\n" << jwt_token.get_token() << '\n';
    auto pub_key = jwt_token.get_public_key();
    std::cout << "PUBLIC KEY:\n FIRST NUMBER:\n" << pub_key.first << "\nSECOND NUMBER:\n" << pub_key.second;

    return 0;
}
