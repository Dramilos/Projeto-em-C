#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

typedef struct elo          // estrutura dos dados que v�o pra lista
{

    int codSol;         // informacao que sera guardada na lista]
    char codEqu[6];
    char nomeEqu[20];
    int periodo;
    int prioridade;

    struct elo *proximo;    // ponteiro que aponta para o proximo elo da lista

} Elo;

typedef struct lista        // estrutura que percorre a lista
{

    Elo *inicio;            // ponteiro que aponta somente pro comeco da lista

} Lista;

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Lista* IniciaLista()        // estrutura que inicia a lista
{

    return NULL;

}

Lista* CriaUmaLista()       // estrutura que cria uma lista qualquer
{

    Lista *aux;
    aux = (Lista *) malloc(sizeof(Lista));
    aux ->inicio = NULL;

    return aux;

}

Elo* CriarElo(Elo* Antigo, int codSol, char codEqu[], int prioridade, char nomeEqu[])
{
    Elo *NovoElo;
    NovoElo = (Elo *) malloc(sizeof(Elo));

    // passando as informaçoes pro novo elo

    NovoElo ->codSol = codSol;

    for(int i = 0; codEqu[i] != '\0'; i++)
    {
        NovoElo ->codEqu[i] = codEqu[i];
    }

    NovoElo ->prioridade = prioridade;

    for(int i = 0; nomeEqu[i] != '\0'; i++)
    {
        NovoElo ->nomeEqu[i] = nomeEqu[i];
    }

    NovoElo ->proximo = Antigo;

    return NovoElo;
}

/*
Elo* CriarEloFinal(Lista* Antigo, int v)
{
    Elo *NovoElo;
    NovoElo = (Elo *) malloc(sizeof(Elo));

    NovoElo ->informacao = ;
    NovoElo ->proximo = NULL;

    return NovoElo;
}
*/

void InsereNaLista(Lista *EloAntigo, int codSol, char codEqu[], int prioridade, char nomeEqu[])
{
    EloAntigo ->inicio = CriarElo(EloAntigo ->inicio, codSol, codEqu, prioridade, nomeEqu);
}

/*
void InsereNoFim(Lista *cartelinha, int ValorInserido)
{
    Elo *aux = cartelinha ->inicio;

    while(aux ->proximo != NULL)
    {
        aux = aux ->proximo;
    }

    aux ->proximo = CriarEloFinal(cartelinha, ValorInserido);
}

*/

void ImprimeLista(Lista *manutencaozinha)
{
    Elo *aux = manutencaozinha ->inicio;

    while (aux != NULL)
    {
        printf("\n -%s", aux ->nomeEqu);
        aux = aux ->proximo;
    }
}

/*

Elo* AuxTiraDaLista(Elo *antigo)
{
    Elo *apagar;

    apagar = antigo;
    antigo = antigo ->proximo;
    free(apagar);

    return antigo;
}

int TiraDaLista(Lista *listaAntiga)
{
    int valor;

    valor = listaAntiga ->inicio ->informacao;
    listaAntiga ->inicio = AuxTiraDaLista(listaAntiga ->inicio);

    return valor;
}

void LimparLista(Lista *apague)
{
    int valor;

    while (apague ->inicio != NULL)
    {
        valor = apague ->inicio ->informacao;
        apague ->inicio = AuxTiraDaLista(apague ->inicio);

        printf("REMOVIDO: %i\n", valor);
    }
}

int ProcuraElemento(Lista *cartelinha, int valor)
{
    Elo *aux = cartelinha ->inicio;

    while(aux != NULL)
    {
        if(aux ->informacao == valor)
        {
            printf("\nAchamo o valor");
            return 1;
        }
        aux = aux ->proximo;
    }
    printf("\nValor nao encontrado");
    return 0;
}

bool TaVazia(Lista *cartelinha)
{
    if (cartelinha ->inicio == NULL)
    {
        return true;
    }

    return false;
}

int Quantidade (Lista *cartelinha)
{
    int cont = 0;
    Elo *aux = cartelinha ->inicio;

    while (aux != NULL)
    {
        cont++;
        aux = aux ->proximo;
    }

    return cont;
}

int Soma(Lista *cartelinha)
{
    int sum = 0;
    Elo *aux = cartelinha ->inicio;

    while(aux != NULL)
    {
        sum += aux->informacao;
        aux = aux ->proximo;
    }

    return sum;
}
*/
#endif      // FUNCS_H_INCLUDED
