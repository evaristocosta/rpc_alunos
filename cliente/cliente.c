#include <rpc/rpc.h>
#include "lucasCosta.h"

CLIENT *handle;

int main(int argc, char *argv[]) {
    handle = clnt_create("localhost", NOTASPROG, NOTASVERSION, "tcp");
    if (handle == 0) {
		printf("Não pode conectar programa remoto\n");
		exit(1);
	}

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

        switch(opcao) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
				printf("Errou... Digite operação valida\n\n");
        }

    } while (opcao != 9);
}