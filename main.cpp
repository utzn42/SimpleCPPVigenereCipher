#include <iostream>
#include <string>
#include "Vigenere.h"

int main() {
    bool loop = false;
    bool encrypt;
    std::string text;
    std::string key;
    Vigenere vig = Vigenere();
    do {
        std::cout << "Do you want to decrypt(0) or encrypt(1)? Enter 0 or 1 and confirm with enter: " << std::endl;
        std::cin >> encrypt;
        std::cout << "Enter text (no spaces or punctuation) and confirm with enter: " << std::endl;
        std::cin >> text;
        std::cout << "Enter key (no spaces or punctuation) and confirm with enter: " << std::endl;
        std::cin >> key;
        if(encrypt){
            std::cout << "Ciphertext: " << vig.encr(text, key) << std::endl;
        } else{
            std::cout << "Plaintext: " << vig.decr(text, key) << std::endl;
        }

        std::cout << "Abort(0) or continue(1)? Enter 0 or 1 and confirm with enter:";
        std::cin >> loop;
    } while (loop);
}