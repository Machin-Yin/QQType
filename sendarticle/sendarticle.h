#ifndef SENDARTICLE_H
#define SENDARTICLE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QSplitter>

#include "customtoolbox.h"

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
    QVBoxLayout *mainLayout;

};

#endif // SENDARTICLE_H
