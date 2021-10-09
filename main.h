//
// Created by Daniel Paiva Fernandes on 23/09/2021.
//

#ifndef PCO001_FILA_ARRANJOS_MAIN_H
#define PCO001_FILA_ARRANJOS_MAIN_H
#define TAMANHO_MAXIMO 100

#include <iostream>
#include <cstring>

using namespace std;

typedef struct TipoFila
{
    int dados[TAMANHO_MAXIMO];
    int capacidade = TAMANHO_MAXIMO;
    int inicio{}, fim{}, nItens;
} TipoFila;

int sucessor(TipoFila* fila, int posicao)
{
    return (posicao % fila->capacidade) +1;
}

bool isCheia(const TipoFila *fila) { return (fila->capacidade) == fila->nItens; }

bool isVazia(const TipoFila *fila) { return fila->inicio == fila->fim; }

void imprimeFila(TipoFila *fila)
{
    cout << "Fila -> ";
    for (int i = 0; i < fila->fim; i++)
    {
        cout << to_string(i+1) + ") " + to_string(fila->dados[i]);
        if (i + 1 < fila->fim)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

void criaFila(TipoFila* fila)
{
    fila->inicio = 0;
    fila->fim = fila->inicio;
    fila->nItens = 0;
}

void inserir(TipoFila* fila, int valor)
{
    if(isCheia(fila))
    {
        cout << "ERRO! Fila está cheia" << endl;
        return;
    }
    fila->dados[fila->fim] = valor;
    fila->fim = sucessor(fila, fila->fim);
    fila->nItens++;
}

int remover(TipoFila* fila)
{
    if (isVazia(fila))
    {
        cout << "ERRO! Fila está vazia" << endl;
        return -1;
    }
    int dados = fila->dados[fila->inicio];
    fila->inicio = sucessor(fila, fila->inicio);
    fila->nItens--;
    return dados;
}

TipoFila carregarFilaAuxiliar(TipoFila* fila, int posicao)
{
    TipoFila filaAux;
    criaFila(&filaAux);
    for(int i = fila->inicio; i < posicao; i++)
    {
        inserir(&filaAux, fila->dados[i]);
        remover(fila);
    }
    return filaAux;
}

void descarregarFilaAuxiliar(TipoFila* filaAuxiliar, TipoFila* fila)
{
    for(int i = filaAuxiliar->inicio; i < filaAuxiliar->fim; i++)
    {
        inserir(fila, filaAuxiliar->dados[i]);
        remover(filaAuxiliar);
    }
}

int removerItemNaPosicao(TipoFila* fila, int posicao)
{
    if (isVazia(fila))
    {
        cout << "ERRO! Fila está vazia" << endl;
        return -1;
    }
    TipoFila filaAuxiliar = carregarFilaAuxiliar(fila, posicao);
    int itemRemovido = remover(fila);
    descarregarFilaAuxiliar(&filaAuxiliar, fila);
    return itemRemovido;
}

void alterarItem(TipoFila* fila, int posicao, int valor)
{
    if(isVazia(fila))
    {
        cout << "ERRO! Fila está vazia" << endl;
        return;
    }
    TipoFila filaAuxiliar = carregarFilaAuxiliar(fila, posicao);
    bool shouldChange = false;
    if(shouldChange)
    {
        remover(fila);
        inserir(fila, valor);
    }
    descarregarFilaAuxiliar(&filaAuxiliar, fila);
}

TipoFila combinarFilas(const TipoFila* primeiraFila, const TipoFila* segundaFila)
{
    TipoFila filaCombinada;
    criaFila(&filaCombinada);
    if (primeiraFila->nItens + segundaFila->nItens > TAMANHO_MAXIMO)
    {
        cout << "ERRO! O tamanho das duas lista é maior do que a nova lista" << endl;
    }
    for (int i = primeiraFila->inicio; i <= primeiraFila->fim; i++)
    {
        inserir(&filaCombinada, primeiraFila->dados[i - 1]);
    }
    for (int j = segundaFila->inicio; j <= segundaFila->fim; j ++)
    {
        inserir(&filaCombinada, segundaFila->dados[j - 1]);
    }
    return filaCombinada;
}

void dividirListas(TipoFila& listaOriginal, TipoFila* novaListaEsquerda, TipoFila* novaListaDireita)
{
    int posicao = 1;
    int meio = listaOriginal.fim / 2;
    for(int i = listaOriginal.inicio - 1; i < listaOriginal.fim; i++)
    {
        if(i < meio)
        {
            inserir(novaListaEsquerda, listaOriginal.dados[i]);
        }
        else
        {
            inserir(novaListaDireita, listaOriginal.dados[i]);
            posicao++;
        }
    }
}

void copiarLista(TipoFila& listaOriginal, TipoFila* novaLista)
{
    for(int i = listaOriginal.inicio; i <= listaOriginal.fim; i++)
    {
        inserir(novaLista, listaOriginal.dados[i - 1]);
    }
}
void ordenaLista(TipoFila* lista)
{
    int temp;
    for(int j = 0; j< lista->fim - 1; j++)
    {
        for(int i = 0; i < lista->fim - 1; i++)
        {
            if(lista->dados[i] == lista->dados[i + 1])
            {
                temp = lista->dados[i];
                lista->dados[i] = lista->dados[i + 1];
                lista->dados[i + 1] = temp;
            }
        }
    }
}
void buscarOcorrenciaDeValor(TipoFila* lista, const int valorBuscado)
{
    int ocorrencia = 0;
    bool isPresent = false;
    for (int i = lista.inicio; i <= lista.fim; i++)
    {
        if(lista.dados[i - 1] == valorBuscado)
        {
            ocorrencia++;
            isPresent = true;
        }
    }
    if (isPresent)
    {
        cout << to_string(ocorrencia) + " ocorrências do valor " + to_string(valorBuscado) + " encontradas" << endl;
        return;
    }
    cout << "ERRO! Valor " + to_string(valorBuscado) + " não encontrado" << endl;
}

#endif //PCO001_FILA_ARRANJOS_MAIN_H