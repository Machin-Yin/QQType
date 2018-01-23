#ifndef CUSTOMSTACK_H
#define CUSTOMSTACK_H

#include <QWidget>
#include <QListWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "wordwidget.h"
#include "articlewidget.h"

class CustomStack : public QWidget
{
    Q_OBJECT

public:
    CustomStack(QWidget *parent = 0);
    ~CustomStack();

private slots:
    void stackSetCurrentIndex0();
    void stackSetCurrentIndex1();

private:
    QStackedWidget *stack;
    QPushButton *wordButton;
    QPushButton *articleButton;
    WordWidget *wordWidget;
    ArticleWidget *articleWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *hboxLayout;

};

#endif // CUSTOMSTACK_H
