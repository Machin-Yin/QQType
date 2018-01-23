#ifndef ARTICLEWIDGET_H
#define ARTICLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ArticleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ArticleWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *nameLabel2;
    QLineEdit *nameLineEdit2;
    QLabel *cutLabel2;
    QPushButton *cutButton2;
    QPushButton *keepButton2;
    QLineEdit *beginEdit2;
    QLabel *cutToLabel2;
    QLineEdit *endEdit2;
    QLabel *cutIntroLabel2;
    QLabel *wordNumLabel2;
    QPushButton *fixedButton2;
    QPushButton *randomButton2;
    QLineEdit *paraWorldEdit;
    QLabel *beginParaLabel2;
    QLineEdit *beginParaEdit2;

    QVBoxLayout *main2Layout;
    QHBoxLayout *hbox2Layout1;
    QHBoxLayout *hbox2Layout2;
    QHBoxLayout *hbox2Layout3;
    QHBoxLayout *hbox2Layout4;
};

#endif // ARTICLEWIDGET_H
