#include<iostream>

#include "Vigenere.h"

Vigenere::Vigenere() {
    lowercase_alphabet = "abcdefghijklmnopqrstuvwxyz";
    uppercase_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

std::string Vigenere::encr(std::string plaintext, std::string key) {
    int key_mapping[key.size()];
    int plaintext_mapping[plaintext.size()];
    bool uppercase_indices[key.size()];
    std::string ciphertext = plaintext;
    for (int h = 0; h < key.size(); ++h) {
        uppercase_indices[h] = false;
    }

    for (int i{0}; i < key.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (key[i] == lowercase_alphabet[j]) {
                key_mapping[i] = j;
            }
            if (key[i] == uppercase_alphabet[j]) {
                key_mapping[i] = j;
            }
        }
    }

    for (int i{0}; i < plaintext.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (plaintext[i] == lowercase_alphabet[j]) {
                plaintext_mapping[i] = j;
            }
            if (plaintext[i] == uppercase_alphabet[j]) {
                plaintext_mapping[i] = j;
                uppercase_indices[i] = true;
            }
        }
    }

    for (int k = 0; k < plaintext.size(); ++k) {
        if (!uppercase_indices[k]) {
            ciphertext[k] = lowercase_alphabet[(1 + plaintext_mapping[k] + key_mapping[k % key.size()]) % 26];
        } else {
            ciphertext[k] = uppercase_alphabet[(1 + plaintext_mapping[k] + key_mapping[k % key.size()]) % 26];
        }
    }
    return ciphertext;
}

std::string Vigenere::decr(std::string ciphertext, std::string key) {
    int key_mapping[key.size()];
    int ciphertext_mapping[ciphertext.size()];
    bool uppercase_indices[key.size()];
    std::string plaintext = ciphertext;
    for (int h = 0; h < key.size(); ++h) {
        uppercase_indices[h] = false;
    }

    for (int i{0}; i < key.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (key[i] == lowercase_alphabet[j]) {
                key_mapping[i] = j;
            }
            if (key[i] == uppercase_alphabet[j]) {
                key_mapping[i] = j;
            }
        }
    }

    for (int i{0}; i < ciphertext.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (ciphertext[i] == lowercase_alphabet[j]) {
                ciphertext_mapping[i] = j;
            }
            if (ciphertext[i] == uppercase_alphabet[j]) {
                ciphertext_mapping[i] = j;
                uppercase_indices[i] = true;
            }
        }
    }

    for (int k = 0; k < plaintext.size(); ++k) {
        if (!uppercase_indices[k]) {
            int index = (26 + (ciphertext_mapping[k] - key_mapping[k % key.size()] - 1)) % 26;
            plaintext[k] = lowercase_alphabet[index];
        } else {
            plaintext[k] = uppercase_alphabet[(26 + (ciphertext_mapping[k] - key_mapping[k % key.size()] - 1)) % 26];
        }
    }
    return plaintext;
}

