#include "debugwindow.h"
#include "ui_debugwindow.h"
#include "coreservice.h"

DebugWindow::DebugWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DebugWindow)
{
    ui->setupUi(this);
}

DebugWindow::~DebugWindow()
{
    delete ui;
}

void DebugWindow::on_pushButton_clicked()
{
    for (int count = 0; count < 100; count++) {
        CoreService::getInstance()->addItemRandomly(ItemType::commonBall);
    }

    ui->lcdNumber->display((int) CoreService::getInstance()->getBallList().size());
}
