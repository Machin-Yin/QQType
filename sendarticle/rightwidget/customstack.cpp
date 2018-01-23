#include "customstack.h"

CustomStack::CustomStack(QWidget *parent)
    : QWidget(parent)
{
    wordButton = new QPushButton;
    articleButton = new QPushButton;
    wordWidget = new WordWidget;
    articleWidget = new ArticleWidget;
    stack = new QStackedWidget(this);
    stack->addWidget(wordWidget);
    stack->addWidget(articleWidget);

    mainLayout = new QVBoxLayout(this);
    hboxLayout = new QHBoxLayout;
    hboxLayout->addWidget(wordButton);
    hboxLayout->addWidget(articleButton);
    mainLayout->addLayout(hboxLayout);
    mainLayout->addWidget(stack);
    connect(wordButton, SIGNAL(clicked()), this, SLOT(stackSetCurrentIndex0()));
    connect(articleButton, SIGNAL(clicked()), this, SLOT(stackSetCurrentIndex1()));

}

CustomStack::~CustomStack()
{

}

void CustomStack::stackSetCurrentIndex0()
{
    stack->setCurrentIndex(0);
}

void CustomStack::stackSetCurrentIndex1()
{
    stack->setCurrentIndex(1);
}
