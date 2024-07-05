#include "MainWindow.h"
#include "ui_MainWindow.h"

// 鼓1
void MainWindow::on_drum1_pressed()
{
    switch(drumset){
    case 1:{
         QSound::play(":/media/sound/drum1.wav");
         break;
    }
    case 2:{
        QSound::play(":/media/sound/drum1_2.wav");
        break;
    }
    }
    ui->drum1->setStyleSheet("border-image: url(:/pic/pic/drun1_2.png);border-radius: 10px;");//文件名drum拼错了...
}

// 鼓1按键释放
void MainWindow::on_drum1_released()
{
    ui->drum1->setStyleSheet("border-image: url(:/pic/pic/drum1.png);border-radius: 10px;");
}


void MainWindow::on_drun4_released()
{
    ui->drun4->setStyleSheet("border-image: url(:/pic/pic/drum4.png);border-radius: 10px;");
}


void MainWindow::on_drun4_pressed()
{
    switch(drumset){
    case 1:{
         QSound::play(":/media/sound/drum4.wav");
         break;
    }
    case 2:{
        QSound::play(":/media/sound/drum4_2.wav");
        break;
    }
    }

    ui->drun4->setStyleSheet("border-image: url(:/pic/pic/drum4_2.png);border-radius: 10px;");
}


void MainWindow::on_drum2_pressed()
{
    switch(drumset){
    case 1:{
         QSound::play(":/media/sound/drum2.wav");
         break;
    }
    case 2:{
        QSound::play(":/media/sound/drum2_2.wav");
        break;
    }
    }
    ui->drum2->setStyleSheet("border-image: url(:/pic/pic/drum2_2.png);border-radius: 10px;");

}


void MainWindow::on_drum2_released()
{
    ui->drum2->setStyleSheet("border-image: url(:/pic/pic/drum2.png);border-radius: 10px;");
}

void MainWindow::on_drum3_pressed()
{
    switch(drumset){
    case 1:{
         QSound::play(":/media/sound/drum3.wav");
         break;
    }
    case 2:{
        QSound::play(":/media/sound/drum3_2.wav");
        break;
    }
    }
    ui->drum3->setStyleSheet("border-image: url(:/pic/pic/drum3_2.jpg);border-radius: 10px;");
}


void MainWindow::on_drum5_pressed()
{
    switch(drumset){
    case 1:{
         QSound::play(":/media/sound/drum5.wav");
         break;
    }
    case 2:{
        QSound::play(":/media/sound/drum5_2.wav");
        break;
    }
    }
    ui->drum5->setStyleSheet("border-image: url(:/pic/pic/drum5_2.jpg);border-radius: 10px;");
}


void MainWindow::on_drum6_pressed()
{
    switch(drumset){
    case 1:{
         QSound::play(":/media/sound/drum6.wav");
         break;
    }
    case 2:{
        QSound::play(":/media/sound/drum6_2.wav");
        break;
    }
    }
    ui->drum6->setStyleSheet("border-image: url(:/pic/pic/drum6_2.jpg);border-radius: 10px;");
}


void MainWindow::on_drum3_released()
{
    ui->drum3->setStyleSheet("border-image: url(:/pic/pic/drum3_1.png);border-radius: 10px;");
}


void MainWindow::on_drum5_released()
{
    ui->drum5->setStyleSheet("border-image: url(:/pic/pic/drum5_1.jpg);border-radius: 10px;");
}


void MainWindow::on_drum6_released()
{
    ui->drum6->setStyleSheet("border-image: url(:/pic/pic/drum6.jpg);border-radius: 10px;");
}

// 根据点击的按钮选择音乐播放
void MainWindow::buttonPressed(QPushButton *button,char c,int k)
{
    // 连接信号和五线谱刷新函数
    connect(this,SIGNAL(mySignal()),scr,SLOT(scrSlot()));
    // 发出信号
    emit mySignal();

//    // 创建播放器对象
//    QMediaPlayer *player=new QMediaPlayer;
//    // 设置播放的音频
//    switch (c) {
//        case '1': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/C3up.wav")));break;
//        case '2': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/D3up.wav")));break;
//        case '3': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/F3up.wav")));break;
//        case '4': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/G3up.wav")));break;
//        case '5': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/A3up.wav")));break;
//        case '6': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/C4up.wav")));break;
//        case '7': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/D4up.wav")));break;
//        case '8': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/F4up.wav")));break;
//        case '9': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/G4up.wav")));break;
//        case '0': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/A4up.wav")));break;
//        case '-': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/C5up.wav")));break;
//        case '=': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/D5up.wav")));break;
//        case '[': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/F5up.wav")));break;
//        case ']': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/G5up.wav")));break;
//        case '\\': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/A5up.wav")));break;

//        case 'q': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/C3.wav")));break;
//        case 'w': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/D3.wav")));break;
//        case 'e': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/E3.wav")));break;
//        case 'r': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/F3.wav")));break;
//        case 't': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/G3.wav")));break;
//        case 'y': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/A3.wav")));break;
//        case 'u': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/B3.wav")));break;

//        case 'i': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/C4.wav")));break;
//        case 'o': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/D4.wav")));break;
//        case 'p': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/E4.wav")));break;
//        case 'a': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/F4.wav")));break;
//        case 's': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/G4.wav")));break;
//        case 'd': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/A4.wav")));break;
//        case 'f': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/B4.wav")));break;

//        case 'g': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/C5.wav")));break;
//        case 'h': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/D5.wav")));break;
//        case 'j': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/E5.wav")));break;
//        case 'k': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/F5.wav")));break;
//        case 'l': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/G5.wav")));break;
//        case 'z': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/A5.wav")));break;
//        case 'x': player->setMedia(QMediaContent(QUrl("qrc:/media/sound/B5.wav")));break;
//    }
//    // 播放音频
//    player->play();


    // 通过测试发现使用QMediaPlayer播放音频时，如果播放太多的音频后会导致内存资源不足，导致线程创建失败而卡住
    // 使用QSound来播放就会好很多

    switch (c) {
        case '1': QSound::play(":/media/sound/C3up.wav");break;
        case '2': QSound::play(":/media/sound/D3up.wav");break;
        case '3': QSound::play(":/media/sound/F3up.wav");break;
        case '4': QSound::play(":/media/sound/G3up.wav");break;
        case '5': QSound::play(":/media/sound/A3up.wav");break;
        case '6': QSound::play(":/media/sound/C4up.wav");break;
        case '7': QSound::play(":/media/sound/D4up.wav");break;
        case '8': QSound::play(":/media/sound/F4up.wav");break;
        case '9': QSound::play(":/media/sound/G4up.wav");break;
        case '0': QSound::play(":/media/sound/A4up.wav");break;
        case '-': QSound::play(":/media/sound/C5up_2.wav");break;
        case '=': QSound::play(":/media/sound/D5up_2.wav");break;
        case '[': QSound::play(":/media/sound/F5up_2.wav");break;
        case ']': QSound::play(":/media/sound/G5up_2.wav");break;
        case '\\': QSound::play(":/media/sound/A5up_2.wav");break;

        case 'q': QSound::play(":/media/sound/C3.wav");break;
        case 'w': QSound::play(":/media/sound/D3.wav");break;
        case 'e': QSound::play(":/media/sound/E3.wav");break;
        case 'r': QSound::play(":/media/sound/F3.wav");break;
        case 't': QSound::play(":/media/sound/G3.wav");break;
        case 'y': QSound::play(":/media/sound/A3.wav");break;
        case 'u': QSound::play(":/media/sound/B3.wav");break;

        case 'i': QSound::play(":/media/sound/C4.wav");break;
        case 'o': QSound::play(":/media/sound/D4.wav");break;
        case 'p': QSound::play(":/media/sound/E4.wav");break;
        case 'a': QSound::play(":/media/sound/F4.wav");break;
        case 's': QSound::play(":/media/sound/G4.wav");break;
        case 'd': QSound::play(":/media/sound/A4.wav");break;
        case 'f': QSound::play(":/media/sound/B4.wav");break;

        case 'g': QSound::play(":/media/sound/C5_2.wav");break;
        case 'h': QSound::play(":/media/sound/D5_2.wav");break;
        case 'j': QSound::play(":/media/sound/E5_2.wav");break;
        case 'k': QSound::play(":/media/sound/F5_2.wav");break;
        case 'l': QSound::play(":/media/sound/G5_2.wav");break;
        case 'z': QSound::play(":/media/sound/A5_2.wav");break;
        case 'x': QSound::play(":/media/sound/B5_2.wav");break;
    }


    // 改变按键背景
    if(k==0)
        button->setStyleSheet("QPushButton{background-color: rgb(246, 192, 115);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}");
    else
        button->setStyleSheet("QPushButton{background-color: rgb(118, 195, 237);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;color: rgb(255, 255, 255);}");


    // 记录操作
    if(flag)
    {
        // 写出全部内容
        QFile file(filePath);
        if(file.open(QIODevice::WriteOnly | QIODevice::Append| QIODevice::Text)) {
            QTextStream out(&file);
            int curtime = timer.elapsed();
            qDebug()<<"curt:"<<curtime<<endl;
            out<<c<<"_press"<<";"<<curtime<<"\n";
        }
        else qDebug()<<"文件打开失败";
        file.close();
    }
}

void MainWindow::buttonRelease(QPushButton *button,char c, int k)
{
    connect(this,SIGNAL(mySignal()),scr,SLOT(scrSlot()));
    emit mySignal();
    if(k==0)
        button->setStyleSheet("QPushButton{background-color: rgb(234, 234, 234);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}");
    else
        button->setStyleSheet("QPushButton{background-color: rgb(54, 54, 54);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;color: rgb(255, 255, 255);}");

    // 记录操作
    if(flag)
    {
        // 写出全部内容
        QFile file(filePath);
        if(file.open(QIODevice::WriteOnly | QIODevice::Append| QIODevice::Text)) {
            QTextStream out(&file);
            int curtime = timer.elapsed();
            qDebug()<<"curt:"<<curtime<<endl;
            out<<c<<"_release"<<";"<<curtime<<"\n";
        }
        else qDebug()<<"文件打开失败";
        file.close();
    }
}

// C3
void MainWindow::on_btn_C3_pressed()
{
    // 用于刷新五线谱
    isActive[12]=1;
    buttonPressed(ui->btn_C3,'q',0);
//    if(flag)
//    {
//        // 写出全部内容
//        QFile file(filePath);
//        if(file.open(QIODevice::WriteOnly | QIODevice::Append| QIODevice::Text)) {
//            QTextStream out(&file);
//            int curtime = timer.elapsed();
//            qDebug()<<"curt:"<<curtime<<endl;
//            out<<"C3"<<";"<<curtime<<"\n";
//        }
//        else qDebug()<<"文件打开失败";
//        file.close();
//    }
}


void MainWindow::on_btn_C3_released()
{
    isActive[12]=0;
    buttonRelease(ui->btn_C3,'q',0);
}


void MainWindow::on_btn_C3up_pressed()
{
    isActive[13]=1;
    buttonPressed(ui->btn_C3up,'1',1);
}

void MainWindow::on_btn_C3up_released()
{
    isActive[13]=0;
    buttonRelease(ui->btn_C3up,'1',1);
}


void MainWindow::on_btn_D3_pressed()
{
    isActive[14]=1;
    buttonPressed(ui->btn_D3,'w',0);
}


void MainWindow::on_btn_D3_released()
{
    isActive[14]=0;
    buttonRelease(ui->btn_D3,'w',0);
}


void MainWindow::on_btn_D3up_pressed()
{
    isActive[15]=1;
    buttonPressed(ui->btn_D3up,'2',1);
}


void MainWindow::on_btn_D3up_released()
{
    isActive[15]=0;
    buttonRelease(ui->btn_D3up,'2',1);
}


void MainWindow::on_btn_E3_pressed()
{
    isActive[16]=1;
    buttonPressed(ui->btn_E3,'e',0);
}

void MainWindow::on_btn_E3_released()
{
    isActive[16]=0;
    buttonRelease(ui->btn_E3,'e',0);
}


void MainWindow::on_btn_F3_pressed()
{
    isActive[17]=1;
    buttonPressed(ui->btn_F3,'r',0);
}


void MainWindow::on_btn_F3_released()
{
    isActive[17]=0;
    buttonRelease(ui->btn_F3,'r',0);
}

void MainWindow::on_btn_F3up_pressed()
{
    isActive[18]=1;
    buttonPressed(ui->btn_F3up,'3',1);
}


void MainWindow::on_btn_F3up_released()
{
    isActive[18]=0;
    buttonRelease(ui->btn_F3up,'3',1);
}


void MainWindow::on_btn_G3_pressed()
{
    isActive[19]=1;
    buttonPressed(ui->btn_G3,'t',0);
}


void MainWindow::on_btn_G3_released()
{
    isActive[19]=0;
    buttonRelease(ui->btn_G3,'t',0);
}

void MainWindow::on_btn_G3up_released()
{
    isActive[20]=0;
    buttonRelease(ui->btn_G3up,'4',1);
}


void MainWindow::on_btn_G3up_pressed()
{
    isActive[20]=1;
    buttonPressed(ui->btn_G3up,'4',1);
}



void MainWindow::on_btn_A3_pressed()
{
    isActive[21]=1;
    buttonPressed(ui->btn_A3,'y',0);
}



void MainWindow::on_btn_A3_released()
{
    isActive[21]=0;
    buttonRelease(ui->btn_A3,'y',0);
}



void MainWindow::on_btn_A3up_pressed()
{
    isActive[22]=1;
    buttonPressed(ui->btn_A3up,'5',1);
}


void MainWindow::on_btn_A3up_released()
{
    isActive[22]=0;
    buttonRelease(ui->btn_A3up,'5',1);
}


void MainWindow::on_btn_B3_pressed()
{
    isActive[23]=1;
    buttonPressed(ui->btn_B3,'u',0);
}


void MainWindow::on_btn_B3_released()
{
    isActive[23]=0;
    buttonRelease(ui->btn_B3,'u',0);
}
void MainWindow::on_btn_C4_pressed()
{
    isActive[24]=1;
    buttonPressed(ui->btn_C4,'i',0);
}
void MainWindow::on_btn_C4_released()
{
    isActive[24]=0;
    buttonRelease(ui->btn_C4,'i',0);
}

void MainWindow::on_btn_C4up_pressed()
{
    isActive[25]=1;
    buttonPressed(ui->btn_C4up,'6',1);
}


void MainWindow::on_btn_C4up_released()
{
    isActive[25]=0;
    buttonRelease(ui->btn_C4up,'6',1);
}


void MainWindow::on_btn_D4_pressed()
{
    isActive[26]=1;
   buttonPressed(ui->btn_D4,'o',0);
}


void MainWindow::on_btn_D4_released()
{
    isActive[26]=0;
    buttonRelease(ui->btn_D4,'o',0);
}


void MainWindow::on_btn_D4up_pressed()
{
    isActive[27]=1;
    buttonPressed(ui->btn_D4up,'7',1);
}


void MainWindow::on_btn_D4up_released()
{
    isActive[27]=0;
    buttonRelease(ui->btn_D4up,'7',1);
}


void MainWindow::on_btn_E4_pressed()
{
    isActive[28]=1;
    buttonPressed(ui->btn_E4,'p',0);
}


void MainWindow::on_btn_E4_released()
{
    isActive[28]=0;
    buttonRelease(ui->btn_E4,'p',0);
}


void MainWindow::on_btn_F4_pressed()
{
    isActive[29]=1;
    buttonPressed(ui->btn_F4,'a',0);
}


void MainWindow::on_btn_F4_released()
{
    isActive[29]=0;
    buttonRelease(ui->btn_F4,'a',0);
}


void MainWindow::on_btn_F4up_pressed()
{
    isActive[30]=1;
    buttonPressed(ui->btn_F4up,'8',1);
}


void MainWindow::on_btn_F4up_released()
{
    isActive[30]=0;
    buttonRelease(ui->btn_F4up,'8',1);
}


void MainWindow::on_btn_G4_pressed()
{
    isActive[31]=1;
    buttonPressed(ui->btn_G4,'s',0);
}


void MainWindow::on_btn_G4_released()
{
    isActive[31]=0;
    buttonRelease(ui->btn_G4,'s',0);
}


void MainWindow::on_btn_G4up_pressed()
{
    isActive[32]=1;
    buttonPressed(ui->btn_G4up,'9',1);
}


void MainWindow::on_btn_G4up_released()
{
    isActive[32]=0;
    buttonRelease(ui->btn_G4up,'9',1);
}


void MainWindow::on_btn_A4_pressed()
{
    isActive[33]=1;
    buttonPressed(ui->btn_A4,'d',0);
}


void MainWindow::on_btn_A4_released()
{
    isActive[33]=0;
    buttonRelease(ui->btn_A4,'d',0);

}


void MainWindow::on_btn_A4up_pressed()
{
    isActive[34]=1;
    buttonPressed(ui->btn_A4up,'0',1);
}


void MainWindow::on_btn_A4up_released()
{
    isActive[34]=0;
    buttonRelease(ui->btn_A4up,'0',1);
}


void MainWindow::on_btn_B4_pressed()
{
    isActive[35]=1;
    buttonPressed(ui->btn_B4,'f',0);
}


void MainWindow::on_btn_B4_released()
{
    isActive[35]=0;
    buttonRelease(ui->btn_B4,'f',0);
}

void MainWindow::on_btn_C5_pressed()
{
    isActive[36] = 1;
    buttonPressed(ui->btn_C5,'g',0);
}

void MainWindow::on_btn_C5_released()
{
    isActive[36] = 0;
    buttonRelease(ui->btn_C5,'g',0);
}

void MainWindow::on_btn_C5up_pressed()
{
    isActive[37] = 1;
    buttonPressed(ui->btn_C5up,'-',1);
}

void MainWindow::on_btn_C5up_released()
{
    isActive[37] = 0;
    buttonRelease(ui->btn_C5up,'-',1);
}

void MainWindow::on_btn_D5_pressed()
{
    isActive[38] = 1;
    buttonPressed(ui->btn_D5,'h',0);
}

void MainWindow::on_btn_D5_released()
{
    isActive[38] = 0;
    buttonRelease(ui->btn_D5,'h',0);
}

void MainWindow::on_btn_D5up_pressed()
{
    isActive[39]= 1;
    buttonPressed(ui->btn_D5up,'=',1);
}

void MainWindow::on_btn_D5up_released()
{
    isActive[39] = 0;
    buttonRelease(ui->btn_D5up,'=',1);
}

void MainWindow::on_btn_E5_pressed()
{
    isActive[40] = 1;
    buttonPressed(ui->btn_E5,'j',0);
}

void MainWindow::on_btn_E5_released()
{
    isActive[40] = 0;
    buttonRelease(ui->btn_E5,'j',0);
}

void MainWindow::on_btn_F5_pressed()
{
    isActive[41] = 1;
    buttonPressed(ui->btn_F5,'k',0);
}

void MainWindow::on_btn_F5_released()
{
    isActive[41] = 0;
    buttonRelease(ui->btn_F5,'k',0);
}

void MainWindow::on_btn_F5up_pressed()
{
    isActive[42] = 1;
    buttonPressed(ui->btn_F5up,'[',1);
}

void MainWindow::on_btn_F5up_released()
{
    isActive[42] = 0;
    buttonRelease(ui->btn_F5up,'[',1);
}

void MainWindow::on_btn_G5_pressed()
{
    isActive[43] = 1;
    buttonPressed(ui->btn_G5,'l',0);
}

void MainWindow::on_btn_G5_released()
{
    isActive[43] = 0;
    buttonRelease(ui->btn_G5,'l',0);
}

void MainWindow::on_btn_G5up_pressed()
{
    isActive[44] = 1;
    buttonPressed(ui->btn_G5up,']',1);
}

void MainWindow::on_btn_G5up_released()
{
    isActive[44] = 0;
    buttonRelease(ui->btn_G5up,']',1);
}

void MainWindow::on_btn_A5_pressed()
{
    isActive[45] = 1;
    buttonPressed(ui->btn_A5,'z',0);
}

void MainWindow::on_btn_A5_released()
{
    isActive[45] = 0;
    buttonRelease(ui->btn_A5,'z',0);
}

void MainWindow::on_btn_A5up_pressed()
{
    isActive[46] = 1;
    buttonPressed(ui->btn_A5up,'\\',1);
}

void MainWindow::on_btn_A5up_released()
{
    isActive[46] = 0;
    buttonRelease(ui->btn_A5up,'\\',1);
}

void MainWindow::on_btn_B5_pressed()
{
    isActive[47] = 1;
    buttonPressed(ui->btn_B5,'x',0);
}

void MainWindow::on_btn_B5_released()
{
    isActive[47] = 0;
    buttonRelease(ui->btn_B5,'x',0);
}
