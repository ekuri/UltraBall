#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QWidget>

namespace Ui {
class DebugWindow;
}

class DebugWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DebugWindow(QWidget *parent = 0);
    ~DebugWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DebugWindow *ui;
};

#endif // DEBUGWINDOW_H
