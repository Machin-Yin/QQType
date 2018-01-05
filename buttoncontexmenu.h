#ifndef BUTTONCONTEXMENU_H
#define BUTTONCONTEXMENU_H

#include <QPushButton>
#include <QAction>

class ButtonContexMenu : public QPushButton
{
    Q_OBJECT
public:
    ButtonContexMenu(QWidget *parent = 0);
    ~ButtonContexMenu();
private:
    void createAction();

protected slots:
    void actionSendSlot();

private:
    QAction *actionLogin;
    QAction *actionSetting;
    QAction *actionHistory;
    QAction *actionBWList;
    QAction *actionSend;
    QAction *actionThesaurus;
    QAction *actionAbility;
};

#endif // BUTTONCONTEXMENU_H
