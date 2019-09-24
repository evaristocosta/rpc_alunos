#include <rpc/rpc.h>
#include "lucasCosta.h"

CLIENT *handle;

int main(int argc, char *argv[]) {
    handle = clnt_create("localhost", NOTASPROG, NOTASVERSION, "tcp");
    if (handle == 0) {
		printf("Não pode conectar programa remoto\n");
		exit(1);
	}

    // variaveis de retorno
    int *Iretorno;
    double *Dretorno;

    // entrutura de envio
    dadosAluno aluno;
    int opcao;

    do {
		printf("Digite:\n");
		printf("1 - Para adicionar um aluno\n");
		printf("2 - Para obter a nota de um aluno\n");
		printf("3 - Para alterar uma nota\n");
		printf("4 - Para contar os aprovados\n");
		printf("5 - Para obter a media da turma\n");
		printf("9 - Para sair\n\n");

		printf("Opcao: ");
		scanf("%d", &opcao);

        // casos que precisam do ra
        if (opcao == 1 || opcao == 2 || opcao == 3) {
            printf("Digite o RA: ");
			scanf("%d", &(aluno.ra));
        } // casos que precisam de nota
        if(opcao == 1 || opcao == 3) {
            printf("Digite a nota: ");
			scanf("%lf", &(aluno.nota));
        }
        
        switch(opcao) {
            case 1:
                Iretorno = adicionaraluno_1(&aluno, handle);
                if(*Iretorno == 1) {
                    printf("\n--------\nAdicao realizada com sucesso!\n\n");
                } else {
                    printf("\n--------\nEste aluno ja foi adicionado anteriormente.\n\n");
                }
                break;
            case 2:
                Dretorno = obternota_1(&aluno.ra, handle);
                if (*Dretorno == -1) {
                    printf("\n--------\nAluno nao existe!\n\n");
                } else {
                    printf("\n--------\nNota do aluno: %lf\n\n", *Dretorno);
                }
                break;
            case 3:
                Iretorno = alterarnota_1(&aluno, handle);
                if(*Iretorno == 1) {
                    printf("\n--------\nNota alterada com sucesso!\n\n");
                } else {
                    printf("\n--------\nAluno nao encontrado!\n\n");
                }
                break;
            case 4:
                Iretorno = contaraprovados_1(&aluno, handle);
                printf("\n--------\nTotal de aprovados: %d\n\n", *Iretorno);
                break;
            case 5:
                Dretorno = mediadaturma_1(&aluno, handle);
                printf("\n--------\nMedia da turma: %lf\n\n", *Dretorno);
                break;
            case 9:
                printf("Saindo...\n\n");
                break;
            default:
				printf("Errou... Digite operação valida\n\n");
        }

    } while (opcao != 9);
}