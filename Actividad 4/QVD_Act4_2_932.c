#include <stdio.h>

//Diego Demian Quiros Vicencio
// 08/30/2023
//Programa que use un menu para realizar conversiones de unidad de medida
//donde el usuario seleccione una opcion y realizara tal conversion

void menu(){
    
    printf("~~~~~~~~~~~~~~~");    
    printf("\nCalculadora\n");
    printf("~~~~~~~~~~~~~~");
    printf("\n1. cm a pulgadas");
    printf("\n2. cm a pies");
    printf("\n3. Km a millas");
    printf("\n4. Pulgadas a cm");
    printf("\n5. pies a cm");
    printf("\n6. Millas a Km");
    printf("\nIngrese la conversion a realizar: ");
}

int main(){
    int op;
    float resultado,n1;

    menu();
    scanf("%d",&op);

    printf("Ingrese la unidad: ");scanf("%f",&n1);

    if (op==1)
    {
        resultado=n1/2.54;
        printf("Resultado= %.2f pulgadas",resultado);
    }
    else
    {
        if (op==2)
        {
            resultado=n1/30.48;
            printf("Resultado= %.2f pies",resultado);
        }
        else
        {
            if (op==3)
            {
                resultado=n1/1.609;
                printf("Resultado= %.2f millas",resultado);    
            }
            else
            {
                if (op==4)
                {
                    resultado=n1*2.54;
                    printf("Resultado= %.2f cm",resultado);    
                }
                else
                {
                    if (op==5)
                    {
                        resultado=n1*30.48;
                        printf("Resultado= %.2f cm",resultado);
                    }
                    else
                    {
                        if (op==6)
                        {
                            resultado=n1*1.609;
                            printf("Resultado= %.2f Km",resultado);
                        }
                        
                    }
                    
                }
                
            }
        }   
    }
    return 0;
}