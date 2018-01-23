#include "wordwidget.h"

WordWidget::WordWidget(QWidget *parent) : QWidget(parent)
{
    configChooseLabel = new QLabel(tr("配置选择"));
    confComb = new QComboBox();
    nameLabel = new QLabel(tr("文章名称"));
    nameLineEdit = new QLineEdit();
    cutLabel = new QLabel(tr("文章截取"));
    cutButton = new QPushButton(tr("截取"));
    keepButton = new QPushButton(tr("保持"));
    beginEdit = new QLineEdit();
    cutToLabel = new QLabel(tr("至"));
    endEdit = new QLineEdit();
    cutIntroLabel = new QLabel();
    typeWayLabel = new QLabel(tr("跟打方式"));
    noOrderButton = new QPushButton(tr("乱序"));
    orderButton = new QPushButton(tr("顺序"));
    wordNumLabel = new QLabel(tr("每段字数"));
    fixedButton = new QPushButton(tr("固定"));
    randomButton = new QPushButton(tr("随机"));
    randomBeginEdit = new QLineEdit(this);
    numToLabel = new QLabel(tr("至"));
    randomEndEdit = new QLineEdit(this);
    beginParaLabel = new QLabel(tr("起始段号"));
    beginParaEdit = new QLineEdit();

    main1Layout = new QVBoxLayout(this);
    hbox1Layout1 = new QHBoxLayout;
    hbox1Layout2 = new QHBoxLayout;
    hbox1Layout3 = new QHBoxLayout;
    hbox1Layout4 = new QHBoxLayout;
    hbox1Layout5 = new QHBoxLayout;
    hbox1Layout6 = new QHBoxLayout;
    groupLayout = new QVBoxLayout;
    groupBox = new QGroupBox;

    hbox1Layout1->addWidget(configChooseLabel);
    hbox1Layout1->addWidget(confComb);
    hbox1Layout2->addWidget(nameLabel);
    hbox1Layout2->addWidget(nameLineEdit);
    hbox1Layout3->addWidget(cutLabel);
    hbox1Layout3->addWidget(cutButton);
    hbox1Layout3->addWidget(keepButton);
    hbox1Layout3->addWidget(beginEdit);
    hbox1Layout3->addWidget(cutToLabel);
    hbox1Layout3->addWidget(endEdit);
    hbox1Layout4->addWidget(typeWayLabel);
    hbox1Layout4->addWidget(noOrderButton);
    hbox1Layout4->addWidget(orderButton);
    hbox1Layout5->addWidget(wordNumLabel);
    hbox1Layout5->addWidget(fixedButton);
    hbox1Layout5->addWidget(randomButton);
    hbox1Layout5->addWidget(randomBeginEdit);
    hbox1Layout5->addWidget(numToLabel);
    hbox1Layout5->addWidget(randomEndEdit);
    hbox1Layout6->addWidget(beginParaLabel);
    hbox1Layout6->addWidget(beginParaEdit);
    groupLayout->addLayout(hbox1Layout4);
    groupLayout->addLayout(hbox1Layout5);
    groupBox->setLayout(groupLayout);

    main1Layout->addLayout(hbox1Layout1);
    main1Layout->addLayout(hbox1Layout2);
    main1Layout->addLayout(hbox1Layout3);
    main1Layout->addWidget(cutIntroLabel);
    main1Layout->addWidget(groupBox);
    main1Layout->addLayout(hbox1Layout6);
}
