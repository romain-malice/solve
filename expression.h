#ifndef _EXPRESSION_H
#define _EXPRESSION_H

typedef struct Expr_t Expr;
typedef enum {
    PLUS,
    MINUS,
    DIV,
    TIMES,
} Operator;

Expr *exprOp(Operator, Expr *, Expr *);

Expr *exprNum(double);
double getNum(Expr *);

Expr *exprVar(char);
char getSymbol(Expr *);

void exprFree(Expr *);

void exprSolve(Expr *);

#endif
