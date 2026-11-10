#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>

void error (){
    getchar();
    getchar();
}

double pedir_valor (char mensaje []){ //Funcion para pedir el valor al usuario ademas de validar que no introduzca una letra o caracter no valido

    double valor;

    printf("%s \n", mensaje); //Escribe el mensaje que el usuario ve
    
    while (scanf("%lf", &valor) != 1){ //Mientras el scan no detecte un valor compatible con double (scanf != 1)

        printf("\033[31m Has de introducir un valor compatible: \033[0m"); //Codigo de error para el usuario
        
        while (getchar () != '\n' ); //Limpiar el buffer del teclado (la cola de caracteres por leer)

    } //Si detecta un valor correcto pasa de esto o pasa a la ultima parte de abajo, sino vuelve a repetir lo mismo de el error

    while (getchar () != '\n' ); //Pa por si acaso   

    return valor;

}

void reinicio_terminal (){

    system("cls");
    printf("\033[1;36m\n============== RESOLVEDOR DE EJERCICIOS ==============\n\033[0m");

}

int main () {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    system("cls");
    system("color 0F");

    //Variables de programa

    int ej_tipe = 0;
    int ej_incog = 0;
    int fin = 0;

    //Variables de ejercicio

    double Xo = 0;
    double Yo = 0;
    double To = 0;
    double Vo = 0;
    double Xf = 0;
    double Yf = 0;
    double Tf = 0;
    double Vf = 0;
    double a = 0;
    double g = 9.81;
   
    // Variables de alcance (ej. mixto)

    double Xo_mru = 0;
    double Yo_mru = 0;
    double To_mru = 0;
    double Vo_mru = 0;
    double Xf_mru = 0;
    double Yf_mru = 0;
    double Tf_mru = 0;

    double Xo_mrua = 0;
    double Yo_mrua = 0;
    double To_mrua = 0;
    double Vo_mrua = 0;
    double Xf_mrua = 0;
    double Yf_mrua = 0;
    double Tf_mrua = 0;
    double Vf_mrua = 0;
    double a_mrua = 0;

    do{

    //Escojer tipo de ejercicio

    reinicio_terminal();

    printf("\nA continuación has de seleccionar el tipo de ejercicio que quieres resolver.\n");
    printf("== Tipos de ejercicio ==\n");
    printf("1 (MRU)\n");
    printf("2 (MRUA)\n");
    printf("3 (MRU y MRUA alcanzar)\n");


    scanf("%d", &ej_tipe);



    reinicio_terminal();

    if (ej_tipe > 3 || ej_tipe < 1) {

        printf("\033[31m Valor incorrecto\033[0m, pulsa ENTER para finalizar.\n");
        error();
        return 0;

    }

    //Escojer incognita de ejercicio

    if (ej_tipe == 1) {
        printf("Has escojido el tipo de ejercicio MRU, ahora selecciona la incognita:\n");
    } else if (ej_tipe == 2) {
        printf("Has escojido el tipo de ejercicio MRUA, ahora selecciona la incognita:\n");
    } else {
        printf("Has escojido el tipo de ejercicio de alcance de MRUA a MRU, ahora selecciona la incognita:\n");
    }
    

    if (ej_tipe == 1){ //Si el ejercicio es MRU
        printf("== Incognitas posibles ==\n");
        printf("1 (Posición final/Distancia recorrida)\n");
        printf("2 (Velocidad)\n");
        printf("3 (Tiempo)\n");


        scanf("%d", &ej_incog);
    } else if (ej_tipe == 2) { //Si el ejercicio es MRUA
        printf("== Incognitas posibles ==\n");
        printf("1 (Posición final/Distancia recorrida)\n");
        printf("2 (Velocidad final)\n");
        printf("3 (Velocidad inicial)\n");
        printf("4 (Aceleración)\n");
        printf("5 (Tiempo)\n");


        scanf("%d", &ej_incog);
    } else { //Si el ejercicio es de Alcance de MRUA a MRU
        printf("== Incognitas posibles ==\n");
        printf("1 (Tiempo de alcance)\n");
        printf("2 (Posicion de alcance)\n");
   
        scanf("%d", &ej_incog);


    }

    reinicio_terminal();


    if (ej_tipe == 1 && ej_incog > 3 || ej_tipe == 2 && ej_incog >5 || ej_tipe == 3 && ej_incog > 2 || ej_incog < 1) {

        printf("\033[31m Valor incorrecto\033[0m, pulsa ENTER para finalizar.\n");
        error();
        return 0;
        
    }

    if      (ej_tipe == 1 && ej_incog == 1)  { printf("Has escojido el ejercicio de MRU con la posición final o distancia como incognita.\n"); } //MRU
    else if (ej_tipe == 1 && ej_incog == 2)  { printf("Has escojido el ejercicio de MRU con la velocidad como incognita.\n"); }
    else if (ej_tipe == 1 && ej_incog == 3)  { printf("Has escojido el ejercicio de MRU con el tiempo como incognita.\n"); }


    else if (ej_tipe == 2 && ej_incog == 1)  { printf("Has escojido el ejercicio de MRUA con la posición final o distancia como incognita.\n"); } //MRUA
    else if (ej_tipe == 2 && ej_incog == 2)  { printf("Has escojido el ejercicio de MRUA con la velocidad final como incognita.\n"); }
    else if (ej_tipe == 2 && ej_incog == 3)  { printf("Has escojido el ejercicio de MRUA con la velocidad inicial como incognita.\n"); }
    else if (ej_tipe == 2 && ej_incog == 4)  { printf("Has escojido el ejercicio de MRUA con la aceleración como incognita.\n"); }
    else if (ej_tipe == 2 && ej_incog == 5)  { printf("Has escojido el ejercicio de MRUA con el tiempo como incognita.\n"); }
   
    else if (ej_tipe == 3 && ej_incog == 1)  { printf("Has escojido el ejercicio de alcance de MRUA a MRU con el tiempo de alcance como incognita.\n"); } //Alcance de MRUA a MRU
    else if (ej_tipe == 3 && ej_incog == 2)  { printf("Has escojido el ejercicio de alcance de MRUA a MRU con la posicion de alcance como incognita.\n"); }


    //Introducir datos segun el ejercicio que haigas escojido


    printf("Escribe a continuacion los datos necesarios para resolver el ejercicio:\n\n");



    if (ej_tipe == 1){ // Ejercicios de MRU

     if (ej_incog == 1){ 
        Xo = pedir_valor("Posicion inicial (m)");
        Vo = pedir_valor("Velocidad (m/s)");
        To = pedir_valor("Tiempo inicial (s)");
        Tf = pedir_valor("Tiempo final (s)");

     } else if (ej_incog == 2){ 
        Xo = pedir_valor("Posicion inicial (m)");
        Xf = pedir_valor("Posicion final (m)");
        To = pedir_valor("Tiempo inicial (s)");
        Tf = pedir_valor("Tiempo final (s)");

       } else{ 
        Xo = pedir_valor("Posicion inicial (m)");
        Xf = pedir_valor("Posicion final (m)");
        Vo = pedir_valor("Velocidad (m/s)");
        To = pedir_valor("Tiempo inicial (s)");
     }

    } else if (ej_tipe == 2){ // Ejercicios de MRUA

        if (ej_incog == 1){
        Xo = pedir_valor("Posicion inicial (m)");
        Vo = pedir_valor("Velocidad inicial (m/s)");
        a = pedir_valor("Aceleracion (m/s2)");
        To = pedir_valor("Tiempo inicial (s)");
        Tf = pedir_valor("Tiempo final (s)");

      }else if (ej_incog == 2){
        Vo = pedir_valor("Velocidad inicial (m/s)");
        a = pedir_valor("Aceleracion (m/s2)");
        To = pedir_valor("Tiempo inicial (s)");
        Tf = pedir_valor("Tiempo final (s)");

     }else if (ej_incog == 3){
        Vf = pedir_valor("Velocidad final (m/s)");
        a = pedir_valor("Aceleracion (m/s2)");
        To = pedir_valor("Tiempo inicial (s)");
        Tf = pedir_valor("Tiempo final (s)");

     }else if (ej_incog == 4){
        Vo = pedir_valor("Velocidad inicial (m/s)");
        Vf = pedir_valor("Velocidad final (m/s)");
        To = pedir_valor("Tiempo inicial (s)");
        Tf = pedir_valor("Tiempo final (s)");

     }else{
        Xo = pedir_valor("Posicion inicial (m)");
        Xf = pedir_valor("Posicion final (m)");
        a = pedir_valor("Aceleracion (m/s2)");
        Vo = pedir_valor("Velocidad inicial (m/s)");
        To = pedir_valor("Tiempo inicial (s)");
     }

    } else { // Ejercicios mixtos de MRU y MRUA

    Xo_mru = pedir_valor("Posicion inicial del MRU (m)");
    Vo_mru = pedir_valor("Velocidad del MRU (m/s)");
    Xo_mrua = pedir_valor("Posicion inicial del MRUA (m)");
    Vo_mrua = pedir_valor("Velocidad inicial del MRUA (m/s)");
    a_mrua = pedir_valor("Aceleracion del MRUA (m/s2)");

    }


    //Calcular las incognitas de los ejercicios

    reinicio_terminal();

    if (ej_tipe == 1 && ej_incog == 1){ // POSICION FINAL // MRU

    double Tt = 0;

    Tt = Tf - To ;
    Xf = Xo + Vo*Tt ;
    printf("\033[33mLa posicion final es igual a %lfm .\033[0m", Xf);
    
    } else if (ej_tipe == 1 && ej_incog == 2){ // VELOCIDAD

        if (Tf != To){

            double X;
            double T;

            X = Xf - Xo ;
            T = Tf - To ;

            Vf = X / T ;

            printf("\033[33mLa velocidad del objeto es igual a %lfm/s .\033[0m\n", Vf);

        } else{

            printf("\033[31m¡Error, el tiempo transcurrido es de 0s no puedo calcular la velocidad!\033[0m, pulsa ENTER para finalizar.\n");
            error();
            return 0;
        }

    } else if (ej_tipe == 1 && ej_incog == 3){ // TIEMPO FINAL

            if (Vo == 0){

            printf("\033[31m¡Error, la velocidad inicial es 0 por lo que no es posible ejecutar el calculo!\033[0m, pulsa ENTER para finalizar.\n");
            error();
            return 0;

            }else{

                double X;

                X = Xf - Xo ;
                Tf = To + (X/Vo);

                printf("\033[33mEl tiempo final es igual a %lfs .\033[0m\n", Tf);
            }

    } else if (ej_tipe == 2 && ej_incog == 1){ // POSICION FINAL // MRUA

        double T ;

        T = Tf - To ;
        Xf = Xo + Vo*T + 0.5*a*T*T ;

        printf("\033[33mLa posicion final es igual a %lfm .\033[0m\n", Xf);

    }else if (ej_tipe == 2 && ej_incog == 2){ // VELOCIDAD FINAL

        double T;

        T = Tf - To ;
        Vf = Vo + a*T ;

        printf("\033[33mLa velocidad final es igual a %lfm/s .\033[0m\n", Vf);

    }else if (ej_tipe == 2 && ej_incog == 3){ // VELOCIDAD INICIAL

        double T;

        T = Tf - To ;
        Vo = Vf - a*T ;

        printf("\033[33mLa velocidad inicial es igual a %lfm/s .\033[0m\n", Vo);

    }else if (ej_tipe == 2 && ej_incog == 4){ // ACELERACIÓN    

        if (Tf == To){

        printf("\033[31m¡Error, el tiempo inicial y final son iguales por lo que no puedo calcular la aceleración.\033[0m, pulsa ENTER para finalizar.\n");
        error();
        return 0;

        }else if (Vo == Vf) {

        printf("\033[33mLa velocidad final y la inicial son iguales por lo que la aceleración es 0m/s² .\033[0m\n");
        
        }else{

        double V;
        double T;

        V = Vf - Vo ;
        T = Tf - To ;
        a = V / T ;

        printf("\033[33mLa aceleración es igual a %lfm/s² .\033[0m\n", a);

        }

    }else if (ej_tipe == 2 && ej_incog == 5){ // TIEMPO
        
        if (a != 0){

        double A, B, C, D;
        double T1, T2 ;
        
        A = 0.5*a;
        B = Vo;
        C = Xo - Xf;
        D = B*B - 4*A*C ;

        if (D < 0){
            printf("\033[31mAquesta equació no te resultat (discriminant < 0).\033[0m\n");
        }else if (D > 0){
            T1 =  ( -B + sqrt(D) ) / (2*A);
            T2 =  ( -B - sqrt(D) ) / (2*A);

            if (T1 >= 0){
                Tf = To + T1 ;
                printf("\033[33mEl tiempo final es igual a %lfs .\033[0m\n", Tf);
            }
            if (T2 >= 0){
                Tf = To + T2 ;
                printf("\033[33mEl tiempo final es igual a %lfs .\033[0m\n", Tf);
            }
            if (T1 < 0 && T2 < 0){
                printf("\033[31mNinguno de los tiempos resultantes son validos. (T1 = %lfs, T2 = %lfs).\033[0m\n", T1, T2);
            }
            
        }else {
            double T;
            T = (-B)/(2*A);
            if (T >= 0){
                Tf = To + T;
                printf("\033[33mEl tiempo final es igual a %lfs .\033[0m\n", Tf);
            }else {
                printf("\033[31mEl tiempo resultante no es valido (T = %lfs).\033[0m\n", T);
            }
        } 
        
        
    } else {
        if (Vo != 0){
            Tf = To + ( (Xf - Xo) / Vo );
            printf("\033[33mEl tiempo final es igual a %lfs .\033[0m\n", Tf);
        }else{
            printf("\033[31mLa velocidad es 0 y la aceleración tambien por lo que no puedo calcular el tiempo final!\033[0m");
        }

    }
        
    }else if (ej_tipe == 3 && ej_incog == 1){ // TIEMPO DE ALCANCE MIXTOS

        double A, B, C, D;

        A = 0.5*a_mrua ;
        B = Vo_mrua - Vo_mru ;
        C = Xo_mrua -   Xo_mru ;

        D = B*B - 4*A*C ;

        if (A == 0){

            if (B != 0){
                double T;
                T = (-C)/B;
            if (T > 0){
                printf("\033[33mEl tiempo de alcance es igual a %lfs .\033[0m\n", T);
            }else {
                printf("\033[31mNo hay un encuentro posterior al inicio.\033[0m\n");
            }   
            }else {
                if (C == 0){
                printf ("\033[33mAmbas velocidades son iguales, y al tener una aceleración igual a 0m/s² se mantienen juntos siempre.\033[0m\n");
                }else {
                printf ("\033[33mAmbas velocidades son iguales, pero al estar en posiciones distintas nunca se encontrarán.\033[0m\n");
                }
            }
       
        }else{

        if (D < 0){
            printf("\033[31mAquesta equació no te resultat (discriminant < 0).\033[0m\n");
        }else if (D > 0){
            double T1, T2 ;

            T1 = (-B + sqrt(D)) / (2*A);
            T2 = (-B - sqrt(D)) / (2*A);

            if (T1 > 0){
                printf("\033[33mEl tiempo de alcance es igual a %lfs .\033[0m\n", T1);
            }
            if (T2 > 0){
                printf("\033[33mEl tiempo de alcance es igual a %lfs .\033[0m\n", T2);
            }
            if (T1 <= 0 && T2 <= 0){
                printf("\033[31mNinguno de los tiempos de alcance resultantes son validos. (T1 = %lfs, T2 = %lfs).\033[0m\n ", T1, T2);
            }

        }else{
            double T;

            T = (-B) / (2*A);
            
            if (T > 0){
                printf("\033[33mEl tiempo de alcance es igual a %lfs .\033[0m\n", T);
            }else {
                printf("\033[31mNo hay un encuentro posterior al inicio.\033[0m\n");
            }   


        }

    }

    }else { // POSICION DE ALCANCE
        double A, B, C, D;
        double T;
        double X1, X2;

        A = 0.5*a_mrua;
        B = Vo_mrua - Vo_mru;
        C = Xo_mrua - Xo_mru;
        D = B*B - 4*A*C;

        if (A == 0){

            if (B != 0){
             T = (-C)/B;
             if (T > 0){
                 X1 = Xo_mru + Vo_mru*T;
                 printf("\033[33mLa posición de alcance de los objetos es de %lfm .\033[0m\n", X1);
             }else {
                    printf("\033[31mNo hay un encuentro posterior al inicio.\033[0m\n");
             }  

            }else {

                if (C == 0){
                printf ("\033[33mAmbas velocidades son iguales, y al tener una aceleración igual a 0m/s² se mantienen juntos siempre.\033[0m\n");
                }else {
                printf ("\033[33mAmbas velocidades son iguales, pero al estar en posiciones distintas nunca se encontrarán.\033[0m\n");
                }
            }

        }else{

        if (D < 0){
            printf("\033[31mAquesta equació no te resultat (discriminant < 0).\033[0m\n");
        }else if (D > 0){
            double T1, T2 ;

            T1 = (-B + sqrt(D)) / (2*A);
            T2 = (-B - sqrt(D)) / (2*A);

            if (T1 > 0){
                X1 = Xo_mru + Vo_mru*T1;
                printf("\033[33mLa posición de alcance es igual a %lfm .\033[0m\n", X1);
            }
            if (T2 > 0){
                X2 = Xo_mru + Vo_mru*T2;
                printf("\033[33mLa posición de alcance es igual a %lfm .\033[0m\n", X2);
            }
            if (T1 <= 0 && T2 <= 0){
                printf("\033[31mNinguno de los tiempos de alcance resultantes son validos. (T1 = %lfs, T2 = %lfs).\033[0m\n ", T1, T2);
            }

        }else{
            double T;

            T = (-B) / (2*A);
            X1 = Xo_mru + Vo_mru*T;

            if (T > 0){
                printf("\033[33mLa posición de alcance es igual a %lfm .\033[0m\n", X1);
            }else {
                printf("\033[31mNo hay un encuentro posterior al inicio.\033[0m\n");
            }   


        }

        }
        
    }


    //Repetir el programa?

    printf("\n\nYa has terminado?\n");
    printf("1 (si)\n");
    printf("2 (no)\n");
    scanf("%d", &fin);

} while (fin != 1);

    system("cls");
    return 0;

}


// los ejercicios mixtos asumen que ambos tienen como To = 0s.
//Posibles fallos a revisar de mostrar datos (no afecta al resultado solo la estetica).
// Añadir una función para poder escribir los resultados de forma rapida, utilizando char mensaje[]

/*
Al escribir como valor de un dato del ejercicio, si poner un numero y luego texto detecta el numero (123caca > 123)
, si pones un texto y luego numeros da error (caca123 > ERROR) y si poner varios numero separados detecta solo el primero como 
valor del dato (123 321 > 123).
*/