#include "integral.h"

int Validarint(char buffer[]){
    int verd=1, i=0;
    
    while(buffer[i]!='\0' && verd){
        if(isdigit(buffer[i]))
            verd=1;
        else
            verd=0;
        i++;
    }
    return verd;
}

int Validarnum(char buffer[]){
    int verd=1, i=0, pontos=0, sinais=0;
    
    while(buffer[i]!='\0' && verd){
        if(buffer[i]=='-')sinais++;
        if(buffer[i]=='.')pontos++;
        if(isdigit(buffer[i]) || (buffer[i]=='.') || (buffer[0]=='-'))
            verd=1;
        else
            verd=0;
        i++;
    }
    if(pontos>1 || sinais>1){
        return 0;
    }
    return verd;
}

void Grau(int *ptr){
    char buffer[5];
    
    do{
       do{
       system("cls");
       printf("\nInforme o Grau do polinômio: ");gets(buffer);fflush(stdin); 
    }while(!Validarint(buffer));
    *ptr=atoi(buffer); 
    if(*ptr>GRMAX){
        printf("\nError: O grau deve ser menor que %d", GRMAX);system("pause");
    }
    }while(*ptr>GRMAX);
    
}

void ReservarMemoria(real **ptr, int n){
    *ptr=(real*)malloc((n+1)*sizeof(real));
}

void LerCoeficiente(real *a, int n){
    char buffer[20];
    for(int i=0;i<=n;i++){
        do{
        printf("a(%d): ",i);fflush(stdin);gets(buffer);
        }while(!Validarnum(buffer));
        a[i]=atof(buffer);
    }
    
}

void Limites(LIMITES *L){
    char buffer[20];
    
    do{
       system("cls");
       do{
       printf("Ingressar Limite Inferior: ");fflush(stdin);gets(buffer); 
       }while(!Validarnum(buffer));
       L->limf=atof(buffer);
    
       do{
       printf("Ingressar Limite Superior: ");fflush(stdin);gets(buffer); 
       }while(!Validarnum(buffer));
       L->lims=atof(buffer);
       if(L->limf>L->lims){
           printf("\nError: O limite inferior não deve ser maior que o limite superior\n");system("pause");
       }
    }while(L->limf>L->lims);
    
}

real RegraS(real *a, int n, LIMITES *L){
    real fx, soma, x=L->limf;
    int c;
    
    for(int i=0;i<=N;i++){
        fx=0;
        
        if(n==0)
            fx=a[0];
        else{
            for(int j=0;j<=n;j++){
                if(L->limf==0 && j==0)
                    fx=fx+a[j]*pow(1,j);
                else
                    fx=fx+a[j]*pow(x,j);
            }
        }
        if(i==0 || i==N)
            c=1;
        else if(i%2==0)
            c=2;
        else
            c=4;
        soma=soma+c*fabs(fx);
        x=x+((L->lims-L->limf)/N);
    }
    return (((L->lims-L->limf)/(3*N))*soma);
}


