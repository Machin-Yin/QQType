#ifndef TOOLBOXITEM_H
#define TOOLBOXITEM_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class ToolBoxItem : public QWidget
{
    Q_OBJECT
public:
    ToolBoxItem(QWidget *parent, QString filename);
private:
    void initWidget();

signals:

public slots:
private:
    QString fileName;
    QLabel *selectedLabel;
    QLabel *nameLabel;
    QLabel *countLabel;
    QHBoxLayout *mainLayout;
};

#endif // TOOLBOXITEM_H
