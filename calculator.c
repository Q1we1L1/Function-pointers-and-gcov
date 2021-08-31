/*
 * calculator.c
 * Author:Qiwei Li
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expr.h"
#include "expr_student.h"

/* Eval given Expr instance */
float evalExpr(Expr *expr)
{
	float val;
	float lhs, rhs;

	if (!expr)
		return 0;

	lhs = evalExpr(expr->left);
	rhs = evalExpr(expr->right);

	/* Leaf node */
	if (!expr->left && !expr->right)
		val = expr->eval(lhs, rhs, expr->floatVal);
	else {	/* Non-leaf node, i.e., Op node */
		val = expr->eval(lhs, rhs, 0);
		printf("%s = %f\n", expr->origText, val);
	}

	return val;
}

/* Free given Expr instance */
void freeExpr(Expr *expr)
{
	if (!expr)
		return;

	/* Free child exprs if any */
	freeExpr(expr->left);
	freeExpr(expr->right);

	/* Free origText and expr itself */
	free(expr->origText);
	free(expr);
}

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	Expr *expr;

	while (1) {
		/* Prompt and getline */
		printf("> ");
		if (getline(&line, &len, stdin) < 0)
			break;

		/* Remove trailing newline */
		line[strcspn(line, "\n")] = 0;

		/* Parse line into expr */
		expr = parseExpr(line);

		/* Eval the expr */
		if (!expr)
			printf("Could not parse the expression: %s\n", line);
		else
			printf("%f\n", evalExpr(expr));

		/* Free the expr */
		freeExpr(expr);
	}

	if (line)
		free(line);
	return 0;
}
