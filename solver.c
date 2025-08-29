#include "expression.h"
#include <stdio.h>

int main() {
        Expr *testExpr = exprOp(TIMES, exprOp(PLUS, exprNum(1), exprNum(8)), exprNum(2));
        exprSolve(testExpr);
        printf("%f\n", getNum(testExpr));
        exprFree(testExpr);
    return 0;
}
