#include "buttoncontexmenu.h"

ButtonContexMenu::ButtonContexMenu(QWidget *parent)
    :QPushButton(parent)
{
    setContextMenuPolicy(Qt::ActionsContextMenu);
    createAction();
}



ButtonContexMenu::~ButtonContexMenu()
{

}

void ButtonContexMenu::createAction()
{
    actionLogin = new QAction(this);
    actionSetting = new QAction(this);
    actionHistory = new QAction(this);
    actionBWList = new QAction(this);
    actionSend = new QAction(this);
    actionThesaurus = new QAction(this);
    actionAbility = new QAction(this);

    actionLogin->setText("登录");
    actionSetting->setText("设置");
    actionHistory->setText("跟打历史");
    actionBWList->setText("黑白名单");
    actionSend->setText("我的发文");
    actionThesaurus->setText("词库管理");
    actionAbility->setText("我的能力");

    addAction(actionLogin);
    addAction(actionSetting);
    addAction(actionHistory);
    addAction(actionBWList);
    addAction(actionSend);
    addAction(actionThesaurus);
    addAction(actionAbility);
}

void ButtonContexMenu::actionSendSlot()
{

}
