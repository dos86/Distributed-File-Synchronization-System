#include "Encryption.hpp"
#include <openssl/aes.h>
#include <cstring>

std::string Encryption::encrypt(const std::string& data, const std::string& key) {
    AES_KEY aesKey;
    unsigned char encryptedData[1024];
    memset(encryptedData, 0, sizeof(encryptedData));

    AES_set_encrypt_key((unsigned char*)key.c_str(), 256, &aesKey);
    AES_encrypt((unsigned char*)data.c_str(), encryptedData, &aesKey);

    return std::string((char*)encryptedData);
}

std::string Encryption::decrypt(const std::string& encryptedData, const std::string& key) {
    AES_KEY aesKey;
    unsigned char decryptedData[1024];
    memset(decryptedData, 0, sizeof(decryptedData));

    AES_set_decrypt_key((unsigned char*)key.c_str(), 256, &aesKey);
    AES_decrypt((unsigned char*)encryptedData.c_str(), decryptedData, &aesKey);

    return std::string((char*)decryptedData);
}
