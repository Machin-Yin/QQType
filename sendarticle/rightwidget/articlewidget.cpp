#include "articlewidget.h"

ArticleWidget::ArticleWidget(QWidget *parent) : QWidget(parent)
{
    nameLabel2 = new QLabel(tr("文章名称"));
    nameLineEdit2 = new QLineEdit();
    cutLabel2 = new QLabel(tr("文章截取"));
    cutButton2 = new QPushButton(tr("截取"));
    keepButton2 = new QPushButton(tr("保持"));
    beginEdit2 = new QLineEdit();
    cutToLabel2 = new QLabel(tr("至"));
    endEdit2 = new QLineEdit();
    cutIntroLabel2 = new QLabel();
    wordNumLabel2 = new QLabel(tr("每段字数"));
    fixedButton2 = new QPushButton(tr("全文"));
    randomButton2 = new QPushButton(tr("分段"));
    paraWorldEdit = new QLineEdit();
    beginParaLabel2 = new QLabel(tr("起始段号"));
    beginParaEdit2 = new QLineEdit();

    main2Layout = new QVBoxLayout(this);
    hbox2Layout1 = new QHBoxLayout;
    hbox2Layout2 = new QHBoxLayout;
    hbox2Layout3 = new QHBoxLayout;
    hbox2Layout4 = new QHBoxLayout;

    hbox2Layout1->addWidget(nameLabel2);
    hbox2Layout1->addWidget(nameLineEdit2);
    hbox2Layout2->addWidget(cutLabel2);
    hbox2Layout2->addWidget(cutButton2);
    hbox2Layout2->addWidget(keepButton2);
    hbox2Layout2->addWidget(beginEdit2);
    hbox2Layout2->addWidget(cutToLabel2);
    hbox2Layout2->addWidget(endEdit2);
    hbox2Layout3->addWidget(wordNumLabel2);
    hbox2Layout3->addWidget(fixedButton2);
    hbox2Layout3->addWidget(randomButton2);
    hbox2Layout3->addWidget(paraWorldEdit);
    hbox2Layout4->addWidget(beginParaLabel2);
    hbox2Layout4->addWidget(beginParaEdit2);

    main2Layout->addLayout(hbox2Layout1);
    main2Layout->addLayout(hbox2Layout2);
    main2Layout->addLayout(hbox2Layout3);
    main2Layout->addLayout(hbox2Layout4);
}
