cmake_minimum_required(VERSION 3.10)
project(FileSyncSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network)

add_executable(FileSyncSystem
    src/FileMetadata.cpp
    src/Server.cpp
    src/Client.cpp
    src/Encryption.cpp
    src/MainWindow.cpp
    main.cpp
)

target_link_libraries(FileSyncSystem
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Network
    OpenSSL::SSL
    OpenSSL::Crypto
)
