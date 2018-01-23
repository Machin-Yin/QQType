#include "sendarticle.h"

SendArticle::SendArticle(QWidget *parent) : QWidget(parent)
{
    resize(600,400);
    splitterMain = new QSplitter(Qt::Horizontal);
    customToolBox = new CustomToolBox;
    rightWidget = new RightWidget;
    splitterMain->addWidget(customToolBox);
    splitterMain->addWidget(rightWidget);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(splitterMain);
//    setLayout(mainLayout);
}
