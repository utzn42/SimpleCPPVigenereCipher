

#ifndef VIGENERE_VIGENERE_H
#define VIGENERE_VIGENERE_H


#include <string>
#include <vector>

class Vigenere {
    std::string lowercase_alphabet;
    std::string uppercase_alphabet;
public:
    Vigenere();

    std::string encr(std::string plaintext, std::string key);

    std::string decr(std::string ciphertext, std::string key);
};


#endif //VIGENERE_VIGENERE_H
