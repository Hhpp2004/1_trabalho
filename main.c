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
                p->fb++;
                q = q->esq;
            }
            else
            {
                p->fb--;
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

int verifica(No *raiz)
{
    int num;
    if (raiz != NULL)
    {
        verifica(raiz->esq);
        verifica(raiz->dir);
        if (raiz->fb >= 2 || raiz->fb <= -2)
        {
            num = 1;
        }
        else
        {
            num = 0;
        }
    }
    return num;
}

void deletar_dados(No *raiz)
{
    if (raiz != NULL)
    {
        deletar_dados(raiz->esq);
        deletar_dados(raiz->dir);
        free(raiz);
    }
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
        num = verifica(arvore);
        if (num == 0)
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }
        //deletar_dados(arvore);
        free(arvore);
        arvore = NULL;
    }
    return 0;
}