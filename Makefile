PROGS  = calculator
CC     = gcc
CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage

.PHONY: all clean

all: $(PROGS)

$(PROGS): calculator.c calculator_parser.c expr.h expr_student.h
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(PROGS)
