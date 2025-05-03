#ifndef SERVER_HPP
#define SERVER_HPP

#include <unordered_map>
#include <vector>
#include <thread>
#include <mutex>
#include "FileMetadata.hpp"
#include "Encryption.hpp"

class Server {
public:
    // Start the server
    void start();

    // Stop the server
    void stop();

    // Handle client requests
    void handleClient(int clientSocket);

private:
    std::unordered_map<std::string, FileMetadata> files; // File metadata stored on the server
    std::mutex mtx;

    // Serialize and send file metadata to the client
    void sendFileMetadata(int clientSocket, const std::string& fileName);

    // Receive and store a file from the client
    void receiveFile(int clientSocket, const std::string& fileName, size_t fileSize);

    // Resolve conflicts if a file with the same name exists
    bool resolveConflict(const std::string& fileName, const FileMetadata& newMetadata);
};

#endif // SERVER_HPP
