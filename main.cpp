#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#define N 50
using namespace std;

struct Book{
    //int id;
    char im[30];
    char naz[30];
    char tyt[30];
    char wyd[30];
    double cena;
};
void Zapis(Book ks[]){
    ofstream plik("dane.bin", ios::out | ios::binary);
    for(int i=0;i<N;i++){
        if(ks[i].cena!=NULL){plik.write((const char*) &ks[i], sizeof(Book));}
    }
    plik.close();
}

void Ustaw(int ile){
    Book x[ile];
    ofstream plik("dane.bin", ios::out | ios::app | ios::binary);
    cout<<"> Podaj informacje o ksiazkach: "<<endl;
    cout<<"----------------------------"<<endl;
    for(int i=0;i<ile;i++){
        cout<<"Imie: ";
        cin>>x[i].im;
        cout<<"Nazwisko: ";
        cin>>x[i].naz;
        cout<<"Tytul: ";
        cin>>x[i].tyt;
        cout<<"Wydawnictwo: ";
        cin>>x[i].wyd;
        cout<<"Cena: ";
        cin>>x[i].cena;
        cout<<"----------------------------"<<endl;
        plik.write((const char*) &x[i], sizeof(Book));

    }
    plik.close();
}

void Wypisz(Book ks[]){
    cout<<"> Ksiazki w bazie danych: "<<endl;
    cout<<"----------------------------"<<endl;
    for(int i=0;i<N;i++){
        if(ks[i].cena!=NULL){
            cout<<"["<<i<<"] "<<ks[i].im<<" "<<ks[i].naz<<" pt.'"<<ks[i].tyt<<"'" <<" wyd. "<<ks[i].wyd<<endl;
            cout<<"Koszt: "<<ks[i].cena<<" $"<<endl;
            cout<<"----------------------------"<<endl;
        }
    }
}

void Odczyt(Book ks[]){
    ifstream plik("dane.bin", ios::in | ios::binary);
    for(int i=0;i<N;i++){
        plik.read((char *) &ks[i], sizeof(Book));
        if(plik.eof()){
            memset(&ks[i],0,sizeof(ks[i]));
        }
    }
    plik.close();
}

bool WyswietlWgKlucza(Book ks[], bool wyn, int i){
    cout<<"Ksiazka autorstwa: "<<ks[i].naz<<" pt.'"<<ks[i].tyt<<"'" <<" wyd. "<<ks[i].wyd<<endl;
    cout<<"Koszt: "<<ks[i].cena<<" $"<<endl;
    cout<<"----------------------------"<<endl;
    return true;
}

void SzukajWgKlucz(Book ks[],int wybor){
    bool wyn=false;
    double maxi=0;
    int z;
    cout<<" > Podaj klucz: ";
    char klucz[30];
    cin>>klucz;
    cout<<"----------------------------"<<endl;
    for(int i=0;i<N;i++){
        switch(wybor){
        case 1:
            if(strcmp(ks[i].im,klucz)==0){
                wyn=WyswietlWgKlucza(ks,wyn,i);
            }
            break;
        case 2:
            if(strcmp(ks[i].naz,klucz)==0){
                wyn=WyswietlWgKlucza(ks,wyn,i);
            }
            break;
        case 3:
            if(ks[i].im[0]==klucz[0]){
                wyn=WyswietlWgKlucza(ks,wyn,i);
            }
            break;
        case 4:
            if(ks[i].naz[0]==klucz[0]){
                wyn=WyswietlWgKlucza(ks,wyn,i);
            }
            break;
        case 5:
            if(strcmp(ks[i].tyt,klucz)==0){
                wyn=WyswietlWgKlucza(ks,wyn,i);
            }
            break;
        case 6:
            if(strcmp(ks[i].wyd,klucz)==0){
                wyn=WyswietlWgKlucza(ks,wyn,i);
            }
            break;
        case 7:
            if(maxi<ks[i].cena && ks[i].cena!=NULL){
                maxi=ks[i].cena;
                z=i;
            }
            break;
        }
    }
    if(wybor==7){
        WyswietlWgKlucza(ks,wyn,z);
        wyn=true;
    }
    if(not wyn){
        cout<<"Nie znaleniono ksiazki/ek w bazie!"<<endl;
        cout<<"----------------------------"<<endl;
    }
}

void Del(Book ks[],int id){
    memset(&ks[id],0,sizeof(ks[id]));
}

void Zlicz(Book ks[]){
    double wartosc=0;
    for(int i=0;i<N;i++){
        if(ks[i].cena>0 && ks[i].cena!=NULL) wartosc+=ks[i].cena;
    }
    if(wartosc>0){
        cout<<"Wartosc sumaryczna ksiazek wynosi: "<<wartosc<<" $"<<endl;
        cout<<"----------------------------"<<endl;
    }
    else if(wartosc==0){
        cout<<"Najprawdopodobniej w bazie nie ma ksiazek, lub ich laczna wartosc wynosi 0 $"<<endl;
        cout<<"----------------------------"<<endl;
    }
}
////////////////////////////////////////////////////////////////////////
int main(){
    Book ks[N];
    int menu, submenu, x;
    double wartosc=0;
    do{
    Odczyt(ks);
    system("cls");
    cout<<"---109520-Rogowski-Lukasz---"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"[1] Dodawanie ksiazki/ek do bazy."<<endl;
    cout<<"[2] Wyswietlanie bazy"<<endl;
    cout<<"[3] Przeszukiwanie bazy wg klucza."<<endl;
    cout<<"[4] Wartosc sumaryczna ksiazek."<<endl;
    cout<<"[5] Usuwanie ksiazki z bazy"<<endl;
    cout<<"[6] Wyjscie."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<" > Co chcesz zrobic?: ";
    cin>>menu;
    switch(menu){
        case 1:
            system("cls");
            cout<<"----------------------------"<<endl;
            cout<<"> Ile ksiazek chcesz dodac?: ";
            cin>>x;
            Ustaw(x);
            Odczyt(ks);
            system("pause");
            break;
        case 2:
            system("cls");
            cout<<"----------------------------"<<endl;
            Wypisz(ks);
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"----------------------------"<<endl;
            cout<<"[1] Wyszukiwanie wg imienia."<<endl;
            cout<<"[2] Wyszukiwanie wg nazwiska."<<endl;
            cout<<"[3] Wyszukiwanie wg pierwszej litery imienia."<<endl;
            cout<<"[4] Wyszukiwanie wg pierwszej litery nazwiska."<<endl;
            cout<<"[5] Wyszukiwanie wg tytulu."<<endl;
            cout<<"[6] Wyszukiwanie wg wydawnictwa."<<endl;
            cout<<"[7] Wyszukiwanie wg najwyzszej ceny."<<endl;
            cout<<"[8] Powrot."<<endl;
            cout<<"----------------------------"<<endl;
            cout<<" > Co chcesz wyszukac?: ";
            cin>>submenu;
            //system("cls");
            if(submenu!=8) {SzukajWgKlucz(ks,submenu);}
            else{break;}
            system("pause");
            break;
        case 4:
            system("cls");
            Zlicz(ks);
            system("pause");
            break;
        case 5:
            system("cls");
            int id;
            cout<<"Podaj ID rekordu ktory chcesz usunac: ";
            cin>>id;
            Del(ks,id);
            break;
        case 6:
            system("cls");
            break;
    }
    Zapis(ks);
    }while(menu!=6);
    return 0;
}
