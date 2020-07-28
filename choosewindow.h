#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QIcon>
#include "sumwindow.h"
#include "subwindow.h"
#include "divwindow.h"
#include "mulwindow.h"
class chooseWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QPoint StarPos;
    SumWindow *sumpractice=NULL;
    Subwindow *subpractice=NULL;
    DivWindow *divpractice=NULL;
    Mulwindow *mulpractice=NULL;
    int rank;
signals:
    void chooseBcak();
};

#endif // CHOOSEWINDOW_H
