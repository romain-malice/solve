#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include <stdbool.h>

typedef struct Expr_t Expr;
typedef enum {
    PLUS,
    MINUS,
    DIV,
    TIMES,
    EXP
} Operator;

Expr *exprOp(Operator, Expr *, Expr *);
Operator exprGetOp(Expr *);
bool exprIsOp(Expr *);

Expr *exprNum(int);
bool exprIsNum(Expr *);
int getNum(Expr *);

Expr *exprVar(char);
bool exprIsVar(Expr *);
char getSymbol(Expr *);

void exprFree(Expr *);

void exprSolve(Expr *);

void exprPrint(Expr *);

#endif
