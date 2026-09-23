#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "FUNCS.h"

int main()
{
    system("clear");

    Lista *manutencao;
    int quant;

    manutencao = IniciaLista();
    manutencao = CriaUmaLista();

    printf("deseja inserir quantos equipamentos na lista? ");
    scanf("%i", &quant);

    flush();

    while (quant > 0)
    {
        int codSol, periodo, prioridade;
        char codEqu[7], nomeEqu[21];

        printf("EQUIPAMENTO %i", quant);

        printf("\ndigite o nome do equipamento: ");
        fgets(nomeEqu, sizeof(nomeEqu), stdin);
        nomeEqu[strcspn(nomeEqu, "\n")] = '\0';         // tira o enter da string

        do
        {
            printf("\ndigite o codigo do equipamento: ");
            fgets(codEqu, sizeof(codEqu), stdin);
            nomeEqu[strcspn(nomeEqu, "\n")] = '\0';

            if (strlen(codEqu) < 6)
            {
                printf("\ttamanho incorreto. Tente novamente.");
            }

        } while (strlen(codEqu) < 6);

        do
        {
            printf("\ndigite o codigo de solicitacao: ");
            scanf("%d",&codSol);

            if (codSol < 1000 || codSol > 9999)
            {
                printf("\ttamanho incorreto. Tente novamente.");
            }
        } while (codSol < 1000 || codSol > 9999);

        flush();

        do
        {
            printf("\ndigite a prioridade do equipamento: ");
            scanf("%d",&prioridade);

            if (prioridade > 3)
            {
                printf("\ttamanho incorreto. Tente novamente.");
            }
        } while (prioridade > 3);

        flush();

        InsereNaLista(manutencao, codSol, codEqu, prioridade, nomeEqu);

        quant--;
    }

    printf("\n-=-=-=-=-=-\n IMPRIMINDO NOME DOS ELEMENTOS INSERIDOS\n-=-=-=-=-=- ");

    ImprimeLista(manutencao);

    return 0;
}
