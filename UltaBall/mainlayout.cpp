#include "mainlayout.h"
#include "ui_mainlayout.h"
#include <QMessageBox>
#include "coreservice.h"
#include <QPen>
#include "target.h"

MainLayout::MainLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainLayout)
{
    ui->setupUi(this);
    started = false;

    srand(QTime::currentTime().msecsSinceStartOfDay());
    image.load(":/image/image.png");

    timer.setInterval(10);
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(checkWalls()));
    timer.start();
}

MainLayout::~MainLayout()
{
    delete ui;
}

void MainLayout::paintEvent(QPaintEvent *event)
{
    if (!started)
        return;
    if (CoreService::getInstance()->getBallList()->size() == 0) {
        CoreService::getInstance()->removeTarget();
        this->setEnabled(false);
        //this->close();
    }
    // update score display
    ui->scoreLcdNumber->display(CoreService::getInstance()->getScore());

    list<Ball> *ballList = CoreService::getInstance()->getBallList();
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::lightGray);
    if (CoreService::getInstance()->ballsAction()) {
        //QMessageBox::information(this, "Congratulation", "Success!!!");
        //this->close();
        //return;
    }
    Target *target =  CoreService::getInstance()->getTarget();
    if (target)
        target->moveNext();

    QPainter p(this);
    p.setPen(pen);
    if (mouseClicked)
        p.drawLine(startPoint, endPoint);

    // paint target
    if (target)
        p.drawPixmap(target->getGeometry().topLeft(), image.scaled(target->getGeometry().size()));

    // paint balls
    for (list<Ball>::iterator it = ballList->begin(); it != ballList->end(); it++) {
        p.drawPixmap(it->getPos().x(), it->getPos().y(), it->getSize(), it->getSize(), image.scaled(QSize(it->getSize(), it->getSize())));
    }

    // paint walls
    list<Wall> *wallList = CoreService::getInstance()->getWallList();
    for (list<Wall>::iterator it = wallList->begin(); it != wallList->end(); it++) {
        p.drawLine(it->getStartPoint(), it->getEndPoint());
    }

    // paint and move virtual balls
    list<Ball> *virtualBallList = CoreService::getInstance()->getVirtualBallList();
    for (list<Ball>::iterator it = virtualBallList->begin(); it != virtualBallList->end(); it++) {
        it->moveNext();
        it->bounce();
        p.drawPixmap(it->getPos().x(), it->getPos().y(), it->getSize(), it->getSize(), image.scaled(QSize(it->getSize(), it->getSize())));
    }

    event->accept();
}

void MainLayout::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        startPoint = event->pos();
        endPoint = startPoint;
        mouseClicked = true;
    }
    event->accept();
}

void MainLayout::mouseReleaseEvent(QMouseEvent *event)
{
    list<Ball> *ballList = CoreService::getInstance()->getBallList();
    for (list<Ball>::iterator it = ballList->begin(); it != ballList->end(); it++) {
        if (it->bounceToLine(startPoint, endPoint))
            return;
    }
    Wall temp(startPoint, endPoint);
    CoreService *core = CoreService::getInstance();
    core->getWallList()->push_back(temp);
    mouseClicked = false;
    event->accept();
}

void MainLayout::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        endPoint = event->pos();
    }
    event->accept();
}

void MainLayout::resizeEvent(QResizeEvent *event)
{
    CoreService::getInstance()->setWindowHeight(this->height());
    CoreService::getInstance()->setWindowWidth(this->width());
    event->accept();
}

void MainLayout::on_addBallBtn_clicked()
{
    CoreService::getInstance()->addBall(Ball(48));
}

void MainLayout::checkWalls()
{
    CoreService::getInstance()->checkWallsAge();
}

void MainLayout::on_addTargetBtn_clicked()
{
    CoreService::getInstance()->setTarget(new Target(24));
}

void MainLayout::on_resetBtn_clicked()
{
    CoreService::getInstance()->resetAllElement();
}

void MainLayout::on_startBtn_clicked()
{
    started = true;
}
