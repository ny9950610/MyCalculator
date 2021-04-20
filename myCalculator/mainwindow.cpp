#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculate.h"

Calculate c ;
bool isZero = false ;      // 上一個字元為"0"
bool isDelimiter = false ; // 上一個字元為delimiter
bool isStart = true ;      // 目前字串中沒有字元
bool restart = false ;     // 一個算式已被計算完畢

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* 當"0"被按下之後輸入"0" */
void MainWindow::on_pushButton_0_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果"0"為數字開頭或上一個字元為delimiter 則下個字元不能為"0"
    if( !isZero ){
        c.mStr += "0" ;
    }
    else if( restart ) {
        c.mStr = "0" ;
        restart = false ;
    }

    // 檢查這個"0"是否為數字開頭或他的上個字元為delimiter
    if( isDelimiter || isStart ) {
        isZero = true ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"1"被按下之後輸入"1" */
void MainWindow::on_pushButton_1_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果字串由"0"做開頭 按下"1"後由"1"取代"0"
    if( c.mStr == "0" || restart ) {
        c.mStr = "1" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
        restart = false ;
    }
    // 如果"0"為一個數字的開頭就無視按下的動作
    else if( !isZero ) {
        c.mStr += "1" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"2"被按下之後輸入"2" */
void MainWindow::on_pushButton_2_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果字串由"0"做開頭 按下"2"後由"2"取代"0"
    if( c.mStr == "0" || restart ) {
        c.mStr = "2" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
        restart = false ;
    }
    // 如果"0"為一個數字的開頭就無視按下的動作
    else if( !isZero ) {
        c.mStr += "2" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"3"被按下之後輸入"3" */
void MainWindow::on_pushButton_3_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果字串由"0"做開頭 按下"3"後由"3"取代"0"
    if( c.mStr == "0" || restart ) {
        c.mStr = "3" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
        restart = false ;
    }
    // 如果"0"為一個數字的開頭就無視按下的動作
    else if( !isZero ) {
        c.mStr += "3" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"4"被按下之後輸入"4" */
void MainWindow::on_pushButton_4_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果字串由"0"做開頭 按下"4"後由"4"取代"0"
    if( c.mStr == "0" || restart ) {
        c.mStr = "4" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
        restart = false ;
    }
    // 如果"0"為一個數字的開頭就無視按下的動作
    else if( !isZero ) {
        c.mStr += "4" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"5"被按下之後輸入"5" */
void MainWindow::on_pushButton_5_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果字串由"0"做開頭 按下"5"後由"5"取代"0"
    if( c.mStr == "0" || restart ) {
        c.mStr = "5" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
        restart = false ;
    }

    // 如果"0"為一個數字的開頭就無視按下的動作
    else if( !isZero ) {
        c.mStr += "5" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"6"被按下之後輸入"6" */
void MainWindow::on_pushButton_6_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果字串由"0"做開頭 按下"6"後由"6"取代"0"
    if( c.mStr == "0" || restart ) {
        c.mStr = "6" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
        restart = false ;
    }

    // 如果"0"為一個數字的開頭就無視按下的動作
    else if( !isZero ) {
        c.mStr += "6" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"7"被按下之後輸入"7" */
void MainWindow::on_pushButton_7_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果字串由"0"做開頭 按下"7"後由"7"取代"0"
    if( c.mStr == "0" || restart ) {
        c.mStr = "7" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
        restart = false ;
    }

    // 如果"0"為一個數字的開頭就無視按下的動作
    else if( !isZero ) {
        c.mStr += "7" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"8"被按下之後輸入"8" */
void MainWindow::on_pushButton_8_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果字串由"0"做開頭 按下"8"後由"8"取代"0"
    if( c.mStr == "0" || restart ) {
        c.mStr = "8" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
        restart = false ;
    }

    // 如果"0"為一個數字的開頭就無視按下的動作
    else if( !isZero ) {
        c.mStr += "8" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"9"被按下之後輸入"9" */
void MainWindow::on_pushButton_9_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果字串由"0"做開頭 按下"9"後由"9"取代"0"
    if( c.mStr == "0" || restart ) {
        c.mStr = "9" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
        restart = false ;
    }

    // 如果"0"為一個數字的開頭就無視按下的動作
    else if( !isZero ) {
        c.mStr += "9" ;

        isZero = false ;
        isDelimiter = false ;
        isStart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"+"被按下之後輸入"+" */
void MainWindow::on_pushButton_plus_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 如果"-"為字串開頭 清除整個字串
    if( c.mStr == "-" ) {
        c.mStr = "" ;
        isDelimiter = false ;
        isStart = true ;
    }

    // 正常輸入"+"
    else if( !isDelimiter && !isStart ) {
        c.mStr += "+" ;
        isDelimiter = true ;
        isStart = false ;
        isZero = false ;
        restart = false ;
    }

    ui->lineEdit->setText(c.mStr) ;
}

/* 當"-"被按下之後輸入"-" */
void MainWindow::on_pushButton_minus_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 前一個字元不是delimiter或是開頭 就輸入"-"
    if( !isDelimiter || isStart ) {
        c.mStr += "-" ;
        isDelimiter = true ;
        isStart = false ;
        isZero = false ;
        restart = false ;
    }
    ui->lineEdit->setText(c.mStr) ;
}

/* 當"*"被按下之後輸入"*" */
void MainWindow::on_pushButton_multiply_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 前一個字元不是delimiter且不是開頭 就輸入"*"
    if( !isDelimiter && !isStart ) {
        c.mStr += "*" ;
        isDelimiter = true ;
        isZero = false ;
        restart = false ;
    }
    ui->lineEdit->setText(c.mStr) ;
}

/* 當"/"被按下之後輸入"/" */
void MainWindow::on_pushButton_divide_clicked()
{
    if(c.mStr == "Error!" ) return ;
    // 前一個字元不是delimiter且不是開頭 就輸入"/"
    if( !isDelimiter && !isStart ) {
        c.mStr += "/" ;
        isDelimiter = true ;
        isZero = false ;
        restart = false ;
    }
    ui->lineEdit->setText(c.mStr) ;
}

void MainWindow::on_pushButton_cancel_clicked()
{
    // 初始化
    c.mStr = "" ;
    c.tokens.clear() ;
    isZero = false ;
    isDelimiter = false ;
    isStart = true ;
    ui->lineEdit->setText(c.mStr) ;
}


void MainWindow::on_pushButton_equal_clicked()
{
    if(c.mStr == "Error!" ) return ;
    c.startCalculation() ;

    ui->lineEdit->setText(c.mStr) ;

    restart = true ;
    if( c.mStr == "0" ) isZero = true ;
}
