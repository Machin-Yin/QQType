#include "machintype.h"

MachinType::MachinType(QWidget *parent)
    : QMainWindow(parent)
{
    resize(QSize(650,470));

    rightColor = "#CCCCCC";
    wrongColor = "#FF4040";
    QColor backGroundColor = "#FFFFFF";
    defColor = backGroundColor;

    splitterMain = new QSplitter(Qt::Vertical,0);

    srcEdit = new QTextEdit(splitterMain);
    srcEdit->setFontPointSize(18);
    srcEdit->setReadOnly(true);
    srcEdit->setText("中华人民共和国");
    srcStr = srcEdit->toPlainText();
    srcLength = srcStr.length();

    destEdit = new QTextEdit(splitterMain);
    destEdit->setFontPointSize(18);

    splitterMain->addWidget(srcEdit);
    splitterMain->addWidget(destEdit);
    splitterMain->setOpaqueResize(true);
    splitterMain->setStyleSheet("QSplitter::handle { background-color: orange; height: 20 }"); //设置分界线的样式
    splitterMain->setStretchFactor(0,1);

    connect(destEdit,SIGNAL(textChanged()),this,SLOT(onType()));

    setCentralWidget(splitterMain);
    destEdit->setFocus();
}

MachinType::~MachinType()
{

}

void MachinType::onType()
{
    destEdit->setFontPointSize(18);
    qDebug() << __FUNCTION__;
    QString destStr = destEdit->toPlainText();
    int destLength = destStr.length();
    for(int i = 0; i < destLength; i++)
    {
        if(i >= srcLength)
        {
            qDebug() << i;
            destStr.chop(destStr.length() - srcLength); // Cut off at 300 characters
            destEdit->setPlainText(destStr); // Reset text

            // This below code just resets the cursor back to the end position
            // If you don't use this, it moves back to the beginning.
            // This is helpful for really long text edits where you might
            // lose your place.
            QTextCursor cursor = destEdit->textCursor();
            cursor.setPosition(destEdit->document()->characterCount() - 1);
            destEdit->setTextCursor(cursor);
            break;
        }
        if(srcStr.at(i) != destStr.at(i))
        {
            qDebug() << i + 1;
            setCharColor(i,false);
        }
        else
        {
            setCharColor(i,true);
        }
    }
}

void MachinType::setCharColor(unsigned int pos, bool equal)
{
    qDebug() << "pos == " << pos;
    if(pos < 0)return ;
    QTextCursor cursor = srcEdit->textCursor();
    cursor.movePosition( QTextCursor::StartOfLine );//行首
    cursor.movePosition( QTextCursor::Right, QTextCursor::MoveAnchor, pos);//向右移动到Pos
    cursor.movePosition( QTextCursor::NextCharacter, QTextCursor::KeepAnchor );
    srcEdit->setTextCursor( cursor ); // added
    QTextCharFormat defcharfmt = srcEdit->currentCharFormat();
    QTextCharFormat newcharfmt = defcharfmt;
    if(equal)
    {
        newcharfmt.setBackground(rightColor);
    }
    else
    {
        newcharfmt.setBackground(wrongColor);
    }
    srcEdit->setCurrentCharFormat( newcharfmt );
    srcEdit->setTextCursor( cursor ); // added

    cursor.movePosition( QTextCursor::PreviousCharacter );//加上这句是为了去除光标selected
    srcEdit->setTextCursor( cursor ); // added
}

void MachinType::setCharColorBack(unsigned int pos)
{
    qDebug() << "pos == " << pos;
    if(pos < 0)return ;
    QTextCursor cursor = srcEdit->textCursor();
    cursor.movePosition( QTextCursor::StartOfLine );//行首
    cursor.movePosition( QTextCursor::Right, QTextCursor::MoveAnchor, pos);//向右移动到Pos
    cursor.movePosition( QTextCursor::NextCharacter, QTextCursor::KeepAnchor );
    srcEdit->setTextCursor(cursor); // added
    QTextCharFormat defcharfmt = srcEdit->currentCharFormat();
    QTextCharFormat newcharfmt = defcharfmt;
    newcharfmt.setBackground(defColor);
    srcEdit->setCurrentCharFormat( newcharfmt );
    srcEdit->setTextCursor( cursor ); // added

    cursor.movePosition( QTextCursor::PreviousCharacter );//加上这句是为了去除光标selected
    srcEdit->setTextCursor( cursor ); // added
}

bool MachinType::event(QEvent *event)
{
    if (event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Backspace)
        {
            qDebug() << __FUNCTION__ << "Qt::Key_Backspace";
            QString desStr = destEdit->toPlainText();
            unsigned int desLength = desStr.length();
            qDebug() << "desLength == " << desLength;
            setCharColorBack(desLength);
            return true;
        }
    }
    return QWidget::event(event);
}


