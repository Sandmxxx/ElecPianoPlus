#include "MainWindow.h"
#include "ui_MainWindow.h"
#include<qbitmap.h>
#include<qdebug.h>

//初始化键盘
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//把ui文件中的全设好了
    //显示五线谱
    scr = new Screen(this,this);
    scr->show();
    drumset=1;//默认鼓组1

    for(int i=0;i<48;i++)
    {
        isActive[i]=0;
    }
    //窗口样式
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(1500,900);

    //圆角窗口
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),15,15);
    setMask(bmp);

    // 鼠标穿透
    ui->label_A3->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_B3->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_C3->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_D3->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_E3->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_F3->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_G3->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    ui->label_A4->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_B4->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_C4->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_D4->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_E4->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_F4->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_G4->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    ui->label_A5->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_B5->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_C5->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_D5->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_E5->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_F5->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    ui->label_G5->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    flag = 0;
    playerFlag = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_recordBegin_clicked()
{
    // 如果正在录制
    if(flag==1)
    {
        QMessageBox::warning(this, "警告！", "正在录制！");
        return;
    }
    QString path=QCoreApplication::applicationDirPath()+"/"+"弹琴记录";  //保存记录文件的路径
    qDebug()<<path<<endl;
    QDir dir(path);
    qDebug()<<dir.exists()<<endl;
    if(!dir.exists()){
        dir.mkdir(path);//新建文件夹
    }

    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间

    QString str = dateTime .toString("yyyy-MM-dd hh,mm,ss");//格式化时间

    filePath = path + "/"+ str + "_record.txt";
    QFile file(filePath);

    // 提示
    QMessageBox::information(this, "提醒", "录制开始！");
    // 开始计时
    flag = 1;
    timer.start();

    ui->lable_infor->setText("正在录制");                      //设置显示文本
    ui->lable_infor->setAlignment(Qt::AlignCenter);           //设置字体居中显示
    QFont font = QFont("宋体", 15);
    ui->lable_infor->setFont(font);                           //设置字体
    ui->lable_infor->setStyleSheet("QLabel{color:rgb(234, 64, 46); background-color:blue}");   //设置字体颜色和背景色

}

void MainWindow::on_recordEnd_clicked()
{
    if(flag==0)
    {
        QMessageBox::warning(this, "警告！", "请先开始录制！");
        return;
    }
    // 记录操作
    if(flag)
    {
        // 写出全部内容
        QFile file(filePath);
        if(file.open(QIODevice::WriteOnly | QIODevice::Append| QIODevice::Text)) {
            QTextStream out(&file);
            int curtime = timer.elapsed();
            qDebug()<<"curt:"<<curtime<<endl;
            out<<"end"<<";"<<curtime<<"\n";
        }
        else qDebug()<<"文件打开失败";
        file.close();
    }
    //结束计时
    flag = 0;
    // 提示
    QMessageBox::information(this, "提醒", "录制结束！");
    // 删除标签
    ui->lable_infor->setText("");                      //设置显示文本
    ui->lable_infor->setAlignment(Qt::AlignCenter);           //设置字体居中显示
    QFont font = QFont("宋体", 15);
    ui->lable_infor->setFont(font);                           //设置字体
    ui->lable_infor->setStyleSheet("QLabel{color:white; background-color:white}");   //设置字体颜色和背景色
    // 结束计时
    timer.invalidate();
}

void MainWindow::recordPlayEnd()
{
    QMessageBox::information(this, "提醒", "播放已结束！");
    playerFlag = 0;
    ui->lable_infor->setText("");                      //设置显示文本
    ui->lable_infor->setAlignment(Qt::AlignCenter);           //设置字体居中显示
    QFont font = QFont("宋体", 15);
    ui->lable_infor->setFont(font);                           //设置字体
    ui->lable_infor->setStyleSheet("QLabel{color:white; background-color:white}");   //设置字体颜色和背景色

    // 开启交互
    this->setEnabled(true);

    return;
}

void MainWindow::on_recordPlay_clicked()
{
    if(playerFlag==1)
    {
        QMessageBox::warning(this, "警告！", "正在播放");
        return;
    }
    // 获取文件名
    QString playfileName = QFileDialog::getOpenFileName(this, "打开弹琴记录", "./debug/弹琴记录", "记录文件(*.txt)");
    if(playfileName=="") return;
    playerFlag = 1;

    ui->lable_infor->setText("正在播放");                      //设置显示文本
    ui->lable_infor->setAlignment(Qt::AlignCenter);           //设置字体居中显示
    QFont font = QFont("宋体", 15);
    ui->lable_infor->setFont(font);                           //设置字体
    ui->lable_infor->setStyleSheet("QLabel{color:rgb(172, 248, 129); background-color:blue}");   //设置字体颜色和背景色


    QFile file(playfileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString line;
        QTextStream in(&file);  //用文件构造流
        while(!in.atEnd())//字符串有内容
        {
            line=in.readLine();//循环读取下行
            qDebug() << line;
            if(line!="")
            {
                QStringList list = line.split(";");
                QString op = list[0];
                int curt = list[1].toInt();
//                connect(t, SIGNAL(timeout()), this, SLOT(on_btn_C3_pressed()));
//                t->start(tl);
                if(op=="q_press")
                   QTimer::singleShot(curt,this,SLOT(on_btn_C3_pressed()));
                else if(op=="q_release")
                   QTimer::singleShot(curt,this,SLOT(on_btn_C3_released()));
                else if(op=="1_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C3up_pressed()));
                else if(op=="1_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C3up_released()));
                else if(op=="w_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D3_pressed()));
                else if(op=="w_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D3_released()));
                else if(op=="2_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D3up_pressed()));
                else if(op=="2_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D3up_released()));
                else if(op=="e_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_E3_pressed()));
                else if(op=="e_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_E3_released()));
                else if(op=="r_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F3_pressed()));
                else if(op=="r_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F3_released()));
                else if(op=="3_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F3up_pressed()));
                else if(op=="3_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F3up_released()));
                else if(op=="t_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G3_pressed()));
                else if(op=="t_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G3_released()));
                else if(op=="4_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G3up_pressed()));
                else if(op=="4_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G3up_released()));
                else if(op=="y_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A3_pressed()));
                else if(op=="y_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A3_released()));
                else if(op=="5_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A3up_pressed()));
                else if(op=="5_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A3up_released()));
                else if(op=="u_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_B3_pressed()));
                else if(op=="u_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_B3_released()));
                else if(op=="i_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C4_pressed()));
                else if(op=="i_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C4_released()));
                else if(op=="6_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C4up_pressed()));
                else if(op=="6_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C4up_released()));
                else if(op=="o_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D4_pressed()));
                else if(op=="o_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D4_released()));
                else if(op=="7_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D4up_pressed()));
                else if(op=="7_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D4up_released()));
                else if(op=="p_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_E4_pressed()));
                else if(op=="p_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_E4_released()));
                else if(op=="a_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F4_pressed()));
                else if(op=="a_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F4_released()));
                else if(op=="8_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F4up_pressed()));
                else if(op=="8_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F4up_released()));
                else if(op=="s_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G4_pressed()));
                else if(op=="s_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G4_released()));
                else if(op=="9_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G4up_pressed()));
                else if(op=="9_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G4up_released()));
                else if(op=="d_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A4_pressed()));
                else if(op=="d_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A4_released()));
                else if(op=="0_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A4up_pressed()));
                else if(op=="0_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A4up_released()));
                else if(op=="f_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_B4_pressed()));
                else if(op=="f_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_B4_released()));
                else if(op=="g_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C5_pressed()));
                else if(op=="g_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C5_released()));
                else if(op=="-_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C5up_pressed()));
                else if(op=="-_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_C5up_released()));
                else if(op=="h_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D5_pressed()));
                else if(op=="h_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D5_released()));
                else if(op=="=_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D5up_pressed()));
                else if(op=="=_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_D5up_released()));
                else if(op=="j_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_E5_pressed()));
                else if(op=="j_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_E5_released()));
                else if(op=="k_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F5_pressed()));
                else if(op=="k_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F5_released()));
                else if(op=="[_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F5up_pressed()));
                else if(op=="[_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_F5up_released()));
                else if(op=="l_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G5_pressed()));
                else if(op=="l_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G5_released()));
                else if(op=="]_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G5up_pressed()));
                else if(op=="]_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_G5up_released()));
                else if(op=="z_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A5_pressed()));
                else if(op=="z_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A5_released()));
                else if(op=="\\_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A5up_pressed()));
                else if(op=="\\_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_A5up_released()));
                else if(op=="x_press")
                    QTimer::singleShot(curt,this,SLOT(on_btn_B5_pressed()));
                else if(op=="x_release")
                    QTimer::singleShot(curt,this,SLOT(on_btn_B5_released()));
                else if(op=="end")
                    QTimer::singleShot(curt,this,&MainWindow::recordPlayEnd);
            }
        }
    }
    // 屏蔽交互
    this->setEnabled(false);
}
