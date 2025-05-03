# Distributed-File-Synchronization-System

#### Overview:
This project simulates a **distributed file synchronization system** where multiple clients can upload, download, and synchronize files with a central server. The system ensures that all clients have access to the latest version of files stored on the server. It uses **TCP/IP** for reliable communication, **serialization** for transmitting file metadata, and **multithreading** to handle concurrent client requests.

---

### Key Features:
1. **File Upload/Download**:
   - Clients can upload files to the server or download files from the server.
   - Files are stored on the server with metadata (e.g., file name, size, timestamp).

2. **File Synchronization**:
   - Clients periodically check the server for updates and synchronize their local files with the latest versions.

3. **Concurrency**:
   - The server handles multiple clients concurrently using multithreading.
   - Thread-safe data structures ensure safe access to shared resources.

4. **Serialization**:
   - File metadata (e.g., name, size, timestamp) is serialized and transmitted over the network.
   - Binary or JSON serialization can be used for efficient data transfer.

5. **STL Usage**:
   - Use `std::map` or `std::unordered_map` to store file metadata on the server.
   - Use `std::vector` and `std::queue` for managing client requests.

6. **OOP Design**:
   - Encapsulate the server, client, and file metadata in separate classes (`Server`, `Client`, `FileMetadata`).
   - Use polymorphism to allow different types of operations (e.g., upload, download, sync).

7. **Error Handling**:
   - Handle invalid file paths, missing files, and network errors.
   - Provide meaningful error messages for debugging.

8. **Optional SQL Integration**:
   - Store file metadata in a Microsoft SQL Server database for persistence.

---

#### Folder Structure:
```
FileSyncSystem/
├── include/
│   ├── FileMetadata.hpp     // File metadata class definition
│   ├── Server.hpp           // Server class definition
│   ├── Client.hpp           // Client class definition
│   └── Encryption.hpp       // Encryption utilities
├── src/
│   ├── FileMetadata.cpp
│   ├── Server.cpp
│   ├── Client.cpp
│   ├── Encryption.cpp
│   └── MainWindow.cpp       // GUI implementation
├── main.cpp                 // Main entry point
├── CMakeLists.txt           // Build configuration
└── README.md                // Project documentation
```

---

### Workflow:
1. **Server**:
   - Listens for incoming client connections.
   - Handles file upload, download, and synchronization requests.
   - Stores file metadata and ensures thread-safe access.

2. **Client**:
   - Connects to the server via TCP/IP.
   - Sends requests to upload, download, or synchronize files.
   - Periodically checks the server for updates.

3. **File Synchronization**:
   - Clients compare their local file metadata with the server's metadata.
   - If a newer version exists on the server, the client downloads the updated file.

---

### Example Use Case:
- A user starts the server application.
- Multiple clients connect to the server and upload files.
- Clients periodically synchronize their local files with the server.
- If a file is updated on the server, all connected clients download the latest version.

---

### Technologies Used:
1. **STL**: `std::map`, `std::unordered_map`, `std::vector`, `std::thread`, `std::mutex`.
2. **OOP**: Encapsulation and modularity in designing `FileMetadata`, `Server`, and `Client` classes.
3. **Multithreading**: Concurrent handling of multiple client requests using threads.
4. **Networking**: TCP/IP sockets for reliable communication.
5. **Serialization**: Binary or JSON serialization for transmitting file metadata.
6. **SQL (Optional)**: Interaction with Microsoft SQL Server using ODBC for storing file metadata.

---
