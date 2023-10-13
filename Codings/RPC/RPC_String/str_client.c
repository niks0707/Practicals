#include "str.h"


void
add_prog_1(char *host , char* x ,char* y)
{
	CLIENT *clnt;
	bool_t  *result_1;
	strings  add_1_arg;
	int  *result_2;
	strings  count_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ADD_PROG, ADD_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	add_1_arg.str1=x;
	add_1_arg.str2=y;
	result_1 = add_1(&add_1_arg, clnt);
	if (result_1 == (bool_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("Result:%d\n",*result_1);
	}
	count_1_arg.str1 =x;
	count_1_arg.str2=y;
	result_2 = count_1(&count_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("Result:%d\n",*result_2);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	add_prog_1 (host,(argv[2]),(argv[3]));
exit (0);

}
