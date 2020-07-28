#ifndef SUMWINDOW_H
#define SUMWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QKeyEvent>
#include <QtGlobal>
#include <QTime>
#include <QStringList>
#include <QMessageBox>
class SumWindow: public QMainWindow
{
    Q_OBJECT
public:
    SumWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool eventFilter(QObject *target,QEvent *event);
    void getRandomNumber();
    void levelup();
    int number1;
    int number2;
    int flag;
    int rank;
    int answer;
    QPoint StarPos;
    QTextEdit *daan;
    QLabel *timu;
    QLabel *tishi;
signals:
    void back();
};

#endif // SUMWINDOW_H
