#ifndef DIVWINDOW_H
#define DIVWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QKeyEvent>
#include <QtGlobal>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include <QString>
class DivWindow:public QMainWindow
{
    Q_OBJECT
public:
    DivWindow(QWidget *parent=nullptr);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *target,QEvent *event);
    void getRandomNumber();
    void levelup();
    int flag;
    int rank;
    int number1;
    int number2;
    double answer;
    QPoint StarPos;
    QTextEdit *daan;
    QLabel *timu;
    QLabel *tishi;
signals:
    void back();
};

#endif // DIVWINDOW_H
