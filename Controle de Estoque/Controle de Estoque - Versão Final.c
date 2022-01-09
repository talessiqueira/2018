/* Programação de Computadores I
 * Trabalho Prático - Controle de Estoque
 * Data de entrega: 23/11/2018
 * Alunos: RAFAELA OLIVEIRA MIRANDA
           TALES SIQUEIRA DA CRUZ
           WEBERT BENTO QUEIROZ
 */

#include <stdio.h>
#include <string.h>

struct Produto
{
    int codigo;
    char descricao[30];
    float preco;
    int quantidade;
};

char menu()
{
    char entrada;

    printf ("-----------------------------------------------------------------------");
    printf ("\n------------------------- Controle de Estoque -------------------------");
    printf ("\nDesenvolvido por: Rafaela, Tales e Webert");
    printf ("\n\n\t1 - Incluir novo produto");
    printf ("\n\t2 - Imprimir estoque");
    printf ("\n\t3 - Pesquisar dados de um produto");
    printf ("\n\t4 - Alterar preco");
    printf ("\n\t5 - Alterar quantidade");
    printf ("\n\t6 - Excluir produto");
    printf ("\n\t0 - Sair");

    printf ("\n\n\tDigite a opcao desejada: ");
    fflush (stdin);
    scanf ("%s", &entrada);

    return (entrada);
}

void incluir (struct Produto A[], const int a)
{
    int w, verificacao = 0, cod, existencia = 0, aux = 0;

    printf ("\n\tInclusao de produto\n\tCodigo:\t\t");
    scanf ("%d", &cod);

    for (w=0; w<a; w++) {
        if (A[w].codigo == cod)
            existencia++;
    }

    for (w=0; w<a; w++) {
        if ((A[w].codigo == 0) && (verificacao == 0) && (existencia == 0)) {
            A[w].codigo = cod;
            printf ("\tDescricao:\t");
            fflush (stdin);
            scanf ("%[^\n]s", A[w].descricao);
            printf ("\tPreco:\t\tR$");
            scanf ("%f", &A[w].preco);
            printf ("\tQuantidade:\t");
            scanf ("%d", &A[w].quantidade);

            verificacao++; /*Retorna que há espaço vago sendo preenchido*/
        }
        if (A[w].codigo == 0)
            aux++;
    }

    if ((existencia != 0) && (cod == 0))
        printf ("\tCodigo indisponivel para uso."); /*O caractere '0' é um valor usado para o programa checar os espaços vazios do vetor*/
    else if (existencia != 0) { /*Caso em que todas as lacunas estão cheias*/
            printf ("\tCodigo ja cadastrado no sistema.\n");
            printf ("\tOs dados desse produto nao serao computados.\n");
    }
    if ((verificacao==0) && (aux == 0)) /*Caso em que todas as lacunas estão cheias*/
        printf ("\tNao ha mais espaco para armazenar produtos.\n"); /* Aux evita que essa mensagem seja lida quando o codigo já existe no produto 1 e há espaço vago.*/

    existencia = 0;
    verificacao = 0;
}

void imprimir (struct Produto B[], const int b)
{
    int j, i=0;

    if (B[0].codigo == 0)
        printf ("\n\tEstoque vazio!\n"); /*Para quando não houver nada em estoque*/
    else {
    for (j=0; j<b; j++) {
        if (B[j].codigo == 0)
        {
            i++;
        }
    }
    printf ("\n\t------------------------------\n");
    printf ("\t Dados amarzenados no sistema\n");
    printf ("\t------------------------------\n");

    for (j=0; j<(b-i); j++)
    {
        printf("\tProduto %d\n", j+1);
        printf("\tCodigo:\t\t%d\n", B[j].codigo);
        printf("\tDescricao:\t%s\n", B[j].descricao);
        printf("\tPreco:\t\tR$%.2f\n", B[j].preco);
        printf("\tQuantidade:\t%d\n\n", B[j].quantidade);
    }

    printf ("\t______________________________\n");
    }
}

void pesquisar (struct Produto C[], const int c)
{
    int X, i, aux = 0;

    printf ("\t________________________________");
    printf ("\n\t  Pesquisa de dados do produto\n");
    printf ("\t--------------------------------\n");
    printf ("\n\tCodigo:\t\t");
    scanf ("%d", &X);

    for (i=0; i<c; i++)
    {
        if (C[i].codigo == X) {
            printf("\n\tDescricao:\t%s\n", C[i].descricao);
            printf("\tPreco:\t\tR$%.2f\n", C[i].preco);
            printf("\tQuantidade:\t%d\n", C[i].quantidade);
            aux = 1;
        }
    }

    if ((aux == 0) || (X==0))
        printf ("\n\tCodigo de produto inexistente!\n");
    printf ("\t________________________________\n");
}

void alterar_preco (struct Produto D[], const int d)
{
    int Y, i, aux = 0;

    printf ("\n\t------------------------------");
    printf ("\n\t      Alteracao de preco\n");
    printf ("\t------------------------------\n");
    printf ("\n\tCodigo: ");
    scanf ("%d", &Y);

    for (i=0; i<d; i++)
    {
        if (D[i].codigo == Y) {
            printf("\tPreco atual: R$%.2f\n", D[i].preco);
            printf ("\tDigite o novo preco: R$");
            scanf ("%f", &D[i].preco);
            printf ("\n\n\tPreco alterado para R$%.2f\n", D[i].preco);
            aux = 1;
        }
    }

    if ((aux == 0) || (Y==0))
        printf ("\n\tCodigo de produto inexistente!\n");
    printf ("\t________________________________\n");
}

void alterar_quantidade (struct Produto E[], const int e)
{
    int Z, i, aux = 0;

    printf ("\n\t------------------------------");
    printf ("\n\t   Alteracao de quantidade\n");
    printf ("\t------------------------------\n");
    printf ("\n\tCodigo: ");
    scanf ("%d", &Z);

    for (i=0; i<e; i++)
    {
        if (E[i].codigo == Z) {
            printf("\tQuantidade atual: %d item(ns)\n", E[i].quantidade);
            printf ("\tDigite a nova quantidade: ");
            scanf ("%d", &E[i].quantidade);
            printf ("\n\n\tQuantidade alterada para %d item(ns)\n", E[i].quantidade);
            aux = 1;
        }
    }

    if ((aux == 0) || (Z==0))
        printf ("\n\tCodigo de produto inexistente!\n");
    printf ("\t________________________________\n");
}

void excluir (struct Produto F[], const int f)
{
    int cod, i, j, aux = 0;

    printf ("\n\t------------------------------");
    printf ("\n\t    Exclusao de produto\n");
    printf ("\t------------------------------\n");
    printf("\n\tCodigo: ");
    scanf("%d",&cod);

    for(i=0; i<f; i++)
    {
        if(F[i].codigo == cod)
        {
            for (j=i; j<f; j++) {
                F[j].codigo = F[j+1].codigo;
                strcpy(F[j].descricao, F[j+1].descricao);
                F[j].preco = F[j+1].preco;
                F[j].quantidade = F[j+1].quantidade;
            }

            F[f-1].codigo = 0;
            strcpy(F[f-1].descricao, "vazio");
            F[f-1].preco = 0;
            F[f-1].quantidade = 0;
            aux++;
            printf("\tProduto excluido!\n");
        }
    }

    if ((aux == 0) || (cod==0))
        printf ("\n\tCodigo de produto inexistente!\n");
    printf ("\t________________________________\n");
}

main ()
{
    const int tam = 100;
    struct Produto item[100];
    char opcao;
    int i, x = 0;

    for (i=0; i<tam; i++) { /*Resetando os dados de código*/
        item[i].codigo = 0;
    }

    do {
    system("cls");

    opcao = menu();

    switch (opcao)
    {
        case '1':
            incluir(item, tam);
        break;

        case '2':
            imprimir(item, tam);
        break;

        case '3':
            pesquisar(item, tam);
        break;

        case '4':
            alterar_preco (item, tam);
        break;

        case '5':
            alterar_quantidade (item, tam);
        break;

        case '6':
            excluir (item, tam);
        break;

        default:
            if ((opcao != 0) && (opcao != '\n') && (opcao != '0'))
                printf ("\tOpcao invalida!");
    }
    printf ("\n\tPessione ENTER para continuar. ");
    getch();
    } while (opcao != '0');

    printf ("\n\nObrigado por usar este programa! :-)\n\n");

    system ("pause");
}
