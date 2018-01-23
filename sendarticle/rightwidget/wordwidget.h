#ifndef WORDWIDGET_H
#define WORDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

class WordWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WordWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *configChooseLabel;
    QComboBox *confComb;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *cutLabel;
    QPushButton *cutButton;
    QPushButton *keepButton;
    QLineEdit *beginEdit;
    QLabel *cutToLabel;
    QLineEdit *endEdit;
    QLabel *cutIntroLabel;
    QLabel *typeWayLabel;
    QPushButton *noOrderButton;
    QPushButton *orderButton;
    QLabel *wordNumLabel;
    QPushButton *fixedButton;
    QPushButton *randomButton;
    QLineEdit *randomBeginEdit;
    QLabel *numToLabel;
    QLineEdit *randomEndEdit;
    QLabel *beginParaLabel;
    QLineEdit *beginParaEdit;

    QVBoxLayout *main1Layout;
    QHBoxLayout *hbox1Layout1;
    QHBoxLayout *hbox1Layout2;
    QHBoxLayout *hbox1Layout3;
    QHBoxLayout *hbox1Layout4;
    QHBoxLayout *hbox1Layout5;
    QHBoxLayout *hbox1Layout6;
    QVBoxLayout *groupLayout;
    QGroupBox *groupBox;
};

#endif // WORDWIDGET_H
