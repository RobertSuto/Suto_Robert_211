#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
//MAJORITATEA CODULUI PRELUAT DIN LABORATOARE.
//interfata
class ProdusPerisabil
{
protected:
    float greutate;
    string data_expirarii;
    float temperaturaPastrare;
public:
    ProdusPerisabil()
    {
        greutate = temperaturaPastrare = 0;
        data_expirarii = "xx/xx/xxxx";
    }
    ProdusPerisabil(float greutate, string data_expirarii, float temperaturaPastrare)
        :greutate(greutate), data_expirarii(data_expirarii), temperaturaPastrare(temperaturaPastrare)
    {}
    ProdusPerisabil(const ProdusPerisabil& other)
        :greutate(other.greutate), data_expirarii(other.data_expirarii), temperaturaPastrare(other.temperaturaPastrare)
    {}
    ~ProdusPerisabil()
    {
        greutate = temperaturaPastrare = 0;
        data_expirarii = "xx/xx/xxxx";
    }
    ProdusPerisabil& operator=(const ProdusPerisabil& other)
    {
        greutate = other.greutate;
        data_expirarii = other.data_expirarii;
        temperaturaPastrare = other.temperaturaPastrare;
        return *this;
    }
    friend istream& operator>>(istream& in, ProdusPerisabil& p)
    {
        in >> p.greutate >> p.data_expirarii >> p.temperaturaPastrare;
        return in;
    }
    friend ostream& operator<<(ostream& out, ProdusPerisabil& p)
    {
        out << p.greutate << p.data_expirarii << p.temperaturaPastrare;
        return out;
    }
};

class Dezinfectant : public ProdusPerisabil
{
protected:
    const int ID = 22;
    string producator;
    int concentratie;
    float pret;
    bool solubil;
public:

    //constructori
    Dezinfectant(const Dezinfectant& d2) :ID(d2.ID)
    {
        producator = d2.producator;
        concentratie = d2.concentratie;
        pret = d2.pret;
        solubil = d2.solubil;
    }
    Dezinfectant() : ID(0000)
    {
        this->producator = "Anonim";
        this->concentratie = 0;
        this->pret = 0;
        this->solubil = 0;
    }

    Dezinfectant(int id, string producator, int concentratie, float pret, bool solubil) :ID(id)
    {
        this->producator = producator;
        this->concentratie = concentratie;
        this->pret = pret;
        this->solubil = solubil;
    }

    //DESTRUCTOR
    ~Dezinfectant() {
        cout << "nu vreau la galati";
    }

    // FunCTiOnAliTAtE
    virtual string con() = 0;
    //Dezinfectant devine clasa abstracta

    //SUPRAINCARCARI <<, >>, =;
    Dezinfectant& operator =(const Dezinfectant& dez)
    {
        if (this != &dez)
        {
            this->producator = dez.producator;
            this->concentratie = dez.concentratie;
            this->pret = dez.pret;
            this->solubil = dez.solubil;
        }
        return *this;
    }
    friend ostream& operator<< (ostream& out, const Dezinfectant& dez)
    {
        out << "\nProducatorul " << dez.producator << "produce un dezinfectant cu conecntratia de " << dez.concentratie << " care costa " << dez.pret << "lei ";
        if (dez.solubil == 1)
            out << "De asemenea, dezinfectantul este solubil";
        else
            out << "Dezinfectantul nu este solubil";

        return out;
    }
    friend istream& operator>> (istream& in, Dezinfectant& dez)
    {
        cout << "\nIntroduceti numele producatorului: ";
        in >> dez.producator;
        cout << "\nIntroduceti concentratia: ";
        in >> dez.concentratie;
        cout << "\nIntroduceti pretul: ";
        in >> dez.pret;
        cout << "\nEste solubil? (1=da/0=nu): ";
        in >> dez.solubil;
        return in;
    }
};

class DezinfectantBacterii : public Dezinfectant
{
public:
    string con()
    {
        if (concentratie >= 70)
            return "Putem folosi acest dezinfectant.";
        else
            return "Nu putem folosi acest dezinfectant.";
    }
    DezinfectantBacterii(const DezinfectantBacterii& d2)
        : Dezinfectant(d2)
    {}
    DezinfectantBacterii()
        : Dezinfectant()
    {}

    DezinfectantBacterii(int id, string producator, int concentratie, float pret, bool solubil)
        : Dezinfectant(id, producator, concentratie, pret, solubil)
    {}

    //DESTRUCTOR
    ~DezinfectantBacterii() {
        cout << "nu vreau la galati";
    }

    friend istream& operator>> (istream& in, DezinfectantBacterii& d)
    {
        in >> *((Dezinfectant*)(&d));
        return in;
    }

    friend ostream& operator>> (ostream& out, DezinfectantBacterii& d)
    {
        out << *((Dezinfectant*)(&d));
        return out;
    }

};

class DezinfectantVirusuri : public Dezinfectant
{
public:
    string con()
    {
        if (concentratie >= 70)
            return "Putem folosi acest dezinfectant.";
        else
            return "Nu putem folosi acest dezinfectant.";
    }
    DezinfectantVirusuri(const DezinfectantVirusuri& d2)
        : Dezinfectant(d2)
    {}
    DezinfectantVirusuri()
        : Dezinfectant()
    {}

    DezinfectantVirusuri(int id, string producator, int concentratie, float pret, bool solubil)
        : Dezinfectant(id, producator, concentratie, pret, solubil)
    {}

    //DESTRUCTOR
    ~DezinfectantVirusuri() {
        cout << "nu vreau la galati";
    }

    friend istream& operator>> (istream& in, DezinfectantVirusuri& d)
    {
        in >> *((Dezinfectant*)(&d));
        return in;
    }

    friend ostream& operator>> (ostream& out, DezinfectantVirusuri& d)
    {
        out << *((Dezinfectant*)(&d));
        return out;
    }
};

class Medicament : public ProdusPerisabil
{
private:
    const int ID = 22;
    string producator;
    int cantitate;
    float pret;
    bool antibiotic;
public:
    Medicament() : ID(0000)
    {
        this->producator = "Anonim";
        this->cantitate = 0;
        this->pret = 0;
        this->antibiotic = 0;
    }
    Medicament(int id, string producator, int cantitate, float pret, bool antibiotic) : ID(id)
    {
        this->producator = producator;
        this->cantitate = cantitate;
        this->pret = pret;
        this->antibiotic = antibiotic;
    }

    //DESTRUCTOR
    ~Medicament() {
        cout << "nu vreau la galati";
    }

    // FunCTiOnAliTAtE
    string con()
    {
        if (antibiotic == true)
            return "Nu se poate da fara reteta.";
        else
            return "Se poate da fara reteta.";
    }
    //SUPRAINCARCARI <<, >>, =;
    Medicament& operator =(const Medicament& dez)
    {
        if (this != &dez)
        {
            this->producator = dez.producator;
            this->cantitate = dez.cantitate;
            this->pret = dez.pret;
            this->antibiotic = dez.antibiotic;
        }
    }
    friend ostream& operator<<  (ostream& out, const Medicament& dez)
    {
        out << "\nProducatorul " << dez.producator << "produce recipiente de " << dez.cantitate << " grame, care costa " << dez.pret << "lei ";
        if (dez.antibiotic == true)
            out << "De asemenea, medicamentul nu este antibiotic";
        else
            out << "Medicamentul nu este antibiotic";

        return out;
    }
    friend istream& operator >>(istream& in, Medicament& dez)
    {
        cout << "\nIntroduceti numele producatorului: ";
        in >> dez.producator;
        cout << "\nIntroduceti cantitatea: ";
        in >> dez.cantitate;
        cout << "\nIntroduceti pretul: ";
        in >> dez.pret;
        cout << "\nEste antibiotic? (1=da/0=nu): ";
        in >> dez.antibiotic;

        return in;
    }
};

class Personal
{
protected:
    static int nrpersoane;
    const int ID = 22;
    int varsta;
    char* nume = nullptr;
    char tura;
    char sectie[100];
    float inaltime;
    double greutate;
    int zileLucrate;
    int* Ore = (int*)malloc(101 * sizeof(int));
    vector<Dezinfectant*> dezinfectanti;
    vector<Medicament> medicamente;
public:
    //SETERS & GETTERS
    int getID()
    {
        return ID;
    }

    void setVarsta(int varsta)
    {
        this->varsta = varsta;
    }
    int getVarsta()
    {
        return varsta;
    }

    void setNume(char* a)
    {

        this->nume = (char*)malloc(256 * sizeof(char));
        fgets(this->nume, 256, stdin);
        this->nume[strlen(this->nume) - 1] = '\0';
    }
    char* getNume()
    {
        return this->nume;
    }

    void setTura(char tura)
    {
        this->tura = tura;
    }
    char getTura()
    {
        return this->tura;
    }

    string getSectie()
    {
        string s;
        s = sectie;
        return s;
    }
    void setSectie(const char* sectie)
    {
        strcpy(this->sectie, sectie);
    }

    void setInaltime(float inaltime)
    {
        this->inaltime = inaltime;
    }
    float getInaltime()
    {
        return this->inaltime;
    }

    void setGreutate(double greutate)
    {
        this->greutate = greutate;
    }
    double getGreutate()
    {
        return this->greutate;
    }



    void setZileLucrate(int zileLucrate)
    {
        this->zileLucrate = zileLucrate;
    }
    int getZileLucrate()
    {
        return this->zileLucrate;
    }

    void setOre(int* a, int b)
    {
        if (this->Ore != nullptr)
            delete[] this->Ore;

        this->zileLucrate = b;
        this->Ore = new int[b];

        for (int i = 0; i < zileLucrate; i++)
            this->Ore[i] = a[i];
    }
    int* getOre()
    {
        return this->Ore;
    }
    void afisare()
    {
        int s = 0;
        for (int i = 0; i < this->zileLucrate; i++)
        {
            cout << this->Ore[i] << " ";
            s = s + Ore[i];

        }
        cout << "IN TOTAL " << s << "ORE SAPTAMNA ASTA" << endl;
    }

    void sumaorelibere()
    {
        int s = 0;
        for (int i = 0; i < this->zileLucrate; i++)
        {

            s = s + Ore[i];
        }
        if (s > 56)
            cout << "Personalul poate primi 2 zile libere";
    }


    int getNrpersoane()
    {
        return this->nrpersoane;
    }

    // CONSTRUCTOR in caz ca stim tot
    Personal(int id, int varsta, const char* nume, char tura, const char sectie[100], float inaltime, double greutate, int* Ore, int zileLucrate) :ID(id)
    {
        cout << ID << endl;
        this->varsta = varsta;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->tura = tura;
        strcpy(this->sectie, sectie);
        this->inaltime = inaltime;
        this->greutate = greutate;
        this->zileLucrate = zileLucrate;
        this->Ore = new int[zileLucrate];
        for (int i = 0; i < zileLucrate; i++)
            this->Ore[i] = Ore[i];
        this->nrpersoane++;

    }




    // CONSTRUCTOR DEFAULT
    Personal() :ID(0000)
    {
        this->varsta = 0;
        nume = new char[strlen("Anonim") + 1];
        strcpy(this->nume, "Anonim");
        this->tura = 'n';
        strcpy(this->sectie, "Anonim");
        this->inaltime = 0;
        this->greutate = 0;
        this->zileLucrate = 0;
        nrpersoane++;
        Ore = nullptr;

    }

    // COPY CONSTRUCTOR
    Personal(const Personal& l2) :ID(l2.ID)
    {
        varsta = l2.varsta;
        inaltime = l2.inaltime;

        if (this->nume != nullptr)
            delete[] this->nume;

        this->nume = new char[strlen(l2.nume) + 1];
        strcpy(this->nume, l2.nume);

        tura = l2.tura;
        strcpy(this->sectie, l2.sectie);
        inaltime = l2.inaltime;
        greutate = l2.greutate;

        zileLucrate = l2.zileLucrate;
        for (int i = 0; i < l2.zileLucrate; i++)
            this->Ore[i] = l2.Ore[i];

        for (int i = 0; i < l2.medicamente.size(); i++)
        {
            this->medicamente.push_back(l2.medicamente[i]);
        }
        for (int i = 0; i < l2.dezinfectanti.size(); i++)
        {
            this->dezinfectanti.push_back(l2.dezinfectanti[i]);
        }

    }
    // Supraincarcare operatori =, << si >>
    Personal& operator= (const Personal& pers)
    {

        if (this != &pers)
        {

            this->varsta = pers.varsta;
            this->zileLucrate = pers.zileLucrate;

            if (this->nume != NULL)
                delete[] this->nume;

            this->nume = new char[strlen(pers.nume) + 1];
            strcpy(this->nume, pers.nume);

            if (this->Ore != NULL)
                delete[] this->Ore;

            this->Ore = new int[pers.zileLucrate];
            for (int i = 0; i < pers.zileLucrate; i++)
                this->Ore[i] = pers.Ore[i];

        }
        this->medicamente.clear();
        this->dezinfectanti.clear();
        for (int i = 0; i < pers.medicamente.size(); i++)
        {
            this->medicamente.push_back(pers.medicamente[i]);
        }
        for (int i = 0; i < pers.dezinfectanti.size(); i++)
        {
            this->dezinfectanti.push_back(pers.dezinfectanti[i]);
        }
        return *this;
    }
    void adaugaMedicament(Medicament m)
    {
        this->medicamente.push_back(m);
    }
    void adaugaDezinfectant(Dezinfectant* d)
    {
        this->dezinfectanti.push_back(d);
    }
    friend ostream& operator<< (ostream& out, const Personal& pers)
    {
        out << "\nPersonalul " << pers.nume << " cu varsta de " << pers.varsta <<
            " are " << pers.zileLucrate << "  zile lucrate, in aceasta saptamana " << endl;
        out << " la sectia de " << pers.sectie << " lucrand tura de " << pers.tura <<
            " si are dezinfectantii: ";
        for (int i = 0; i < pers.dezinfectanti.size(); i++)
        {
            out << pers.dezinfectanti[i] << ' ';
        }
        out << "si medicamentele: ";
        for (int i = 0; i < pers.medicamente.size(); i++)
        {
            out << pers.medicamente[i] << ' ';
        }
        out << endl;

        return out;
    }
    friend istream& operator>> (istream& in, Personal& pers)
    {
        string aux;
        cout << "\nIntroduceti numele ";
        in.ignore();
        getline(in, aux);

        if (pers.nume != NULL)
            delete[] pers.nume;
        pers.nume = new char[aux.size() + 1];
        for (int i = 0; i < aux.size(); i++)
        {
            pers.nume[i] = aux[i];
        }
        pers.nume[aux.size()] = '\0';

        cout << "Introduceti varsta ";
        in >> pers.varsta;
        cout << "\nIntroduceti numarul de Zile Lucrate ";
        in >> pers.zileLucrate;
        if (pers.Ore != NULL)
            delete[] pers.Ore;
        pers.Ore = new int[pers.zileLucrate];
        cout << "\nIntroduceti orele ";
        for (int i = 0; i < pers.zileLucrate; i++)
        {
            in >> pers.Ore[i];


        }
        cout << "\nIntroduceti tura ";
        in >> pers.tura;
        cout << "\nIntroduceti sectia ";
        in >> pers.sectie;


        return in;
    }
    // DESTRUCTOR
    ~Personal()
    {
        nrpersoane--;

        if (this->nume != nullptr)
            delete[] this->nume;

        if (this->Ore != nullptr)
            delete[] this->Ore;
        cout << "moisture initiating" << endl;


    }

    // OPERATORI 7
    const Personal operator++()
    {
        this->varsta++;
        return *this;

    }
    const Personal operator++(int)
    {

        Personal aux(*this);
        this->varsta++;
        return aux;
    }

    void operator +(int a)
    {
        int Ore2[100];
        if (this->Ore != NULL)
        {
            for (int i = 0; i < this->zileLucrate; i++)
                Ore2[i] = this->Ore[i];
            delete[] this->Ore;
        }

        this->zileLucrate++;
        this->Ore = new int[this->zileLucrate];
        for (int i = 0; i < this->zileLucrate - 1; i++)
            this->Ore[i] = Ore2[i];

        this->Ore[this->zileLucrate - 1] = a;

    }
    void operator *(int a)
    {
        int Ore2[100];
        if (this->Ore != NULL)
        {
            for (int i = 0; i < this->zileLucrate; i++)
                Ore2[i] = this->Ore[i];
            delete[] this->Ore;
            this->Ore = new int[this->zileLucrate];
            for (int i = 0; i < this->zileLucrate; i++)
                this->Ore[i] = Ore2[i] * a;
        }

    }
    friend bool operator < (const Personal& pers1, const Personal& pers2)
    {
        if (pers1.varsta < pers2.varsta)
            return 1;
        else
            return 0;

    }
    friend bool operator == (Personal& pers1, Personal& pers2)
    {
        if (pers1.zileLucrate == pers2.zileLucrate)
            return 1;
        else
            return 0;
    }

    //cast implicit explicit

    operator int() const
    {
        int s = 0;
        for (int i = 0; i < this->zileLucrate; i++)
            s = s + Ore[i];
        return s;
    }

    int operator [] (int i)
    {
        if (i == 1)
            return this->zileLucrate;
        if (i == 2)
            return this->varsta;
    }


};

class Doctor : public Personal
{
protected:
    bool garzi;
public:

    Doctor()
        : Personal()
    {
        this->garzi = 0;
    }

    Doctor(int id, int varsta, const char* nume, char tura, const char sectie[100], float inaltime, double greutate, int* Ore, int zileLucrate, bool garzi)
        : Personal(id, varsta, nume, tura, sectie, inaltime, greutate, Ore, zileLucrate)
    {
        this->garzi = 0;
    }

    Doctor(const Doctor& d)
        : Personal(d)
    {
        garzi = d.garzi;
    }

    ~Doctor()
    {}

    void setGarzi(bool garzi)
    {
        this->garzi = garzi;
    }
    bool getGarzi()
    {
        return this->garzi;
    }

    friend std::istream& operator>>(std::istream& in, Doctor& d)
    {
        in >> *((Personal*)(&d));
        cout << "\nGarzi?(1=da,0=nu) ";
        in >> d.garzi;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Doctor& d)
    {
        out << *((Personal*)(&d));
        return out;
    }
};

class Asistent : public Personal
{
protected:
public:

    Asistent()
        : Personal()
    {
    }

    Asistent(int id, int varsta, const char* nume, char tura, const char sectie[100], float inaltime, double greutate, int* Ore, int zileLucrate, bool garzi)
        : Personal(id, varsta, nume, tura, sectie, inaltime, greutate, Ore, zileLucrate)
    {
    }

    Asistent(const Asistent& d)
        : Personal(d)
    {
    }

    ~Asistent()
    {}


    friend std::istream& operator>>(std::istream& in, Asistent& d)
    {
        in >> *((Personal*)(&d));
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Asistent& d)
    {
        out << *((Personal*)(&d));
        return out;
    }
};

class Pacient
{
private:
    static int nrPacienti;
    const int ID = 22;
    int varsta;
    char* nume = nullptr;
    //   char
    char sectie[100];
    float inaltime;
    double greutate;
    bool infectat;
    int zileInternare;
    int* tratamente = (int*)malloc(101 * sizeof(int));
public:
    // SETTERI & GETTERS
    int getID()
    {
        return ID;
    }
    void setVarsta(int varsta)
    {
        this->varsta = varsta;
    }
    int getVarsta()
    {
        return varsta;
    }
    void setNume(char* a)
    {
        this->nume = (char*)malloc(256 * sizeof(char));
        fgets(this->nume, 256, stdin);
        this->nume[strlen(this->nume) - 1] = '\0';
    }
    char* getNume()
    {
        return this->nume;
    }
    void setSectie(char* sectie)
    {
        strcpy(this->sectie, sectie);
    }
    string getSectie()
    {
        string s;
        s = sectie;
        return s;
    }

    void setInaltime(float inaltime)
    {
        this->inaltime = inaltime;
    }
    float getInaltime()
    {
        return this->inaltime;
    }

    void setGreutate(double greutate)
    {
        this->greutate = greutate;
    }
    double getGreutate()
    {
        return this->greutate;
    }
    void setInfectat(bool infectat)
    {
        this->infectat = infectat;
    }
    bool getInfectat()
    {
        return this->infectat;
    }
    void setZileInternare(int zileInternare)
    {
        this->zileInternare = zileInternare;
    }
    int getZileInternare()
    {
        return this->zileInternare;
    }
    void setTratamente(int* a, int b)
    {
        if (this->tratamente != nullptr)
            delete[] this->tratamente;
        this->zileInternare = b;
        this->tratamente = new int[b];
        for (int i = 0; i < zileInternare; i++)
            this->tratamente[i] = a[i];
    }
    int* getTratamente()
    {
        return this->tratamente;
    }
    void afisare()
    {
        int s = 0;
        for (int i = 0; i < this->zileInternare; i++)
            cout << this->tratamente[i] << " ";
        cout << endl;
    }
    int getNrPacienti()
    {
        return this->nrPacienti;
    }
    //CONSTRUCTOR cu toti parametrii
    Pacient(int id, int varsta, char* nume, char sectie[100], float inaltime, double greutate, bool infectat, int* tratamente, int zileInternare) :ID(id)
    {
        this->varsta = varsta;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);

        strcpy(this->sectie, sectie);
        this->inaltime = inaltime;
        this->greutate = greutate;
        this->infectat = infectat;
        this->zileInternare = zileInternare;
        this->tratamente = new int[zileInternare];
        for (int i = 0; i < zileInternare; i++)
            this->tratamente[i] = tratamente[i];
        this->nrPacienti++;
    }
    //CONSTRuCTOR DEFAULT
    Pacient() :ID(0000)
    {
        this->varsta = 0;
        nume = new char[strlen("Anonim") + 1];

        strcpy(nume, "Anonim");

        strcpy(this->sectie, "Anonim");
        this->inaltime = 0;
        this->infectat = 0;
        this->greutate = 0;
        this->inaltime = 0;
        this->zileInternare = 0;
        nrPacienti++;
        tratamente = NULL;
    }
    //COPY CONSTRUCTOR
    Pacient(const Pacient& p2) :ID(p2.ID)
    {
        varsta = p2.varsta;
        inaltime = p2.inaltime;

        if (this->nume != nullptr)
            delete[] this->nume;

        nume = new char[strlen(p2.nume) + 1];
        strcpy(this->nume, p2.nume);

        strcpy(this->sectie, p2.sectie);
        inaltime = p2.inaltime;
        greutate = p2.greutate;
        infectat = p2.infectat;
        zileInternare = p2.zileInternare;
        for (int i = 0; i < p2.zileInternare; i++)
            this->tratamente[i] = p2.tratamente[i];
    }
    //DESTRUCTOR
    ~Pacient()
    {
        nrPacienti--;
        if (this->nume != nullptr)
            delete[] this->nume;
        if (this->tratamente != nullptr)
            delete[] this->tratamente;
    }
    //OVERLOAD LA << = si >>
    Pacient& operator =(const Pacient& pac)
    {
        if (this != &pac)
        {
            this->varsta = pac.varsta;
            this->zileInternare = pac.zileInternare;

            if (this->nume != nullptr)
                delete[] this->nume;
            this->nume = new char[strlen(pac.nume) + 1];
            strcpy(this->nume, pac.nume);

            if (this->tratamente != nullptr)
                delete[] this->tratamente;

            this->tratamente = new int[pac.zileInternare];
            for (int i = 0; i < pac.zileInternare; i++)
                this->tratamente[i] = pac.tratamente[i];


        }
        return *this;
    }
    friend ostream& operator<< (ostream& out, const Pacient& pac)
    {
        out << "\nPacientul " << pac.nume << " cu varsta de " << pac.varsta << " are " << pac.zileInternare << "  zile de la internare " << endl;
        out << " la sectia de " << pac.sectie << " fiind (1=infectat/0=neinfectat) " << pac.infectat << endl;

        return out;

    }
    friend istream& operator>>(istream& in, Pacient& pac)
    {
        string aux;
        cout << "\nIntroduceti numele ";
        in.ignore();
        getline(in, aux);



        if (pac.nume != NULL)
            delete[] pac.nume;
        pac.nume = new char[aux.size() + 1];
        for (int i = 0; i < aux.size(); i++)
        {
            pac.nume[i] = aux[i];
        }
        pac.nume[aux.size()] = '\0';




        cout << "Introduceti varsta ";
        in >> pac.varsta;
        cout << "\nIntroduceti numarul de zile Internate ";
        in >> pac.zileInternare;
        if (pac.tratamente != NULL)
            delete[] pac.tratamente;
        pac.tratamente = new int[pac.zileInternare];
        cout << "\nIntroduceti tratamentele administrate ";
        for (int i = 0; i < pac.zileInternare; i++)
        {
            in >> pac.tratamente[i];
        }
        cout << "\nIntroduceti sectia ";
        in >> pac.sectie;
        cout << "\nEste infectat cu COVID-19?(1=da/0=nu) ";
        in >> pac.infectat;

        return in;
    }
    // Operatori ++,+
    const Pacient operator++()
    {
        this->varsta++;
        return *this;
    }
    const Pacient operator++(int)
    {
        Pacient aux(*this);
        this->varsta++;
        return aux;
    }
    void operator +(int a)
    {
        int tratamente2[100];
        if (this->tratamente != NULL)
        {
            for (int i = 0; i < this->zileInternare; i++)
                tratamente2[i] = this->tratamente[i];
            delete[] this->tratamente;
        }
        this->zileInternare++;
        this->tratamente = new int[this->zileInternare];
        for (int i = 0; i < this->zileInternare - 1; i++)
            this->tratamente[i] = tratamente2[i];
        this->tratamente[this->zileInternare - 1] = a;

    }
    void operator *(int a)
    {
        int tratamente2[100];
        if (this->tratamente != NULL)
        {
            for (int i = 0; i < this->zileInternare; i++)
                tratamente2[i] = this->tratamente[i];
            delete[] this->tratamente;
            this->tratamente = new int[this->zileInternare];
            for (int i = 0; i < this->zileInternare; i++)
                this->tratamente[i] = tratamente2[i] * a;
        }

    }
    //OPERATOR comparativi
    friend bool operator < (const Pacient& pac1, const Pacient& pac2)
    {
        if (pac1.varsta < pac2.varsta)
            return 1;
        else
            return 0;
    }
    friend bool operator == (Pacient& pac1, Pacient& pac2)
    {
        if (pac1.zileInternare == pac2.zileInternare)
            return 1;
        else
            return 0;
    }
    //Operator cast
    operator int() const
    {
        int s = 0;
        for (int i = 0; i < this->zileInternare; i++)
            s = s + tratamente[i];
        return s;
    }
    int operator [] (int i)
    {
        if (i == 1)
            return this->zileInternare;
        if (i == 2)
            return this->varsta;
    }
    // FunCTiOnAliTAtE
    string izolator()
    {
        if (zileInternare >= 14)
            return "Pacientul poate fi mutat din izolator.";
        else
            return "Pacientul trebuie sa mai stea in izolator.";
    }

};


//MENIU LUAT DE PE GITHUBUL/ARHIVA LUI ANDREI TUDOSE INFO ANUL 2
void afisareMeniu()
{
    cout << "-----------------------\n";
    cout << "1. Adaugare Personal\n";
    cout << "2. Adaugare Pacient\n";
    cout << "2. Adaugare Pacient\n";
    cout << "3. Afisare Personal\n";
    cout << "4. Afisare Pacienti\n";
    cout << "5. Stergere Personal\n";
    cout << "6. Stergere Pacient\n";

    cout << "7. Iesire\n";
    cout << "-----------------------\n";
    cout << "Optiune: ";
}

int Pacient::nrPacienti = 0;
int Personal::nrpersoane = 0;

int main()
{
    vector<Pacient> vectorPacienti;
    vector<Personal> vectorPersonal;
    int opt;
    do
    {
        afisareMeniu();
        cin >> opt;
        if (opt == 1)
        {
            Personal temp;
            cin >> temp;
            vectorPersonal.push_back(temp);
        }
        else if (opt == 2)
        {
            Pacient temp;
            cin >> temp;
            vectorPacienti.push_back(temp);
        }
        else if (opt == 3)
        {
            for (int i = 0; i < vectorPersonal.size(); i++)
            {
                cout << vectorPersonal[i] << endl;
                cout << "Orele lucrate/zi: ";
                vectorPersonal[i].afisare();
            }
        }
        else if (opt == 4)
        {
            for (int i = 0; i < vectorPacienti.size(); i++)
            {
                cout << vectorPacienti[i] << endl;
                cout << "Tratamente administrate/zi: ";
                vectorPacienti[i].afisare();
            }
        }
        else if (opt == 5)
        {
            int index;
            cout << "Ce personal doriti sa stergeti? [0 - " << vectorPersonal.size() - 1 << "]: ";
            cin >> index;
            vectorPersonal.erase(vectorPersonal.begin() + index);
        }
        else if (opt == 6)
        {
            int index;
            cout << "Ce pacient doriti sa stergeti? [0 - " << vectorPacienti.size() - 1 << "]: ";
            cin >> index;
            vectorPacienti.erase(vectorPacienti.begin() + index);
        }
    } while (opt != 7);
    return 0;
}
