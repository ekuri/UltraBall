#include "gamelayout.h"
#include "ui_gamelayout.h"

GameLayout::GameLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameLayout)
{
    ui->setupUi(this);
}

GameLayout::~GameLayout()
{
    delete ui;
}
