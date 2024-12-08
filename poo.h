#ifndef CGI_TPOO_H
#define CGI_TPOO_H

#define ITEM_ALLOC_ERROR  1
#define ITEM_EMPTY       -1

#ifdef __cplusplus
  extern "C" {
#endif

typedef struct t_data
{
    int Nomber;
    struct t_data *prec;
} t_data ;


typedef struct t_poo
{
    void(*Clear)(struct t_poo*);
    void(*Liberer)(struct t_poo**);
    int(*Addition)(struct t_poo*, int, int);
    void(*View)(struct t_poo*);
    int Nomber;
    struct t_data *Top;
} t_poo;

t_poo TPoo_Create(void);

t_poo *Instancier_poo(void);

int TPoo_Addition(t_poo*, int, int);

void TPoo_Clear(t_poo*);

void TPoo_View(t_poo*);

#ifdef __cplusplus
}
#endif

#endif // CGI_TPOO_H
