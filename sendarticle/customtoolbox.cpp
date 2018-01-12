#include "customtoolbox.h"

CustomToolBox::CustomToolBox(QWidget *parent)
    : QWidget(parent)
{
    headLabel = new QLabel("文章列表", this);
    headButton = new QPushButton("+");
    pushButton1 = new QPushButton;
    pushButton2 = new QPushButton;
    listWidget1 = new QListWidget;
    listWidget2 = new QListWidget;
    headHLayout = new QHBoxLayout;
    vboxLayout = new QVBoxLayout(this);
    spacerItem = new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum);

    headHLayout->addWidget(headLabel);
    headHLayout->addStretch();
    headHLayout->addWidget(headButton);

    vboxLayout->addLayout(headHLayout);
    vboxLayout->addWidget(pushButton1);
    vboxLayout->addWidget(listWidget1);
    vboxLayout->addWidget(pushButton2);
    vboxLayout->addWidget(listWidget2);
    vboxLayout->addSpacerItem(spacerItem);

    vboxLayout->setSpacing(0);
    vboxLayout->setMargin(0);
    vboxLayout->setContentsMargins(0,0,0,0);
//    setLayout(vboxLayout);

    connect(pushButton1,SIGNAL(clicked()),SLOT(onButton1Clicked()));
    connect(pushButton2,SIGNAL(clicked()),SLOT(onButton2Clicked()));
}

CustomToolBox::~CustomToolBox()
{

}

void CustomToolBox::onButton1Clicked()
{
    if(listWidget1->isHidden())
    {
        setSpacerExpand(false);
        listWidget1->show();
    }
    else
    {
        if(listWidget2->isHidden())
        {
            setSpacerExpand(true);
        }
        listWidget1->hide();
    }
}

void CustomToolBox::onButton2Clicked()
{
    if(listWidget2->isHidden())
    {
        setSpacerExpand(false);
        listWidget2->show();
    }
    else
    {
        if(listWidget1->isHidden())
        {
            setSpacerExpand(true);
        }
        listWidget2->hide();
    }
}

void CustomToolBox::setSpacerExpand(bool is)
{
    if(is)
    {
        spacerItem->changeSize(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
    }
    else
    {
        spacerItem->changeSize(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum);
    }
}
