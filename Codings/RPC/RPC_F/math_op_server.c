/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <math.h>
#include "math_op.h"

int *
square_1_svc(numbers *argp, struct svc_req *rqstp)
{
	static int  result;

	 result = (argp->a * argp->a);

	return &result;
}

float *
sqrt_1_svc(numbers *argp, struct svc_req *rqstp)
{
	 
	static float result;
    result =(float)(argp->a);
    float i = 0.0;
    
    while(TRUE){
        if(result == i*i){ 
        result = i;
        break;
        } else {
            i++;
        }
    }
    
    
    return &result;
}

int *
factorial_1_svc(numbers *argp, struct svc_req *rqstp)
{
	static int result = 1;
    int n = argp->a;
    while (n > 0) {
        result *= n;
        n--;
    }
    return &result;
}
