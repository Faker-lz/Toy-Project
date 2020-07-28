#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <QPushButton>
#include <QPropertyAnimation>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label_1->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_1->setToolTip("本软件由王凌志、张凯文编写，感谢使用！");
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->pbt_close->setToolTip("关闭");
    ui->pbt_close->setCursor(QCursor(Qt::PointingHandCursor));
    ui->pbt_close->setStyleSheet("QPushButton:hover{border-image:url(:/pic/logo.png);color:red}");
    choose=new chooseWindow;
    ui->pbt_start->setCursor(QCursor(Qt::PointingHandCursor));
    connect(ui->pbt_close,&QPushButton::clicked,this,&QWidget::close);
    connect(ui->pbt_start,&QPushButton::clicked,[=](){
    this->hide();
    choose->show();
    connect(choose,&chooseWindow::chooseBcak,[=](){
        this->show();
        choose->hide();
    });
    });
}
void Dialog::paintEvent(QPaintEvent *)
{
    QPixmap back_icon;
    back_icon.load(":/material/black-click-pen-on-white-paper-167682.jpg");
    QPixmap fitpixmap=back_icon.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPainter painter(this);
    QPixmap pix=QPixmap(fitpixmap);
    painter.drawPixmap(0,0,pix);
}
void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    QPoint EndPos;
    if(event->buttons()==Qt::LeftButton)
    {
        EndPos=event->globalPos()-StarPos;
        this->move(EndPos);
    }
}
void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton)
    {
       StarPos=event->globalPos()-this->frameGeometry().topLeft();
    }
}
Dialog::~Dialog()
{
    delete ui;
}

