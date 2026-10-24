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

    system("pause");
}

int ExisteCod(Lista *manutencao, int codSol)
{
    Elo *aux;

    aux = manutencao ->inicio;

    // caminhar pela lista ate chegar no codigo procurado (ou passar dele)

    while ((aux != NULL) && (aux ->codSol < codSol))
    {
        aux = aux ->proximo;
    }

    // chegou no fim ou passou do codigo: nao existe na lista

    if ((aux == NULL) || (aux ->codSol != codSol))
    {
        return 0;
    }

    return 1;
}

void AdicionarElementos (Lista *manutencao)
{
    int quant, flag = 0;

    system("clear");

    printf("1 - ADICIONAR EQUIPAMENTOS\n");

    do
    {
        printf("deseja inserir quantos equipamentos na lista? ");
        scanf("%i", &quant);
        flush();

        if(quant < 1)
        {
            printf("\t- nao\n");
        }
    }
    while(quant < 1);

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
            flag = 0;

            printf("\ndigite o codigo de solicitacao (0123): ");
            scanf("%d",&codSol);

            if (codSol < 1000 || codSol > 9999)
            {
                printf("\ttamanho incorreto. Tente novamente.");
            }

            if(ExisteCod(manutencao, codSol) == 1)
            {
                printf("\t-Este codigo ja existe!");
                flag = 1;
            }
        } while (codSol < 1000 || codSol > 9999 || flag == 1);

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

        InsereNaLista(manutencao, codSol, codEqu, prioridade, nomeEqu, periodo);
    }
}

void ConsultarSolicitacao(Lista *manutencao)
{
    int codSol, flag;
    Elo *aux;

    system("clear");

    if(TaVazia(manutencao) == 1)
    {
        printf("parece que nao tem nada aqui.\n");
        system("pause");
    }
    else
    {
        do
        {
            system("clear");

            aux = manutencao ->inicio;
            printf("codigos disponiveis: ");
            while (aux != NULL)
            {
                printf("\n NOME -%s", aux ->nomeEqu);
                printf("\n CODIGO DE SOLICITACAO -%i\n", aux ->codSol);
                aux = aux ->proximo;
            }

            flag = 0;
            aux = manutencao ->inicio;

            printf("Digite o codigo de solicitacao que deseja consultar: \n");
            scanf("%i", &codSol);

            // caminhar pela lista ate chegar no codigo procurado (ou passar dele)

            while ((aux != NULL) && (aux ->codSol < codSol))
            {
                aux = aux ->proximo;
            }

            // chegou no fim ou passou do codigo: nao existe na lista

            if ((aux == NULL) || (aux ->codSol != codSol))
            {
                printf("\t- O codigo digitado nao existe!\n");
                system("pause");
                flag = 1;
            }
            else
            {
                system("clear");
                printf("LISTANDO ITEM\n\n");
                printf("\t- ITEM: %s\n", aux ->nomeEqu);
                printf("\t- CODIGO DO EQUIPAMENTO: %s\n", aux ->codEqu);
                printf("\t- CODIGO DE SOLICITACAO: %i\n", aux ->codSol);
                printf("\t- PRIORIDADE: %i\n", aux ->prioridade);
                printf("\t- PERIODO: %i\n", aux ->periodo);

                printf("\nTecle 1 para consultar outra solicitacao, 0 para sair\n");
                scanf("%i", &flag);
            }
        }
        while (flag == 1);
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

void LimparListaAux(Lista *apague)
{
    int valor;

    while (apague ->inicio != NULL)
    {
        valor = apague ->inicio ->codSol;
        apague ->inicio = AuxTiraDaLista(apague ->inicio);

        printf("REMOVIDO: %i\n", valor);
    }
}

void LimparLista(Lista *apague)
{
    char opcao;

    printf("Tem certeza de que deseja remover todas as solicitacoes? (S | n)\n");
    scanf(" %c", &opcao);
    getchar();

    if(opcao == 's')
    {
        LimparListaAux(apague);

        printf("Lista de manutencao limpa!\n");
        system("pause");
    }
}

void InserePrioridade (Lista *listaPrioridade, char nomeEqu[], int prioridade, int periodo)
{
    Elo *NovoElo, *aux1, *aux2;
    NovoElo = (Elo *) malloc(sizeof(Elo));

    // passando as informaçoes pro novo elo

    strcpy(NovoElo ->nomeEqu, nomeEqu);
    NovoElo ->prioridade = prioridade;
    NovoElo ->periodo = periodo;

    // logica de inserçao

    aux1 = listaPrioridade ->inicio;
    aux2 = NULL;

    // caminha até:
    // a lista acabar, e a prioridade do elemento novo for maior do que a do elemento atual
    // ou, se a prioridade for igual, conferir se o período é maior do que o do elemento atual
    // dessa forma, ele organiza a lista por prioridade, depois periodo, depois codigo de solicitacao.

    while ((aux1 != NULL) && ((aux1 ->prioridade < NovoElo ->prioridade) || (aux1 ->prioridade == NovoElo ->prioridade && aux1 ->periodo < NovoElo ->periodo)))
    {
        aux2 = aux1;
        aux1 = aux1 ->proximo;
    }

    NovoElo ->proximo = aux1;

    if(aux2 == NULL)
    {
        listaPrioridade ->inicio = NovoElo;
    }
    else
    {
        aux2 ->proximo = NovoElo;
    }
}

void ListaPrioridade (Lista *manutencao)
{

    Lista *listaPrioridade;
    int gondola;

    system("clear");

    // cria essa lista nova de prioridade
    listaPrioridade = IniciaLista();
    listaPrioridade = CriaUmaLista();

    // auxiliar pra percorrer a lista de manutençao
    Elo *aux;

    // encontrar elementos na lista original condizentes com cada prioridade
    for(int i = 1; i <= 3; i++)
    {
        printf("adicionando prioridade %i", i);
        aux = manutencao ->inicio;

        while(aux != NULL)
        {
            if(aux ->prioridade == i)
            {
                InserePrioridade(listaPrioridade, aux ->nomeEqu, i, aux ->periodo);
            }
            aux = aux ->proximo;
        }
    }


    // imprimir a lista
    Elo *aux1 = listaPrioridade ->inicio;
    int cont = 1;

    system("clear");
    printf("\n-=-=-=-=-=-\nIMPRIMINDO POR PRIORIDADE\n-=-=-=-=-=-\n");

    if(listaPrioridade ->inicio == NULL)
    {
        printf("Parece que nao tem nada aqui\n");
    }
    else
    {
        while (aux1 != NULL)
        {
            printf("%i", cont);
            printf("\n NOME -%s", aux1 ->nomeEqu);
            printf("\n PRIORIDADE -%i", aux1 ->prioridade);
            printf("\n PERIODO -%i\n", aux1 ->periodo);
            aux1 = aux1 ->proximo;
            cont++;
        }
    }

    system("pause");

    LimparListaAux(listaPrioridade);
    free(listaPrioridade);
}

void AlteraPrioPer (Elo *aux, int opcao)       // opcao: 1 = as duas, 2 = so prioridade, 3 = so periodo
{
    int prioridade, periodo, flag;

    // comeca com os valores atuais: o que nao for alterado continua igual

    prioridade = aux ->prioridade;
    periodo = aux ->periodo;

    if(opcao < 3)
    {
        do
        {
            flag = 0;

            printf("\ndigite a nova prioridade do equipamento (1 - 3): ");
            scanf("%d",&prioridade);

            if (prioridade < 1 || prioridade > 3)
            {
                printf("\ttamanho incorreto. Tente novamente.");
                flag = 1;
            }
            else if(opcao == 2)
            {
                // conferir se a prioridade digitada pelo usuário condiz com o periodo do equipamento

                switch (prioridade)
                {
                case 1:
                    if (periodo > 7)
                    {
                        printf(" -O periodo atual (%i) nao condiz com a prioridade 1 (1 - 7)", periodo);
                        flag = 1;
                    }
                    break;
                case 2:
                    if (periodo > 15)
                    {
                        printf(" -O periodo atual (%i) nao condiz com a prioridade 2 (1 - 15)", periodo);
                        flag = 1;
                    }
                    break;
                }
            }
        } while (flag == 1);
    }

    if(opcao != 2)
    {
        do
        {
            flag = 0;

            printf("\nqual o novo periodo de reparo necessario para o equipamento? ");
            scanf("%d",&periodo);

            if (periodo < 1)
            {
                printf(" -O periodo precisa ser de pelo menos 1 dia");
                flag = 1;
            }

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
    }

    // so grava no elo depois que tudo foi validado

    aux ->prioridade = prioridade;
    aux ->periodo = periodo;
}

void AlterarSolicitacao(Lista *manutencao)
{
    int codSol, opcao, flag;
    Elo *aux;

    system("clear");

    if(TaVazia(manutencao) == 1)
    {
        printf("parece que nao tem nada aqui.\n");
        system("pause");
    }
    else
    {
        do
        {
            system("clear");

            aux = manutencao ->inicio;
            printf("codigos disponiveis: ");
            while (aux != NULL)
            {
                printf("\n NOME -%s", aux ->nomeEqu);
                printf("\n CODIGO DE SOLICITACAO -%i\n", aux ->codSol);
                aux = aux ->proximo;
            }

            flag = 0;
            aux = manutencao ->inicio;

            printf("Digite o codigo de solicitacao que deseja alterar: \n");
            scanf("%i", &codSol);

            // caminhar pela lista ate chegar no codigo procurado (ou passar dele)

            while ((aux != NULL) && (aux ->codSol < codSol))
            {
                aux = aux ->proximo;
            }

            // chegou no fim ou passou do codigo: nao existe na lista

            if ((aux == NULL) || (aux ->codSol != codSol))
            {
                printf("\t- O codigo digitado nao existe!\n");
                system("pause");
                flag = 1;
            }
            else
            {
                system("clear");
                printf("ALTERANDO ITEM\n\n");
                printf("\t- ITEM: %s\n", aux ->nomeEqu);
                printf("\t- PRIORIDADE ATUAL: %i\n", aux ->prioridade);
                printf("\t- PERIODO ATUAL: %i\n", aux ->periodo);

                do
                {
                    printf("\nO que deseja alterar?\n1 - Prioridade e periodo\n2 - Somente prioridade\n3 - Somente periodo\n");
                    scanf("%i", &opcao);

                    if (opcao < 1 || opcao > 3)
                    {
                        printf("\t- Opcao invalida!");
                    }
                } while (opcao < 1 || opcao > 3);

                AlteraPrioPer(aux, opcao);

                printf("\nSolicitacao %i alterada!\n", aux ->codSol);
                printf("\t- PRIORIDADE: %i\n", aux ->prioridade);
                printf("\t- PERIODO: %i\n", aux ->periodo);

                printf("\nTecle 1 para alterar outra solicitacao, 0 para sair\n");
                scanf("%i", &flag);
            }
        }
        while (flag == 1);
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

    system("pause");
}

#endif      // FUNCS_H_INCLUDED
