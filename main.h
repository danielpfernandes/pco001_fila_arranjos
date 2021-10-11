//
// Created by Daniel Paiva Fernandes on 23/09/2021.
//

#ifndef PCO001_FILA_ARRANJOS_MAIN_H
#define PCO001_FILA_ARRANJOS_MAIN_H
#define TAMANHO_MAXIMO 100

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct TipoFila
{
    int dados[TAMANHO_MAXIMO]{};
    int capacidade = TAMANHO_MAXIMO;
    int inicio{}, fim{}, nItens{};
} TipoFila;

int sucessor(TipoFila* fila, int posicao)
{
    return (posicao % fila->capacidade) +1;
}

bool isCheia(const TipoFila *fila) { return (fila->capacidade) == fila->nItens; }

bool isVazia(const TipoFila *fila) { return fila->inicio == fila->fim; }

void imprimeFila(TipoFila *fila)
{
    int dados;
    cout << "Fila -> ";
    for (int i = fila->inicio; i < fila->fim; i++)
    {
        dados = fila->dados[i];
        cout << std::to_string(dados);
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
    fila->dados[fila->inicio] = 0;
    fila->inicio = sucessor(fila, fila->inicio);
    fila->nItens--;
    return dados;
}

TipoFila carregarFilaAuxiliarParaRemover(TipoFila* fila, int posicao)
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
    fila->inicio = fila->inicio - filaAuxiliar->nItens;
    for(int i = filaAuxiliar->inicio; i < filaAuxiliar->fim; i++)
    {
        fila->dados[fila->inicio+i] = filaAuxiliar->dados[i];
        fila->nItens++;
    }
    for(int j = filaAuxiliar->fim; j < fila->fim; j++)
    {
        fila->dados[j+1] = fila->dados[j+2];
    }
    fila->fim--;
    fila->nItens--;
}

int removerItemNaPosicao(TipoFila* fila, int posicao)
{
    if (isVazia(fila))
    {
        cout << "ERRO! Fila está vazia" << endl;
        return -1;
    }
    int itemRemovido = fila->dados[fila->inicio+posicao-1];
    TipoFila filaAuxiliar = carregarFilaAuxiliarParaRemover(fila, posicao);
    descarregarFilaAuxiliar(&filaAuxiliar, fila);
    return itemRemovido;
}

void alterarItem(TipoFila* fila, int posicao)
{
    if(isVazia(fila))
    {
        cout << "ERRO! Fila está vazia" << endl;
        return;
    }
    cout << "Valor " + to_string(fila->dados[fila->inicio+posicao])
        + " encontrado na posição " + to_string(posicao) << endl
        << "Gostaria de altera? (s/n)";

    string shouldChange = "n";
    cin >> shouldChange;
    if(shouldChange == "s")
    {
        int valor;
        cout << "Insira o valor: ";
        cin >> valor;
        fila->dados[fila->inicio+posicao] = valor;
    }
}

void combinarFilas(const TipoFila* primeiraFila, const TipoFila* segundaFila, TipoFila* filaCombinada)
{
    if (primeiraFila->nItens + segundaFila->nItens > TAMANHO_MAXIMO)
    {
        cout << "ERRO! O tamanho das duas lista é maior do que a nova lista" << endl;
    }
    for (int i = primeiraFila->inicio; i < primeiraFila->fim; i++)
    {
        inserir(filaCombinada, primeiraFila->dados[i]);
    }
    for (int j = segundaFila->inicio; j < segundaFila->fim; j ++)
    {
        inserir(filaCombinada, segundaFila->dados[j]);
    }
}

void dividirFila(TipoFila* filaOriginal, TipoFila* novaPrimeiraFila, TipoFila* novaSegundaFila, int posicao)
{
    for(int i = 0; i < filaOriginal->nItens; i++)
    {
        if(i < posicao)
        {
            inserir(novaPrimeiraFila, filaOriginal->dados[i]);
        }
        else
        {
            inserir(novaSegundaFila,filaOriginal->dados[i]);
            posicao++;
        }
    }
}

void copiarFila(TipoFila* filaOriginal, TipoFila* filaCopiada)
{
    for(int i = filaOriginal->inicio; i < filaOriginal->fim; i++)
    {
        inserir(filaCopiada, filaOriginal->dados[i]);
    }
}

void ordenaFila(TipoFila* fila)
{
    vector<int> temp;
    temp.reserve(fila->fim);
for(int i = 0; i < fila->fim; i++)
    {
        temp.push_back(fila->dados[i]);
    }
    std::sort(temp.begin(), temp.end());
    criaFila(fila);
    for(int value: temp)
    {
        inserir(fila, value);
    }
}
void buscarOcorrenciaDeValor(TipoFila* lista, const int valorBuscado)
{
    int ocorrencia = 0;
    bool isPresent = false;
    for (int i = lista->inicio; i <= lista->fim; i++)
    {
        if(lista->dados[i - 1] == valorBuscado)
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