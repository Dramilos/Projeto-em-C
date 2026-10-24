#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "FUNCS.h"

int main()
{
    system("clear");

    Lista *manutencao;
    int opcao;

    manutencao = IniciaLista();
    manutencao = CriaUmaLista();

    do
    {
        system("clear");

        printf("====================\n\tMENU\n====================\n");
        printf("1 - Adicionar itens\n2 - Listar itens\n3 - Consultar solicitacao\n4 - Alterar prioridade/periodo\n5 - Listar por prioridade\n6 - Remover solicitacao\n7 - Limpar lista\n8 - Sair\n");
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
            AlterarSolicitacao(manutencao);
            break;
        case 5:
            ListaPrioridade(manutencao);
            break;
        case 6:
            RemoverElemento(manutencao);
            break;
        case 7:
            LimparLista(manutencao);
            break;
        case 8:
            break;
        default:
            printf("\nOpcao invalida\n");
            scanf("%i", &opcao);
            break;
        }
    } while(opcao != 8);

    LimparListaAux(manutencao);
    free(manutencao);
    printf("\nprograma encerrado.");

    return 0;
}
