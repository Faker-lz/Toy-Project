#include "subwindow.h"

Subwindow::Subwindow(QWidget *parent) : QMainWindow(parent)
{
    rank=1,flag=1;
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
        emit this->back();
    });
    getRandomNumber();
    QString labeltext;
    labeltext="题目："+QString::number(number2,10)+"-"+QString::number(number1,10)+"=";
    timu=new QLabel(labeltext,this);
    timu->setFixedSize(200,50);
    timu->setStyleSheet("font-size:25px;color: black;background:transparent;border:4px solid white;aliqnment: AliqnHCenter");
    timu->move(200,30);
    timu->installEventFilter(this);
    QString information;
    information="难度等级:"+QString::number(rank,10)+" 累计回答正确题目个数:"+QString::number(flag-1,10);
    tishi=new QLabel(information,this);
    tishi->setFixedSize(350,40);
    tishi->move(125,85);
    tishi->installEventFilter(this);
    tishi->setStyleSheet("font-size:20px;color: black;background:transparent;border:4px solid white;aliqnment: AliqnHCenter");
    daan=new QTextEdit("请输入答案,按回车确定",this);
    daan->setStyleSheet("background:rgb(255,0,0,0);border:4px solid white;font-size:17px");
    daan->setGeometry(200,320,200,40);
    daan->installEventFilter(this);
}
void Subwindow::paintEvent(QPaintEvent *)
{
    QPixmap back_icon;
    back_icon.load(":/material/lianxi.jpg");
    QPixmap fitpixmap=back_icon.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPainter painter(this);
    QPixmap pix=QPixmap(fitpixmap);
    painter.drawPixmap(0,0,pix);
}
void Subwindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint EndPos;
    if(event->buttons()==Qt::LeftButton)
    {
        EndPos=event->globalPos()-StarPos;
        this->move(EndPos);
    }
}

void Subwindow::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton)
    {
       StarPos=event->globalPos()-this->frameGeometry().topLeft();
    }
}

bool Subwindow::eventFilter(QObject *target,QEvent *event)
{
    if(target == this->daan)
    {
        if(event->type()==QEvent::KeyPress)
        {
            QKeyEvent *k=static_cast<QKeyEvent *>(event);
            if(k->key()==Qt::Key_Return||k->key()==Qt::Key_Enter)
            {
                QString tempdaan=daan->toPlainText();
                daan->clear();
                answer=tempdaan.toUInt();
                if(answer==number2-number1)
                {
                    flag++;
                    QMessageBox::information(this,"答案反馈","回答正确");
                    getRandomNumber();
                    QString labeltext;
                    labeltext="题目:"+QString::number(number2,10)+"-"+QString::number(number1,10)+"=";
                    timu->setText(labeltext);
                }
                else
                {
                    QString labeltext;
                    labeltext="回答错误,正确答案为"+QString::number(number2-number1,10);
                    QMessageBox::information(this,"答案反馈",labeltext);
                    getRandomNumber();
                    labeltext="题目:"+QString::number(number2,10)+"-"+QString::number(number1,10)+"=";
                    timu->setText(labeltext);
                }
                if(flag==11&&rank<3)
                {
                    QMessageBox::information(this,"提示","难度升级");
                    rank++;
                    flag=1;
                }
                QString information;
                information="难度等级:"+QString::number(rank,10)+" 累计回答正确题目个数:"+QString::number(flag-1,10);
                tishi->setText(information);
            }
        }
    }

    return QWidget::eventFilter(target,event);
}

void Subwindow::getRandomNumber()
{
    QTime time=QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    if(rank==1)
    number1=qrand()%9;
    else if(rank==2)
    number1=qrand()%99;
    else
    number1=qrand()%999;
    qsrand(time.msec()+time.second()*5000);
    if(rank==1)
    number2=qrand()%9+number1;
    else if(rank==2)
        number2=qrand()%99+number1;
    else
        number2=qrand()%999+number1;
}
void Subwindow::levelup()
{
    rank++;
}
