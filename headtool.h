#ifndef HEADTOOL_H
#define HEADTOOL_H

#include <QWidget>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QMenu>
#include <QContextMenuEvent>

//#include "buttoncontexmenu.h"

class HeadTool : public QWidget
{
    Q_OBJECT
public:
    explicit HeadTool(QWidget *parent = nullptr);

private:
    void createHorizontalGroup();
    void createHorizontalGroup1();
    void createHorizontalGroup2();
    void createHorizontalGroup3();
    void addLayout();
    void setObjName();
    void setLabelAlign();
    void setWidgetFixSize();
    void createButtonMenu();
    bool eventFilter(QObject * obj, QEvent *event);

signals:

public slots:

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout *hboxLayout1;
    QHBoxLayout *hboxLayout2;
    QHBoxLayout *hboxLayout3;

    QPushButton *timeButton;
    QLabel *speedLabel;
    QLabel *keyStrokeLabel;
    QLabel *codeLengthLabel;
    QLabel *avSpeedLabel;
    QLabel *avKeyStrokeLabel;
    QLabel *avCodeLengthLabel;
    QPushButton *menuButton;

    QPushButton *paraButton;
    QPushButton *starButton;
    QLabel *titleLabel;
    QPushButton *historyButton;
    QLabel *classLabel;
    QLabel *countLabel;
    QLabel *groupLabel;

    QProgressBar *progBar;

    QMenu *buttonMenu;
    QAction *actionLogin;
    QAction *actionSetting;
    QAction *actionHistory;
    QAction *actionBWList;
    QAction *actionSend;
    QAction *actionThesaurus;
    QAction *actionAbility;
};

#endif // HEADTOOL_H
