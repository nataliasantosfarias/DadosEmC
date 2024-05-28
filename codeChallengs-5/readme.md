# Tarefa 05 

# Instruções
Escolha um dos algoritmos estudados hoje, e o implemente para ordenar o array de alunos que utilizamos e está persistido no arquivo do último exercício.

* O sistema deverá ler o arquivo;
* Preencher um array de structs;
* E ordenar ele por ordem alfabética.

Obrigatoriamente deveremos usar o cabeçalho string.h e sua função de comparação (strcmp()).

Para lembrar como utilizar o strcmp(): https://br-c.org/doku.php?id=strcmp


Os códigos dos algoritmos de ordenação estão em: https://github.com/yurifarod/Algorithms/tree/master/Estrutura%20de%20Dados


A base de dados está em: https://github.com/yurifarod/Algorithms/blob/master/Estrutura%20de%20Dados/database_alunos.txt



Prazo :
17 de maio de 2024 às 23:59


# tarefa 6

Construa um programa que faça a gerência de uma escola, utilizando sructs.
Ele deverá :
* conter o registro de alunos, contendo matricula (inteiro), nome (string), curso (string), endereço (string), ativo (bool);
* Funções (definidas no código) deverão ser chamadas no menu do programa;
* Cadastrar aluno (cria um novo aluno e aloca no array de registros;
* Remover aluno (marca F na variável ativa do aluno);
* Alterar curso (entra como parâmetro a matricula do aluno e o array de alunos para alterar o seu curso);
* Alterar endereço (entra como parâmetro a matricula do aluno e o array de alunos para alterar o seu endereço);
* Relatório de alunos (imprime, de maneira formatada, todos os alunos ATIVOS e seus dados;
* O menu não precisará de interface gráfica, podemos usar uma mensage de texto que peça um número para cada uma das possiblidades ( 1 – Cadastrar, 2 – Remover, 3 – Relatório, etc);
* Número 0 é digitado para sair do programa;
* Um número que seja digitado e não esteja no menu deverá imprimir  a mensagem “Opção Inválida” e chamar o menu novamente;
* Após cada operação, até que seja chamada a opção 0 (sair) o Menu deverá ser impresso novamente.


Material utilizado como referência:

A base de dados está em: https://github.com/yurifarod/Algorithms/tree/master/Estrutura%20de%20Dados


