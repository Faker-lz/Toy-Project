#ifndef CHOOSELAILOG_H
#define CHOOSELAILOG_H

#include <QWidget>

class chooseLailog:public QWidget
{
    Q_OBJECT;
public:
    chooseLailog(QWidget *parent);
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    QPoint StarPos;
};

#endif // CHOOSELAILOG_H
