struct dadosAluno {
	int ra;
	double nota;
};

const CAPACIDADE = 20;

program NOTASPROG {
    version NOTASVERSION {
        int ADICIONARALUNO(dadosAluno) = 1;
        double OBTERNOTA(int) = 2;
        int ALTERARNOTA(dadosAluno) = 3;
        int CONTARAPROVADOS(void) = 4;
        double MEDIADATURMA(void) = 5;
    } = 1;
} = 12345;