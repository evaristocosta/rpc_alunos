#include <stdio.h>

struct dadosAluno {
	int ra;
	double nota;
};

int posicao = 0;

int main() {
	struct dadosAluno alunos[20];
	printf("%d", alunos[posicao].ra);
}