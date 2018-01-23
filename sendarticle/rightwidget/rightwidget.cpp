#include "rightwidget.h"

RightWidget::RightWidget(QWidget *parent)
    : QWidget(parent)
{
    sendConfigLabel = new QLabel("发文配置");
    customStack = new CustomStack;
    sendButton = new QPushButton("开始发文");
    mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(sendConfigLabel);
    mainLayout->addWidget(customStack);
    mainLayout->addWidget(sendButton);
}

RightWidget::~RightWidget()
{

}
