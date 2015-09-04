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
    CoreService::getInstance()->addItemRandomly(ItemType::commonBall);
}
