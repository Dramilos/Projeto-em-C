#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
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

        printf("==================\n\tMENU\n====================\n");
        printf("1 - Adicionar itens\n2 - Listar itens\n3 - bomb\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            AdicionarElementos(manutencao);
            break;
        case 2:
            ImprimeLista(manutencao);
            break;
        default:
            exit(0);
            break;
        }
    } while(opcao != 5);

    return 0;
}
