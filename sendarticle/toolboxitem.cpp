#include "toolboxitem.h"

ToolBoxItem::ToolBoxItem(QWidget *parent, QString filename)
    : QWidget(parent), fileName(filename)
{
    initWidget();
    mainLayout->addWidget(selectedLabel);
    mainLayout->addWidget(nameLabel);
    mainLayout->addWidget(countLabel);
}

void ToolBoxItem::initWidget()
{
    selectedLabel = new QLabel(this);
    nameLabel = new QLabel(this);
    countLabel = new QLabel(this);
    mainLayout = new QHBoxLayout(this);

    selectedLabel->setObjectName("selectedLabel");
    nameLabel->setObjectName("nameLabel");
    countLabel->setObjectName("countLabel");
}


