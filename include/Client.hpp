#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include "FileMetadata.hpp"
#include "Encryption.hpp"

class Client {
public:
    // Connect to the server
    void connectToServer(const std::string& serverAddress, int port);

    // Disconnect from the server
    void disconnectFromServer();

    // Upload a file to the server
    void uploadFile(const std::string& filePath);

    // Download a file from the server
    void downloadFile(const std::string& fileName);

    // Synchronize files with the server
    void synchronizeFiles();

private:
    int serverSocket;
    std::unordered_map<std::string, FileMetadata> localFiles; // Local file metadata
    std::mutex mtx;

    // Serialize and send file metadata to the server
    void sendFileMetadata(const std::string& fileName);

    // Receive and store a file from the server
    void receiveFile(const std::string& fileName);
};

#endif // CLIENT_HPP
