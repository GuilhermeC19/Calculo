#include "integral.h"

int main(){ 
    int n;
    char op;
    
    real *a, area;
    LIMITES limites;
    
    do{
    Grau(&n);
    ReservarMemoria(&a,n);
    LerCoeficiente(a,n);
    Limites(&limites);
    area=RegraS(a,n,&limites);
    printf("\nÁrea: %.f\n", area);
    
    printf("\nDeseja efetuar outro cálculo? [S-N]");
    scanf("%c", &op);
    }while(op=='S' || op=='s');
    
    return(EXIT_SUCCESS);
}
