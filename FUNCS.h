#ifndef FUNCS_H_INCLUDED
#define FUNCS_H_INCLUDED

typedef struct elo          // estrutura dos dados que v�o pra lista
{

    int codSol;         // informacao que sera guardada na lista]
    char codEqu[7];
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

int TaVazia(Lista *manutencao)
{
    if (manutencao ->inicio == NULL)
    {
        return 1;
    }

    return 0;
}

Elo* CriarElo(Elo* Antigo, int codSol, char codEqu[], int prioridade, char nomeEqu[], int periodo)
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

    NovoElo ->periodo = periodo;

    NovoElo ->proximo = Antigo;

    return NovoElo;
}

void InsereNaLista(Lista *manutencao, int codSol, char codEqu[], int prioridade, char nomeEqu[], int periodo)
{
    Elo aux1, aux2;
    aux1 = manutencao ->inicio;

    if (TaVazia(manutencao) == 1)
    {
        manutencao ->inicio = CriarElo(manutencao ->inicio, codSol, codEqu, prioridade, nomeEqu, periodo);
    }
    else
    {
        while(aux1 )
        if (codSol < aux1 ->codSol)
        {

        }
        else
        {
            aux2 = aux1;
            aux1 = aux1 ->proximo;
        }
    }
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
    int cont = 1;

    system("cls");
    printf("\n-=-=-=-=-=-\n IMPRIMINDO NOME DOS ELEMENTOS INSERIDOS\n-=-=-=-=-=- ");

    while (aux != NULL)
    {
        printf("%i", cont);
        printf("\n NOME -%s", aux ->nomeEqu);
        printf("\n CODIGO DE SOLICITACAO -%i\n", aux ->codSol);
        aux = aux ->proximo;
        cont++;
    }

    printf("\n\n -Digite 1 para prosseguir");
    scanf("%i", &cont);
}

void AdicionarElementos (Lista *manutencao)
{
    int quant;

    system("cls");

    printf("1 - ADICIONAR EQUIPAMENTOS\n");
    printf("deseja inserir quantos equipamentos na lista? ");
    scanf("%i", &quant);
    flush();

    for(int i = 0; i < quant; i++)
    {
        int codSol, periodo, prioridade, flag;
        char codEqu[7], nomeEqu[21];

        system("cls");

        printf("EQUIPAMENTO %i", i + 1);
        printf("\ndigite o nome do equipamento: ");
        fgets(nomeEqu, sizeof(nomeEqu), stdin);
        nomeEqu[strcspn(nomeEqu, "\n")] = '\0';         // tira o enter da string

        do
        {
            printf("\ndigite o codigo do equipamento (123abc): ");
            fgets(codEqu, sizeof(codEqu), stdin);
            nomeEqu[strcspn(nomeEqu, "\n")] = '\0';
            flush();

            if (strlen(codEqu) < 6)
            {
                printf("\ttamanho incorreto. Tente novamente.");
            }

        } while (strlen(codEqu) < 6);

        do
        {
            printf("\ndigite o codigo de solicitacao (0123): ");
            scanf("%d",&codSol);

            if (codSol < 1000 || codSol > 9999)
            {
                printf("\ttamanho incorreto. Tente novamente.");
            }
        } while (codSol < 1000 || codSol > 9999);

        do
        {
            printf("\ndigite a prioridade do equipamento (1 - 3): ");
            scanf("%d",&prioridade);

            if (prioridade > 3)
            {
                printf("\ttamanho incorreto. Tente novamente.");
            }
        } while (prioridade > 3);

        do
        {
            flag = 0;

            printf("\nqual o periodo de reparo necessario para o equipamento? ");
            scanf("%d",&periodo);

            switch (prioridade)
            {
            case 1:
                if (periodo > 7)
                {
                    printf(" -O periodo nao condiz com a prioridade (0 - 7)");
                    flag = 1;
                }
                break;
            case 2:
                if (periodo > 15)
                {
                    printf(" -O periodo nao condiz com a prioridade (0 - 15)");
                    flag = 1;
                }
                break;
            case 3:
                if (periodo > 20)
                {
                    printf(" -O periodo nao condiz com a prioridade (0 - 20)");
                    flag = 1;
                }
                break;
            }
        } while (flag == 1);

        flush();

        InsereNaLista(manutencao, codSol, codEqu, prioridade, nomeEqu, prioridade);
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
