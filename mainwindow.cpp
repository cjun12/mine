#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridLayout->addWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getLayoutWidth()
{
    return iLayoutWidth;
}

int MainWindow::getLayoutHeight(){
    return iLayoutHeight;
}

void MainWindow::setLayoutHeight(int h){
    this->iLayoutHeight = h;
}
void MainWindow::setLayoutWidth(int w){
    this->iLayoutWidth = w;
}


Mode MainWindow::getMode(){
    return mode_e;
}

bool MainWindow::setMode(Mode m){
    mode_e = m
}

void MainWindow::init()
{
    cppMap = new char*[iLayoutHeight];
    for(int i=0; i<iLayoutHeight; i++)
    {
        cppMap[i] = new char[iLayoutWidth];
    }
    for(int i=0; i<iLayoutHeight; i++)
    {
        for(int j=0; j<iLayoutWidth; j++)
        {
            cppMap[i][j]='0';
        }
    }
}

void MainWindow::printMap()
{
    cout<<"print map"<<endl;
    for(int i=0; i<iLayoutHeight; i++)
    {
        for(int j=0; j<iLayoutWidth; j++)
        {
            cout<<cppMap[i][j]<<" ";
        }
        cout<<endl;
    }
}

void MainWindow::mining()
{
    srand((unsigned)time(NULL));
    for(int i=0; i<iMineNum; i++)
    {
        int iLayoutWidthPos=rand()%iLayoutWidth;
        int iLayoutHeightPos=rand()%iLayoutHeight;
        if(cppMap[iLayoutHeightPos][iLayoutWidthPos]=='*')
        {
            i--;
            continue;
        }
        cppMap[iLayoutHeightPos][iLayoutWidthPos]='*';
    }
}

void MainWindow::addHint()
{
    for(int i = 0; i<iLayoutHeight; i++)
    {
        for(int j = 0 ; j<iLayoutWidth; j++)
        {
            if(cppMap[i][j]=='*')
            {
                for(int k=i-1; k<=i+1; k++)
                {
                    if(k<0||k>=iLayoutHeight)
                    { continue; }
                    for(int l=j-1; l<=j+1; l++)
                    {
                        if(l<0||l>=iLayoutWidth||(k==i&&l==j))
                        { continue; }
                        if(cppMap[k][l]!='*')
                            cppMap[k][l]+=1;
                    }
                }
            }
        }
    }
}

void MainWindow::destory()
{
    cout<<"destory"<<endl;
    for(int i=0; i<iLayoutHeight; i++)
    {
        delete[] cppMap[i];
    }
    delete[] cppMap;
}
