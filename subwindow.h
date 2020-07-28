#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QKeyEvent>
#include <QtGlobal>
#include <QTime>
#include <QMessageBox>
#include <QDebug>
class Subwindow:public QMainWindow
{
    Q_OBJECT
public:
    Subwindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *target,QEvent *event);
    void getRandomNumber();
    void levelup();
    int number1;
    int number2;
    int answer;
    int flag;
    int rank;
    QPoint StarPos;
    QTextEdit *daan;
    QLabel *timu;
    QLabel *tishi;
signals:
    void back();
};

#endif // SUBWINDOW_H
