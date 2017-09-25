#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

enum Mode{
    PRIMARY 10;
    MIDDLE 40;
    ADVANCED 99
};



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QWidget *parent = 0,Mode mode);
    ~MainWindow();
    int getLayoutWidth();
    int getLayoutHeight();
    void setLayoutWidth(int w);
    void setLayoutHeight(int h);
    bool setMode(Mode m);
    Mode getMode();
private:
    Ui::MainWindow *ui;
    int iLayoutWidth;
    int iLayoutHeight;
    Mode mode_e;
    char** cppMap;
    int iMineNum;

    void init();
    void mining();
    void addHint();
    void destory();
};

#endif // MAINWINDOW_H
