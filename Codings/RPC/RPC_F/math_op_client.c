#include "math_op.h"
#include <stdio.h>
#include <stdlib.h>

void math_prog_1(char *host, int x) {
    CLIENT *clnt;
    int *result_1;
    numbers square_1_arg;
    float *result_2;
    numbers sqrt_1_arg;
    int *result_3;
    numbers factorial_1_arg;

#ifndef	DEBUG
    clnt = clnt_create(host, MATH_PROG, MATH_VERSION, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }
#endif	/* DEBUG */

    // Calculate the square
    square_1_arg.a = x;
    result_1 = square_1(&square_1_arg, clnt);

    if (result_1 == (int *) NULL) {
        clnt_perror(clnt, "call failed");
    } else {
        printf("Square: %d\n", *result_1);
    }

    // Calculate the square root
    sqrt_1_arg.a = x;
    result_2 = sqrt_1(&sqrt_1_arg, clnt);
    if (result_2 == (float *) NULL) {
        clnt_perror(clnt, "call failed");
    } else {
        printf("Square Root: %f\n", *result_2);
    }

    // Calculate the factorial
    factorial_1_arg.a = x;
    result_3 = factorial_1(&factorial_1_arg, clnt);
    if (result_3 == (int *) NULL) {
        clnt_perror(clnt, "call failed");
    } else {
        printf("Factorial: %d\n", *result_3);
    }

#ifndef	DEBUG
    clnt_destroy(clnt);
#endif	 /* DEBUG */
}

int main(int argc, char *argv[]) {
    char *host;

    if (argc < 3) {
        printf("usage: %s server_host number\n", argv[0]);
        exit(1);
    }
    host = argv[1];
    math_prog_1(host, atoi(argv[2]));
    exit(0);
}

