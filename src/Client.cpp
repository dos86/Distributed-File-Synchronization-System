#include "Client.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

void Client::connectToServer(const std::string& serverAddress, int port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, serverAddress.c_str(), &serverAddr.sin_addr);

    connect(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    std::cout << "Connected to server.\n";
}

void Client::uploadFile(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return;
    }

    // Send file metadata
    sendFileMetadata(filePath);

    // Send file content
    char buffer[1024];
    while (file.read(buffer, sizeof(buffer))) {
        send(serverSocket, buffer, file.gcount(), 0);
    }
    file.close();
}

void Client::sendFileMetadata(const std::string& fileName) {
    // Serialize and send metadata
}
