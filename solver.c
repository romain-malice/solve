#include "expression.h"
#include <stdio.h>

int main() {
    // 1/2 * (2 * (a + b) - (7 * 8) - (4 + 2 * 2)) / ((8 + 8) * a)
    Expr *testExpr = exprOp(TIMES, exprOp(DIV, exprNum(1), exprNum(2)), exprOp(DIV, exprOp(MINUS, exprOp(MINUS, exprOp(TIMES, exprNum(2), exprOp(PLUS, exprVar('a'), exprVar('b'))), exprOp(TIMES, exprNum(7), exprNum(8))), exprOp(PLUS, exprNum(4), exprOp(TIMES, exprNum(2), exprNum(2)))), exprOp(TIMES, exprOp(PLUS, exprNum(8), exprNum(8)), exprVar('a'))));

    exprSolve(testExpr);
    exprPrint(testExpr);
    printf("\n");

    exprFree(testExpr);
    return 0;
}
