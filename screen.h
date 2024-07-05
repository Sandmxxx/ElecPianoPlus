#ifndef SCREEN_H
#define SCREEN_H
#include <QWidget>
#include<qpainter.h>
class MainWindow;

class Screen : public QWidget
{
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = nullptr,MainWindow *p=nullptr);
protected:
    void paintEvent(QPaintEvent *event);
public slots:
    void scrSlot();
private:
    MainWindow *prt;

signals:

};

#endif // SCREEN_H
