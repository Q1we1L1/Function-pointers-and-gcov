/*
 * expr_student.h
 * Author:Qiwei Li
 */

#ifndef __EXPR_STUDENT_H__
#define __EXPR_STUDENT_H__

#include "expr.h"

/* Export parseExpr */
Expr *parseExpr(char *in);

/* Free given Expr instance */
void freeExpr(Expr *expr);

#endif /* __EXPR_STUDENT_H__ */
