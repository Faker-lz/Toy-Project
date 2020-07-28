#include "lianxiwindow.h"
#include <QString>
#include <QDebug>
lianxiwindow::lianxiwindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(600,400);
    QPushButton *pbt_close=new QPushButton;
    pbt_close->setFixedSize(41,41);
    pbt_close->setIcon(QIcon(":/material/close.png"));
    pbt_close->setParent(this);
    pbt_close->move(559,0);
    pbt_close->setIconSize(QSize(40,40));
    pbt_close->setFlat(true);
    pbt_close->setToolTip("关闭");
    pbt_close->setCursor(QCursor(Qt::PointingHandCursor));
    connect(pbt_close,&QPushButton::clicked,this,&QWidget::close);
    QPushButton *pbt_back=new QPushButton;
    pbt_back->setFixedSize(41,41);
    pbt_back->setIcon(QIcon(":/material/back.ico"));
    pbt_back->setParent(this);
    pbt_back->move(559,359);
    pbt_back->setIconSize(QSize(40,40));
    pbt_back->setFlat(true);
    pbt_back->setToolTip("返回");
    pbt_back->setCursor(QCursor(Qt::PointingHandCursor));
    connect(pbt_back,&QPushButton::clicked,[=](){
        emit this->lianxiback();
    });
    timu=new QLabel("题目",this);
    timu->setFixedSize(200,50);
    timu->setStyleSheet("color: black;background:transparent;border:4px solid white;aliqnment: AliqnHCenter");
    timu->move(200,30);
    timu->installEventFilter(this);
    daan=new QTextEdit("请输入答案,按回车键结束",this);
    daan->setStyleSheet("background:rgb(255,0,0,0);border:4px solid white");
    daan->setGeometry(200,320,200,50);
    daan->installEventFilter(this);
}
void lianxiwindow::paintEvent(QPaintEvent *)
{
    QPixmap back_icon;
    back_icon.load(":/material/lianxi.jpg");
    QPixmap fitpixmap=back_icon.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPainter painter(this);
    QPixmap pix=QPixmap(fitpixmap);
    painter.drawPixmap(0,0,pix);
}
void lianxiwindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint EndPos;
    if(event->buttons()==Qt::LeftButton)
    {
        EndPos=event->globalPos()-StarPos;
        this->move(EndPos);
    }
}

void lianxiwindow::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton)
    {
       StarPos=event->globalPos()-this->frameGeometry().topLeft();
    }
}

bool lianxiwindow::eventFilter(QObject *target,QEvent *event)
{
    if(target == this->daan)
    {
        if(event->type()==QEvent::KeyPress)
        {
            QKeyEvent *k=static_cast<QKeyEvent *>(event);
            if(k->key()==Qt::Key_Return||k->key()==Qt::Key_Enter)
            {
                QString tempdaan=daan->toPlainText();
                qDebug()<<tempdaan;
                timu->setText(tempdaan);
            }
        }
    }
    return QWidget::eventFilter(target,event);
}

int lianxiwindow::getRandomNumber()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int random=qrand()%10;
    return random;
}
void lianxiwindow::levelup()
{
    rank++;
}
