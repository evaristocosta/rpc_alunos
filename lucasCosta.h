/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _LUCASCOSTA_H_RPCGEN
#define _LUCASCOSTA_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct dadosAluno {
	int ra;
	double nota;
};
typedef struct dadosAluno dadosAluno;
#define CAPACIDADE 20

#define NOTASPROG 12345
#define NOTASVERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define ADICIONARALUNO 1
extern  int * adicionaraluno_1(dadosAluno *, CLIENT *);
extern  int * adicionaraluno_1_svc(dadosAluno *, struct svc_req *);
#define OBTERNOTA 2
extern  double * obternota_1(int *, CLIENT *);
extern  double * obternota_1_svc(int *, struct svc_req *);
#define ALTERARNOTA 3
extern  int * alterarnota_1(dadosAluno *, CLIENT *);
extern  int * alterarnota_1_svc(dadosAluno *, struct svc_req *);
#define CONTARAPROVADOS 4
extern  int * contaraprovados_1(void *, CLIENT *);
extern  int * contaraprovados_1_svc(void *, struct svc_req *);
#define MEDIADATURMA 5
extern  double * mediadaturma_1(void *, CLIENT *);
extern  double * mediadaturma_1_svc(void *, struct svc_req *);
extern int notasprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ADICIONARALUNO 1
extern  int * adicionaraluno_1();
extern  int * adicionaraluno_1_svc();
#define OBTERNOTA 2
extern  double * obternota_1();
extern  double * obternota_1_svc();
#define ALTERARNOTA 3
extern  int * alterarnota_1();
extern  int * alterarnota_1_svc();
#define CONTARAPROVADOS 4
extern  int * contaraprovados_1();
extern  int * contaraprovados_1_svc();
#define MEDIADATURMA 5
extern  double * mediadaturma_1();
extern  double * mediadaturma_1_svc();
extern int notasprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_dadosAluno (XDR *, dadosAluno*);

#else /* K&R C */
extern bool_t xdr_dadosAluno ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_LUCASCOSTA_H_RPCGEN */
