#include <iostream>
#include <string.h>
#include <cstring>
#include <list>

using namespace std;

class CitireAfisare
{
public:
    virtual ostream& Afisare(ostream& out)const=0;
    virtual istream& Citire(istream& in)=0;

};
class Informatie:public CitireAfisare
{
protected:
    int nrCuvinte;
    string domeniu;
    int publicTinta;
public:
    Informatie();
    Informatie(int nrCuvinte, string domeniu, int publicTinta);

    Informatie(const Informatie& info);

    Informatie& operator=(const Informatie& info);

    virtual ostream& Afisare(ostream& out)const;
    virtual istream& Citire(istream& in);
    friend ostream& operator<<(ostream& out, const Informatie& info);
    friend istream& operator>>(istream& in, Informatie& info);

    virtual void calculViteza()=0;

    ~Informatie() {};
};
ostream& Informatie::Afisare(ostream& out)const
{
    out<<"\nNumarul de cuvinte este: "<<this->nrCuvinte;
    out<<"\nDomeniul este: "<<this->domeniu;
    out<<"\nPublicul tinta este: "<<this->publicTinta;

    return out;
}
istream& Informatie::Citire(istream& in)
{
    cout<<"\nIntroduceti numarul de cuvinte: ";
    in>>this->nrCuvinte;
    cout<<"\nIntroduceti domeniul: ";
    in>>this->domeniu;
    cout<<"\nIntroduceti publicul tinta: ";
    in>>this->publicTinta;
    return in;
}
ostream& operator<<(ostream& out, const Informatie& info)
{
    return info.Afisare(out);
}
istream& operator>>(istream& in, Informatie& info)
{
    return info.Citire(in);
}
Informatie::Informatie()
{
    this->nrCuvinte=0;
    this->domeniu="Nu exista";
    this->publicTinta=0;
}
Informatie::Informatie(int nrCuvinte, string domeniu, int publicTinta)
{
    this->nrCuvinte=nrCuvinte;
    this->domeniu=domeniu;
    this->publicTinta=publicTinta;
}
Informatie::Informatie(const Informatie& info)
{
    this->nrCuvinte=info.nrCuvinte;
    this->domeniu=info.domeniu;
    this->publicTinta=info.publicTinta;
}
Informatie& Informatie::operator=(const Informatie& info)
{
    if(this!=&info)
    {
        this->nrCuvinte=info.nrCuvinte;
        this->domeniu=info.domeniu;
        this->publicTinta=info.publicTinta;
    }
    return *this;
}
class Carte: public virtual Informatie
{
protected:
    int nrPagini;
    string titlu;
    int anAparitie;
    string autorNume;
    string autorPrenume;
    string editura;
public:
    Carte();
    Carte(int nrPagini, string titlu, int anAparitie, string autorNume, string autorPrenume, string editura, int nrCuvinte, string domeniu, int publicTinta);

    Carte(const Carte& car);

    Carte& operator=(const Carte& car);

    void setNrCuvinte(int nrCuvinte);

    int getNrPagini();
    string getTitlu();
    int getAnAparitie();
    string getAutorNume();
    string getAutorPrenume();
    string getEditura();

    ostream& Afisare(ostream& out)const;
    istream& Citire(istream& in);

    void calculViteza();

    ~Carte() {};
};
void Carte::setNrCuvinte(int nrCuvinte)
{
    this->nrCuvinte=nrCuvinte;
}
int Carte::getNrPagini()
{
    return this->nrPagini;
}
string Carte::getTitlu()
{
    return this->titlu;
}
int Carte::getAnAparitie()
{
    return this->anAparitie;
}
string Carte::getAutorNume()
{
    return this->autorNume;
}
string Carte::getAutorPrenume()
{
    return this->autorNume;
}
string Carte::getEditura()
{
    return this->editura;
}
Carte::Carte():Informatie()
{
    this->nrPagini=0;
    this->titlu=" ";
    this->anAparitie=0;
    this->autorNume="Anonim Nume";
    this->autorPrenume="Anonim Prenume";
    this->editura=" ";
}
Carte::Carte(int nrPagini, string titlu, int anAparitie, string autorNume, string autorPrenume, string editura, int nrCuvinte, string domeniu, int publicTinta):Informatie(nrCuvinte, domeniu, publicTinta)
{
    this->nrPagini=nrPagini;
    this->titlu=titlu;
    this->anAparitie=anAparitie;
    this->autorNume=autorNume;
    this->autorPrenume=autorPrenume;
    this->editura=editura;
}
Carte::Carte(const Carte& car):Informatie(car)
{
    this->nrPagini=car.nrPagini;
    this->titlu=car.titlu;
    this->anAparitie=car.anAparitie;
    this->autorNume=car.autorNume;
    this->autorPrenume=car.autorPrenume;
    this->editura=car.editura;
}
Carte& Carte::operator=(const Carte& car)
{
    if(this!=&car)
    {
        Informatie::operator=(car);
        this->nrPagini=car.nrPagini;
        this->titlu=car.titlu;
        this->anAparitie=car.anAparitie;
        this->autorNume=car.autorNume;
        this->autorPrenume=car.autorPrenume;
        this->editura=car.editura;
    }
    return *this;
}
ostream& Carte::Afisare(ostream& out)const
{
    Informatie::Afisare(out);
    out<<"\nNumarul de pagini este: "<<this->nrPagini;
    out<<"\nTitlul este: "<<this->titlu;
    out<<"\nAnul aparitiei este: "<<this->anAparitie;
    out<<"\nNumele autorului este: "<<this->autorNume;
    out<<"\nPrenumele autorului este: "<<this->autorPrenume;
    out<<"\nEditura este: "<<this->editura;
    return out;
}
istream& Carte::Citire(istream& in)
{
    Informatie::Citire(in);
    cout<<"\nNumarul de pagini este: ";
    in>>this->nrPagini;
    cout<<"\nTitlul este: ";
    in>>this->titlu;
    cout<<"\nAnul aparitiei este: ";
    in>>this->anAparitie;
    cout<<"\nNumele autorului este: ";
    in>>this->autorNume;
    cout<<"\nPrenumele autorului este: ";
    in>>this->autorPrenume;
    cout<<"\nEditura este: ";
    in>>this->editura;
    return in;
}
void Carte::calculViteza()  //calculez viteza (cate cuvinte/minut)
{
    int timp;
    cout<<"\nIntroduceti numarul de ore in care doriti sa terminati de citit cartea\n";
    cin>>timp;
    timp*=3600;   //aflu nr de secunde
    double viteza=0;
    if(timp!=0)
        viteza=(double)this->nrCuvinte/timp;
    cout<<"Viteza necesara pentru a termina cartea in "<<timp/3600<<" de ore este "<<viteza<<" de cuvinte/secunda.";
}
class Inregistrare: public virtual Informatie
{
protected:
    double durata;   //in ore
public:
    Inregistrare();
    Inregistrare(double durata, int nrCuvinte, string domeniu, int publicTinta);

    Inregistrare(const Inregistrare& inreg);

    Inregistrare& operator=(const Inregistrare& inreg);

    ostream& Afisare(ostream& out)const;
    istream& Citire(istream& in);

    void calculViteza();

    ~Inregistrare() {};
};
Inregistrare::Inregistrare():Informatie()
{
    this->durata=0;
}
Inregistrare::Inregistrare(double durata, int nrCuvinte, string domeniu, int publicTinta):Informatie(nrCuvinte, domeniu, publicTinta)
{
    this->durata=durata;
}
Inregistrare& Inregistrare::operator=(const Inregistrare& inreg)
{
    if(this!=&inreg)
    {
        Informatie::operator=(inreg);
        this->durata=inreg.durata;
    }
    return *this;
}
Inregistrare::Inregistrare(const Inregistrare& inreg):Informatie(inreg)
{
    this->durata=inreg.durata;
}
ostream& Inregistrare::Afisare(ostream& out)const
{
    Informatie::Afisare(out);
    out<<"\nDurata este: "<<this->durata;
    return out;
}
istream& Inregistrare::Citire(istream& in)
{
    Informatie::Citire(in);
    cout<<"\nDurata este: ";
    in>>this->durata;
    return in;
}
void Inregistrare::calculViteza()    //calculez viteza de redare a inregistrarii
{
    double viteza=0;
    double timp;
    timp=this->durata;
    timp*=3600;                     //aflu nr de secunde
    if(timp!=0)
        viteza=this->nrCuvinte/timp;
    cout<<"Viteza necesara pentru a asculta in inregistrare "<<this->nrCuvinte<<" de cuvinte in "<<this->durata<<" de ore este "<<viteza<<" de cuvinte/secunda.";

}
class Audiobook: public Carte, public Inregistrare
{
protected:
    string limba;
public:
    Audiobook();
    Audiobook(string limba, double durata, int nrPagini, string titlu, int anAparitie, string autorNume, string autorPrenume, string editura, int nrCuvinte, string domeniu, int publicTinta);

    Audiobook(const Audiobook& aud);

    Audiobook& operator=(const Audiobook& aud);

    ostream& Afisare(ostream& out)const;
    istream& Citire(istream& in);

    void calculViteza();

    ~Audiobook() {};
};
Audiobook::Audiobook():Inregistrare(),Carte(),Informatie()
{
    this->limba=" ";
}
Audiobook::Audiobook(string limba, double durata, int nrPagini, string titlu, int anAparitie, string autorNume, string autorPrenume, string editura, int nrCuvinte, string domeniu, int publicTinta):Inregistrare(durata, nrCuvinte, domeniu, publicTinta),Carte(nrPagini, titlu, anAparitie, autorNume, autorPrenume, editura, nrCuvinte, domeniu, publicTinta),Informatie(nrCuvinte, domeniu, publicTinta)
{
    this->limba=limba;
}
Audiobook& Audiobook::operator=(const Audiobook& aud)
{
    if(this!=&aud)
    {
        /*Informatie::operator=(aud);
        this->durata=inreg.durata;
        this->viteza=inreg.viteza;
        this->nrPagini=car.nrPagini;
        this->titlu=car.titlu;
        this->anAparitie=car.anAparitie;
        this->autorNume=car.autorNume;
        this->autorPrenume=car.autorPrenume;
        this->editura=car.editura;  */
        Carte::operator=(aud);
        Inregistrare::operator=(aud);
        this->limba=limba;
    }
    return *this;
}
Audiobook::Audiobook(const Audiobook& aud):Inregistrare(aud),Carte(aud),Informatie(aud)
{
    /*this->durata=inreg.durata;
    this->viteza=inreg.viteza;
    this->nrPagini=car.nrPagini;
    this->titlu=car.titlu;
    this->anAparitie=car.anAparitie;
    this->autorNume=car.autorNume;
    this->autorPrenume=car.autorPrenume;
    this->editura=car.editura;*/
    this->limba=limba;
}
ostream& Audiobook::Afisare(ostream& out)const
{
    Informatie::Afisare(out);
    out<<"\nNumarul de pagini este: "<<this->nrPagini;
    out<<"\nTitlul este: "<<this->titlu;
    out<<"\nAnul aparitiei este: "<<this->anAparitie;
    out<<"\nNumele autorului este: "<<this->autorNume;
    out<<"\nPrenumele autorului este: "<<this->autorPrenume;
    out<<"\nEditura este: "<<this->editura;
    out<<"\nDurata este: "<<this->durata;
    out<<"\nLimba este: "<<this->limba;
    return out;
}
istream& Audiobook::Citire(istream& in)
{
    Informatie::Citire(in);
    cout<<"\nNumarul de pagini este: ";
    in>>this->nrPagini;
    cout<<"\nTitlul este: ";
    in>>this->titlu;
    cout<<"\nAnul aparitiei este: ";
    in>>this->anAparitie;
    cout<<"\nNumele autorului este: ";
    in>>this->autorNume;
    cout<<"\nPrenumele autorului este: ";
    in>>this->autorPrenume;
    cout<<"\nEditura este: ";
    in>>this->editura;
    cout<<"\nDurata este: ";
    in>>this->durata;
    cout<<"\nLimba este: ";
    in>>this->limba;
    return in;
}
void Audiobook::calculViteza()
{
    double viteza=0;
    double timp;
    timp=this->durata;
    timp*=3600;
    if(timp!=0)
        viteza=this->nrCuvinte/timp;
    cout<<"Viteza necesara pentru a termina cartea in "<<this->durata<<" de ore este "<<viteza<<" de cuvinte/secunda.";
}
class Librarie
{
private:
    string nume;
    string adresa;
    int nrCarti;
    string* carti;
public:
    Librarie();
    Librarie(string nume, string adresa, int nrCarti, string* carti);

    Librarie(const Librarie& lib);

    Librarie& operator=(const Librarie& lib);

    friend ostream& operator<<(ostream& out, const Librarie& lib);
    friend istream& operator>>(istream& in, Librarie& lib);

    void VerifCarteInLibrarie(const Librarie& lib,Carte& car);

    ~Librarie();
};
Librarie::Librarie()
{
    this->nume=" ";
    this->adresa=" ";
    this->nrCarti=0;
    this->carti=NULL;
}
Librarie::Librarie(string nume, string adresa, int nrCarti, string* carti)
{
    this->nume=nume;
    this->adresa=adresa;
    this->nrCarti=nrCarti;
    this->carti=new string[this->nrCarti];
    for(int i=0; i<this->nrCarti; i++)
        this->carti[i]=carti[i];
}
Librarie::Librarie(const Librarie& lib)
{
    this->nume=lib.nume;
    this->adresa=lib.adresa;
    this->nrCarti=lib.nrCarti;
    this->carti=new string[this->nrCarti];
    for(int i=0; i<this->nrCarti; i++)
        this->carti[i]=lib.carti[i];
}
Librarie& Librarie::operator=(const Librarie& lib)
{
    if(this!=&lib)
    {
        this->nume=lib.nume;
        this->adresa=lib.adresa;
        this->nrCarti=lib.nrCarti;
        if(this->carti!=NULL)
            delete[] this->carti;
        this->carti=new string[this->nrCarti];
        for(int i=0; i<this->nrCarti; i++)
            this->carti[i]=lib.carti[i];
    }
    return *this;
}
ostream& operator<<(ostream& out, const Librarie& lib)
{
    out<<"\nNumele este: "<<lib.nume;
    out<<"\nAdresa este: "<<lib.adresa;
    if(lib.nrCarti!=0)
    {
        out<<"\nNumarul de carti este: "<<lib.nrCarti;
        out<<"\nCartile sunt: ";
        for(int i=0; i<lib.nrCarti; i++)
            out<<lib.carti[i]<<" ";
    }
    else out<<"\nNu exista carti. ";
    return out;
}
istream& operator>>(istream& in, Librarie& lib)
{
    cout<<"\nNumele este: ";
    in>>lib.nume;
    cout<<"\nAdresa este: ";
    in>>lib.adresa;
    cout<<"\nNumarul de carti este: ";
    in>>lib.nrCarti;
    if(lib.nrCarti!=0)
    {
        if(lib.carti!=NULL)
            delete[] lib.carti;
        lib.carti=new string[lib.nrCarti];
        for(int i=0; i<lib.nrCarti; i++)
            in>>lib.carti[i];
    }
    return in;
}
void Librarie::VerifCarteInLibrarie(const Librarie& lib,Carte& car)  //verific daca cartea car se afla in libraria lib
{
    bool ok=0;
    for(int i=0; i<lib.nrCarti; i++)
        if(lib.carti[i]==car.getTitlu())            //verific toate cartile din libraria lib
        {
            ok=1;
            break;
        }
    if(ok)
        cout<<"\nCartea "<<car.getTitlu()<<" se afla in libraria "<<lib.nume<<" de la adresa "<<lib.adresa;
    else cout<<"\nCartea "<<car.getTitlu()<<" nu se afla in libraria "<<lib.nume<<" de la adresa "<<lib.adresa;
}
Librarie::~Librarie()
{
    if(this->carti!=NULL)
        delete[] this->carti;
}

int comanda;
list <Carte> carte;
list <Inregistrare> inregistrare;
list <Audiobook> audiobook;
list <Librarie> librarie;


void meniuInteractiv()
{
    while(comanda!=5)
    {
        cout << "\nBun venit! Introduceti clasa cu care doriti sa lucrati. \nApasati tasta:  \n1 pentru clasa Carte\n2 pentru clasa Inregistrare\n3 pentru clasa Audiobook\n4 pentru clasa Librarie\n5 pentru EXIT" << endl;
        cout << endl;
        cin >> comanda;
        switch (comanda)
        {
        case 1:
        {
            int optiuniCarte=0;
            while (optiuniCarte != 5)
            {
                cout << "Selectati operatia pe care doriti sa o efectuati:\n1 pentru CREATE\n2 pentru READ\n3 pentru UPDATE\n4 pentru DELETE\n5 pentru BACK\n6 pentru a calcula viteza" << endl;
                cout << endl;
                cin >> optiuniCarte;
                switch (optiuniCarte)
                {
                case 1:
                {
                    int optiuniCarteCreate=0;
                    while (optiuniCarteCreate != 5)
                    {
                        cout << "\nSelectati constructorul:\n1 pentru constructorul fara parametri\n2 pentru constructorul cu toti parametrii\n5 pentru back" << endl;
                        cout << endl;
                        cin >> optiuniCarteCreate;
                        switch (optiuniCarteCreate)
                        {
                        case 1:
                        {
                            Carte c;
                            carte.push_back(c);
                            break;
                        }
                        case 2:
                        {
                            Carte c;
                            cin >> c;
                            carte.push_back(c);
                            break;
                        }
                        case 5:
                        {
                            optiuniCarteCreate=5;
                            break;
                        }
                        default:
                        {
                            cout << "\nComanda incorecta " << endl;
                            break;
                        }
                        }
                    }
                    break;
                }
                case 2:
                {
                    bool okRRead = 1;
                    while (okRRead)
                    {
                        cout << "\nSelectati indexul cartii din lista care doriti sa fie afisata: ";
                        list<Carte>::iterator index_carte;
                        int indexCarte;
                        cin >> indexCarte;
                        index_carte = carte.begin();
                        advance(index_carte, indexCarte - 1);
                        if (index_carte == carte.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okRRead = 0;
                        }
                        else
                            cout << *index_carte << endl;
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okRRead;
                    }
                    optiuniCarte=5;
                    break;
                }
                case 3:
                {
                    bool okRUpdate = 1;
                    while (okRUpdate)
                    {
                        cout << "\nSelectati indexul cartii din lista care doriti sa fie updatata: ";
                        list<Carte>::iterator index_carte;
                        int indexCarte;
                        cin >> indexCarte;
                        index_carte = carte.begin();
                        advance(index_carte, indexCarte - 1);
                        if (index_carte == carte.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okRUpdate = 0;
                        }
                        else
                        {
                            Carte c;
                            cin >> c;
                            *index_carte = c;
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okRUpdate;
                    }
                    optiuniCarte=5;
                    break;
                }
                case 4:
                {
                    bool okRDelete = 1;
                    while (okRDelete)
                    {
                        cout << "\nSelectati indexul cartii din lista care doriti sa fie stearsa: ";
                        list<Carte>::iterator index_carte;
                        int indexCarte;
                        cin >> indexCarte;
                        index_carte = carte.begin();
                        advance(index_carte, indexCarte - 1);
                        if (index_carte == carte.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okRDelete = 0;
                        }
                        else
                            carte.erase(index_carte);
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okRDelete;
                    }
                    optiuniCarte=5;
                    break;
                }
                case 5:
                {
                    optiuniCarte=5;
                    break;
                }
                case 6:
                {
                    bool okCalcul = 1;
                    while (okCalcul)
                    {
                        cout << "\nSelectati indexul cartii din lista la care doriti sa se calculeze viteza: ";
                        list<Carte>::iterator Index_carte;
                        int IndexCarte;
                        cin >> IndexCarte;
                        Index_carte = carte.begin();
                        advance(Index_carte, IndexCarte - 1);
                        if (Index_carte == carte.end())
                        {
                            cout << "\nIndex gresit" << endl;
                        }
                        else
                        {
                            Carte r;
                            r = *Index_carte;
                            r.calculViteza();
                            cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                            cin >> okCalcul;
                        }
                        break;
                    }
                }
                default:
                {
                    cout << "\nComanda gresita";
                    break;
                }
                }
            }
            break;
        }
        case 2:
        {
            int optiuniInregistrare=0;
            while (optiuniInregistrare != 5)
            {
                cout << "\nSelectati operatia pe care doriti sa o efectuati:\n1 pentru CREATE\n2 pentru READ\n3 pentru UPDATE\n4 pentru DELETE\n5 pentru BACK\n6 pentru a calcula viteza" << endl;
                cout << endl;
                cin >> optiuniInregistrare;
                switch (optiuniInregistrare)
                {
                case 1:
                {
                    int optiuniInregistrareCreate=0;
                    while (optiuniInregistrareCreate != 5)
                    {
                        cout << "\nSelectati constructorul:\n1 pentru constructorul fara parametri\n2 pentru constructorul cu toti parametrii\n5 pentru back" << endl;
                        cout << endl;
                        cin >> optiuniInregistrareCreate;
                        switch (optiuniInregistrareCreate)
                        {
                        case 1:
                        {
                            Inregistrare r;
                            inregistrare.push_back(r);
                            break;
                        }
                        case 2:
                        {
                            Inregistrare r;
                            cin >> r;
                            inregistrare.push_back(r);
                            break;
                        }
                        case 5:
                        {
                            optiuniInregistrareCreate=5;
                            break;
                        }
                        default:
                        {
                            cout << "\nComanda incorecta " << endl;
                            break;
                        }
                        }
                    }
                    break;
                }
                case 2:
                {
                    bool okDRead = 1;
                    while (okDRead)
                    {
                        cout << "\nSelectati indexul inregistrarii din lista care doriti sa fie afisata: ";
                        list<Inregistrare>::iterator index_inregistrare;
                        int indexInregistrare;
                        cin >> indexInregistrare;
                        index_inregistrare = inregistrare.begin();
                        advance(index_inregistrare, indexInregistrare - 1);
                        if (index_inregistrare == inregistrare.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okDRead = 0;
                        }
                        else

                            cout << *index_inregistrare << endl;
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okDRead;
                    }
                    optiuniInregistrare=5;
                    break;
                }
                case 3:
                {
                    bool okDUpdate = 1;
                    while (okDUpdate)
                    {
                        cout << "\nSelectati indexul inregistrarii din lista care doriti sa fie updatata: ";
                        list<Inregistrare>::iterator index_inregistrare;
                        int indexInregistrare;
                        cin >> indexInregistrare;
                        index_inregistrare = inregistrare.begin();
                        advance(index_inregistrare, indexInregistrare - 1);
                        if (index_inregistrare == inregistrare.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okDUpdate = 0;
                        }
                        else
                        {
                            Inregistrare d;
                            cin >> d;
                            *index_inregistrare = d;
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okDUpdate;
                    }
                    optiuniInregistrare=5;
                    break;
                }
                case 4:
                {
                    bool okDDelete = 1;
                    while (okDDelete)
                    {
                        cout << "\nSelectati indexul inregistrarii din lista care doriti sa fie stearsa: ";
                        list<Inregistrare>::iterator index_inregistrare;
                        int indexInregistrare;
                        cin >> indexInregistrare;
                        index_inregistrare = inregistrare.begin();
                        advance(index_inregistrare, indexInregistrare - 1);
                        if (index_inregistrare == inregistrare.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okDDelete = 0;
                        }
                        else

                            inregistrare.erase(index_inregistrare);
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okDDelete;
                    }
                    optiuniInregistrare=5;
                    break;
                }
                case 5:
                {
                    optiuniInregistrare=5;
                    break;
                }
                case 6:
                {
                    bool okCalcul1 = 1;
                    while (okCalcul1)
                    {
                        cout << "\nSelectati indexul cartii din lista la care doriti sa se calculeze viteza: ";
                        list<Inregistrare>::iterator Index_inregistrare;
                        int IndexInregistrare;
                        cin >> IndexInregistrare;
                        Index_inregistrare = inregistrare.begin();
                        advance(Index_inregistrare, IndexInregistrare - 1);
                        if (Index_inregistrare == inregistrare.end())
                        {
                            cout << "\nIndex gresit" << endl;
                        }
                        else
                        {
                            Inregistrare p;
                            p = *Index_inregistrare;
                            p.calculViteza();
                            cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                            cin >> okCalcul1;
                        }
                        break;
                    }
                    break;
                }
                default:
                {
                    //optiuniinregistrare=5;
                    cout << "\nComanda gresita";
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            int optiuniAudiobook=0;
            while (optiuniAudiobook != 5)
            {
                cout << "\nSelectati operatia pe care doriti sa o efectuati:\n1 pentru CREATE\n2 pentru READ\n3 pentru UPDATE\n4 pentru DELETE\n5 pentru BACK\n5 pentru a calcula viteza" << endl;
                cout << endl;
                cin >> optiuniAudiobook;
                switch (optiuniAudiobook)
                {
                case 1:
                {
                    int optiuniAudiobookCreate=0;
                    while (optiuniAudiobookCreate != 5)
                    {
                        cout << "\nSelectati constructorul:\n1 pentru constructorul fara parametri\n2 pentru constructorul cu toti parametrii\n5 pentru back" << endl;
                        cout << endl;
                        cin >> optiuniAudiobookCreate;
                        switch (optiuniAudiobookCreate)
                        {
                        case 1:
                        {
                            Audiobook a;
                            audiobook.push_back(a);
                            break;
                        }
                        case 2:
                        {
                            Audiobook a;
                            cin >> a;
                            audiobook.push_back(a);
                            break;
                        }
                        case 5:
                        {
                            optiuniAudiobookCreate=5;
                            break;
                        }
                        default:
                        {
                            cout << "\nComanda incorecta " << endl;
                            break;
                        }
                        }
                    }
                    break;
                }
                case 2:
                {
                    bool okCRead = 1;
                    while (okCRead)
                    {
                        cout << "\nSelectati indexul audiobook-ului din lista care doriti sa fie afisata: ";
                        list<Audiobook>::iterator index_audiobook;
                        int indexAudiobook;
                        cin >> indexAudiobook;
                        index_audiobook = audiobook.begin();
                        advance(index_audiobook, indexAudiobook - 1);
                        if (index_audiobook == audiobook.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okCRead = 0;
                        }
                        else

                            cout << *index_audiobook << endl;
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okCRead;
                    }
                    optiuniAudiobook=5;
                    break;
                }
                case 3:
                {
                    bool okCUpdate = 1;
                    while (okCUpdate)
                    {
                        cout << "\nSelectati indexul audiobook-ului din lista care doriti sa fie updatata: ";
                        list<Audiobook>::iterator index_audiobook;
                        int indexAudiobook;
                        cin >> indexAudiobook;
                        index_audiobook = audiobook.begin();
                        advance(index_audiobook, indexAudiobook - 1);
                        if (index_audiobook == audiobook.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okCUpdate = 0;
                        }
                        else
                        {
                            Audiobook a;
                            cin >> a;
                            *index_audiobook = a;
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okCUpdate;
                    }
                    optiuniAudiobook=5;
                    break;
                }
                case 4:
                {
                    bool okCDelete = 1;
                    while (okCDelete)
                    {
                        cout << "\nSelectati indexul audiobook-ului din lista care doriti sa fie stearsa: ";
                        list<Audiobook>::iterator index_audiobook;
                        int indexAudiobook;
                        cin >> indexAudiobook;
                        index_audiobook = audiobook.begin();
                        advance(index_audiobook, indexAudiobook - 1);
                        if (index_audiobook == audiobook.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okCDelete = 0;
                        }
                        else
                            audiobook.erase(index_audiobook);
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okCDelete;
                    }
                    optiuniAudiobook=5;
                    break;
                }
                case 5:
                {
                    optiuniAudiobook=5;
                    break;
                }
                case 6:
                {
                    bool okCalcul2 = 1;
                    while (okCalcul2)
                    {
                        cout << "\nSelectati indexul cartii din lista la care doriti sa se calculeze viteza: ";
                        list<Audiobook>::iterator Index_audiobook;
                        int IndexAudiobook;
                        cin >> IndexAudiobook;
                        Index_audiobook = audiobook.begin();
                        advance(Index_audiobook, IndexAudiobook - 1);
                        if (Index_audiobook == audiobook.end())
                        {
                            cout << "\nIndex gresit" << endl;
                        }
                        else
                        {
                            Audiobook a;
                            a = *Index_audiobook;
                            a.calculViteza();
                            cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                            cin >> okCalcul2;
                        }
                        break;
                    }
                }
                default:
                {
                    cout << "\nComanda gresita";
                    break;
                }
                }
            }
            break;
        }
        case 4:
        {
            int optiuniLibrarie=0;
            while (optiuniLibrarie != 5)
            {
                cout << "\nSelectati operatia pe care doriti sa o efectuati:\n1 pentru CREATE\n2 pentru READ\n3 pentru UPDATE\n4 pentru DELETE\n5 pentru BACK\n6 pentru a verifica in ce librarie se gaseste o carte" << endl;
                cout << endl;
                cin >> optiuniLibrarie;
                switch (optiuniLibrarie)
                {
                case 1:
                {
                    int optiuniLibrarieCreate=0;
                    while (optiuniLibrarieCreate != 5)
                    {
                        cout << "\nSelectati constructorul:\n1 pentru constructorul fara parametri\n2 pentru constructorul cu toti parametrii\n5 pentru back" << endl;
                        cout << endl;
                        cin >> optiuniLibrarieCreate;
                        switch (optiuniLibrarieCreate)
                        {
                        case 1:
                        {
                            Librarie a;
                            librarie.push_back(a);
                            break;
                        }
                        case 2:
                        {
                            Librarie a;
                            cin >> a;
                            librarie.push_back(a);
                            break;
                        }
                        case 5:
                        {
                            optiuniLibrarieCreate=5;
                            break;
                        }
                        default:
                        {
                            cout << "\nComanda incorecta " << endl;
                            break;
                        }
                        }
                    }
                    break;
                }
                case 2:
                {
                    bool okCRead = 1;
                    while (okCRead)
                    {
                        cout << "\nSelectati indexul librariei din lista care doriti sa fie afisata: ";
                        list<Librarie>::iterator index_librarie;
                        int indexLibrarie;
                        cin >> indexLibrarie;
                        index_librarie = librarie.begin();
                        advance(index_librarie, indexLibrarie - 1);
                        if (index_librarie == librarie.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okCRead = 0;
                        }
                        else

                            cout << *index_librarie << endl;
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okCRead;
                    }
                    optiuniLibrarie=5;
                    break;
                }
                case 3:
                {
                    bool okCUpdate = 1;
                    while (okCUpdate)
                    {
                        cout << "\nSelectati indexul librariei din lista care doriti sa fie updatata: ";
                        list<Librarie>::iterator index_librarie;
                        int indexLibrarie;
                        cin >> indexLibrarie;
                        index_librarie = librarie.begin();
                        advance(index_librarie, indexLibrarie - 1);
                        if (index_librarie == librarie.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okCUpdate = 0;
                        }
                        else
                        {
                            Librarie a;
                            cin >> a;
                            *index_librarie = a;
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okCUpdate;
                    }
                    optiuniLibrarie=5;
                    break;
                }
                case 4:
                {
                    bool okCDelete = 1;
                    while (okCDelete)
                    {
                        cout << "\nSelectati indexul librariei din lista care doriti sa fie stearsa: ";
                        list<Librarie>::iterator index_librarie;
                        int indexLibrarie;
                        cin >> indexLibrarie;
                        index_librarie = librarie.begin();
                        advance(index_librarie, indexLibrarie - 1);
                        if (index_librarie == librarie.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okCDelete = 0;
                        }
                        else
                            librarie.erase(index_librarie);
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okCDelete;

                    }
                    optiuniLibrarie=5;
                    break;
                }
                case 5:
                {
                    optiuniLibrarie=5;
                    break;
                }
                case 6:
                {
                    bool okVerif = 1;
                    while (okVerif)
                    {
                        cout << "\nSelectati indexul cartii din lista la care doriti sa se faca verificarea: ";
                        list<Carte>::iterator Index_carte;
                        int IndexCarte;
                        cin >> IndexCarte;
                        Index_carte = carte.begin();
                        advance(Index_carte, IndexCarte - 1);
                        if (Index_carte == carte.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okDetinregistrare = 0;
                        }
                        else
                        {
                            cout << "\nSelectati indexul librariei din lista la care doriti sa se faca verificarea: ";
                            list<Librarie>::iterator Index_Librarie;
                            int IndexLibrarie;
                            cin >> IndexLibrarie;
                            Index_Librarie = librarie.begin();
                            advance(Index_Librarie, IndexLibrarie - 1);
                            if (Index_Librarie == librarie.end())
                            {
                                cout << "\nIndex gresit" << endl;
                                //okDetinregistrare = 0;
                            }
                            else
                            {
                                Carte c;
                                Librarie d;
                                c = *Index_carte;
                                d = *Index_Librarie;
                                d.VerifCarteInLibrarie(d,c);
                                cout<<endl;
                            }
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okVerif;
                    }
                    break;
                }
                default:
                {
                    cout << "\nComanda gresita";
                    break;
                }
                }
            }
            break;
        }
        case 5:
        {
            comanda=5;
            break;
        }
        default:
        {
            cout << "\nComanda gresita";
            break;
        }
        }
    }
}
int main()
{
    meniuInteractiv();
    return 0;
}
