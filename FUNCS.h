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
    while ((c = getchar()) != '\n' && c != EOF)
    {

    };
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

void InsereNaLista(Lista *manutencao, int codSol, char codEqu[], int prioridade, char nomeEqu[], int periodo)
{
    Elo *NovoElo, *aux1, *aux2;
    NovoElo = (Elo *) malloc(sizeof(Elo));

    // passando as informaçoes pro novo elo

    NovoElo ->codSol = codSol;
    strcpy(NovoElo ->codEqu, codEqu);
    NovoElo ->prioridade = prioridade;
    strcpy(NovoElo ->nomeEqu, nomeEqu);
    NovoElo ->periodo = periodo;

    // logica de inserçao

    aux1 = manutencao ->inicio;
    aux2 = NULL;

    // caminhar pela lista até achar a posicao necessária

    while ((aux1 != NULL) && (NovoElo ->codSol > aux1 ->codSol))
    {
        aux2 = aux1;
        aux1 = aux1 ->proximo;
    }

    NovoElo ->proximo = aux1;

    if(aux2 == NULL)
    {
        manutencao ->inicio = NovoElo;
    }
    else
    {
        aux2 ->proximo = NovoElo;
    }
}

void ImprimeLista(Lista *manutencaozinha)
{
    Elo *aux = manutencaozinha ->inicio;
    int cont = 1;

    system("clear");
    printf("\n-=-=-=-=-=-\n IMPRIMINDO NOME DOS ELEMENTOS INSERIDOS\n-=-=-=-=-=-\n");

    if(manutencaozinha ->inicio == NULL)
    {
        printf("Parece que nao tem nada aqui\n");
    }
    else
    {
        while (aux != NULL)
        {
            printf("%i", cont);
            printf("\n NOME -%s", aux ->nomeEqu);
            printf("\n CODIGO DE SOLICITACAO -%i\n", aux ->codSol);
            aux = aux ->proximo;
            cont++;
        }
    }

    printf("\n\n -Digite 1 para prosseguir");
    scanf("%i", &cont);
}

void AdicionarElementos (Lista *manutencao)
{
    int quant, flag = 0;

    system("clear");

    printf("1 - ADICIONAR EQUIPAMENTOS\n");
    printf("deseja inserir quantos equipamentos na lista? ");
    scanf("%i", &quant);
    flush();

    for(int i = 0; i < quant; i++)
    {
        int codSol, periodo, prioridade, flag;
        char codEqu[15], nomeEqu[21];

        system("clear");

        printf("EQUIPAMENTO %i", i + 1);
        printf("\ndigite o nome do equipamento: ");
        fgets(nomeEqu, sizeof(nomeEqu), stdin);
        nomeEqu[strcspn(nomeEqu, "\n")] = '\0';         // tira o enter da string

        do
        {
            flag = 0;

            printf("\ndigite o codigo do equipamento (abc123): ");
            fgets(codEqu, sizeof(codEqu), stdin);
            codEqu[strcspn(codEqu, "\n")] = '\0';

            if (strlen(codEqu) != 6)
            {
                printf("\ttamanho incorreto. Tente novamente.");
            }
            else
            {
                for(int j = 0; j < 3; j++)
                {
                    if(j < 3 && !isalpha(codEqu[j]))
                    {
                        flag = 1;
                    }
                }

                for(int j = 3; j < 6; j++)
                {
                    if(j >= 3 && !isdigit(codEqu[j]))
                    {
                        flag = 1;
                    }
                }
            }

            if(flag == 1)
            {
                printf("\t-Formatacao incorreta! (abc123)");
            }


        } while (strlen(codEqu) != 6 || flag == 1);

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

Elo* AuxTiraDaLista(Elo *antigo)
{
    Elo *apagar;

    apagar = antigo;
    antigo = antigo ->proximo;
    free(apagar);

    return antigo;
}

void LimparLista(Lista *apague)
{
    char opcao;

    printf("Tem certeza de que deseja remover todas as solicitações? S | n\n");
    scanf(" %c", &opcao);
    getchar();

    if(opcao == 's')
    {
        int valor;

        while (apague ->inicio != NULL)
        {
            valor = apague ->inicio ->codSol;
            apague ->inicio = AuxTiraDaLista(apague ->inicio);

            printf("REMOVIDO: %i\n", valor);
        }

        printf("Lista de manutencao limpa! Digite 1 para retornar\n");
        scanf("%i", &valor);
    }
}

int RemoveDaLista(Lista *manutencao, int codSol)     // retorna 1 se removeu, 0 se nao achou
{
    Elo *atual, *anterior;

    atual = manutencao ->inicio;
    anterior = NULL;

    // caminhar pela lista ate chegar no codigo procurado (ou passar dele)

    while ((atual != NULL) && (atual ->codSol < codSol))
    {
        anterior = atual;
        atual = atual ->proximo;
    }

    // chegou no fim ou passou do codigo: nao existe na lista

    if ((atual == NULL) || (atual ->codSol != codSol))
    {
        return 0;
    }

    // religar a lista pulando o elo que vai ser apagado

    if (anterior == NULL)
    {
        manutencao ->inicio = atual ->proximo;      // era o primeiro da lista
    }
    else
    {
        anterior ->proximo = atual ->proximo;       // estava no meio ou no fim
    }

    free(atual);

    return 1;
}

void RemoverElemento(Lista *manutencao)
{
    int codSol, flag;

    system("clear");

    printf("REMOVER SOLICITACAO\nitens salvos:\n");

    if (TaVazia(manutencao))
    {
        printf("Parece que nao tem nada aqui\n");
    }
    else
    {
        flag = 0;
        Elo *aux = manutencao ->inicio;

        while (aux != NULL)
        {
            printf("\n NOME -%s", aux ->nomeEqu);
            printf("\n CODIGO DE SOLICITACAO -%i\n", aux ->codSol);
            aux = aux ->proximo;
        }
        do
        {
            printf("\ndigite o codigo de solicitacao que deseja remover: ");
            scanf("%d", &codSol);

            if (RemoveDaLista(manutencao, codSol))
            {
                printf("Solicitacao %i removida!\n", codSol);
                flag = 0;
            }
            else
            {
                printf("Solicitacao %i nao encontrada.\n", codSol);
                flag = 1;
            }
        } while(flag == 1);
    }

    printf("\nDigite 1 para retornar\n");
    scanf("%i", &codSol);
}

#endif      // FUNCS_H_INCLUDED
