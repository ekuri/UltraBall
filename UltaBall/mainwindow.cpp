#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "coreservice.h"


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainLayout = new MainLayout(this);
    mainLayout->setObjectName(QStringLiteral("mainLayout"));
    mainLayout->setGeometry(QRect(0, 0, 400, 300));
    mainLayout->setStyleSheet(QStringLiteral("background-image: url();"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    mainLayout->resize(this->size());
    ui->wallPaperLabel->resize(this->size());
    event->accept();
}
