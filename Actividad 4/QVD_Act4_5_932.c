#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/30/2023
//Algoritmo que sirva para desplegar el Total de una llamada telefónica

int main(){
    int minutos, llamada;
    float subtotal,iva,total; 

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\tTelefonia UABC UABC\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Tipo de llamada: \n");
    printf("1)Local");
    printf("\n2)Nacional\n");
    printf("3)Internacional\n");
    scanf("%d",&llamada); 
    printf("Minutos de la llamada: ");scanf("\n%d",&minutos); 

    if (llamada==1)
    {
        subtotal=3;
        iva=3*0.16;
        total=subtotal+iva;
    }
    else
    {
        if (llamada==2)
        {
            if (minutos<=3)
            {
                subtotal=7*minutos;
                iva=subtotal*0.16;
                total=subtotal+iva;
            }
            else
            {
                if (minutos>3)
                {
                    subtotal=(7*3)+(2*(minutos-3));
                    iva=subtotal*0.16;
                    total=subtotal+iva;
                }
            }
                
        }
        else
        {
            if (llamada==3)
            {   
                if (minutos<=2)
                {
                    subtotal=9;
                    iva=subtotal*0.16;
                    total=subtotal+iva;
                }
                else
                {   
                    if (minutos>2)
                    {
                        subtotal=9+(4*(minutos-2));
                        iva=subtotal*0.16;
                        total=subtotal+iva;
                    }            
                }
            }
            
            
        }
            
    }
    printf("~~~~~~~~~~~~~~\n");
    printf("Subtotal: %.2f$\n",subtotal);
    printf("Iva(16%): %.2f$\n",iva);
    printf("Subtotal: %.2f$\n",total);
    printf("~~~~~~~~~~~~~~");

    return 0;        
}