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

    cout << endl <<  "05. Localizar dados na Lista" << endl;
    alterarItem(primeiraFila, 2);
    alterarItem(segundaFila, 3);

    cout << endl << "06. Combinar duas ou mais estruturas em uma" << endl;
    auto* filaCombinada = new TipoFila;
    criaFila(filaCombinada);
    combinarFilas(segundaFila, primeiraFila, filaCombinada);
    imprimeFila(filaCombinada);

    cout << endl << "07. Partir uma estrutura em duas ou mais" << endl;
    auto *novaPrimeiraFila = new TipoFila;
    auto *novaSegundaFila = new TipoFila;
    criaFila(novaPrimeiraFila);
    criaFila(novaSegundaFila);
    dividirFila(filaCombinada, novaPrimeiraFila, novaSegundaFila, 4);
    imprimeFila(novaPrimeiraFila);
    imprimeFila(novaSegundaFila);

    cout << endl << "08. Fazer uma cópia" << endl;
    auto *filaCopiada = new TipoFila;
    criaFila(filaCopiada);
    copiarFila(novaPrimeiraFila, filaCopiada);
    imprimeFila(filaCopiada);

    cout << endl << "09. Ordenar os itens da estrutura" << endl;
    ordenaFila(filaCombinada);
    imprimeFila(filaCombinada);

    cout << endl << "10. Buscar a ocorrência de um valor particular" << endl;
    inserir(filaCombinada, 23);
    imprimeFila(filaCombinada);
    buscarOcorrenciaDeValor(filaCombinada, 23);
}
