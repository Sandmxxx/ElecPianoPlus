#include"MainWindow.h"
#include "screen.h"
#include<qdebug.h>
#include<QBitmap>
#include<qpainter.h>
Screen::Screen(QWidget *parent,MainWindow *p) : QWidget(parent)
{
    prt=p;//传入父窗口指针，以便调用数据
    // 设置五线谱位置
    // 从屏幕上（x，y）位置开始（即为最左上角的点），显示一个w*h的界面（宽w，高h）
    this->setGeometry(50, 50, 640, 300);

    QPalette pal(this->palette());
     //设置背景灰色
    pal.setColor(QPalette::Background, QColor(220,220,220));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    //圆角窗口
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter pt(&bmp);
    pt.setPen(Qt::NoPen);
    pt.setBrush(Qt::black);
    pt.drawRoundedRect(bmp.rect(),10,10);
    setMask(bmp);

}

void Screen::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //QPainter painter1(this);
    //painter.setBrush(Qt::white);
    QFont font;
    // 设置绘制的文字大小
    font.setPointSize(35);
    painter.setFont(font);
    // 绘制谱号
    painter.drawText(15,95,"𝄞");
    painter.drawText(15,250,"𝄢");

    font.setPointSize(8);
    painter.setFont(font);
    //显示五线谱
    for(int i=0;i<5;i++)
    {
        painter.drawLine(QPoint(0,35+20*i),QPoint(640,35+20*i));
        painter.drawLine(QPoint(0,185+20*i),QPoint(640,185+20*i));
    }
    if(prt->isActive[12]==1){//C3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(80,235),7,4);
    }
    if(prt->isActive[13]==1){//#C3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(80,235),7,4);
        painter.drawText(QPoint(62,240),"#");
    }
    if(prt->isActive[14]==1){//D3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(100,225),7,4);
    }
    if(prt->isActive[15]==1){//#D3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(100,225),7,4);
        painter.drawText(QPoint(82,230),"#");
    }
    if(prt->isActive[16]==1){//E3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(120,215),7,4);
    }
    if(prt->isActive[17]==1){//F3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(140,205),7,4);
    }
    if(prt->isActive[18]==1){//#F3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(140,205),7,4);
        painter.drawText(QPoint(122,210),"#");
    }
    if(prt->isActive[19]==1){//G3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(160,195),7,4);
    }
    if(prt->isActive[20]==1){//#G3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(160,195),7,4);
        painter.drawText(QPoint(142,200),"#");
    }
    if(prt->isActive[21]==1){//A3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(180,185),7,4);
    }
    if(prt->isActive[22]==1){//#A3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(180,185),7,4);
        painter.drawText(QPoint(162,190),"#");
    }
    if(prt->isActive[23]==1){//B3
        painter.setBrush(QColor(147, 181, 207));
        painter.drawEllipse(QPoint(200,175),7,4);
    }
    if(prt->isActive[24]==1){//C4
        painter.setBrush(QColor(0, 205, 0));
        // 原来代码
        painter.drawLine(205,135,235,135);
        painter.drawEllipse(QPoint(220,135),7,4);
//        // 往上移一格
//        painter.drawLine(205,115,235,115);
//        painter.drawEllipse(QPoint(220,115),7,4);
    }
    if(prt->isActive[25]==1){//#C4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawLine(205,135,235,135);
        painter.drawEllipse(QPoint(220,135),7,4);
        painter.drawText(QPoint(202,140),"#");//左移18，下移5
    }
    if(prt->isActive[26]==1){//D4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(240,125),7,4);
    }
    if(prt->isActive[27]==1){//#D4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(240,125),7,4);
        painter.drawText(QPoint(222,130),"#");
    }
    if(prt->isActive[28]==1){//E4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(260,115),7,4);
    }
    if(prt->isActive[29]==1){//F4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(280,105),7,4);
    }
    if(prt->isActive[30]==1){//#F4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(280,105),7,4);
        painter.drawText(QPoint(262,110),"#");
    }
    if(prt->isActive[31]==1){//G4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(300,95),7,4);
    }
    if(prt->isActive[32]==1){//#G4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(300,95),7,4);
        painter.drawText(QPoint(282,100),"#");
    }
    if(prt->isActive[33]==1){//A4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(320,85),7,4);
    }
    if(prt->isActive[34]==1){//#A4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(320,85),7,4);
        painter.drawText(QPoint(302,90),"#");
    }
    if(prt->isActive[35]==1){//B4
        painter.setBrush(QColor(0, 205, 0));
        painter.drawEllipse(QPoint(340,75),7,4);
    }
    if(prt->isActive[36]==1){//C5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawEllipse(QPoint(360,65),7,4);
    }
    if(prt->isActive[37]==1){//#C5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawEllipse(QPoint(360,65),7,4);
        painter.drawText(QPoint(342,70),"#");//左移18，下移5
    }
    if(prt->isActive[38]==1){//D5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawEllipse(QPoint(380,55),7,4);
    }
    if(prt->isActive[39]==1){//#D5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawEllipse(QPoint(380,55),7,4);
        painter.drawText(QPoint(362,60),"#");
    }
    if(prt->isActive[40]==1){//E5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawEllipse(QPoint(400,45),7,4);
    }
    if(prt->isActive[41]==1){//F5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawEllipse(QPoint(420,35),7,4);
    }
    if(prt->isActive[42]==1){//#F5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawEllipse(QPoint(420,35),7,4);
        painter.drawText(QPoint(402,40),"#");
    }
    if(prt->isActive[43]==1){//G5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawEllipse(QPoint(440,25),7,4);
    }
    if(prt->isActive[44]==1){//#G5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawEllipse(QPoint(440,25),7,4);
        painter.drawText(QPoint(422,30),"#");
    }
    if(prt->isActive[45]==1){//A5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawLine(445,15,473,15);
        painter.drawEllipse(QPoint(460,15),7,4);
    }
    if(prt->isActive[46]==1){//#A5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawLine(445,15,473,15);
        painter.drawEllipse(QPoint(460,15),7,4);
        painter.drawText(QPoint(442,20),"#");
    }
    if(prt->isActive[47]==1){//B5
        painter.setBrush(QColor(251, 185, 87));
        painter.drawLine(465,5,495,5);
        painter.drawLine(465,15,495,15);
        painter.drawEllipse(QPoint(480,5),7,4);
    }

}

// 刷新五线谱
void Screen::scrSlot(){
    update();
}
