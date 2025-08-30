#ifndef _EXPRESSION_H
#define _EXPRESSION_H

#include <stdbool.h>

typedef struct Expr_t Expr;
typedef enum {
    PLUS,
    MINUS,
    DIV,
    TIMES,
} Operator;

Expr *exprOp(Operator, Expr *, Expr *);
Operator exprGetOp(Expr *);
bool exprIsOp(Expr *);

Expr *exprNum(int);
int exprGetNum(Expr *);
bool exprIsNum(Expr *);

Expr *exprVar(char);
char exprGetSymbol(Expr *);
bool exprIsVar(Expr *);

void exprFree(Expr *);

void exprSolve(Expr *);

void exprPrint(Expr *);

#endif
