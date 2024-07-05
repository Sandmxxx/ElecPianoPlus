#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qcoreapplication.h>
#include<QtMultimedia/QMediaPlayer>
#include<QKeyEvent>
#include<qurl.h>
#include<qpainter.h>
#include<qwidget.h>
#include<screen.h>
#include<QPushButton>
#include<QSound>
#include<QTimer>
#include<QElapsedTimer>
#include<QDebug>
#include<QDateTime>
#include<QDir>
#include<QMessageBox>
#include<QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     bool isActive[48];
     int drumset;
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void buttonPressed(QPushButton *button, char c ,int k);
    void buttonRelease(QPushButton *button, char c ,int k);

    void recordPlayEnd();
signals:
    void mySignal();
private slots:
    void on_btn_C4_released();
    void on_btn_C4_pressed();
    void on_drum1_pressed();
    void on_drum1_released();
    void on_drun4_released();
    void on_drun4_pressed();
    void on_drum2_pressed();
    void on_drum2_released();
    void on_drum3_pressed();
    void on_drum5_pressed();
    void on_drum6_pressed();
    void on_drum3_released();
    void on_drum5_released();
    void on_drum6_released();
    void on_btn_C4up_pressed();
    void on_btn_C4up_released();
    void on_btn_D4_pressed();
    void on_btn_D4_released();
    void on_btn_D4up_pressed();
    void on_btn_D4up_released();
    void on_btn_E4_pressed();
    void on_btn_E4_released();
    void on_btn_F4_pressed();
    void on_btn_F4_released();
    void on_btn_F4up_pressed();
    void on_btn_F4up_released();
    void on_btn_G4_pressed();
    void on_btn_G4_released();
    void on_btn_G4up_pressed();
    void on_btn_G4up_released();
    void on_btn_A4_pressed();
    void on_btn_A4_released();
    void on_btn_A4up_pressed();
    void on_btn_A4up_released();
    void on_btn_B4_pressed();
    void on_btn_B4_released();
    void on_pushButton_2_clicked();
    void on_btn_C3_pressed();
    void on_btn_C3_released();
    void on_btn_C3up_pressed();
    void on_btn_C3up_released();
    void on_btn_D3_pressed();
    void on_btn_D3_released();
    void on_btn_D3up_pressed();
    void on_btn_D3up_released();
    void on_btn_E3_pressed();
    void on_btn_E3_released();
    void on_btn_F3_pressed();
    void on_btn_F3_released();
    void on_btn_F3up_pressed();
    void on_btn_F3up_released();
    void on_btn_G3_pressed();
    void on_btn_G3_released();
    void on_btn_G3up_released();
    void on_btn_G3up_pressed();
    void on_btn_A3_pressed();
    void on_btn_A3_released();
    void on_btn_A3up_pressed();
    void on_btn_A3up_released();
    void on_btn_B3_pressed();
    void on_btn_B3_released();
    void on_btn_C5_pressed();

    void on_btn_C5_released();

    void on_btn_C5up_pressed();

    void on_btn_C5up_released();

    void on_btn_D5_pressed();

    void on_btn_D5_released();

    void on_btn_D5up_pressed();

    void on_btn_D5up_released();

    void on_btn_E5_pressed();

    void on_btn_E5_released();

    void on_btn_F5_pressed();

    void on_btn_F5_released();

    void on_btn_F5up_pressed();

    void on_btn_F5up_released();

    void on_btn_G5_pressed();

    void on_btn_G5_released();

    void on_btn_G5up_pressed();

    void on_btn_G5up_released();

    void on_btn_A5_pressed();

    void on_btn_A5_released();

    void on_btn_A5up_pressed();

    void on_btn_A5up_released();

    void on_btn_B5_pressed();

    void on_btn_B5_released();

    void on_recordEnd_clicked();

    void on_recordPlay_clicked();

    void on_recordBegin_clicked();

private:
    Ui::MainWindow *ui;

    Screen *scr;

    bool flag;
    bool playerFlag;
    QString filePath;
    QElapsedTimer timer;



//friend Screen;
//friend drumChoose;
};
#endif // MAINWINDOW_H
