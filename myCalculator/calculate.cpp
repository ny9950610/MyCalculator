#include "calculate.h"

/* 依照算式計算出答案 */
void Calculate::startCalculation() {
    // 將算式切成多個token
    tokens.clear() ;
    tokenSegmentation() ;

    // 將tokens從中序轉成後序並計算
    reversePolishNotation() ;

    // 用來測試token是否正確
  /*  mStr = "" ;
    int i = 0 ;
    while( i < tokens.size() ) {
        mStr += tokens[i] + " " ;
        i ++ ;
    }*/
}

/* 切token */
void Calculate::tokenSegmentation() {
    int i = 0 ;
    QString tempToken = "" ; // 用來暫存一個token

    // 把整行的字串分成多個token
    while( i < mStr.size() ) {
        // 遇到delimiter開始切token
        if( isDelimiter( mStr[i] ) ) {
            if( tempToken != "" ) {
                // delimiter前面的數字為一個token
                tokens.push_back( tempToken ) ;
            }

            // delimiter本身也是一個token
            tempToken = mStr[i] ;
            tokens.push_back( tempToken ) ;
            tempToken = "" ;
        }
        else {
            // 將一個字元放入tempToken
            tempToken += mStr[i] ;
        }

        i ++ ;
    }

    // 將最後面的operand也放入tokens
    tokens.push_back( tempToken ) ;
    // 如果第一個token為"-" 在前面加上一個token"0"
    if( tokens[0] == "-" ) {
        tokens.insert( 0, "0" ) ;
    }
}

/* 以逆波蘭表示法來找出後序計算式並計算 */
void Calculate::reversePolishNotation() {
    QString operatorStack [20] ;  // 用來存operator的stack
    bool divideZero = false ;
    int i = 0 ;
    int j = -1 ; // 用來記錄RPNStack的位置
    int k = -1 ; // 用來記錄operatorStack的位置

    // 把tokens分成operand和operator 並分別放到兩種stack中
    while( i < tokens.size() && !divideZero ) {
        // operand為數字 放進RPNStack
        if( isDigit( tokens[i] ) ) {
            j ++ ;
            RPNStack[j] = tokens[i] ;
        }
        // 將operator放進operatorStack
        else {
            // 如果新放入的operator優先度小於等於operatorStack頂端的operator優先度
            // 就將operatorStack頂端的operator放入RPNStack
            while( k != -1 && !biggerPriority( tokens[i], operatorStack[k] ) ) {
                j ++ ;
                RPNStack[j] = operatorStack[k] ;
                k -- ;
            }

            k ++ ;
            operatorStack[k] = tokens[i] ;
        }

        i ++ ;
    }

    // 將operatorStack中剩下的operator全部放入RPNStack
    while( k >= 0 ) {
        j ++ ;
        RPNStack[j] = operatorStack[k] ;
        k -- ;
    }

    i = 0 ;  // 用來紀錄RPNStack的位置
    k = -1 ; // 用來記錄answerStack中的位置
    // 開始計算
    while( i <= j ) {
        // 數字直接放入answerStack中
        if( isDigit( RPNStack[i] ) ) {
            k ++ ;
            answerStack[k] = RPNStack[i].toInt() ;
        }
        // 遇到operator就把stack中最頂端的2個數字拿來計算 並將結果放回answerStack
        else {
            k -- ;
            answerStack[k] = calculate( answerStack[k], answerStack[k+1], RPNStack[i], divideZero ) ;
        }

        i ++ ;
    }

    // 輸出結果
    if( divideZero ) mStr = "Error!" ;
    else mStr = QString::number( answerStack[0] ) ;
}

/* 依照operator進行計算 */
int Calculate::calculate( int num1, int num2, QString op, bool &divideZero ) {
    if( op == "+" ) return num1 + num2 ;
    else if( op == "-" ) return num1 - num2 ;
    else if( op == "*" ) return num1 * num2 ;
    else if( op == "/" && num2 != 0 ) return num1 / num2 ;
    else if( op == "/" && num2 == 0 ) divideZero = true ;

    return -1 ;

}

/* 判斷字元是否為delimiter */
bool Calculate::isDelimiter( QCharRef ch ) {
    if( ch == '+' || ch == '-' || ch == '*' || ch == '/' ) return true ;
    else return false ;
}

/* 判斷字串是否全為數字 */
bool Calculate::isDigit( QString str ) {
    int i = 0 ;

    while( i < str.size() ) {
        if( str[i] < '0' || str[i] > '9' ) {
            return false ;
        }

        i ++ ;
    }

    return true ;
}

/* 判斷operator的優先度 */
bool Calculate::biggerPriority( QString op1, QString op2 ) {
    if( ( op1 == "*" || op1 == "/" ) && ( op2 == "+" || op2 == "-" ) ) return true ;
    else return false ;
}
