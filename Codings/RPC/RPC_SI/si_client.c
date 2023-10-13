/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "si.h"


void
add_prog_1(char *host, int p, int r, int t)
{
	CLIENT *clnt;
	int  *result_1;
	numbers  simple_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ADD_PROG, ADD_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
    simple_1_arg.a=p;
    simple_1_arg.b=r;
    simple_1_arg.c=t;
    
	result_1 = simple_1(&simple_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	} else {
	    printf("Simple Intrest: %d\n",*result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 5) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	add_prog_1 (host,atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
exit (0);
}