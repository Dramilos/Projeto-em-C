#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

        printf("==================\n\tMENU\n====================\n");
        printf("1 - Adicionar itens\n2 - Listar itens\n3 - limpar lista\n4 - bomb\n");
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
            LimparLista(manutencao);
            break;
        default:
            exit(0);
            break;
        }
    } while(opcao != 5);

    free(manutencao);

    return 0;
}
