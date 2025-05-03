#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <string>

class Encryption {
public:
    // Encrypt data using AES-256
    static std::string encrypt(const std::string& data, const std::string& key);

    // Decrypt data using AES-256
    static std::string decrypt(const std::string& encryptedData, const std::string& key);
};

#endif // ENCRYPTION_HPP
