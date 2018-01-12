#ifndef CUSTOMTOOLBOX_H
#define CUSTOMTOOLBOX_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QLabel>

class CustomToolBox : public QWidget
{
    Q_OBJECT

public:
    CustomToolBox(QWidget *parent = 0);
    ~CustomToolBox();
private:
    void setSpacerExpand(bool is);
private slots:
    void onButton1Clicked();
    void onButton2Clicked();

private:
    QLabel *headLabel;
    QPushButton *headButton;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QListWidget *listWidget1;
    QListWidget *listWidget2;
    QHBoxLayout *headHLayout;
    QVBoxLayout *vboxLayout;

    QSpacerItem *spacerItem;
};

#endif // CUSTOMTOOLBOX_H
