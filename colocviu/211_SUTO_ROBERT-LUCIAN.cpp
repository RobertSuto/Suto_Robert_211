/* Suto Robert-Lucian 211
Code::Blocks GNU GCC Compiler
Eduard Gabriel Szmeteanca */
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstring>


using namespace std;

class citire_afisare //Colocviu 135 POO Iunie 2020 https://github.com/liviubouruc/Learning-OOP/blob/master/Colocviu2020Iunie.cpp
{
public:
    virtual void citire(istream& ) =0;
    virtual void afisare(ostream&) =0;

    friend istream& operator>>(istream &in, citire_afisare& ob)
    {
        ob.citire(in);
        return in;
    }
    friend ostream& operator<<(ostream &out, citire_afisare& ob)
    {
        ob.afisare(out);
        return out;
    }

};

class Vaccin: public citire_afisare{
protected:
    float pret;
    float temperatura;
    vector<string> subst;
public:
    Vaccin(): pret(0),temperatura(0),subst({}){}
    Vaccin(float _pret,float _temperatura,vector<string> _subst): pret(_pret),temperatura(_temperatura),subst(_subst){};
    virtual ~Vaccin(){};
};

class VaccinAntigripal: public Vaccin{
private:
    vector<string> tulpina;
    bool recomandari;
public:
    VaccinAntigripal():Vaccin(),tulpina({}),recomandari(0){};
    VaccinAntigripal(float _pret,float _temperatura,vector<string> _subst,vector<string> _tulpina, bool _recomandari): Vaccin(_pret,_temperatura,_subst),tulpina(_tulpina),recomandari(_recomandari){}
    void citire(istream&);
    void afisare(ostream&);
    void afisareSchemaVaccinare()
    {
        cout<<"cel Antigripal se administrează la adulți o doză de 0.5 ml, iar la copii și adolescenți o doză de 0.3 ml, repetându-sedin 2 în 2 ani";
    }
    ~VaccinAntigripal(){};


};
void VaccinAntigripal::citire(istream& in){
    int nr;
    string substa;
    string tulpinaa;
    cout<<"Pret :";in>> pret;
    cout<<"Temperatura :";in>> temperatura;
    cout<<"cate substante contine: ";in>> nr;
    cout<<"Introduceti substante:";
    for(int i=0;i<nr;i++)
    {
        in>>substa;
        subst.push_back(substa);
    }
    cout<<"cate Tulpine: ";in>> nr;
    cout<<"Introduceti tulpinele :";
     for(int i=0;i<nr;i++)
    {
        in>>tulpinaa;
        tulpina.push_back(tulpinaa);
    }
    cout<<"Se respecta recomandarile?";in>>recomandari;
};
void VaccinAntigripal::afisare(ostream& out){
    out<<"pret: "<<pret;
    out<<"Temperatura :"<< temperatura;
    out<<" substante:";
    for(int i=0;i<<subst.size();i++)
        out<<subst[i]<<",";
    out<<" Tulpini :";
    for(int i=0;i<<tulpina.size();i++)
        out<<tulpina[i]<<",";

    out<<"Se respecta recomandarile?"<<recomandari;



}


class VaccinAntihepatic: public Vaccin{
private:
    char tip;
    string mod;
public:
    VaccinAntihepatic():Vaccin(),tip('N'),mod("necunoscut"){};
    VaccinAntihepatic(float _pret,float _temperatura,vector<string> _subst,char _tip,string _mod): Vaccin(_pret,_temperatura,_subst),tip(_tip),mod(_mod){}
    void citire(istream&);
    void afisare(ostream&);
    void afisareSchemaVaccinare()
    {
        cout<<" cel Antihepatită A și B, la copii cu vârstă mai mică de 1 an se adminstrează 2injectări la un interval de o lună, a treia injectare după 6 luni de la prima administrare, la adulțiconform schemei de imunizare recomandată de medic; cel Antihepatită C doar la recomandareamedicului ";
    }
    ~VaccinAntihepatic(){};

};
void VaccinAntihepatic::citire(istream& in){
    int nr;
    string substa;
    cout<<"Pret :";in>> pret;
    cout<<"Temperatura :";in>> temperatura;
    cout<<"cate substante contine: ";in>> nr;
    cout<<"Introduceti substante:";
    for(int i=0;i<nr;i++)
    {
        in>>substa;
        subst.push_back(substa);
    }

    cout<<"Tipul hepatitei:"; in>>tip;
    cout<<"Mod Vaccinare: ";in>>mod;
}
void VaccinAntihepatic::afisare(ostream& out){
    out<<"pret: "<<pret;
    out<<"Temperatura :"<< temperatura;
    out<<" substante:";
    for(int i=0;i<<subst.size();i++){
        out<<subst[i]<<",";}
    out<<"Tipul: "<<tip;
    out<<"Modul de vaccinare: "<<mod;

}

class VaccinAntiSarsCov2: public Vaccin{
private:
    vector<string> reactii;
    float eficienta;
    vector<string> medicamente;
public:
    VaccinAntiSarsCov2(): Vaccin(),reactii({}),eficienta(0){};
    VaccinAntiSarsCov2(float _pret,float _temperatura,vector<string> _subst,vector<string> _reactii,float _eficienta): Vaccin(_pret,_temperatura,_subst),reactii(_reactii),eficienta(_eficienta){};
    void citire(istream&);
    void afisare(ostream&);
    void afisareSchemaVaccinare()
    {
        cout<<"cel anti Sars-Cov2 se administreaza persoanelor cu varsta de peste 16 ani, 2 doze la o perioada de 21 zile. ";
    }
    ~VaccinAntiSarsCov2(){};
};

void VaccinAntiSarsCov2::citire(istream& in){
    int nr;
    string substa,reactiii,medicamentee;
    cout<<"Pret :";in>> pret;
    cout<<"Temperatura :";in>> temperatura;
    cout<<"cate substante contine: ";in>> nr;
    cout<<"Introduceti substante:";
    for(int i=0;i<nr;i++)
    {
        in>>substa;
        subst.push_back(substa);
    }

    cout<<"Eficienta :";in>>eficienta;
    cout<<"cate Reactii contine: ";in>> nr;
    cout<<"Introduceti reactiile:";
    for(int i=0;i<nr;i++)
    {
        in>>reactiii;
        reactii.push_back(reactiii);
    }
    cout<<"cate medicamente trebuie evitate: ";in>> nr;
    cout<<"Introduceti medicamentele:";
    for(int i=0;i<nr;i++)
    {
        in>>medicamentee;
        medicamente.push_back(medicamentee);
    }




}

void VaccinAntiSarsCov2::afisare(ostream& out){
    out<<"pret: "<<pret;
    out<<"Temperatura :"<< temperatura;
    out<<" substante:";
    for(int i=0;i<<subst.size();i++){
        out<<subst[i]<<",";}
    out<<"eficienta:"<<eficienta;
    out<<" reactii:";
    for(int i=0;i<<reactii.size();i++){
        out<<reactii[i]<<",";}
    out<<" medicamente :";
    for(int i=0;i<<medicamente.size();i++){
        out<<medicamente[i]<<",";}

}
class Manager{
    vector<Vaccin*> produse;
    static Manager* instance;
    Manager() {}
    Manager(const Manager& ob) = delete;// si liniile acestea cu delete tot din laborator<3
    Manager(Manager&& ob) noexcept = delete;
    Manager& operator=(const Manager& ob) = delete;
    Manager& operator=(Manager&& ob) = delete;
public:
    static Manager* getInstance() {
        if (instance == nullptr) return new Manager();
        return instance;
    }

    void citireProd(){
        cout<<"cate produse?\n";
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"Ce produs doriti sa adaugati?";
            int nr;
            cout<<"1.Antigripal/2.AntiHepatic/3.AntiSarsCov2\n";
            cin>>nr;
            if (nr==1){
                Vaccin* p=new VaccinAntigripal();
                cin>>*p;
                produse.push_back(p);
            }
            else if (nr==2){
                Vaccin* p=new VaccinAntihepatic();
                cin>>*p;
                produse.push_back(p);

            }
            else if (nr==3){
                Vaccin* p=new VaccinAntiSarsCov2();
                cin>>*p;
                produse.push_back(p);

            }



    }
    }
     void afisareProd()
    {
        for(int i=0;i<produse.size();i++)
        {
            cout<<*(produse[i])<<endl;
        }
    }


};
Manager* Manager::instance = nullptr;


int main() {


    int var;
    Manager* M = M->getInstance();
    while (1){
        cout<<"1.Adaugare/2.Afisare/\n";
        cin>>var;
        if (var==1)M->citireProd();
    else if (var==2)M->afisareProd();


    }


VaccinAntigripal a;
VaccinAntihepatic b;
VaccinAntiSarsCov2 c;
cin>>a>>b>>c;
cout<<a<<b<<c;
Vaccin* list[3];
list[0]=new VaccinAntigripal();
list[1]=new VaccinAntihepatic ();
list[2]=new VaccinAntiSarsCov2();



}
