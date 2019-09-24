#include <rpc/rpc.h>
#include "lucasCosta.h"

// estrutura de armazenamento
static dadosAluno alunos[CAPACIDADE];
int posicao = 0;

// funcao de adicao
int *
adicionaraluno_1_svc(dadosAluno *argp, struct svc_req *rqstp) {
	static int  resultado;

	// posicao == 0 significa que ainda nao existem alunos
	if(posicao != 0) {
		// se aluno existe, nao adiciona
		for (size_t i = 0; i < posicao; i++) {
			if (alunos[i].ra == argp->ra) {
				resultado = 0;
				return &resultado;
			}
		}
	}
	// adicao do aluno por partes
	alunos[posicao].ra = argp->ra;
	alunos[posicao].nota = argp->nota;
	// atualizacao da quantidade de alunos inseridos
	posicao++;

	resultado = 1;
	return &resultado;
}

// funcao de pesquisa
double *
obternota_1_svc(int *argp, struct svc_req *rqstp) {
	static double  resultado;

	// procura na estrutura aluno com ra desejado
	for (size_t i = 0; i < posicao; i++)	{
		if (alunos[i].ra == *argp) {
			resultado = alunos[i].nota;
			return &resultado;
		} 
	}
	
	// no caso de nao encontrar,
	resultado = -1;
	return &resultado;
}

// funcao de edicao
int *
alterarnota_1_svc(dadosAluno *argp, struct svc_req *rqstp) {
	static int  resultado;

	// procura aluno por ra
	for (size_t i = 0; i < posicao; i++)	{
		if (alunos[i].ra == argp->ra) {
			// altera a nota, no caso de encontrar
			alunos[i].nota = argp->nota;
			resultado = 1;
			return &resultado;
		}
	}
	
	resultado = 0;
	return &resultado;
}

// funcao de contagem
int *
contaraprovados_1_svc(void *argp, struct svc_req *rqstp) {
	static int  resultado;
	resultado = 0;

	for (size_t i = 0; i < posicao; i++)	{
		// considera-se aprovado aluno com nota maior que 60, nao 6
		if (alunos[i].nota >= 60.0) {
			resultado++;
		}
	}
	return &resultado;
}

// funcao de calculo de media
double *
mediadaturma_1_svc(void *argp, struct svc_req *rqstp) {
	static double  resultado;
	resultado = 0.0;

	// para evitar divisao por zero, verifica antes se existem alunos na estrutura
	if (posicao == 0) {
		return &resultado;
	}
	
	for (size_t i = 0; i < posicao; i++)	{
		resultado += alunos[i].nota;
	}
	// faz a media
	resultado /= posicao;

	return &resultado;
}
