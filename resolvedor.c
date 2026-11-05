#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>

void error (){
    getchar();
    getchar();
}

int main () {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    system("cls");
    system("color 0F");

    //Variables de programa

    int ej_tipe = 0;
    int ej_incog = 0;
    int fin;

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

    system("cls");
    printf("\033[1;36m\n============== RESOLVEDOR DE EJERCICIOS ==============\n\033[0m");

    printf("\nA continuación has de seleccionar el tipo de ejercicio que quieres resolver.\n");
    printf("== Tipos de ejercicio ==\n");
    printf("1 (MRU)\n");
    printf("2 (MRUA)\n");
    printf("3 (MRU y MRUA alcanzar)\n");


    scanf("%d", &ej_tipe);

    //Escojer incognita de ejercicio

    system("cls");
    printf("\033[1;36m\n============== RESOLVEDOR DE EJERCICIOS ==============\n\n\033[0m");



    if (ej_tipe > 3 || ej_tipe < 1) {

        printf("\033[31m Valor incorrecto\033[0m, pulsa ENTER para finalizar.\n");
        error();
        return 0;

    }

    system("cls");
    printf("\033[1;36m\n============== RESOLVEDOR DE EJERCICIOS ==============\n\n\033[0m");



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

    system("cls");
    printf("\033[1;36m\n============== RESOLVEDOR DE EJERCICIOS ==============\n\n\033[0m");



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


    if (ej_tipe == 1){ //Ejercicios de MRU

        if (ej_incog == 1){ 
            printf("Posicion inicial (m)\n");
            scanf("%lf", &Xo);
            printf("Velocidad (m/s)\n");
            scanf("%lf", &Vo);
            printf("Tiempo inicial (s)\n");
            scanf("%lf", &To);
            printf("Tiempo final (s)\n");
            scanf("%lf", &Tf);
        } else if (ej_incog == 2){ 
            printf("Posicion inicial (m)\n");
            scanf("%lf", &Xo);
            printf("Posicion final (m)\n");
            scanf("%lf", &Xf);
            printf("Tiempo inicial (s)\n");
            scanf("%lf", &To);
            printf("Tiempo final (s)\n");
            scanf("%lf", &Tf);
        } else{ 
            printf("Posicion inicial (m)\n");
            scanf("%lf", &Xo);
            printf("Posicion final (m)\n");
            scanf("%lf", &Xf);
            printf("Velocidad (m/s)\n");
            scanf("%lf", &Vo);
            printf("Tiempo inicial (s)\n");
            scanf("%lf", &To);
        }

    } else if (ej_tipe == 2){ //Ejercicios de MRUA

        if (ej_incog == 1){
            printf("Posicion inicial (m)\n");
            scanf("%lf", &Xo);
            printf("Velocidad inicial (m/s)\n");
            scanf("%lf", &Vo);
            printf("Aceleración (m/s²)\n");
            scanf("%lf", &a);
            printf("Tiempo inicial (s)\n");
            scanf("%lf", &To);
            printf("Tiempo final (s)\n");
            scanf("%lf", &Tf);
        }else if (ej_incog == 2){
            printf("Velocidad inicial (m/s)\n");
            scanf("%lf", &Vo);
            printf("Aceleración (m/s²)\n");
            scanf("%lf", &a);
            printf("Tiempo inicial (s)\n");
            scanf("%lf", &To);
            printf("Tiempo final (s)\n");
            scanf("%lf", &Tf);
        }else if (ej_incog == 3){
            printf("Velocidad final (m/s)\n");
            scanf("%lf", &Vf);
            printf("Aceleración (m/s²)\n");
            scanf("%lf", &a);
            printf("Tiempo inicial (s)\n");
            scanf("%lf", &To);
            printf("Tiempo final (s)\n");
            scanf("%lf", &Tf);
        }else if (ej_incog == 4){
            printf("Velocidad inicial (m/s)\n");
            scanf("%lf", &Vo);
            printf("Velocidad final (m/s)\n");
            scanf("%lf", &Vf);
            printf("Tiempo inicial (s)\n");
            scanf("%lf", &To);
            printf("Tiempo final (s)\n");
            scanf("%lf", &Tf);
        }else{
            printf("Posicion inicial (m)\n");
            scanf("%lf", &Xo);
            printf("Posicion final (m)\n");
            scanf("%lf", &Xf);
            printf("Aceleración (m/s²)\n");
            scanf("%lf", &a);
            printf("Velocidad inicial (m/s)\n");
            scanf("%lf", &Vo);
            printf("Tiempo inicial (s)\n");
            scanf("%lf", &To);
        }

    } else { //Ejercicios mixtos de MRU y MRUA

        if (ej_incog == 1){
            printf("Posicion inicial del MRU (m)\n");
            scanf("%lf", &Xo_mru);
            printf("Velocidad del MRU (m/s)\n");
            scanf("%lf", &Vo_mru);
            printf("Posicion inicial del MRUA (m)\n");
            scanf("%lf", &Xo_mrua);
            printf("Velocidad inicial del MRUA (m/s)\n");
            scanf("%lf", &Vo_mrua);
            printf("Aceleración del MRUA (m/s²)\n");
            scanf("%lf", &a_mrua);
        } else{
            printf("Posicion inicial del MRU (m)\n");
            scanf("%lf", &Xo_mru);
            printf("Velocidad del MRU (m/s)\n");
            scanf("%lf", &Vo_mru);
            printf("Posicion inicial del MRUA (m)\n");
            scanf("%lf", &Xo_mrua);
            printf("Velocidad inicial del MRUA (m/s)\n");
            scanf("%lf", &Vo_mrua);
            printf("Aceleración del MRUA (m/s²)\n");
            scanf("%lf", &a_mrua);
        }
    }

    //Calcular las incognitas de los ejercicios

    system("cls");
    printf("\033[1;36m\n============== RESOLVEDOR DE EJERCICIOS ==============\n\n\033[0m");



    if (ej_tipe == 1 && ej_incog == 1){ // POSICION FINAL // MRU

    double Tt = 0;

    Tt = Tf - To ;
    Xf = Xo + Vo*Tt ;
    printf("La posicion final es igual a %lfm .", Xf);
    
    } else if (ej_tipe == 1 && ej_incog == 2){ // VELOCIDAD

        if (Tf != To){

            double X;
            double T;

            X = Xf - Xo ;
            T = Tf - To ;

            Vf = X / T ;

            printf("La velocidad del objeto es igual a %lfm/s .\n", Vf);

        } else{

            printf("\033[31m¡Error, el tiempo transcurrido es de 0s no puedo calcular la velocidad!\033[0m, pulsa ENTER para finalizar.\n");
            error();
            return 0;
        }

    } else if (ej_tipe == 1 && ej_incog == 3){ // TIEMPO FINAL

            if (Vo == 0){

            printf("\033[31m¡Error, la velocidad inicial es 0 por lo que no es posible ejecutar el calculo!\033[0m, pulsa ENTER para finalizar\n");
            error();
            return 0;

            }else{

                double X;

                X = Xf - Xo ;
                Tf = To + (X/Vo);

                printf("El tiempo final es igual a %lfs .\n", Tf);
            }

    } else if (ej_tipe == 2 && ej_incog == 1){ // POSICION FINAL // MRUA

        double T ;

        T = Tf - To ;
        Xf = Xo + Vo*T + 0.5*a*T*T ;

        printf("La posicion final es igual a %lfm .\n", Xf);

    }else if (ej_tipe == 2 && ej_incog == 2){ // VELOCIDAD FINAL

        double T;

        T = Tf - To ;
        Vf = Vo + a*T ;

        printf("La velocidad final es igual a %lfm/s .\n", Vf);

    }else if (ej_tipe == 2 && ej_incog == 3){ // VELOCIDAD INICIAL

        double T;

        T = Tf - To ;
        Vo = Vf - a*T ;

        printf("La velocidad inicial es igual a %lfm/s .\n", Vo);

    }else if (ej_tipe == 2 && ej_incog == 4){ // ACELERACIÓN    

        if (Tf == To){

        printf("\033[31m¡Error, el tiempo inicial y final son iguales por lo que no puedo calcular la aceleración.\033[0m, pulsa ENTER para finalizar.\n");
        error();
        return 0;

        }else if (Vo == Vf) {

        printf("La velocidad final y la inicial son iguales por lo que la aceleración es 0m/s²\n");
        
        }else{

        double V;
        double T;

        V = Vf - Vo ;
        T = Tf - To ;
        a = V / T ;

        printf("La aceleración es igual a %lfm/s² .\n", a);

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
                printf("El tiempo final es igual a %lfs .\n", Tf);
            }
            if (T2 >= 0){
                Tf = To + T2 ;
                printf("El tiempo final es igual a %lfs .\n", Tf);
            }
            if (T1 < 0 && T2 < 0){
                printf("\033[31mNinguno de los tiempos resultantes son validos. (T1 = %lfs, T2 = %lfs).\033[0m\n ", T1, T2);
            }
            
        }else {
            double T;
            T = (-B)/(2*A);
            if (T >= 0){
                Tf = To + T;
                printf("El tiempo final es igual a %lfs .\n", Tf);
            }else {
                printf("\033[31mEl tiempo resultante no es valido (T = %lfs).\033[0m\n", T);
            }
        } 
        
        
    } else {
        if (Vo != 0){
            Tf = To + ( (Xf - Xo) / Vo );
            printf("El tiempo final es igual a %lfs .\n", Tf);
        }else{
            printf("\033[31mError, la velocidad es 0 y la aceleración tambien por lo que no puedo calcular el tiempo final!\033[0m");
        }

    }
        
    } // Calculo de ej mixtos

    //Repetir el programa?

    printf("\nYa has terminado?\n");
    printf("1 (si)\n");
    printf("2 (no)\n");
    scanf("%d", &fin);

} while (fin != 1);

    return 0;

}


// los ejercicios mixtos asumen que ambos tienen como To = 0s
