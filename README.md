# EP 01 Sistemas Lineares

## Como executar

Para compilar o programa:

```bash
make
```

Para executar o script:

```bash
bash ./script.sh arquivo CPU
```
* arquivo: arquivo onde está localizado os sistemas lineares.
* CPU: número de CPUs. 

## Algumas decisões tomadas
* O sistema linear da entrada do programa é armazenado em uma matriz dos coeficientes = A, vetor do termos independentes = b e a solução do sistema no vetor das incógnitas = x. Quando o programa termina de executar a Eliminação de Gauss clássica e Gauss Seidel clássico, a matriz dos coeficientes é copiada para três vetores d, a e c e são realizadas as operações específicas para matrizes tri-diagonais.

* Para conseguir imprimir os MFLOP/s do LIKWID o programa é executado duas vezes, na primeira execução do programa não é utlizado o LIKWID, já na segunda vez o programa utilizada os marcadores do LIKWID e a saída é impresa com grep para somente mostrar a tabela DP MFLOP/s.

* Para executar o script é necessário informar um arquivo e o número de CPUs desejados.

## Arquivos
* perfSL: programa main.
* gauss.c: funções para realização da eliminação de gauss clássica e eliminação de gauss tridiagonal.
* gaussSeidel.c: funções para realização do gauss seidel clássico e gauss clássico tridiagonal.
* sistLin.c: funções para manipulação dos vetores e das matrizes.
* utils.c: funções para cálculo do tempo.