# Aplicação Simples com RPC

O sistema implementado consiste de um manipulador de notas, conforme especificações abaixo:

O sistema armazena os dados em uma estrutura que contém os seguintes campos:

- ra: um valor inteiro, responsável por armazenar a identificação do estudante;
- nota: um valor de ponto flutuante (double), para armazenar a nota do aluno na disciplina;

A estrutura foi nomeada como dadosAluno. O programa foi nomeado como NOTASPROG, com número 12345, e a versão foi definida como NOTASVERSION, com número 1. O programa contém os seguintes métodos:

- int ADICIONARALUNO – recebe os dados de um aluno, e o adiciona na estrutura de armazenamento do servidor. Antes de adicionar, verifica se o RA do aluno não consta na estrutura de armazenamento. Caso já exista, retorna 0. Caso não exista, adiciona e retorna 1.
- double OBTERNOTA – recebe apenas o RA do aluno, e o busca na estrutura de armazenamento. Caso o aluno exista na estrutura, retorne sua nota. Caso contrário, retorna -1 como condição de erro.
- int ALTERARNOTA – recebe os dados de um aluno. Com o campo de RA, busca o aluno na estrutura de armazenamento. Se o aluno não existir, retorna 0. Caso exista, altera a nota e retorna 1.
- int CONTARAPROVADOS – não recebe nenhum parâmetro, e conta quantos estudantes foram aprovados na disciplina. Média para aprovação é 6,0.
- double MEDIADATURMA – não recebe nenhum parâmetro, e calcula a média da turma. Caso não exista nenhum aluno na turma, a média é zero.

O arquivo foi salvo como lucasCosta.x.

A estrutura de armazenamento no servidor foi criada no arquivo de implementação dos procedimentos, como uma variável static, sendo um vetor de 20 posições de dadosAluno. O nome dessa estrutura não influenciará as implementações remotas.

O programa cliente oferece um menu para acessar os métodos.