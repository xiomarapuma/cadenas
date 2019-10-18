#include <iostream>

using namespace std;

///tamaño cadena iterativo
int tam_cad(char cadena[] ){
    int tam=0;
    for(int i=0 ;cadena[i]!= '\0';i++){
        tam++;
    }
    return tam ;
}
///tamaño de una cadena recursivo
int tam_cadRec(char *cadena){
    if(*cadena=='\0'){
        return 0;
    }
    else{
        return 1+tam_cadRec(++cadena);
    }
}
///invertir cadena iterativo
void invertircad(char  *cadena){
    char *fin = cadena + tam_cad(cadena) -1;
    char t;
    while(fin>cadena){
        t= *cadena;
        *cadena=*fin;
        *fin=t;
        fin--;
        cadena++;
    }
}
///invertir cadena recursivo
void invertirRec(char *cad,char *fin){
    if(fin<cad){
        return;
    }
    else{
        char t= *cad;
        *cad =*fin;
        *fin =t;
        invertirRec(++cad,--fin);
    }
}
///palindrome
bool palindromo(char *cadena, char *fin)
{
    while (fin >= cadena){
        if(fin != cadena)
            return false ;
        else{
        cadena=cadena+1;
        fin=fin-1 ;
        return true;
        }
    }

}

int main()
{
    char cadena[]= "hola" ;
    char cadena1[]={'h','o','l','a','\0'};
    char cadena2[]="hola mundo";
    cout << tam_cad(cadena1);
    cout << endl ;
    cout << tam_cadRec(cadena);
    cout << endl ;
    invertircad(cadena);
    cout << cadena << endl;
    cout << cadena2<< endl;
    char *fin = cadena2 + tam_cad(cadena2) - 1;
    invertirRec(cadena2, fin);
    cout << cadena2;
    char cadena5[]="anitalavalatina";
    char *fin = cadena5 + tam_cad(cadena5) - 1;
    cout << palindromo(cadena5,fin);
    return 0;
}
