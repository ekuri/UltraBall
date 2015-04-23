#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "coreservice.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1000, 600);

    //this->setMouseTracking(true);
    srand(QTime::currentTime().msecsSinceStartOfDay());
    image.load(":/image/image.png");
    image = image.scaled(64, 64);

    timer.setInterval(10);
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(checkWalls()));
    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //b->bounce(this->width(), this->height());
    if (CoreService::getInstance()->ballsAction(this->width(), this->height(), ui->target->geometry())) {
        /*QMessageBox::information(this, "Congratulation", "Success!!!");
        this->close();
        return;*/
    }

    QPainter p(this);
    if (mouseClicked)
        p.drawLine(startPoint, endPoint);

    list<Ball> *ballList = CoreService::getInstance()->getBallList();
    for (list<Ball>::iterator it = ballList->begin(); it != ballList->end(); it++) {
        p.drawPixmap(it->getPos().x(), it->getPos().y(), it->getSize(), it->getSize(), image);
    }

    list<Wall> *wallList = CoreService::getInstance()->getWallList();
    for (list<Wall>::iterator it = wallList->begin(); it != wallList->end(); it++) {
        p.drawLine(it->getStartPoint(), it->getEndPoint());
    }
    event->accept();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        startPoint = event->pos();
        endPoint = startPoint;
        mouseClicked = true;
    }
    event->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    list<Ball> *ballList = CoreService::getInstance()->getBallList();
    for (list<Ball>::iterator it = ballList->begin(); it != ballList->end(); it++) {
        if (it->bounceToLine(startPoint, endPoint))
            return;
        Wall temp(startPoint, endPoint);
        CoreService *core = CoreService::getInstance();
        core->getWallList()->push_back(temp);
        mouseClicked = false;
    }
    event->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug() << event->buttons();
    if (event->buttons() & Qt::LeftButton) {
        endPoint = event->pos();
        //qDebug() << " endPoint" << endPoint;
    }
    event->accept();
}

void MainWindow::on_addBtn_clicked()
{
    CoreService::getInstance()->addBall(Ball(60));
}

void MainWindow::checkWalls()
{
    CoreService::getInstance()->checkWallsAge();
}
