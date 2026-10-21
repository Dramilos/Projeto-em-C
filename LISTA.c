#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "FUNCS.h"

int main()
{
    system("cls");

    Lista *manutencao;
    int opcao;

    manutencao = IniciaLista();
    manutencao = CriaUmaLista();

    do
    {
        system("cls");

        printf("====================\n\tMENU\n====================\n");
        printf("1 - Adicionar itens\n2 - Listar itens\n3 - Consultar solicitacao\n4 - Remover solicitacao\n5 - Limpar lista\n6 - Sair\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            AdicionarElementos(manutencao);
            break;
        case 2:
            ImprimeLista(manutencao);
            break;
        case 3:
            ConsultarSolicitacao(manutencao);
            break;
        case 4:
            RemoverElemento(manutencao);
            break;
        case 5:
            LimparLista(manutencao);
            break;
        case 6:
            break;
        default:
            printf("\nOpcao invalida\n");
            scanf("%i", &opcao);
            break;
        }
    } while(opcao != 6);

    LimparListaAux(manutencao);
    free(manutencao);
    printf("\nprograma encerrado.");

    return 0;
}
