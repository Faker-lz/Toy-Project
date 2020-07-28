#ifndef LIANXIWINDOW_H
#define LIANXIWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QKeyEvent>
#include <QtGlobal>
#include <QTime>
class lianxiwindow: public QMainWindow
{
    Q_OBJECT
public:
    lianxiwindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *target,QEvent *event);
    int getRandomNumber();
    void levelup();
    int flag;
    int rank;
    QPoint StarPos;
    QTextEdit *daan;
    QLabel *timu;
    QPushButton *leixing;
signals:
    void lianxiback();
};

#endif // LIANXIWINDOW_H
