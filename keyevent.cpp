#include "MainWindow.h"
#include "ui_MainWindow.h"


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
    case Qt::Key_3:{
        emit on_btn_F3up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_4:{
        emit on_btn_G3up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_5:{
        emit on_btn_A3up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_6:{
        emit on_btn_C4up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_7:{
        emit on_btn_D4up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_8:{
        emit on_btn_F4up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_9:{
        emit on_btn_G4up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_0:{
        emit on_btn_A4up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_Minus:{
        emit on_btn_C5up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_Equal:{
        emit on_btn_D5up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_BracketLeft:{
        emit on_btn_F5up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_BracketRight:{
        emit on_btn_G5up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_Backslash:{
        emit on_btn_A5up_pressed(); // 发送点击信号
        break;
    }
    case Qt::Key_Q:{
        emit on_btn_C3_pressed();
        break;
    }
    case Qt::Key_W:{
        emit on_btn_D3_pressed();
        break;
    }
    case Qt::Key_E:{
        emit on_btn_E3_pressed();
        break;
    }
    case Qt::Key_R:{
        emit on_btn_F3_pressed();
        break;
    }
    case Qt::Key_T:{
        emit on_btn_G3_pressed();
        break;
    }
    case Qt::Key_Y:{
        emit on_btn_A3_pressed();
        break;
    }
    case Qt::Key_U:{
        emit on_btn_B3_pressed();
        break;
    }
    case Qt::Key_I:{
        emit on_btn_C4_pressed();
        break;
    }
    case Qt::Key_O:{
        emit on_btn_D4_pressed();
        break;
    }
    case Qt::Key_P:{
        emit on_btn_E4_pressed();
        break;
    }
    case Qt::Key_A:{
        emit on_btn_F4_pressed();
        break;
    }
    case Qt::Key_S:{
        emit on_btn_G4_pressed();
        break;
    }
    case Qt::Key_D:{
        emit on_btn_A4_pressed();
        break;
    }
    case Qt::Key_F:{
        emit on_btn_B4_pressed();
        break;
    }
    case Qt::Key_G:{
        emit on_btn_C5_pressed();
        break;
    }
    case Qt::Key_H:{
        emit on_btn_D5_pressed();
        break;
    }
    case Qt::Key_J:{
        emit on_btn_E5_pressed();
        break;
    }
    case Qt::Key_K:{
        emit on_btn_F5_pressed();
        break;
    }
    case Qt::Key_L:{
        emit on_btn_G5_pressed();
        break;
    }
    case Qt::Key_Z:{
        emit on_btn_A5_pressed();
        break;
    }
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
    case Qt::Key_3:{
        emit on_btn_F3up_released();
        break;
    }
    case Qt::Key_4:{
        emit on_btn_G3up_released();
        break;
    }
    case Qt::Key_5:{
        emit on_btn_A3up_released();
        break;
    }
    case Qt::Key_6:{
        emit on_btn_C4up_released();
        break;
    }
    case Qt::Key_7:{
        emit on_btn_D4up_released();
        break;
    }
    case Qt::Key_8:{
        emit on_btn_F4up_released();
        break;
    }
    case Qt::Key_9:{
        emit on_btn_G4up_released();
        break;
    }
    case Qt::Key_0:{
        emit on_btn_A4up_released();
        break;
    }
    case Qt::Key_Minus:{
        emit on_btn_C5up_released();
        break;
    }
    case Qt::Key_Equal:{
        emit on_btn_D5up_released();
        break;
    }
    case Qt::Key_BracketLeft:{
        emit on_btn_F5up_released();
        break;
    }
    case Qt::Key_BracketRight:{
        emit on_btn_G5up_released();
        break;
    }
    case Qt::Key_Backslash:{
        emit on_btn_A5up_released();
        break;
    }
    case Qt::Key_Q:{
        emit on_btn_C3_released();
        break;
    }
    case Qt::Key_W:{
        emit on_btn_D3_released();
        break;
    }
    case Qt::Key_E:{
        emit on_btn_E3_released();
        break;
    }
    case Qt::Key_R:{
        emit on_btn_F3_released();
        break;
    }
    case Qt::Key_T:{
        emit on_btn_G3_released();
        break;
    }
    case Qt::Key_Y:{
        emit on_btn_A3_released();
        break;
    }
    case Qt::Key_U:{
        emit on_btn_B3_released();
        break;
    }
    case Qt::Key_I:{
        emit on_btn_C4_released();
        break;
    }
    case Qt::Key_O:{
        emit on_btn_D4_released();
        break;
    }
    case Qt::Key_P:{
        emit on_btn_E4_released();
        break;
    }
    case Qt::Key_A:{
        emit on_btn_F4_released();
        break;
    }
    case Qt::Key_S:{
        emit on_btn_G4_released();
        break;
    }
    case Qt::Key_D:{
        emit on_btn_A4_released();
        break;
    }
    case Qt::Key_F:{
        emit on_btn_B4_released();
        break;
    }
    case Qt::Key_G:{
        emit on_btn_C5_released();
        break;
    }
    case Qt::Key_H:{
        emit on_btn_D5_released();
        break;
    }
    case Qt::Key_J:{
        emit on_btn_E5_released();
        break;
    }
    case Qt::Key_K:{
        emit on_btn_F5_released();
        break;
    }
    case Qt::Key_L:{
        emit on_btn_G5_released();
        break;
    }
    case Qt::Key_Z:{
        emit on_btn_A5_released();
        break;
    }
    case Qt::Key_X:{
        emit on_btn_B5_released();
        break;
    }
    default:;
    }
}
