#include "headtool.h"

HeadTool::HeadTool(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    createHorizontalGroup();
    setWidgetFixSize();
    setObjName();
    setLabelAlign();
    addLayout();
    setLayout(mainLayout);
}

void HeadTool::createHorizontalGroup()
{
    createHorizontalGroup1();
    createHorizontalGroup2();
    createHorizontalGroup3();
}

void HeadTool::createHorizontalGroup1()
{
    hboxLayout1 = new QHBoxLayout;
    hboxLayout1->setContentsMargins(0,4,0,1);

    timeButton = new QPushButton((tr("0000")));
    speedLabel = new QLabel(tr("0.00"));
    keyStrokeLabel = new QLabel(tr("0.00"));
    codeLengthLabel = new QLabel(tr("0.00"));
    avSpeedLabel = new QLabel(tr("0.00"));
    avKeyStrokeLabel = new QLabel(tr("0.00"));
    avCodeLengthLabel = new QLabel(tr("0.00"));
    menuButton = new QPushButton(tr("菜单 "));
    createButtonMenu();
    menuButton->setMenu(buttonMenu);
    buttonMenu->installEventFilter(this);
    hboxLayout1->setSpacing(0);

    hboxLayout1->addWidget(timeButton);
    hboxLayout1->addWidget(speedLabel);
    hboxLayout1->addWidget(keyStrokeLabel);
    hboxLayout1->addWidget(codeLengthLabel);
    hboxLayout1->addWidget(avSpeedLabel);
    hboxLayout1->addWidget(avKeyStrokeLabel);
    hboxLayout1->addWidget(avCodeLengthLabel);
    hboxLayout1->addWidget(menuButton);

}

void HeadTool::createHorizontalGroup2()
{
    hboxLayout2 = new QHBoxLayout;
    hboxLayout2->setContentsMargins(0,0,0,0);

    paraButton = new QPushButton(tr("无段落"));
    starButton = new QPushButton;
    titleLabel = new QLabel(tr("无标题"));
    historyButton = new QPushButton;
    classLabel = new QLabel(tr("文章"));
    countLabel = new QLabel;
    groupLabel = new QLabel(tr("未设置"));

    hboxLayout2->setSpacing(0);

    hboxLayout2->addWidget(paraButton);
    hboxLayout2->addWidget(starButton);
    hboxLayout2->addWidget(titleLabel);
    hboxLayout2->addWidget(historyButton);
    hboxLayout2->addWidget(classLabel);
    hboxLayout2->addWidget(countLabel);
    hboxLayout2->addWidget(groupLabel);
}

void HeadTool::createHorizontalGroup3()
{
    hboxLayout3 = new QHBoxLayout;
    hboxLayout3->setContentsMargins(0,0,0,0);

    progBar = new QProgressBar;
    progBar->setAlignment(Qt::AlignVCenter);
    hboxLayout3->addWidget(progBar);
}

void HeadTool::addLayout()
{
    mainLayout->addLayout(hboxLayout1);
    mainLayout->addLayout(hboxLayout2);
    mainLayout->addLayout(hboxLayout3);
}

void HeadTool::setObjName()
{
    timeButton->setObjectName("timeButton");
    speedLabel->setObjectName("speedLabel");
    keyStrokeLabel->setObjectName("keyStrokeLabel");
    codeLengthLabel->setObjectName("codeLengthLabel");
    avSpeedLabel->setObjectName("avSpeedLabel");
    avKeyStrokeLabel->setObjectName("avKeyStrokeLabel");
    avCodeLengthLabel->setObjectName("avCodeLengthLabel");
    menuButton->setObjectName("menuButton");

    paraButton->setObjectName("paraButton");
    starButton->setObjectName("starButton");
    titleLabel->setObjectName("titleLabel");
    historyButton->setObjectName("historyButton");
    classLabel->setObjectName("classLabel");
    countLabel->setObjectName("countLabel");
    groupLabel->setObjectName("groupLabel");
}

void HeadTool::setLabelAlign()
{
    speedLabel->setAlignment(Qt::AlignCenter);
    keyStrokeLabel->setAlignment(Qt::AlignCenter);
    codeLengthLabel->setAlignment(Qt::AlignCenter);
    avSpeedLabel->setAlignment(Qt::AlignCenter);
    avKeyStrokeLabel->setAlignment(Qt::AlignCenter);
    avCodeLengthLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setAlignment(Qt::AlignCenter);
    classLabel->setAlignment(Qt::AlignCenter);
    countLabel->setAlignment(Qt::AlignCenter);
    groupLabel->setAlignment(Qt::AlignCenter);
}

void HeadTool::setWidgetFixSize()
{
    paraButton->setFixedSize(QSize(62,18));
    paraButton->setFixedSize(QSize(62,18));
    paraButton->setFixedSize(QSize(60,18));
    starButton->setFixedSize(QSize(18,18));
    historyButton->setFixedSize(QSize(18,18));
    classLabel->setFixedSize(QSize(40,18));
    countLabel->setFixedSize(QSize(60,18));
    groupLabel->setFixedSize(QSize(60,18));
}

void HeadTool::createButtonMenu()
{
    buttonMenu = new QMenu();

    actionLogin = new QAction(buttonMenu);
    actionSetting = new QAction(buttonMenu);
    actionHistory = new QAction(buttonMenu);
    actionBWList = new QAction(buttonMenu);
    actionSend = new QAction(buttonMenu);
    actionThesaurus = new QAction(buttonMenu);
    actionAbility = new QAction(buttonMenu);

    actionLogin->setText("登录");
    actionSetting->setText("设置");
    actionHistory->setText("跟打历史");
    actionBWList->setText("黑白名单");
    actionSend->setText("我的发文");
    actionThesaurus->setText("词库管理");
    actionAbility->setText("我的能力");

    buttonMenu->addAction(actionLogin);
    buttonMenu->addAction(actionSetting);
    buttonMenu->addAction(actionHistory);
    buttonMenu->addAction(actionBWList);
    buttonMenu->addAction(actionSend);
    buttonMenu->addAction(actionThesaurus);
    buttonMenu->addAction(actionAbility);
}

bool HeadTool::eventFilter(QObject * obj, QEvent *event)
{
    if (event->type() == QEvent::Show && obj == menuButton->menu())
    {
        int menuXPos = menuButton->menu()->pos().x();
        int menuWidth = menuButton->menu()->size().width();
        int buttonWidth = menuButton->size().width();

        QPoint pos = QPoint(menuXPos - menuWidth + buttonWidth,
                            menuButton->menu()->pos().y());

        menuButton->menu()->move(pos);
        return true;
    }
    return false;
}

