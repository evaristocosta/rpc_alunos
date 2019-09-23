#include <rpc/rpc.h>
#include "lucasCosta.h"

static dadosAluno alunos[CAPACIDADE];
int posicao = 0;

int *
adicionaraluno_1_svc(dadosAluno *argp, struct svc_req *rqstp) {
	static int  result;

	for (size_t i = 0; i < CAPACIDADE; i++) {
		if (alunos[i].ra == argp->ra) {
			result = 0;
			return &result;
		}
	}
	alunos[posicao].ra = argp->ra;
	alunos[posicao].nota = argp->nota;
	posicao++;

	result = 1;
	return &result;
}

double *
obternota_1_svc(int *argp, struct svc_req *rqstp) {
	static double  result;

	for (size_t i = 0; i < CAPACIDADE; i++)	{
		if (alunos[i].ra == *argp) {
			result = alunos[i].nota;
			return &result;
		} 
	}
	
	result = -1;
	return &result;
}

int *
alterarnota_1_svc(dadosAluno *argp, struct svc_req *rqstp) {
	static int  result;

	for (size_t i = 0; i < CAPACIDADE; i++)	{
		if (alunos[i].ra == argp->ra) {
			alunos[i].nota = argp->nota;
			result = 1;
			return &result;
		}
	}
	
	result = 0;
	return &result;
}

int *
contaraprovados_1_svc(void *argp, struct svc_req *rqstp) {
	static int  result;
	result = 0;

	for (size_t i = 0; i < CAPACIDADE; i++)	{
		if (alunos[i].nota >= 6.0) {
			result++;
		}
	}
	
	return &result;
}

double *
mediadaturma_1_svc(void *argp, struct svc_req *rqstp) {
	static double  result;
	result = 0.0;

	for (size_t i = 0; i < posicao; i++)	{
		result += alunos[i].nota;
	}
	result /= posicao;

	return &result;
}
