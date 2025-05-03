#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include "Client.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void connectToServer();
    void uploadFile();
    void downloadFile();
    void synchronizeFiles();

private:
    Ui::MainWindow* ui;
    QPushButton* connectButton;
    QPushButton* uploadButton;
    QPushButton* downloadButton;
    QPushButton* syncButton;
    QListWidget* fileList;
    QLineEdit* filePathInput;

    Client client;
    bool isConnected;
};

#endif // MAINWINDOW_HPP
