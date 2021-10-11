//
// Created by Daniel Paiva Fernandes on 07/10/2021.
//
#include "main.h"

int main()
{
    auto *primeiraFila = new TipoFila;
    auto *segundaFila = new TipoFila;

    cout << "01. Criação da estrutura de dados vazia" << endl;
    criaFila(primeiraFila);
    criaFila(segundaFila);
    imprimeFila(primeiraFila);
    imprimeFila(segundaFila);

    cout << endl << "02. Inserir um novo dados imediatamente após o i-ésimo dados" << endl;
    int valoresPrimeiraFila[] = {54, 23, 657, 12, 45, 89, 5, 3};
    int valoresSegundaFila[] = {645, 78, 30, 64, 40, 1, 9, 34};
    for(int i: valoresPrimeiraFila) { inserir(primeiraFila, i);}
    for(int j: valoresSegundaFila) { inserir(segundaFila, j);}
    imprimeFila(primeiraFila);
    imprimeFila(segundaFila);

    cout << endl <<  "03. Retirar o inicio dados" << endl;
    remover(primeiraFila);
    remover(segundaFila);
    imprimeFila(primeiraFila);
    imprimeFila(segundaFila);

    cout << endl << "04. Retirar o i-ésimo dados" << endl;
    removerItemNaPosicao(primeiraFila, 4);
    removerItemNaPosicao(segundaFila, 2);
    imprimeFila(primeiraFila);
    imprimeFila(segundaFila);

    cout << endl <<  "05. Localizar um dados na Lista" << endl;
    alterarItem(primeiraFila, 2, 1);
    alterarItem(segundaFila, 3, 1);

    cout << endl << "06. Combinar duas ou mais estruturas em uma" << endl;
    auto *filaCombinada = new TipoFila;
    criaFila(filaCombinada);
    combinarFilas(segundaFila, primeiraFila);
    imprimeFila(filaCombinada);

    cout << endl << "07. Partir uma estrutura em duas ou mais" << endl;
    auto *novaFilaDividida = new TipoFila;
    criaFila(novaFilaDividida);
    dividirFila(filaCombinada, novaFilaDividida, 4);
    imprimeFila(filaCombinada);
    imprimeFila(novaFilaDividida);

    cout << endl << "08. Fazer uma cópia" << endl;
    auto *filaCopiada = new TipoFila;
    criaFila(filaCopiada);
    filaCopiada = copiarFila(novaFilaDividida);
    imprimeFila(filaCopiada);

    cout << endl << "09. Ordenar os itens da estrutura" << endl;
    ordenaFila(filaCombinada);
    imprimeFila(filaCombinada);

    cout << endl << "10. Buscar a ocorrência de um valor particular" << endl;
    inserir(filaCombinada, 1);
    imprimeFila(filaCombinada);
    buscarOcorrenciaDeValor(filaCombinada, 1);
}
