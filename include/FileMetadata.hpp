#ifndef FILEMETADATA_HPP
#define FILEMETADATA_HPP

#include <string>
#include <ctime>

struct FileMetadata {
    std::string fileName;       // Name of the file
    size_t fileSize;            // Size of the file in bytes
    std::time_t timestamp;      // Last modified timestamp
    std::string hash;           // Hash of the file content (e.g., SHA-256)

    // Constructor
    FileMetadata(const std::string& name, size_t size, std::time_t ts, const std::string& h)
        : fileName(name), fileSize(size), timestamp(ts), hash(h) {}
};

#endif // FILEMETADATA_HPP
