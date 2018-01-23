#ifndef SENDARTICLE_H
#define SENDARTICLE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QSplitter>

#include "leftwidget/customtoolbox.h"
#include "rightwidget/rightwidget.h"

class SendArticle : public QWidget
{
    Q_OBJECT
public:
    explicit SendArticle(QWidget *parent = nullptr);

signals:

public slots:

private:
    QSplitter *splitterMain;
    CustomToolBox *customToolBox;
    RightWidget *rightWidget;
    QVBoxLayout *mainLayout;

};

#endif // SENDARTICLE_H
