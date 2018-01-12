#include "sendarticle.h"

SendArticle::SendArticle(QWidget *parent) : QWidget(parent)
{
    resize(600,400);
    splitterMain = new QSplitter(Qt::Vertical,this);
    customToolBox = new CustomToolBox(this);
    splitterMain->addWidget(customToolBox);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(splitterMain);
    setLayout(mainLayout);
}
