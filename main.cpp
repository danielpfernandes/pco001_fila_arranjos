//
// Created by Daniel Paiva Fernandes on 07/10/2021.
//
#include "main.h"

int main()
{
    auto *primeiraLista = new TipoFila;
    auto *segundaLista = new TipoFila;

    cout << "01. Criação da estrutura de dados vazia" << endl;
    criaFila(primeiraLista);
    criaFila(segundaLista);
    imprimeFila(primeiraLista);
    imprimeFila(segundaLista);

    cout << endl << "02. Inserir um novo dados imediatamente após o i-ésimo dados" << endl;
    inserir(primeiraLista, 11);
    inserir(segundaLista, 21);
    imprimeFila(primeiraLista);
    imprimeFila(segundaLista);

    cout << endl <<  "03. Retirar o inicio dados" << endl;
    remover(primeiraLista);
    remover(segundaLista);
    imprimeFila(primeiraLista);
    imprimeFila(segundaLista);

    cout << endl << "04. Retirar o i-ésimo dados" << endl;
    removerItemNaPosicao(primeiraLista, 2);
    removerItemNaPosicao(segundaLista, 2);
    imprimeFila(primeiraLista);
    imprimeFila(segundaLista);

    cout << endl <<  "05. Localizar um dados na Lista" << endl;
    alterarItem(primeiraLista, 2, 1);
    alterarItem(segundaLista, 3, 1);

    cout << endl << "06. Combinar duas ou mais estruturas em uma" << endl;
    auto *novaLista = new TipoFila;
    criaFila(novaLista);
    combinarFilas(segundaLista, primeiraLista);
    imprimeFila(novaLista);

    cout << endl << "07. Partir uma estrutura em duas ou mais" << endl;
    auto *novaListaEsquerda = new TipoFila;
    auto *novaListaDireita = new TipoFila;
    criaFila(novaListaEsquerda);
    criaFila(novaListaDireita);
    dividirListas(*novaLista, novaListaEsquerda, novaListaDireita);
    imprimeFila(novaListaEsquerda);
    imprimeFila(novaListaDireita);

    cout << endl << "08. Fazer uma cópia" << endl;
    auto *listaCopiada = new TipoFila;
    criaFila(listaCopiada);
    copiarLista(*novaListaEsquerda, listaCopiada);
    imprimeFila(listaCopiada);

    cout << endl << "09. Ordenar os itens da estrutura" << endl;
    ordenaLista(novaLista);
    imprimeFila(novaLista);

    cout << endl << "10. Buscar a ocorrência de um valor particular" << endl;
    inserir(novaLista, 1);
    imprimeFila(novaLista);
    buscarOcorrenciaDeValor(novaLista, 1);
}
