#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
    int num;
    struct no *esq;
    struct no *dir;
    int fb;
} No;

No *cria_no(int info)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->num = info;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->fb = 0;
    return novo;
}
No *insere_no_abb(No *raiz, int info)
{
    No *novo = cria_no(info);
    No *p = NULL, *q = raiz;
    if (raiz == NULL)
    {
        raiz = novo;
    }
    else
    {
        while (q != NULL)
        {
            p = q;
            if (info < q->num)
            {
                q->fb++;
                q = q->esq;
            }
            else
            {
                q->fb--;
                q = q->dir;
            }
        }
        if (info < p->num)
        {
            p->esq = novo;
        }
        else
        {
            p->dir = novo;
        }
    }
    return raiz;
}

int calculo_fb(No *raiz)
{
    int num = 0;
    int aux = 0;
    if(raiz != NULL)
    {
        if (raiz->fb >= 2 || raiz->fb <= -2)
        {
            aux = 1;
            num = 1;
        }
        if(aux != 1)
        {
            aux = calculo_fb(raiz->esq);
            aux = calculo_fb(raiz->dir);
            num = aux;
        }
    }
    return num;
}

int main(void)
{

    No *arvore = NULL;
    int num_teste;
    int num;
    int entrada;

    scanf("%i", &num_teste);
    for (int i = 0; i < num_teste; i++)
    {
        do
        {
            scanf("%i", &entrada);
            if (entrada != -1)
            {
                arvore = insere_no_abb(arvore, entrada);
            }
        } while (entrada != -1);
        num = calculo_fb(arvore);
        if (num == 1)
        {
            printf("nao\n");
        }
        else
        {
            printf("sim\n");
        }
        free(arvore);
        arvore = NULL;
    }
    return 0;
}