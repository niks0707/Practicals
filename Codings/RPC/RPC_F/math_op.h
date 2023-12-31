/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _MATH_OP_H_RPCGEN
#define _MATH_OP_H_RPCGEN

#include <rpc/rpc.h>
#include <stdio.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif


struct numbers {
	int a;
};
typedef struct numbers numbers;

#define MATH_PROG 0x20000001
#define MATH_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define SQUARE 1
extern  int * square_1(numbers *, CLIENT *);
extern  int * square_1_svc(numbers *, struct svc_req *);
#define SQRT 2
extern  float * sqrt_1(numbers *, CLIENT *);
extern  float * sqrt_1_svc(numbers *, struct svc_req *);
#define FACTORIAL 3
extern  int * factorial_1(numbers *, CLIENT *);
extern  int * factorial_1_svc(numbers *, struct svc_req *);
extern int math_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define SQUARE 1
extern  int * square_1();
extern  int * square_1_svc();
#define SQRT 2
extern  float * sqrt_1();
extern  float * sqrt_1_svc();
#define FACTORIAL 3
extern  int * factorial_1();
extern  int * factorial_1_svc();
extern int math_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_numbers (XDR *, numbers*);

#else /* K&R C */
extern bool_t xdr_numbers ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_MATH_OP_H_RPCGEN */
