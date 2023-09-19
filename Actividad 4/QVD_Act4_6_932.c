#include <stdio.h>

// Diego Demian Quiros Vicencio
// 08/29/2023
// Programa que calcule el total a pagar por el servicio de agua tomando en cuenta los m3 utilizados

int main(){

    float iva,total;
    int m3,subtotal;
    printf("Ingresar M3 de agua: ");
    scanf("%d",&m3);

    if (m3<=4)
    {
        subtotal=50;
        iva=subtotal*0.16;
        total=subtotal+iva;
    }
    else
    {
        if (m3>4 && m3<16)
        {
            subtotal=8*m3;
            iva=subtotal*0.16;
            total=subtotal+iva;
        }
        else
        {
            if (m3>15 && m3<=50)
            {
                subtotal=10*m3;
                iva=subtotal*0.16;
                total=subtotal+iva;
            }
            else
            {
                if (m3>51)
                {
                    subtotal=11*m3;
                    iva=subtotal*0.16;
                    total=subtotal+iva;     
                }
                
            }
            
        }
        
    }
    
    
    printf("El total a pagar sera de %.2f pesos\n",total);
    printf("Subtotal: %d pesos\n",subtotal);
    printf("IVA (16%): %.2f pesos\n",iva);

    return 0;
}