#include<iostream>
#include<fstream>
using namespace std;

#include "list_film.h"

#define DIM 9

int main(){
    ifstream in("film.txt");
    
    List lista;

    //Inserimento ordinato dei film, presi dal file film.txt, nella lista 
    for(int i = 0; i<DIM; i++){
        string tmp;
        getline(in, tmp);
        string nome = "";
        for(int j = 0; j<tmp.length()-2; j++){
            nome += tmp[j];
        }
        //cout << "nome = " << nome << endl;


        getline(in, tmp);
        string genere = "";
        for(int j = 0; j<tmp.length()-2; j++){
            genere += tmp[j];
        }
        //cout << "genere = " << genere << endl;
        
        
        getline(in, tmp);
        string data = "";
        for(int j = 0; j<tmp.length()-2; j++){
            data += tmp[j];
        }
        //cout << "data = " << data << endl << endl;

        lista.insertInOrder(data, nome, genere);
    }

    //Stampa della lista
    cout << lista << endl;

    //Ricerca del film più nuovo
    lista.film_piu_nuovo();

    //Ricerca del film più vecchio
    lista.film_piu_vecchio();

    cout << endl;

    //Estrazione dei film di un dato genere
    lista.film_dato_un_genere("FANTASY");
    lista.film_dato_un_genere("COMMEDIA");
    lista.film_dato_un_genere("MUSICAL");
    lista.film_dato_un_genere("HORROR");
    lista.film_dato_un_genere("DRAMATIC");
    lista.film_dato_un_genere("ANIME");
    lista.film_dato_un_genere("THRILLER");
    lista.film_dato_un_genere("ACTION");
}