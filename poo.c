#include <stdint.h>
#include <stdio.h>

#include "poo.h"

static t_poo* TPoo_Init(t_poo*);

t_poo TPoo_Create()
{
    t_poo this;
    TPoo_Init(&this);
    this.Liberer = TPoo_Liberer;
    return this;
}

t_poo* Instancier_poo()
{
    t_poo *this = malloc(sizeof(t_poo));
    if (!this)
        return NULL;
    TPoo_Init(this);
    this->Liberer = TPoo_Liberer;
}

static t_poo* TPoo_Init(t_poo *this)
{
    this->Clear = TPoo_Clear;
    this->Addition = TPoo_Addition;
    this->View = TPoo_View;
    this->Nomber = 0;
    this->Top = NULL;
}

int TPoo_Addition(t_poo *this, int a, int b)
{
    t_data *new_data = malloc(sizeof(t_data));
    if (!new_data)
        return ITEM_ALLOC_ERROR;
    new_data->Nomber = a + b;
    new_data->prec = this->Top;
    this->Top = new_data;
    this->Nomber++;
    return 0;
}

void TPoo_Clear(t_poo *this)
{
    t_data *tmp;
    while (this->Top)
    {
        tmp = this->Top->prec;
        free(this->Top);
        this->Top = tmp;
    }
    this->Nomber = 0;
}

void TPoo_View(t_poo *this)
{
    t_data *tmp = this->Top;
    while (tmp)
    {
        printf("%d\n", tmp->Nomber);
        tmp = tmp->prec;
    }
}

void TPoo_Liberer(t_poo **this)
{
    if (this && *this)
    {
        free(*this);
        *this = NULL;
    }
    *this = (t_poo *)0;
    return;
}