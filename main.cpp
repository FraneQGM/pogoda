#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Pomiar{
    string id;
    string data;
    double temperatura;
    double wiatr;
};

class Pomiary{
private:
    vector<Pomiar> baza;

public:
    void wczytaj(string nazwa){
        ifstream plik(nazwa);

        if(!plik.is_open()){
            throw runtime_error("nie mozna otworzyc pliku");
        }

        string linia;

        while(getline(plik, linia)){
            stringstream ss(linia);
            Pomiar p;
            string temp, wiatr;

            getline(ss, p.id, ';');
            getline(ss, p.data, ';');
            getline(ss, temp, ';');
            getline(ss, wiatr, ';');

            try{
                p.temperatura = stod(temp);
                p.wiatr = stod(wiatr);
            }
            catch(...){
                throw runtime_error("niepoprawne dane w pliku");
            }

            baza.push_back(p);
        }
        plik.close();
    }

    Pomiar minimalna(){
        if(baza.empty()){
            throw runtime_error("baza nie ma rekordow");
        }

        Pomiar min = baza[0];

        for(int i = 0; i<baza.size(); i++){
            if(baza[i].temperatura < min.temperatura){
                min = baza[i];
            }
        }
        return min;
    }

    void szukaj(double prog){
        for(int i = 0; i<baza.size(); i++){
            if(baza[i].temperatura > prog){
                cout<<"id bazy: "<<baza[i].id<<"  "<<"data: "<<baza[i].data<<"  "<<"temperatura: "<<baza[i].temperatura<<"  "<<"wiatr: "<<baza[i].wiatr<<endl;
            }
        }
    }
};

int main()
{
    Pomiary stacja;
    double minimalna;

    try{
        stacja.wczytaj("pomiary.txt");

        Pomiar min = stacja.minimalna();

        cout<<"Pomiar z minimalna temperatura: "<<endl;
        cout<<"id bazy: "<<min.id<<"  "<<"data: "<<min.data<<"  "<<"temperatura: "<<min.temperatura<<"  "<<"wiatr: "<<min.wiatr<<endl;

        cout<<endl;

        cout<<"Podaj temperature: "<<endl;
        cin>>minimalna;
        cout<<endl;

        cout<<"Temperatura wieksza niz "<<minimalna<<": "<<endl;
        stacja.szukaj(minimalna);
    }
    catch(exception &e){
        cout<<"Blad: "<<e.what()<<endl;
    }

    return 0;
}
