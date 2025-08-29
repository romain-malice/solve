#include "expression.h"
#include <stdlib.h>
#include <stdio.h>

typedef enum {
    OP,
    NUM,
    VAR
} ExprType;

struct Expr_t {
    ExprType type;
    union {
        Operator operation;
        int num;
        char symbol;
    } value;
    Expr *left;
    Expr *right;
};

/*
 * @brief Creates an operation expression
 *
 * @param op An operation type (PLUS, MINUS, TIMES, DIV)
 * @param left First expression parameter
 * @param right Second expression parameter
 *
 * @return A pointer to the expression
 */
Expr *exprOp(Operator op, Expr *left, Expr *right) {
    Expr *newExpr = malloc(sizeof(Expr));

    newExpr->type = OP;
    newExpr->value.operation = op;
    newExpr->left = left;
    newExpr->right = right;

    return newExpr;
}

/*
 * @brief Creates a number expression
 *
 * @param number The value of the expression
 *
 * @return A pointer to the expression
 */
Expr *exprNum(int number) {
    Expr *newExpr = malloc(sizeof(Expr));

    newExpr->type = NUM;
    newExpr->value.num = number;
    newExpr->left = NULL;
    newExpr->right = NULL;

    return newExpr;
}

Expr *exprVar(char symbol) {
    Expr *newExpr = malloc(sizeof(Expr));

    newExpr->type = VAR;
    newExpr->value.symbol = symbol;
    newExpr->left = NULL;
    newExpr->right = NULL;

    return newExpr;
}

/*
 * @brief Frees an expression of any type (including its children if they exist)
 *
 * @param expression The expression
 */
void exprFree(Expr *expression) {
    if (expression->left)
        exprFree(expression->left);
    if (expression->right)
        exprFree(expression->right);
    free(expression);
    return;
}

/*
 * @brief Tries to solve an expression. Does nothing if not solvable.
 *
 * @param expression The expression to solve
 */
void exprSolve(Expr *expression) {
    if (expression->type == OP) { // => has 2 children, no need to check
        // Solve children if possible
        if (expression->left->type == OP)
            exprSolve(expression->left);
        if (expression->right->type == OP)
            exprSolve(expression->right);

        // Solve the node if possible
        if (expression->left->type == NUM && expression->right->type == NUM) {

            int leftNum = expression->left->value.num;
            int rightNum = expression->right->value.num;

            switch (expression->value.operation) {
                case PLUS:
                    expression->value.num = leftNum + rightNum;
                    expression->type = NUM;
                    break;
                case MINUS:
                    expression->value.num = leftNum - rightNum;
                    expression->type = NUM;
                    break;
                case TIMES:
                    expression->value.num = leftNum * rightNum;
                    expression->type = NUM;
                    break;
                case DIV: break;
            }
        }
    }
}

int getNum(Expr *expression) {
    return expression->value.num;
}

char getSymbol(Expr *expression) {
    return expression->value.symbol;
}

void exprPrint(Expr *expression) {
    switch (expression->type) {
        case NUM:
            printf("%d", expression->value.num);
            break;
        case VAR:
            printf("%c", expression->value.symbol);
            break;
        case OP:
            printf("(");
            exprPrint(expression->left);
            switch (expression->value.operation) {
                case PLUS: printf(" + "); break;
                case MINUS: printf(" - "); break;
                case TIMES: printf(" * "); break;
                case DIV: printf(" / "); break;
            }
            exprPrint(expression->right);
            printf(")");
            break;
    }
}
