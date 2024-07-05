## 一、实验内容

完成一个电子琴软件

**功能需求：**

（1） 软件启动后，显示电子琴的界面，包括黑白按键

（2） 用户可以用鼠标点击琴键弹奏（在桌面系统开发的话，如果用手机系统上开发运行，可用触屏点击弹奏），也可以用键盘上“特定按键对应特定琴键”的方式弹奏。

（3） 用户弹奏时，应播出相应的音乐声，形成乐曲

**相关技术：**

（1） 图像展现或图形展现

（2） 音频播放

（3） 鼠标、键盘消息处理

## 二、实验目的

通过设计并完成一个电子琴软件，熟悉软件开发的流程，掌握相关技术，提升对理论知识的运用能力

## 三、实验文档

### 1、实验项目分析

根据软件的功能需求，涉及到的相关技术主要有图像展现、音频播放和鼠标、键盘消息处理，所以我选择使用Qt Creator来进行软件的开发，使用QMainWindow、QPainter、QSound、QKeyEvent等类以及其成员函数来实现相关功能。因为实体钢琴共有88个按键，但考虑到电脑屏幕大小，键盘按键的数量，以及软件界面的显示效果，这里只实现其中的36个按键，分别是位于中央C的小字一组，以及两侧的小字组，小字二组。除了要求的基本功能外，还实现了一些额外功能：琴键对应的五线谱的显示，鼓声，以及弹奏的录制。

以下是大谱表与钢琴键盘的对照表：

<img src="C:\Users\x\AppData\Roaming\Typora\typora-user-images\image-20231220190436516.png" alt="image-20231220190436516" style="zoom:80%;" />

### 2、实验项目设计和实现

#### 1.**整体框架的构建**

<img src="D:\Downloads\Edge\未命名绘图 (3).png" alt="未命名绘图 (3)" style="zoom:80%;" />

#### 2.**钢琴弹奏的设计和按键的绑定**

- 每个按键其实就是一个QPushButton，对其进行样式效果进行设计，从而使其展现出钢琴按键的效果。

- 为了让按键按下和释放呈现出不同的效果，需要在按键按下或释放后设置对应的样式表。
- 为了让按键可以通过鼠标点击来进行操作，还要对每个按键的released()和pressed()槽函数进行操作的绑定
- 为了让按键可以通过键盘弹奏，要通过keyPressEvent和keyReleaseEvent函数让键盘按键与钢琴按键进行绑定

#### 3.音频播放

- 一开始使用的QMediaPlayer播放音频时，如果播放太多的音频后会导致内存资源不足，导致线程创建失败而卡住，从而改用QSound类的成员函数play来播放音频

- 使用了Qt提供的QSound类，对每一个键初始化了一个音频文件，当按键消息处理时，会播放这个音频文件

#### 4.五线谱的显示

- 为了保存当前按键按下或释放的状态，使用isActive数组保存了每个按键对应的状态，然后如果按键按下为按下的状态，即isActive为True，就在五线谱上对应的位置用QPainter画出对应的一个点或点线

#### 5.弹奏的录制

- 当用户按下录制按钮时，根据当前的日期和时间，自动创建一个记录文件，QElapsedTimer 对象 timer 开始计时
- 当进行弹奏时，向文件写入操作的按钮及操作类型，以及当前的时间刻度，格式是：按键_操作;时间刻度
- 当点击结束录制按钮时，计时器停止计时并清空，记录下结束计时的时间：end;结束时间，并写入文件

#### 6.弹奏记录的播放

- 用户选择一个记录文件，然后从文件中读取每个操作和对应的时间刻度，通过使用QTimer::singleShot，让时间刻度和对应的按键操作进行绑定，经过绑定的时间后，会发送按键的操作信号，从而完成弹奏的播放
- 在播放期间要使用setEnabled(false)来关闭鼠标和键盘的操作，以免与播放的操作冲突

#### 7.核心代码

**详细代码请看源代码**

- 琴键点击操作核心代码（其他按键类似代码省略）

~~~C++
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

......
~~~

- 音频播放，按键动画，弹奏记录核心代码（中间类似代码省略）

~~~C++
// 根据点击的按钮选择音乐播放
void MainWindow::buttonPressed(QPushButton *button,char c,int k)
{
    // 连接信号和五线谱刷新函数
    connect(this,SIGNAL(mySignal()),scr,SLOT(scrSlot()));
    // 发出信号
    emit mySignal();

    // 通过测试发现使用QMediaPlayer播放音频时，如果播放太多的音频后会导致内存资源不足，导致线程创建失败而卡住
    // 使用QSound来播放就会好很多

    switch (c) {
        case '1': QSound::play(":/media/sound/C3up.wav");break;
        case '2': QSound::play(":/media/sound/D3up.wav");break;
        
        ......
            
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
~~~

- 键盘按键与琴键绑定核心代码（中间类似代码省略）

~~~C++
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->isAutoRepeat()) return;//防止不断重复的发送键按下事件
    switch(event->key()){
    case Qt::Key_1:{
        emit on_btn_C3up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_2:{
        emit on_btn_D3up_pressed(); // 发送点击信号
        break;
    }
   
    ......
        
    case Qt::Key_X:{
        emit on_btn_B5_pressed();
        break;
    }
    default:;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    //防止不断重复的发送键释放事件
    if(event->isAutoRepeat()) return;
    switch(event->key()){
    case Qt::Key_1:{
        emit on_btn_C3up_released(); // 发送释放信号
    }
    case Qt::Key_2:{
        emit on_btn_D3up_released();
        break;
    }
    
    ......
        
    case Qt::Key_X:{
        emit on_btn_B5_released();
        break;
    }
    default:;
    }
}
~~~

- 弹奏记录的播放核心代码（中间类似代码省略）

~~~C++
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
                
                ......
                    
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
~~~

**详细代码请看源代码**

#### 8.软件完成效果

<img src="C:\Users\x\AppData\Roaming\Typora\typora-user-images\image-20231220212510811.png" alt="image-20231220212510811" style="zoom:80%;" />

### 3、实验项目测试

通过测试，软件的功能需求都已完成，扩展的功能也已完成，且在测试过程中未发现相关问题
