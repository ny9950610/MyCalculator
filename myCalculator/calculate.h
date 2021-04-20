#ifndef CALCULATE_H
#define CALCULATE_H

#include <QString>
#include <QVector>

class Calculate {
public:
    QString mStr ; // 輸入的算式
    QVector <QString> tokens ; // 將算式分割後得出的token

    /* 依照算式計算出答案 */
    void startCalculation() ;

private:
    QString RPNStack[40] ; //
    int answerStack[40] ;  //

    /* 切token */
    void tokenSegmentation() ;

    /* 以逆波蘭表示法來找出後序計算式並計算 */
    void reversePolishNotation() ;

    /* 依照operator做計算 */
    int calculate( int, int, QString, bool& ) ;

    /* 判斷字元是否為delimiter */
    bool isDelimiter( QCharRef ) ;

    /* 判斷字串是否全為數字 */
    bool isDigit( QString ) ;

    /* 判斷operator的優先級 */
    bool biggerPriority( QString, QString ) ;
};

#endif // CALCULATE_H
