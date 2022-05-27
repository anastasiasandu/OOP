#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <set>
#include <map>
#include <typeinfo>
#include <exception>
#include <stdexcept>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;
using std::runtime_error;

template<class T>
void interface(T x)
{
    cin >> x;
    cout << x;
}
template <typename A>
A findMax(A x, A y)
{
    if(x>y)
        return x;
    return y;
}
template <typename C>
C findMin(C x, C y)
{
    if(x<y)
        return x;
    return y;
}
template <typename T>
T Max(vector<T>x, int n)
{
    T Maxx=x[0];
    for(int i=0; i<n; i++)
        if(x[i]>Maxx)
            Maxx=x[i];
    return Maxx;
}
template <typename B>
vector<B> Sort(vector<B>x, int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(x[i]>x[j])
            {
                B aux;
                aux=x[i];
                x[i]=x[j];
                x[j]=aux;
            }
    return x;
}
template<typename A>
class Garantie
{
private:
    int durata;
    string numeCumparator;
    int nrProduse;
    int zi;
    int luna;
    int an;
    A* produse;
public:
    Garantie()
    {
        this->durata=0;
        this->numeCumparator="";
        this->nrProduse=0;
        this->produse=NULL;
        this->zi=0;
        this->luna=0;
        this->an=0;
    }
    Garantie(int  durata, string numeCumparator, int nrProduse, A* produse, int zi, int luna, int an)
    {
        this->durata=durata;
        this->numeCumparator=numeCumparator;
        this->nrProduse=nrProduse;
        if(this->nrProduse!=0)
        {
            this->produse=new A[this->nrProduse];
            for(int i=0; i<this->nrProduse; i++)
                this->produse[i]=produse[i];
        }
        else this->produse=NULL;
        this->zi=zi;
        this->luna=luna;
        this->an=an;
    };
    void afis()
    {
        cout<<"\nNumele Cumparatorului este: "<<this->numeCumparator;
        cout<<"\nGarantia este pe durata de "<<this->durata<<" de ani.";
        cout<<"\nNumarul de produse este: "<<this->nrProduse;
        if(this->nrProduse!=0)
        {
            cout<<"\nProdusele sunt: ";
            for(int i=0; i<this->nrProduse; i++)
                cout<<endl<<this->produse[i];
        }
        cout<<"\nData achizitiei este: "<<this->zi<<"/"<<this->luna<<"/"<<this->an;
    };
    /*friend ostream& operator<<(ostream& out, const Garantie& gar)
    {
        out<<"\Numele cumparatorului este: "<<gar.numeCumparator;
        out<<"\nDurata garantiei este de: "<<gar.durata;
        out<<"\Numarul de produse este: "<<gar.nrProduse;
        out<<"\nProdusele sunt: ";
        for(int i=0; i<gar.nrProduse; i++)
            cout<<gar.produse[i]<<endl;
        out<<"\nData este: "<<gar.zi<<"/"<<gar.luna<<"/"<<gar.n;
        return out;
    };
    friend istream& operator>>(istream& in, Garantie& gar)
    {
        cout<<"\nIntroduceti durata: ";
        in>>gar.durata;
        cout<<"\nIntroduceti numele cumparatorului: ";
        in>>gar.numeCumparator;
        cout<<"\nIntroduceti numarul de produse: ";
        in>>gar.nrProduse;
        gar.produse=new A[gar.nrProduse];
        cout<<"\nIntroduceti produsele: ";
        for(int i=0; i<gar.nrProduse; i++)
            in>>gar.produse[i];
        cout<<"\nIntroduceti data: ";
        cout<<"\nZiua: ";
        in>>gar.zi;
        cout<<"\nLuna: ";
        in>>gar.luna;
        cout<<"\nAnul: ";
        in>>gar.an;
        return in;
    };*/
    void determinareValabilitate()
    {
        cout<<"\nIntroduceti data de azi: ";
        cout<<"\nZiua: ";
        int zi;
        cin>>zi;
        cout<<"\nLuna: ";
        int luna;
        cin>>luna;
        cout<<"\nAnul: ";
        int an;
        cin>>an;
        int anSfGarantie;
        anSfGarantie= this->an + this->durata;
        if( anSfGarantie > an )
            cout<<"\nNe pare rau! Nu se mai afla in garantie";
        else  if  ( anSfGarantie == an && this->luna < luna )
            cout<<"\nNe pare rau! Nu se mai afla in garantie";
        else  if ( anSfGarantie == an && this->luna == luna && this->zi <= zi)
            cout<<"\nNe pare rau! Nu se mai afla in garantie";
        else cout<<"\nInca se afla in garantie!";
    }
    ~Garantie()
    {
        if (this->produse!=NULL)
            delete[] this->produse;
    } ;
};

class CitireAfisare
{
public:
    virtual ostream& Afisare(ostream& out)const=0;
    virtual istream& Citire(istream& in)=0;
};
//----------------------------------------------------------------------
class instrumentMuzical:public CitireAfisare
{
protected:
    double pret;
    double latime;
    double inaltime;
    string culoare;
    string nume;
public:
    instrumentMuzical();
    instrumentMuzical(double pret, double latime, double inaltime, string culoare, string nume);
    instrumentMuzical(double pret);

    instrumentMuzical(const instrumentMuzical& instr);

    instrumentMuzical& operator=(const instrumentMuzical& instr);

    string getNume();

    void setPret(double pret);

    double getPret();

    bool operator==(const instrumentMuzical& instr);
    bool operator>(const instrumentMuzical& instr);
    bool operator<(const instrumentMuzical& instr);

    instrumentMuzical operator+(int x);
    instrumentMuzical operator+(instrumentMuzical instr);
    friend instrumentMuzical operator+(int x, instrumentMuzical instr);
    instrumentMuzical operator+=(int x);

    instrumentMuzical operator-(int x);
    instrumentMuzical operator-(instrumentMuzical instr);
    friend instrumentMuzical operator-(int x, instrumentMuzical instr);
    instrumentMuzical operator-=(int x);

    virtual ostream& Afisare(ostream& out)const;
    virtual istream& Citire(istream& in);

    friend ostream& operator<<(ostream& out, const instrumentMuzical& instr);
    friend istream& operator>>(istream& in, instrumentMuzical& instr);

    void verifInstrument();

    ~instrumentMuzical() {};
};
double instrumentMuzical::getPret()
{
    return this->pret;
}
string instrumentMuzical::getNume()
{
    return this->nume;
}
void instrumentMuzical::setPret(double pret)
{
    this->pret=pret;
}
ostream& instrumentMuzical::Afisare(ostream& out)const
{
    out<<"\nNumele este: "<<this->nume;
    out<<"\nPretul este: "<<this->pret;
    out<<"\nLatimea este: "<<this->latime;
    out<<"\nInaltimea este: "<<this->inaltime;
    out<<"\nCuloarea este: "<<this->culoare;
    return out;
}
istream& instrumentMuzical::Citire(istream& in)
{
    cout<<"\nIntroduceti numele: ";
    in>>this->nume;
    cout<<"\nIntroduceti pretul: ";
    in>>this->pret;
    cout<<"\nIntroduceti latimea: ";
    in>>this->latime;
    cout<<"\nIntroduceti inaltimea: ";
    in>>this->inaltime;
    cout<<"\nIntroduceti culoarea: ";
    in>>this->culoare;
    return in;
}
istream& operator>>(istream& in, instrumentMuzical& instr)
{
    return instr.Citire(in);
}
ostream& operator<<(ostream& out, const instrumentMuzical& instr)
{
    return instr.Afisare(out);
}
instrumentMuzical::instrumentMuzical()
{
    this->pret=0;
    this->latime=0;
    this->inaltime=0;
    this->culoare="";
    this->nume="";
}
instrumentMuzical::instrumentMuzical(double pret)
{
    this->pret=pret;
    this->latime=0;
    this->inaltime=0;
    this->culoare="";
    this->nume="";
}
instrumentMuzical::instrumentMuzical(double pret, double latime, double inaltime, string culoare, string nume)
{
    this->pret=pret;
    this->latime=latime;
    this->inaltime=inaltime;
    this->culoare=culoare;
    this->nume=nume;
}
instrumentMuzical::instrumentMuzical(const instrumentMuzical& instr)
{
    this->pret=instr.pret;
    this->latime=instr.latime;
    this->inaltime=instr.inaltime;
    this->culoare=instr.culoare;
    this->nume=instr.nume;
}
instrumentMuzical& instrumentMuzical::operator=(const instrumentMuzical& instr)
{
    if(this!=&instr)
    {
        this->pret=instr.pret;
        this->latime=instr.latime;
        this->inaltime=instr.inaltime;
        this->culoare=instr.culoare;
        this->nume=instr.nume;
    }
    return *this;
}
bool instrumentMuzical::operator==(const instrumentMuzical& instr)
{
    if(this->pret==instr.pret && this->inaltime==instr.inaltime && this->latime==instr.latime && this->culoare==instr.culoare && this->nume == instr.nume)
        return true;
    return false;
}
bool instrumentMuzical::operator>(const instrumentMuzical& instr)
{
    if(this->pret>instr.pret)
        return true;
    return false;
}
bool instrumentMuzical::operator<(const instrumentMuzical& instr)
{
    if(this->pret < instr.pret )
        return true;
    return false;
}
instrumentMuzical instrumentMuzical::operator+(int x)
{
    instrumentMuzical aux=*this;
    aux.pret=aux.pret +x;
    return aux;
}
instrumentMuzical instrumentMuzical::operator+(instrumentMuzical instr)
{
    instrumentMuzical aux = *this;
    /*
    aux.inaltime = aux.inaltime + instr.inaltime;
    aux.latime = aux.latime + instr.latime;
    aux.culoare = aux.culoare + instr.culoare;
    aux.nume=aux.nume+instr.nume;*/
    aux.pret = aux.pret + instr.pret;
    return aux;
}
instrumentMuzical operator+(int x, instrumentMuzical instr)
{
    instrumentMuzical aux=instr;
    aux.pret = x+aux.pret;
    return aux;
}
instrumentMuzical instrumentMuzical::operator+=(int x)
{
    this->pret = this->pret + x;
    return *this;
}
instrumentMuzical instrumentMuzical::operator-(int x)
{
    instrumentMuzical aux=*this;
    aux.pret=aux.pret - x;
    return aux;
}
instrumentMuzical instrumentMuzical::operator-(instrumentMuzical instr)
{
    instrumentMuzical aux=*this;
    aux.pret = aux.pret - instr.pret;
    return aux;
}
instrumentMuzical operator-(int x, instrumentMuzical instr)
{
    instr.pret = x-instr.pret;
    return instr;
}
instrumentMuzical instrumentMuzical::operator-=(int x)
{
    this->pret = this->pret - x;
    return *this;
}
void instrumentMuzical::verifInstrument()
{
    cout<<"\nCe instrument muzical va doriti? ";
    string nume;
    cin>>nume;
    if(this->nume!=nume)
        cout<<"\nNe pare rau! Nu este acesta";
    else
    {
        cout<<"\nCe culoare va doriti?";
        string culoare;
        cin>>culoare;
        if(culoare!=this->culoare)
            cout<<"\nNe pare rau! Nu este acesta";
        else cout<<"\nAcesta este!";
    }
}
//-------------------------------------------------------------------------------------------------------------------------
class Chitara:public instrumentMuzical
{
protected:
    int nrCorzi;
    int nrCheiDeAcordare;
    string taraDeFabricatie;
    string material;
    string finisajSuprafata;
    string tip;
public:
    Chitara();
    Chitara(double pret, double latime, double inaltime, string culoare, string nume, int nrCorzi, int nrCheiDeAcordare, string taraDeFabricatie, string material, string finisajSuprafata, string tip);
    Chitara(int nrCorzi, double pret);

    Chitara(const Chitara& chit);

    Chitara& operator=(const Chitara& chit);

    void setNrCorzi(int nrCorzi);
    int getNrCorzi();

    bool operator==(const Chitara& chit);

    string getTaraDeFabricatie();

    Chitara operator+(int x);
    Chitara operator+(Chitara chit);
    friend Chitara operator+(int x, Chitara chit);
    Chitara operator+=(int x);

    Chitara operator-(int x);
    Chitara operator-(Chitara chit);
    friend Chitara operator-(int x, Chitara chit);
    Chitara operator-=(int x);

    ostream& Afisare(ostream& out)const;
    istream& Citire(istream& in);

    void ceTipDeChitaraAiNevoie();

    ~Chitara() {};
};
void Chitara::setNrCorzi(int nrCorzi)
{
    this->nrCorzi=nrCorzi;
}
int Chitara::getNrCorzi()
{
    return this->nrCorzi;
}
string Chitara::getTaraDeFabricatie()
{
    return this->taraDeFabricatie;
}
Chitara::Chitara():instrumentMuzical()
{
    this->nrCorzi=0;
    this->nrCheiDeAcordare=0;
    this->taraDeFabricatie="";
    this->material="";
    this->finisajSuprafata="";
    this->tip="";
}
Chitara::Chitara(int nrCorzi, double pret):instrumentMuzical(pret)
{
    this->nrCorzi=nrCorzi;
    this->nrCheiDeAcordare=0;
    this->taraDeFabricatie="";
    this->material="";
    this->finisajSuprafata="";
    this->tip="";
}
Chitara::Chitara(double pret, double latime, double inaltime, string culoare, string nume, int nrCorzi, int nrCheiDeAcordare, string taraDeFabricatie, string material, string finisajSuprafata, string tip):instrumentMuzical(pret, latime, inaltime, culoare, nume)
{
    this->nrCorzi=nrCorzi;
    this->nrCheiDeAcordare=nrCheiDeAcordare;
    this->taraDeFabricatie=taraDeFabricatie;
    this->material=material;
    this->finisajSuprafata=finisajSuprafata;
    this->tip=tip;
}
Chitara::Chitara(const Chitara& chit):instrumentMuzical(chit)
{
    this->nrCorzi=chit.nrCorzi;
    this->nrCheiDeAcordare=chit.nrCheiDeAcordare;
    this->taraDeFabricatie=chit.taraDeFabricatie;
    this->material=chit.material;
    this->finisajSuprafata=chit.finisajSuprafata;
    this->tip=chit.tip;
}
Chitara& Chitara::operator=(const Chitara& chit)
{
    if(this!=&chit)
    {
        instrumentMuzical::operator=(chit);
        this->nrCorzi=chit.nrCorzi;
        this->nrCheiDeAcordare=chit.nrCheiDeAcordare;
        this->taraDeFabricatie=chit.taraDeFabricatie;
        this->material=chit.material;
        this->finisajSuprafata=chit.finisajSuprafata;
        this->tip=chit.tip;
    }
    return *this;
}
istream& Chitara::Citire(istream& in)
{
    instrumentMuzical::Citire(in);
    cout<<"\nNumarul de corzi este: ";
    in>>this->nrCorzi;
    cout<<"\nNumarul de chei de acordare este: ";
    in>>this->nrCheiDeAcordare;
    cout<<"\nTara de fabricatie: ";
    try
    {
        in>>this->taraDeFabricatie;
        string s=this->taraDeFabricatie;
        std::string::const_iterator it=s.begin();
        while(it!=s.end() && std::isdigit(*it))
            ++it;
        if(it==s.end() && s.empty()==0)
            throw std::invalid_argument("Bad argument");
    }
    catch (invalid_argument)
    {
        cout<< "\nExceptie: ";
        cout<<"\nEste nevoie sa introduceti un string "<<endl;
    }
    catch(...)
    {
        cout<<"\n Exceptie prinsa";
    }
    cout<<"\nMaterialul este: ";
    try
    {
        in>>this->material;
        string s=this->material;
        std::string::const_iterator it=s.begin();
        while(it!=s.end() && std::isdigit(*it))
            ++it;
        if(it==s.end() && s.empty()==0)
            throw std::invalid_argument("Bad argument");
    }
    catch (invalid_argument)
    {
        cout<< "\nExceptie: ";
        cout<<"\nEste nevoie sa introduceti un string "<<endl;
    }
    catch(...)
    {
        cout<<"\n Exceptie prinsa";
    }
    cout<<"\nFinisajul de suprafata este: ";
    try
    {
        in>>this->finisajSuprafata;
        string s=this->finisajSuprafata;
        std::string::const_iterator it=s.begin();
        while(it!=s.end() && std::isdigit(*it))
            ++it;
        if(it==s.end() && s.empty()==0)
            throw std::invalid_argument("Bad argument");
    }
    catch (invalid_argument)
    {
        cout<< "\nExceptie: ";
        cout<<"\nEste nevoie sa introduceti un string "<<endl;
    }
    catch(...)
    {
        cout<<"\n Exceptie prinsa";
    }
    cout<<"\nTipul este: ";
    try
    {
        in>>this->tip;
        string s=this->tip;
        std::string::const_iterator it=s.begin();
        while(it!=s.end() && std::isdigit(*it))
            ++it;
        if(it==s.end() && s.empty()==0)
            throw std::invalid_argument("Bad argument");
    }
    catch (invalid_argument)
    {
        cout<< "\nExceptie: ";
        cout<<"\nEste nevoie sa introduceti un string "<<endl;
    }
    catch(...)
    {
        cout<<"\n Exceptie prinsa";
    }
    return in;
}
ostream& Chitara::Afisare(ostream& out)const
{
    instrumentMuzical::Afisare(out);
    out<<"\nNumarul de corzi este: "<<this->nrCorzi;
    out<<"\nNumarul de chei de acordare este :"<<this->nrCheiDeAcordare;
    out<<"\nTara de fabricatie este: "<<this->taraDeFabricatie;
    out<<"\nMaterialul este: "<<this->material;
    out<<"\nFinisajul de suprafata este: "<<this->finisajSuprafata;
    out<<"\nTipul este: "<<this->tip;
    return out;
}
Chitara Chitara::operator+(int x)
{
    /*instrumentMuzical i;
    Chitara *c;
    c = dynamic_cast<Chitara*> (&i);
    c->operator+(x);
    return *c;*/                                                                   //!am incercat dynamic_cast

    /* Chitara aux=*this;
     instrumentMuzical* instr=static_cast<Chitara*>(&aux);
     instr->operator+(x);*/

    /*instrumentMuzical instr;
    Chitara* chit(this);
    chit=(Chitara*)&instr;
    chit->operator+(x);
    return *chit;*/

    /*
    Chitara aux1;
    instrumentMuzical* instr1=aux;
    cout<<aux;

    Chitara aux1(*this);
    instrumentMuzical aux(aux1.getPret());
    aux=aux+x;
    aux1.pret=aux.getPret();
    aux1.nrCorzi=aux1.nrCorzi+x;
    return aux1;*/


    Chitara aux=*this;
    double pret=aux.getPret();                                           //!am evitat dynamic_cast
    instrumentMuzical i(pret);
    i=i+x;
    cout<<i.getPret()<<endl;
    aux.setPret(i.getPret());
    aux.nrCorzi=aux.nrCorzi+x;
    return aux;
}
Chitara Chitara::operator+(Chitara chit)
{
    /*cout<<"---------------------------------";
    Chitara aux=*this;

    aux.nrCorzi=chit.nrCorzi+this->nrCorzi;
    aux.nrCheiDeAcordare=chit.nrCheiDeAcordare+this->nrCheiDeAcordare;
    aux.taraDeFabricatie=chit.taraDeFabricatie+this->taraDeFabricatie;
    aux.material=chit.material+this->material;
    aux.finisajSuprafata=chit.finisajSuprafata+this->finisajSuprafata;
    aux.tip=chit.tip+this->tip;
    instrumentMuzical i=static_cast<instrumentMuzical&>(aux);
    cout<<"****************************************************"<<endl<<i;
    instrumentMuzical k=static_cast<instrumentMuzical&>(chit);
    cout<<endl<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl<<k;
    instrumentMuzical suma=k+i;

    aux.nrCorzi=chit.nrCorzi+this->nrCorzi;
    aux.nrCheiDeAcordare=chit.nrCheiDeAcordare+this->nrCheiDeAcordare;
    aux.taraDeFabricatie=chit.taraDeFabricatie+this->taraDeFabricatie;
    aux.material=chit.material+this->material;
    aux.finisajSuprafata=chit.finisajSuprafata+this->finisajSuprafata;
    aux.tip=chit.tip+this->tip;*/

    /*    &i=dynamic_cast<instrumentMuzical&>(&aux);
        &i=dynamic_cast<instrumentMuzical&>(&chit);
    */                                                                          //!am incercat iar dynamic_cast

    Chitara aux=*this;
    instrumentMuzical i;
    i=instrumentMuzical::operator+(chit);
    aux.setPret(i.getPret());
    aux.nrCorzi=aux.nrCorzi+chit.nrCorzi;
    return aux;
}
Chitara operator+(int x, Chitara chit)
{
    double pret=chit.getPret();
    instrumentMuzical i(pret);
    i=x+i;
    chit.setPret(i.getPret());
    chit.nrCorzi=x+chit.nrCorzi;
    return chit;
}
Chitara Chitara::operator+=(int x)
{
    this->nrCorzi+=x;
    instrumentMuzical::operator+=(x);
    return *this;
}
Chitara Chitara::operator-(int x)
{
    Chitara aux=*this;
    double pret=aux.getPret();
    instrumentMuzical i(pret);
    i=i-x;
    aux.setPret(i.getPret());
    aux.nrCorzi=aux.nrCorzi-x;
    return aux;
}
Chitara Chitara::operator-(Chitara chit)
{
    Chitara aux=*this;
    instrumentMuzical i;
    i=instrumentMuzical::operator-(chit);
    aux.setPret(i.getPret());
    aux.nrCorzi=aux.nrCorzi-chit.nrCorzi;
    return aux;
}
Chitara operator-(int x, Chitara chit)
{
    double pret=chit.getPret();
    instrumentMuzical i(pret);
    i=x-i;
    chit.setPret(i.getPret());
    chit.nrCorzi=x-chit.nrCorzi;
    return chit;
}
Chitara Chitara::operator-=(int x)
{
    instrumentMuzical::operator-=(x);
    this->nrCorzi=this->nrCorzi-x;
    return *this;
}
bool Chitara::operator==(const Chitara& chit)
{
    bool ok=instrumentMuzical::operator==(chit);
    if(ok==1 && this->nrCorzi==chit.nrCorzi && this->nrCheiDeAcordare==chit.nrCheiDeAcordare && this->taraDeFabricatie==chit.taraDeFabricatie && this->finisajSuprafata==chit.finisajSuprafata && this->material== chit.material && this->tip==chit.tip)
        return true;
    else return false;
}
void Chitara::ceTipDeChitaraAiNevoie()
{
    cout<<"\nDaca va intereseaza genurile muzicale: \nFolk, Pop, Balade atunci va recomandam o chitara acustica \nMuzica Clasica, Latino atunci va recomandam o chitara clasica\nRock, Blues, Jazz atunci va recomandam o chitara electrica \nRock, Pop, Funk atunci va recomandam o chitara bass";
}

//------------------------------------------------------------------------------------------------------------------------------------
class chitaraElectrica:public Chitara
{
protected:
    string comutator;
    int lungimeCablu;
public:
    chitaraElectrica();
    chitaraElectrica(string comutator, int lungimeCablu, double pret, double latime, double inaltime, string culoare, string nume, int nrCorzi, int nrCheiDeAcordare, string taraDeFabricatie, string material, string finisajSuprafata, string tip);

    chitaraElectrica(const chitaraElectrica& elec);
    chitaraElectrica& operator=(const chitaraElectrica& elec);

    bool operator==(const chitaraElectrica& elec);

    chitaraElectrica operator+(int x);
    chitaraElectrica operator+(chitaraElectrica elec);
    friend chitaraElectrica operator+(int x, chitaraElectrica elec);
    chitaraElectrica operator+=(int x);

    chitaraElectrica operator-(int x);
    chitaraElectrica operator-(chitaraElectrica elec);
    friend chitaraElectrica operator-(int x, chitaraElectrica elec);
    chitaraElectrica operator-=(int x);

    ostream& Afisare(ostream& out)const;
    istream& Citire(istream& in);

    void alegereChitara();

    ~chitaraElectrica() {};
};
chitaraElectrica::chitaraElectrica():Chitara()
{
    this->comutator="";
    this->lungimeCablu=0;
}
chitaraElectrica::chitaraElectrica(string comutator, int lungimeCablu, double pret, double latime, double inaltime, string culoare, string nume, int nrCorzi, int nrCheiDeAcordare, string taraDeFabricatie, string material, string finisajSuprafata, string tip):Chitara(pret, latime, inaltime, nume, culoare, nrCorzi, nrCheiDeAcordare, taraDeFabricatie, material, finisajSuprafata, tip)
{
    this->comutator=comutator;
    this->lungimeCablu=lungimeCablu;
}
chitaraElectrica::chitaraElectrica(const chitaraElectrica& elec):Chitara(elec)
{
    this->comutator=elec.comutator;
    this->lungimeCablu=elec.lungimeCablu;
}
chitaraElectrica& chitaraElectrica::operator=(const chitaraElectrica& elec)
{
    if(this!=&elec)
    {
        Chitara::operator=(elec);
        this->comutator=elec.comutator;
        this->lungimeCablu=elec.lungimeCablu;
    }
    return *this;
}
bool chitaraElectrica::operator==(const chitaraElectrica& elec)
{
    bool ok=Chitara::operator==(elec);
    if(ok && this->comutator == elec.comutator && this->lungimeCablu == elec.lungimeCablu)
        return true;
    return false;
}
chitaraElectrica chitaraElectrica::operator+(int x)
{
    chitaraElectrica aux(*this);
    int nrCorzi=aux.getNrCorzi();
    double pret=aux.getPret();
    Chitara i(nrCorzi,pret);
    i=i+x;
    aux.setNrCorzi(i.getNrCorzi());
    aux.setPret(i.getPret());
    aux.lungimeCablu=aux.lungimeCablu+x;
    return aux;
}
chitaraElectrica chitaraElectrica::operator+(chitaraElectrica elec)
{
    chitaraElectrica aux=*this;
    Chitara i;
    i=Chitara::operator+(elec);
    aux.setNrCorzi(i.getNrCorzi());
    aux.setPret(i.getPret());
    aux.lungimeCablu=this->lungimeCablu+elec.lungimeCablu;
    return aux;
}
chitaraElectrica operator+(int x, chitaraElectrica elec)
{
    chitaraElectrica aux(elec);
    int nrCorzi=aux.getNrCorzi();
    double pret=aux.getPret();
    Chitara i(nrCorzi,pret);
    i=x+i;
    elec.setNrCorzi(i.getNrCorzi());
    elec.setPret(i.getPret());
    cout<<elec.getPret()<<endl;
    elec.lungimeCablu=elec.lungimeCablu+x;
    return elec;
}
chitaraElectrica chitaraElectrica::operator+=(int x)
{
    Chitara::operator+=(x);
    this->lungimeCablu+=x;
    return *this;
}
chitaraElectrica chitaraElectrica::operator-(int x)
{
    chitaraElectrica aux(*this);
    int nrCorzi=aux.getNrCorzi();
    double pret=aux.getPret();
    Chitara i(nrCorzi,pret);
    i=i-x;
    aux.setNrCorzi(i.getNrCorzi());
    aux.setPret(i.getPret());
    aux.lungimeCablu=aux.lungimeCablu-x;
    return aux;
}
chitaraElectrica chitaraElectrica::operator-(chitaraElectrica elec)
{
    chitaraElectrica aux=*this;
    Chitara i;
    i=Chitara::operator-(elec);
    aux.setNrCorzi(i.getNrCorzi());
    aux.setPret(i.getPret());
    aux.lungimeCablu=this->lungimeCablu-elec.lungimeCablu;
    return aux;
}
chitaraElectrica operator-(int x, chitaraElectrica elec)
{
    chitaraElectrica aux(elec);
    int nrCorzi=aux.getNrCorzi();
    cout<<elec.getPret()<<endl;
    double pret=aux.getPret();
    Chitara i(nrCorzi,pret);
    i=x-i;
    elec.setNrCorzi(i.getNrCorzi());
    elec.setPret(i.getPret());
    cout<<elec.getPret()<<endl;
    elec.lungimeCablu=elec.lungimeCablu-x;
    return elec;
}
chitaraElectrica chitaraElectrica::operator-=(int x)
{
    Chitara::operator-=(x);
    this->lungimeCablu-=x;
    return *this;
}
ostream& chitaraElectrica::Afisare(ostream& out)const
{
    Chitara::Afisare(out);
    out<<"\nComutatorul este: "<<this->comutator;
    out<<"\nLungimea cablului este: "<<this->lungimeCablu;
    return out;
}
istream& chitaraElectrica::Citire(istream& in)
{
    Chitara::Citire(in);
    cout<<"\nComutatorul este: ";
    in>>this->comutator;
    cout<<"\nLungimea cablului este: ";
    in>>this->lungimeCablu;
    return in;
}
void chitaraElectrica::alegereChitara()
{
    int varsta;
    cout<<"\nIntroduceti varsta dumneavoastra: ";
    try
    {
        cin>>varsta;
        if(varsta!=0)
        {
            if(varsta>=5 && varsta <7)
                cout<<"\nVa recomandam o chitara de 1/4 de aproximativ 68 de cm lungime!";
            else if(varsta>=7 && varsta<10)
                cout<<"\nVa recomandam o chitara de 3/4 de aproximativ 72 de cm lungime!";
            else cout<<"\Va recomandam o chitara de 4/4 de aproximativ 96 de cm lungime!";
        }
        else throw string("\nExceptie \nEste nevoie sa introduceti o varsta valida");
    }
    catch (string s)
    {
        cout<<s;
    }
    catch(...)
    {
        cout<<"\n Exceptie prinsa";
    }

}
//----------------------------------------------------------------------------------------------------------------------
class Magazin
{
private:
    string nume;
    string adresa;
    list <instrumentMuzical> Instrumente;
    set <double> preturi;
public:
    Magazin();
    Magazin(string nume, string adresa, list <instrumentMuzical> Instrumente, set <double> preturi);

    Magazin(const Magazin& mag);

    Magazin& operator=(const Magazin& mag);

    list<instrumentMuzical>::iterator getBegin()
    {
        return this->Instrumente.begin();
    };
    list<instrumentMuzical>::iterator getEnd()
    {
        return this->Instrumente.end();
    };

    friend ostream& operator<<(ostream& out,Magazin m);
    friend istream& operator>>(istream& in, Magazin& m);

    void VerifInstrumentInMagazin(Magazin mag);
    void VerificarePret();

    friend Magazin operator+(instrumentMuzical& instr, Magazin mag);
    friend Magazin operator+(Magazin mag, instrumentMuzical& instr);

    instrumentMuzical operator[](int index)
    {
        list<instrumentMuzical>::iterator index_instrument = this->Instrumente.begin();
        advance(index_instrument, index);
        return *index_instrument;
    };

    bool operator>(const Magazin& mag);
    bool operator<(const Magazin& mag);
    ~Magazin();
};
Magazin::Magazin()
{
    this->nume="";
    this->adresa="";
    this->Instrumente= {};
}
Magazin::Magazin(string nume, string adresa, list <instrumentMuzical> Instrumente, set <double> preturi )
{
    this->nume=nume;
    this->adresa=adresa;
    this->Instrumente=Instrumente;
    list<instrumentMuzical>::iterator index_instrument;
    for( index_instrument = Instrumente.begin(); index_instrument!=Instrumente.end(); index_instrument++)
    {
        instrumentMuzical instr;
        instr=*index_instrument;
        preturi.insert(instr.getPret());
    }

}
Magazin::Magazin(const Magazin& mag)
{
    this->nume=mag.nume;
    this->adresa=mag.adresa;
    this->Instrumente=mag.Instrumente;
    this->preturi=mag.preturi;
}
Magazin& Magazin::operator=(const Magazin& mag)
{
    if(this!=&mag)
    {
        this->nume=mag.nume;
        this->adresa=mag.adresa;
        this->Instrumente=mag.Instrumente;
        this->preturi=mag.preturi;
    }
    return *this;
}
Magazin operator+ (Magazin mag, instrumentMuzical& instr)
{
    mag.Instrumente.push_back(instr);
    return mag;
}
Magazin operator+ (instrumentMuzical& instr, Magazin mag)
{
    mag.Instrumente.push_back(instr);
    return mag;
}
Magazin::~Magazin()
{
    try
    {
        if(Instrumente.empty()==0)
            Instrumente.clear();
        else throw string("\nLista trebuie sa fie vida pentru a fi stearsa ");
    }
    catch(string s)
    {
        cout<<s;
    }
    catch(...)
    {
        cout<<"\nExceptie";
    }
    try
    {
        if(preturi.empty()==0)
            preturi.erase(preturi.begin(),preturi.end());
        else throw string("\nSetul trebuie sa fie vid pentru a fi sters ");
    }
    catch(string s)
    {
        cout<<s;
    }
    catch(...)
    {
        cout<<"\nExceptie";
    }
}
bool Magazin::operator>(const Magazin& mag)
{
    if(this->Instrumente.size() > mag.Instrumente.size())
        return true;
    return false;
}
bool Magazin::operator<(const Magazin& mag)
{
    if(this->Instrumente.size() < mag.Instrumente.size())
        return true;
    return false;
}
void Magazin::VerifInstrumentInMagazin(Magazin mag)
{
    cout<<"\nIntroduceti instrumentul pe care doriti sa il cautati in magazinul "<<mag.nume<<" de la adresa "<<mag.adresa<<endl;
    string instr;
    cin>>instr;
    list<instrumentMuzical>::iterator index_instrument;
    bool ok=0;
    for( index_instrument = Instrumente.begin(); index_instrument!=Instrumente.end(); index_instrument++)
    {
        instrumentMuzical i;
        i=*index_instrument;
        if(i.getNume() == instr)
        {
            ok=1;
            break;
        }
    }
    if(ok)
        cout<<"\nInstrumentul se gaseste in magazin ";
    else cout<<"\nNe pare rau! Nu se gaseste.";
}
void Magazin::VerificarePret()
{
    cout<<"\nCare este bugetul dvs? ";
    double buget;
    cin>>buget;
    cout<<"\Vom verifica daca in magazinul "<<this->nume<<" avem articole in acest pret.";
    if (buget>=*preturi.begin())
        cout<<"\nAvem!";
    else cout<<"\nNe pare rau! Nu avem!";
}
istream& operator>>(istream& in, Magazin& m)
{
    cout << "\nIntroduceti numele magazinului: ";
    in >> m.nume;
    cout<< "\nIntroduceti adresa magazinului: ";
    in>>m.adresa;
    int k = 1, comanda;
    while (k == 1)
    {
        cout << "\n1 pentru ADAUGA si 2 pentru STOP\n";
        cin >> comanda;
        switch(comanda)
        {

        case 1:
        {
            instrumentMuzical instr;
            cin >> instr;
            m.Instrumente.push_back(instr);
            m.preturi.insert( instr.getPret() );
            break;
        }
        case 2:
        {
            k = 0;
            break;
        }
        default:
        {
            cout << "\nComanda incorecta\n";
            break;
        }
        }
    }
    return in;
}
ostream& operator<< (ostream& out,Magazin m)
{
    out << "\nNumele magazinului este: " << m.nume;
    out << "\nAdresa magazinului este :"<<m.adresa;
    out << "\nInstrumentele muzicale din magazin sunt: \n";
    list<instrumentMuzical>::iterator index_instrument;
    for (index_instrument = m.getBegin(); index_instrument != m.getEnd(); ++index_instrument)
    {
        out << *index_instrument << endl;
    }
    out<<"\nPreturile sunt: ";
    set<double>::iterator it;
    for (it = m.preturi.begin(); it != m.preturi.end(); ++it)
    {
        out << *it << endl;
    }
    return out;
}
//-------------------------------------------------------------------------------------------------
vector <instrumentMuzical*> instrumente;
vector <Magazin> magazine;
map <string, int> tari;

class meniuInteractiv
{
private:
    static meniuInteractiv *obiect;
    meniuInteractiv() {};
    meniuInteractiv(const meniuInteractiv& men) {};
    meniuInteractiv& operator=(const meniuInteractiv& men) {};
public:
    static meniuInteractiv* getInstance()
    {
        if(!obiect)
            obiect=new meniuInteractiv();
        return obiect;
    }
    void meniu()
    {
        int k = 1, comanda;
        while(k)
        {
            cout<<"\nBun venit! Introduceti clasa cu care doriti sa lucrati: \n1 pentru clasa INSTRUMENTE MUZICALE \n2 pentru clasa CHITARA \n3 pentru clasa CHITARA ELECTRICA \n4 pentru clasa MAGAZIN \n5 pentru STOP\n";
            cin>>comanda;
            switch(comanda)
            {
            case 1:
            {
                int comandaInstrumente, instr=1;
                while(instr)
                {
                    cout<<"\nIntroduceti operatia pe care doriti sa o efectuati:\n1 pentru CREATE \n2 pentru  READ\n3 pentru UPDATE \n4 pentru DELETE\n5 pentru BACK \n6 pentru a verifica instrumentul muzical\n";
                    cin>>comandaInstrumente;
                    switch(comandaInstrumente)
                    {
                    case 1:
                    {
                        int instrCreate=1, comandaInstrCreate;
                        while(instrCreate)
                        {
                            cout<<"\nIntroduceti constructorul: \n1 pentru cel cu toti parametrii\n2 pentru cel fara parametrii \n5 pentru back\n";
                            cin>>comandaInstrCreate;
                            switch(comandaInstrCreate)
                            {
                            case 1:
                            {
                                instrumentMuzical i;
                                cin>>i;
                                instrumente.push_back(new instrumentMuzical(i));
                                break;
                            }
                            case 2:
                            {
                                instrumentMuzical i;
                                instrumente.push_back(new instrumentMuzical(i));
                                break;
                            }
                            case 5:
                            {
                                instrCreate=0;
                                break;
                            }
                            default:
                            {
                                cout<<"\nComanda gresita";
                                break;
                            }
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        int instrRead=1, comandaInstrRead;
                        while(instrRead)
                        {
                            cout<<"\nIntroduceti preferinta: \n1 pentru a citi un singur instrument \n2 pentru a citi toate instrumentele  \n5 pentru back\n";
                            cin>>comandaInstrRead;
                            switch(comandaInstrRead)
                            {
                            case 1:
                            {
                                cout<<"\nIntroduceti indexul instrumentului ";
                                int index;
                                cin>>index;
                                try
                                {
                                    if (index<instrumente.size())
                                        cout<<*instrumente[index];
                                    else throw std::out_of_range("Bad index");
                                }
                                catch (out_of_range)
                                {
                                    cout<< "\nExceptie: ";
                                    cout<<"\nInstrumentul muzical "<<index<<" nu exista"<<endl;
                                }
                                catch(...)
                                {
                                    cout<<"\n Exceptie prinsa";
                                }

                                /*try
                                {
                                    cin>>index;
                                    if(strcmp(typeid(index).name(),"i")==0)
                                    {
                                        try
                                        {
                                            if (index<instrumente.size())
                                                cout<<*instrumente[index];
                                            else throw std::out_of_range("Bad index");
                                        }
                                        catch (out_of_range)
                                        {
                                            cout<< "\nExceptie: ";
                                            cout<<"\nInstrumentul muzical"<<index<<" nu exista"<<endl;
                                        }
                                        catch(...)
                                        {

                                            cout<<"\n Exceptie prinsa";
                                        }
                                    }
                                    else  throw std::invalid_argument("Bad argument");
                                }
                                catch (invalid_argument)
                                {
                                    cout<< "\nExceptie: ";
                                    cout<<index<<" nu este intreg "<<endl;
                                }
                                catch(...)
                                {
                                    cout<<"\n Exceptie prinsa";
                                }
                                */

                                break;
                            }
                            case 2:
                            {
                                for(int index=0; index<instrumente.size(); index++)
                                    cout<<*instrumente[index]<<endl;
                                break;
                            }
                            case 5:
                            {
                                instrRead=0;
                                break;
                            }
                            default:
                            {
                                cout<<"\nComanda gresita";
                                break;
                            }
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        cout<<"\nIntroduceti indexul instrumentului pe care doriti sa il updatati: ";
                        int indexUpdate;
                        cin>>indexUpdate;
                        try
                        {
                            if (indexUpdate<instrumente.size())
                            {
                                cout<<"\nIntroduceti instrumentul cu care doriti sa fie updatat: ";
                                instrumentMuzical i;
                                cin>>i;
                                instrumente[indexUpdate]=new instrumentMuzical(i);
                            }
                            else throw std::out_of_range("Bad index");
                        }
                        catch (out_of_range)
                        {
                            cout<< "\nExceptie: ";
                            cout<<"\nInstrumentul muzical "<<indexUpdate<<" nu exista"<<endl;
                        }
                        catch(...)
                        {
                            cout<<"\n Exceptie prinsa";
                        }
                        break;
                    }
                    case 4:
                    {
                        cout<<"\nIntroduceti indexul instrumentului pe care doriti sa il stergeti: ";
                        int indexDelete;
                        cin>>indexDelete;
                        try
                        {
                            if (indexDelete<instrumente.size())
                            {
                                instrumente.erase(instrumente.begin()+indexDelete);
                            }
                            else throw std::out_of_range("Bad index");
                        }
                        catch (out_of_range)
                        {
                            cout<< "\nExceptie: ";
                            cout<<"\nInstrumentul muzical "<<indexDelete<<" nu exista"<<endl;
                        }
                        catch(...)
                        {
                            cout<<"\n Exceptie prinsa";
                        }
                        break;
                    }
                    case 5:
                    {
                        instr=0;
                        break;
                    }
                    case 6:
                    {
                        cout<<"\Introduceti indexul instrumentului la care doriti sa se faca verificare: ";
                        int indexVerif;
                        cin>>indexVerif;
                        if(indexVerif>=instrumente.size())
                            cout<<"\nNu exista acest instrument";
                        else
                        {
                            instrumentMuzical i;
                            i=*instrumente[indexVerif];
                            i.verifInstrument();
                        }
                        break;
                    }
                    default:
                    {
                        cout<<"\nComanda gresita";
                        break;
                    }
                    }
                }
                break;
            }
            case 2:
            {
                int comandaChitara, chit=1;
                while(chit)
                {
                    cout<<"\nIntroduceti operatia pe care doriti sa o efectuati:\n1 pentru CREATE \n2 pentru  READ\n3 pentru UPDATE \n4 pentru DELETE\n5 pentru BACK\n6 pentru a vedea ce tari produc chitare\n";
                    cin>>comandaChitara;
                    switch(comandaChitara)
                    {
                    case 1:
                    {
                        int chitCreate=1, comandaChitCreate;
                        while(chitCreate)
                        {
                            cout<<"\nIntroduceti constructorul: \n1 pentru cel cu toti parametrii\n2 pentru cel fara parametrii \n5 pentru back\n";
                            cin>>comandaChitCreate;
                            switch(comandaChitCreate)
                            {
                            case 1:
                            {
                                Chitara i;
                                cin>>i;
                                string tara=i.getTaraDeFabricatie();
                                instrumente.push_back(new Chitara(i));
                                if(tari.empty()==0)
                                {
                                    map<string, int>::iterator itr;
                                    for (itr = tari.begin(); itr != tari.end(); ++itr)
                                    {
                                        if(itr->first == tara)
                                            itr->second++;
                                        else tari.insert(pair<string,int>(tara,1));
                                    }
                                }
                                else tari.insert(pair<string,int>(tara,1));
                                break;
                            }
                            case 2:
                            {
                                Chitara i;
                                instrumente.push_back(new Chitara(i));
                                break;
                            }
                            case 5:
                            {
                                chitCreate=0;
                                break;
                            }
                            default:
                            {
                                cout<<"\nComanda gresita";
                                break;
                            }
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        int chitRead=1, comandaChitRead;
                        while(chitRead)
                        {
                            cout<<"\nIntroduceti preferinta: \n1 pentru a citi o singura chitara \n2 pentru a citi toate chitarele  \n5 pentru back\n";
                            cin>>comandaChitRead;
                            switch(comandaChitRead)
                            {
                            case 1:
                            {
                                cout<<"\nIntroduceti indexul chitarei";
                                int index;
                                cin>>index;
                                if (index>=instrumente.size())
                                    cout<<"\nNu exista aceasta chitara!";
                                else cout<<*instrumente[index];
                                break;
                            }
                            case 2:
                            {
                                for(int index=0; index<instrumente.size(); index++)
                                    cout<<*instrumente[index]<<endl;
                                break;
                            }
                            case 5:
                            {
                                chitRead=0;
                                break;
                            }
                            default:
                            {
                                cout<<"\nComanda gresita";
                                break;
                            }
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        cout<<"\nIntroduceti indexul chitarei pe care doriti sa o updatati: ";
                        int indexUpdate;
                        cin>>indexUpdate;
                        try
                        {
                            if (indexUpdate<instrumente.size())
                            {
                                cout<<"\nIntroduceti chitara cu care doriti sa fie updatata: ";
                                Chitara i;
                                cin>>i;
                                instrumente[indexUpdate]=new Chitara(i);
                            }
                            else throw std::out_of_range("Bad index");
                        }
                        catch (out_of_range)
                        {
                            cout<< "\nExceptie: ";
                            cout<<"\nChitara "<<indexUpdate<<" nu exista"<<endl;
                        }
                        catch(...)
                        {
                            cout<<"\n Exceptie prinsa";
                        }
                        break;
                    }
                    case 4:
                    {
                        cout<<"\nIntroduceti indexul chitarei pe care doriti sa o stergeti: ";
                        int indexDelete;
                        cin>>indexDelete;
                        if(indexDelete>=instrumente.size())
                            cout<<"\nNu exista aceasta chitara!";
                        else
                        {
                            instrumente.erase(instrumente.begin()+indexDelete);
                        }
                        break;
                    }
                    case 5:
                    {
                        chit=0;
                        break;
                    }
                    case 6:
                    {
                        /*if(instrumente.size()==0)
                            cout<<"\nNu exista inca chitare";
                        else
                        {
                            for(int i=0; i<instrumente.size(); i++)
                                if(typeid(*instrumente[i]).name()==typeid(Chitara).name())
                                {
                                    /* instrumentMuzical* a=instrumente[i];
                                     Chitara b;
                                     a=dynamic_cast<instrumentMuzical*>(&b);  */                //!incerc iar dynamic_cast
                        /* Chitara *b;
                         instrumentMuzical a=*instrumente[i];
                         b=dynamic_cast<instrumentMuzical*>(&a); */
                        /*instrumentMuzical i;
                        Chitara *c;
                        c = dynamic_cast<Chitara*> (&i);*/

                        /* instrumentMuzical *i;
                         Chitara c;
                         i=dynamic_cast<instrumentMuzical*>(&c);*/

                        /*Chitara c1;
                        instrumentMuzical* a3=static_cast<Chitara*> (&c1);
                        c1.getNume();*/

                        /* instrumentMuzical* p=new Chitara();
                         Chitara *ptr;
                         p = dynamic_cast<Chitara*>(ptr);*/

                        /*Chitara c1;
                        instrumentMuzical* a2=&c1;
                        instrumentMuzical* a3=static_cast<Chitara*> (&c1); */

                        /*caine c1;
                        pisica p1;
                        gaina g1;
                        lup l1;

                        animal* a2=&c1; // upcasting implicit

                        animal* a3=static_cast<caine*> (&c1);

                        instrumentMuzical *a=new Chitara;
                        Chitara c1;

                        instrumentMuzical* a2=&c1;

                        instrumentMuzical* a3=static_cast<Chitara*> (&c1);*/

                        /*Chitara c1;
                        instrumentMuzical* a2=&c1;
                        instrumentMuzical* a3=static_cast<Chitara*>(&c1); */


                        /*instrumentMuzical *bp;
                        Chitara *dp,d_ob;
                        bp = &d_ob;
                        dp = dynamic_cast<Chitara *> (bp);
                        dp = dynamic_cast<Derived *> (bp);
                        //bp->ceTipDeChitaraAiNevoie();*/

                        /* instrumentMuzical *bp, b_ob;
                         Chitara *dp, d_ob;

                         dp = dynamic_cast<Chitara *> (&d_ob);

                         bp = dynamic_cast<instrumentMuzical *> (&d_ob);*/

                        map<string, int>::iterator itr;
                        for (itr = tari.begin(); itr != tari.end(); ++itr)
                        {
                            cout<<endl<<itr->first<<endl<<itr->second<<endl;
                        }
                        break;
                    }
                    default:
                    {
                        cout<<"\nComanda gresita";
                        break;
                    }
                    }
                }
                break;
            }
            case 3:
            {
                int comandaChitaraElectrica, elec=1;
                while(elec)
                {
                    cout<<"\nIntroduceti operatia pe care doriti sa o efectuati:\n1 pentru CREATE \n2 pentru  READ\n3 pentru UPDATE \n4 pentru DELETE\n5 pentru BACK \n";
                    cin>>comandaChitaraElectrica;
                    switch(comandaChitaraElectrica)
                    {
                    case 1:
                    {
                        int elecCreate=1, comandaElecCreate;
                        while(elecCreate)
                        {
                            cout<<"\nIntroduceti constructorul: \n1 pentru cel cu toti parametrii\n2 pentru cel fara parametrii \n5 pentru back\n";
                            cin>>comandaElecCreate;
                            switch(comandaElecCreate)
                            {
                            case 1:
                            {
                                chitaraElectrica i;
                                cin>>i;
                                instrumente.push_back(new chitaraElectrica(i));
                                break;
                            }
                            case 2:
                            {
                                chitaraElectrica i;
                                instrumente.push_back(new chitaraElectrica(i));
                                break;
                            }
                            case 5:
                            {
                                elecCreate=0;
                                break;
                            }
                            default:
                            {
                                cout<<"\nComanda gresita";
                                break;
                            }
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        int elecRead=1, comandaElecRead;
                        while(elecRead)
                        {
                            cout<<"\nIntroduceti preferinta: \n1 pentru a citi o singura chitara electrica\n2 pentru a citi toate chitarele electrice \n5 pentru back\n";
                            cin>>comandaElecRead;
                            switch(comandaElecRead)
                            {
                            case 1:
                            {
                                cout<<"\nIntroduceti indexul chitarei electrice";
                                int index;
                                cin>>index;
                                if (index>=instrumente.size())
                                    cout<<"\nNu exista aceasta chitara electrica!";
                                else cout<<*instrumente[index];
                                break;
                            }
                            case 2:
                            {
                                for(int index=0; index<instrumente.size(); index++)
                                    cout<<*instrumente[index]<<endl;
                                break;
                            }
                            case 5:
                            {
                                elecRead=0;
                                break;
                            }
                            default:
                            {
                                cout<<"\nComanda gresita";
                                break;
                            }
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        cout<<"\nIntroduceti indexul chitarei electrice pe care doriti sa o updatati: ";
                        int indexUpdate;
                        cin>>indexUpdate;
                        try
                        {
                            if (indexUpdate<instrumente.size())
                            {
                                cout<<"\nIntroduceti chitara electrica cu care doriti sa fie updatata: ";
                                chitaraElectrica i;
                                cin>>i;
                                instrumente[indexUpdate]=new chitaraElectrica(i);
                            }
                            else throw std::out_of_range("Bad index");
                        }
                        catch (out_of_range)
                        {
                            cout<< "\nExceptie: ";
                            cout<<"\nChitara electrica"<<indexUpdate<<" nu exista"<<endl;
                        }
                        catch(...)
                        {
                            cout<<"\n Exceptie prinsa";
                        }
                        break;
                    }
                    case 4:
                    {
                        cout<<"\nIntroduceti indexul chitarei electrice pe care doriti sa o stergeti: ";
                        int indexDelete;
                        cin>>indexDelete;
                        if(indexDelete>=instrumente.size())
                            cout<<"\nNu exista aceasta chitara electrica!";
                        else
                        {
                            instrumente.erase(instrumente.begin()+indexDelete);
                        }
                        break;
                    }
                    case 5:
                    {
                        elec=0;
                        break;
                    }
                    default:
                    {
                        cout<<"\nComanda gresita";
                        break;
                    }
                    }
                }
                break;
            }
            case 4:
            {
                int comandaMagazin, mag=1;
                while(mag)
                {
                    cout<<"\nIntroduceti operatia pe care doriti sa o efectuati:\n1 pentru CREATE \n2 pentru  READ\n3 pentru UPDATE \n4 pentru DELETE\n5 pentru BACK \n6 pentru a verifica daca un magazin anume are un instrument muzical anume \n7 pentru a vedea care magazin are cele mai multe instrumente muzicale\n";
                    cin>>comandaMagazin;
                    switch(comandaMagazin)
                    {
                    case 1:
                    {
                        int magCreate=1, comandaMagCreate;
                        while(magCreate)
                        {
                            cout<<"\nIntroduceti constructorul: \n1 pentru cel cu toti parametrii\n2 pentru cel fara parametrii \n5 pentru back\n";
                            cin>>comandaMagCreate;
                            switch(comandaMagCreate)
                            {
                            case 1:
                            {
                                Magazin i;
                                cin>>i;
                                magazine.push_back(i);
                                break;
                            }
                            case 2:
                            {
                                Magazin i;
                                magazine.push_back(i);
                                break;
                            }
                            case 5:
                            {
                                magCreate=0;
                                break;
                            }
                            default:
                            {
                                cout<<"\nComanda gresita";
                                break;
                            }
                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        int magRead=1, comandaMagRead;
                        while(magRead)
                        {
                            cout<<"\nIntroduceti preferinta: \n1 pentru a citi un singur magazin \n2 pentru a citi toate magazinele \n3 pentru a citi toate magazinele ordonate \n5 pentru back\n";
                            cin>>comandaMagRead;
                            switch(comandaMagRead)
                            {
                            case 1:
                            {
                                cout<<"\nIntroduceti indexul magazinului\n";
                                int index;
                                cin>>index;
                                if (index>=magazine.size())
                                    cout<<"\nNu exista acest magazin!";
                                else cout<<magazine[index];
                                break;
                            }
                            case 2:
                            {
                                for(int index=0; index<magazine.size(); index++)
                                    cout<<magazine[index]<<endl;
                                break;
                            }
                            case 3:
                            {
                                int n=magazine.size();
                                magazine=Sort<Magazin>(magazine,n);
                                for(int i=0; i<magazine.size(); i++)
                                    cout<<magazine[i]<<endl;
                                break;
                            }
                            case 5:
                            {
                                magRead=0;
                                break;
                            }
                            default:
                            {
                                cout<<"\nComanda gresita";
                                break;
                            }
                            }
                        }
                        break;
                    }
                    case 3:
                    {
                        cout<<"\nIntroduceti indexul magazinului pe care doriti sa il updatati: ";
                        int indexUpdate;
                        cin>>indexUpdate;
                        try
                        {
                            if (indexUpdate<magazine.size())
                            {
                                cout<<"\nIntroduceti magazinul cu care doriti sa fie updatat: ";
                                Magazin i;
                                cin>>i;
                                magazine[indexUpdate]=i;
                            }
                            else throw std::out_of_range("Bad index");
                        }
                        catch (out_of_range)
                        {
                            cout<< "\nExceptie: ";
                            cout<<"\nMagazinul"<<indexUpdate<<" nu exista"<<endl;
                        }
                        catch(...)
                        {
                            cout<<"\n Exceptie prinsa";
                        }
                        break;
                    }
                    case 4:
                    {
                        cout<<"\nIntroduceti indexul magazinului pe care doriti sa il stergeti: ";
                        int indexDelete;
                        cin>>indexDelete;
                        if(indexDelete>=magazine.size())
                            cout<<"\nNu exista acest magazin!";
                        else
                        {
                            magazine.erase(magazine.begin()+indexDelete);
                        }
                        break;
                    }
                    case 5:
                    {
                        mag=0;
                        break;
                    }
                    case 6:
                    {
                        cout<<"\Introduceti indexul magazinului pe care doriti sa il verificati: ";
                        int index;
                        cin>>index;
                        if(index>magazine.size())
                            cout<<"\nNu exista acest magazin! ";
                        else
                        {
                            Magazin i;
                            i=magazine[index];
                            i.VerifInstrumentInMagazin(i);
                        }
                        break;
                    }
                    case 7:
                    {
                        int n=magazine.size();
                        if(n==0)
                            cout<<"\nNu exista inca magazine ";
                        else cout<<Max<Magazin>(magazine,n);
                        break;
                    }
                    default:
                    {
                        cout<<"\nComanda gresita";
                        break;
                    }
                    }

                }
                break;
            }
            case 5:
            {
                k=0;
                break;
            }
            default:
            {
                cout<<"\nComanda gresita ";
                break;
            }
            }
        }
    }
};
meniuInteractiv* meniuInteractiv::obiect=0;
int main()
{
    meniuInteractiv *meniulMeu=meniulMeu->getInstance();
    meniulMeu->meniu();
    return 0;
}
