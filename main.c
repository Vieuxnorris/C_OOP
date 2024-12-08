#include "poo.c"

int main()
{
    t_poo *MaPoo = Instancier_poo();
    
    MaPoo->Addition(&MaPoo, 10, 20);
    MaPoo->Addition(&MaPoo, 30, 40);
    MaPoo->Addition(&MaPoo, 50, 60);

    MaPoo->View(&MaPoo);

    MaPoo->Clear(&MaPoo);

    MaPoo->Liberer(MaPoo);

    return (0);
}