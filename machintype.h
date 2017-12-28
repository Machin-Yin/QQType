#ifndef MACHINTYPE_H
#define MACHINTYPE_H

#include <QMainWindow>
#include <QSplitter>
#include <QTextEdit>
#include <QEvent>
#include <QInputMethodEvent>
#include <QDebug>
#include <QPalette>
#include <QColorDialog>
#include <QEvent>
#include <QKeyEvent>

#include "customtextedit.h"

class MachinType : public QMainWindow
{
    Q_OBJECT

public:
    MachinType(QWidget *parent = 0);
    ~MachinType();
private:
    void setCharColor(unsigned int pos, bool equal);
    void setCharColorBack(unsigned int pos);
    bool event(QEvent *event);
private slots:
    void onType();
private:
    QSplitter *splitterMain;
    QTextEdit *srcEdit;
    QTextEdit *destEdit;
    QString srcStr;
    int srcLength;
    QColor defColor;
    QColor rightColor;
    QColor wrongColor;
};

#endif // MACHINTYPE_H
