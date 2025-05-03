#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QFileDialog>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), isConnected(false) {
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    connectButton = new QPushButton("Connect to Server", this);
    uploadButton = new QPushButton("Upload File", this);
    downloadButton = new QPushButton("Download File", this);
    syncButton = new QPushButton("Synchronize Files", this);
    fileList = new QListWidget(this);
    filePathInput = new QLineEdit(this);

    layout->addWidget(connectButton);
    layout->addWidget(uploadButton);
    layout->addWidget(downloadButton);
    layout->addWidget(syncButton);
    layout->addWidget(fileList);
    layout->addWidget(filePathInput);

    setCentralWidget(centralWidget);

    connect(connectButton, &QPushButton::clicked, this, &MainWindow::connectToServer);
    connect(uploadButton, &QPushButton::clicked, this, &MainWindow::uploadFile);
    connect(downloadButton, &QPushButton::clicked, this, &MainWindow::downloadFile);
    connect(syncButton, &QPushButton::clicked, this, &MainWindow::synchronizeFiles);
}

MainWindow::~MainWindow() {}

void MainWindow::connectToServer() {
    client.connectToServer("127.0.0.1", 8080);
    isConnected = true;
}

void MainWindow::uploadFile() {
    QString filePath = QFileDialog::getOpenFileName(this, "Select File");
    if (!filePath.isEmpty()) {
        client.uploadFile(filePath.toStdString());
    }
}
