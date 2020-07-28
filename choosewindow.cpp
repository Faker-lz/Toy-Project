#include "choosewindow.h"

chooseWindow::chooseWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(600,400);
    QPushButton *pbt_back=new QPushButton;
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
    pbt_back->setFixedSize(41,41);
    pbt_back->setIcon(QIcon(":/material/back.ico"));
    pbt_back->setParent(this);
    pbt_back->move(559,359);
    pbt_back->setIconSize(QSize(40,40));
    pbt_back->setFlat(true);
    pbt_back->setToolTip("返回");
    pbt_back->setCursor(QCursor(Qt::PointingHandCursor));
    connect(pbt_back,&QPushButton::clicked,[=](){
        emit this->chooseBcak();
    });
    QFont font;
    font.setFamily("Arial Balk");
    font.setPointSize(12);
    font.setBold(4);
    QPushButton *jiafa=new QPushButton;
    jiafa->setParent(this);
    jiafa->setFixedSize(QSize(150,40));
    jiafa->setStyleSheet("color: rgba(255,0,102);background:transparent;border:4px solid rgba(1,136,209);");
    jiafa->setFlat(true);
    jiafa->move(225,180);
    jiafa->setText("加法测试");
    jiafa->setFont(font);
    jiafa->setCursor(QCursor(Qt::PointingHandCursor));
    QPushButton *jianfa=new QPushButton;
    jianfa->setParent(this);
    jianfa->setFixedSize(QSize(150,40));
    jianfa->setStyleSheet("color: rgba(255,0,102);background:transparent;border:4px solid rgba(1,136,209);");
    jianfa->setFlat(true);
    jianfa->move(225,235);
    jianfa->setText("减法测试");
    jianfa->setFont(font);
    jianfa->setCursor(QCursor(Qt::PointingHandCursor));
    QPushButton *chengfa=new QPushButton;
    chengfa->setParent(this);
    chengfa->setFixedSize(QSize(150,40));
    chengfa->setStyleSheet("color: rgba(255,0,102);background:transparent;border:4px solid rgba(1,136,209);");
    chengfa->setFlat(true);
    chengfa->move(225,290);
    chengfa->setText("乘法测试");
    chengfa->setFont(font);
    chengfa->setCursor(QCursor(Qt::PointingHandCursor));
    QPushButton *chufa=new QPushButton;
    chufa->setParent(this);
    chufa->setFixedSize(QSize(150,40));
    chufa->setStyleSheet("color: rgba(255,0,102);background:transparent;border:4px solid rgba(1,136,209);");
    chufa->setFlat(true);
    chufa->move(225,345);
    chufa->setText("除法测试");
    chufa->setFont(font);
    chufa->setCursor(QCursor(Qt::PointingHandCursor));
    connect(jiafa,&QPushButton::clicked,[=](){
        sumpractice=new SumWindow;
        this->hide();
        sumpractice->show();
        connect(sumpractice,&SumWindow::back,[=](){
            this->show();
            sumpractice->hide();
        });
    });
    connect(jianfa,&QPushButton::clicked,[=](){
        subpractice=new Subwindow;
        this->hide();
        subpractice->show();
        connect(subpractice,&Subwindow::back,[=](){
            this->show();
            subpractice->hide();
        });
    });
    connect(chengfa,&QPushButton::clicked,[=](){
        mulpractice=new Mulwindow;
        this->hide();
        mulpractice->show();
        connect(mulpractice,&Mulwindow::back,[=](){
            this->show();
            mulpractice->hide();
        });
    });
    connect(chufa,&QPushButton::clicked,[=](){
        divpractice=new DivWindow;
        this->hide();
        divpractice->show();
        connect(divpractice,&DivWindow::back,[=](){
            this->show();
            divpractice->hide();
        });
    });
}
void chooseWindow::paintEvent(QPaintEvent *)
{
    QPixmap back_icon;
    back_icon.load(":/material/choosesence.jpg");
    QPixmap fitpixmap=back_icon.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPainter painter(this);
    QPixmap pix=QPixmap(fitpixmap);
    painter.drawPixmap(0,0,pix);
}
void chooseWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint EndPos;
    if(event->buttons()==Qt::LeftButton)
    {
        EndPos=event->globalPos()-StarPos;
        this->move(EndPos);
    }
}
void chooseWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton)
    {
       StarPos=event->globalPos()-this->frameGeometry().topLeft();
    }
}

