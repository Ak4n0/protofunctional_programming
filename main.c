/* Protoprogramación funcional. En main()
 * está la estructura: quiero_que(OPERES).los_datos(A, B)
 * o: quiero_que(OPERES).al_dato(A)
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct operacion {
    int (*los_datos) (int a, int b);
    int (*al_dato) (int a);
} operacion;
 
operacion quiero_que(char *);
 
/* observa las operaciones quiero_que */
 
int main() {
    printf("suma : %d\n" "resta: %d\n" "cambio de signo: %d\n",
        quiero_que("sumes").los_datos(10, 5),
        quiero_que("restes").los_datos(10, 5),
        quiero_que("cambies de signo").al_dato(10)
    );
}
 
/* La magia ocurre aqui abajo */
 
int sumar(int a, int b) {
    return a + b;
}
 
int restar(int a, int b) {
    return a - b;
}
 
int cambio_signo(int a) {
    return -a;
}
 
operacion quiero_que(char *que_hacer) {
    operacion op;
    if(!strcmp(que_hacer, "sumes"))
        op.los_datos = sumar;
    else if(!strcmp(que_hacer, "restes"))
        op.los_datos = restar;
    else if(!strcmp(que_hacer, "cambies de signo"))
        op.al_dato = cambio_signo;
    else
        exit(EXIT_FAILURE); // Como es un juego, que muera el programa
    
    return op;
}
