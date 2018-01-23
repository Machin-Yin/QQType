#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "customstack.h"

class RightWidget : public QWidget
{
    Q_OBJECT

public:
    RightWidget(QWidget *parent = 0);
    ~RightWidget();
private:

private:
    QVBoxLayout *mainLayout;
    QLabel *sendConfigLabel;
    CustomStack *customStack;
    QPushButton *sendButton;

};

#endif // MAINWINDOW_H
