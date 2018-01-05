#include "machintype.h"

MachinType::MachinType(QWidget *parent)
    : QWidget(parent)
{
    init();
    createSplitter();

    mainLayout = new QVBoxLayout;
    mainLayout->setMargin(4);
    headTool = new HeadTool;

    mainLayout->addWidget(headTool);
    mainLayout->setSpacing(1);
    mainLayout->addWidget(splitterMain);

    setLayout(mainLayout);
    destEdit->setFocus();
}

MachinType::~MachinType()
{

}

void MachinType::init()
{
    resize(QSize(550,350));
//    setStyleSheet("background-color: #454545;");
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, "#454545");
    setAutoFillBackground(true);
    setPalette(pal);

    rightColor = "#CCCCCC";
    wrongColor = "#FF4040";
    QColor backGroundColor = "#FFFFFF";
    defColor = backGroundColor;
}

void MachinType::createSplitter()
{
    splitterMain = new QSplitter(Qt::Vertical,0);

    srcEdit = new QTextEdit;
    srcEdit->setFontPointSize(18);
    srcEdit->setReadOnly(true);
    srcEdit->setText("中华人民共和国");
    srcEdit->setStyleSheet("background-color: white;");
    srcStr = srcEdit->toPlainText();
    srcLength = srcStr.length();

    destEdit = new QTextEdit;
    destEdit->setFontPointSize(16);
    destEdit->setStyleSheet("background-color: white;");

    splitterMain->addWidget(srcEdit);
    splitterMain->addWidget(destEdit);
    splitterMain->setOpaqueResize(true);
    splitterMain->setStyleSheet("QSplitter::handle { background-color: #454545; height: 18 }"); //设置分界线的样式
    splitterMain->setStretchFactor(0,1);

    connect(destEdit,SIGNAL(textChanged()),this,SLOT(onType()));
}

void MachinType::onType()
{
    qDebug() << __FUNCTION__;
    QString destStr = destEdit->toPlainText();
    int destLength = destStr.length();
    if(destLength == 0) destEdit->setFontPointSize(18);

    for(int i = 0; i < destLength; i++)
    {
        if(i >= srcLength)
        {
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
    srcEdit->setCurrentCharFormat(newcharfmt);
    srcEdit->setTextCursor(cursor); // added

    cursor.movePosition( QTextCursor::PreviousCharacter );//加上这句是为了去除光标selected
    srcEdit->setTextCursor(cursor); // added
}

void MachinType::setCharColorBack(unsigned int pos)
{
    QTextCursor cursor = srcEdit->textCursor();
    cursor.movePosition( QTextCursor::StartOfLine );//行首
    cursor.movePosition( QTextCursor::Right, QTextCursor::MoveAnchor, pos);//向右移动到Pos
    cursor.movePosition( QTextCursor::NextCharacter, QTextCursor::KeepAnchor );
    srcEdit->setTextCursor(cursor); // added
    QTextCharFormat defcharfmt = srcEdit->currentCharFormat();
    QTextCharFormat newcharfmt = defcharfmt;
    newcharfmt.setBackground(defColor);
    srcEdit->setCurrentCharFormat(newcharfmt);
    srcEdit->setTextCursor(cursor); // added

    cursor.movePosition( QTextCursor::PreviousCharacter );//加上这句是为了去除光标selected
    srcEdit->setTextCursor(cursor); // added
}

bool MachinType::event(QEvent *event)
{
    if (event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Backspace)
        {
            QString desStr = destEdit->toPlainText();
            unsigned int desLength = desStr.length();
            setCharColorBack(desLength);
            return true;
        }
        else if (keyEvent->key() == Qt::Key_F5)
        {
        }
    }
    return QWidget::event(event);
}

