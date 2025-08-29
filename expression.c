#include "expression.h"
#include <stdlib.h>

typedef enum { OP, NUM } ExprType;

struct Expr_t {
    ExprType type;
    union {
        Operator operation;
        double num;
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
Expr *exprNum(double number) {
    Expr *newExpr = malloc(sizeof(Expr));

    newExpr->type = NUM;
    newExpr->value.num = number;
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
 * @brief Turns an expression into a number expression.
 *
 * @param expression The expression to solve
 */
void exprSolve(Expr *expression) {
    if (expression->type == OP) {

        // 1. Get the left and right numbers
        double leftNum, rightNum;

        if (expression->left->type == NUM) {
            leftNum = expression->left->value.num;
        } else {
            exprSolve(expression->left);
            leftNum = expression->left->value.num;
            exprFree(expression->left);
        }

        if (expression->right->type == NUM) {
            rightNum = expression->right->value.num;
        } else {
            exprSolve(expression->right);
            rightNum = expression->right->value.num;
            exprFree(expression->right);
        }

        // 2. Compute the result
        double result;
        switch (expression->value.operation) {
        case PLUS:
            result = leftNum + rightNum;
            break;
        case MINUS:
            result = leftNum - rightNum;
            break;
        case DIV:
            result = leftNum / rightNum;
            break;
        case TIMES:
            result = leftNum * rightNum;
            break;
        }

        // 3. Update the expr
        expression->type = NUM;
        expression->value.num = result;
        expression->left = NULL;
        expression->right = NULL;
    }
    return;
}

double getNum(Expr *expression) { return expression->value.num; }
