#include <iostream>
#include <string.h>
#include <cstring>
#include <list>

using namespace std;
class Pacient
{
private:
    char* nume;
    char* prenume;
    char initialaTata;
    bool sex;        //1 pentru femei si 0 pentru barbati
    int varsta;
    float inaltime;
    double greutate;
    int nrAlergii;
    string* listaAlergii;
    char* tipProblema;
    int gradGravitate;
    int nrReteteAcumulate;
    const int idPacient;
    static int contorId;
public:
    Pacient();
    Pacient(char* nume, char* prenume, char initialaTata, bool sex, int varsta, float inaltime, double greutate, int nrAlergii, string* listaAlergii, char* tipProblema, int gradGravitate, int nrReteteAcumulate);
    Pacient(char* nume, char* prenume, char initialaTata);
    Pacient(char* tipProblema, int gradGravitate);
    Pacient(const Pacient& pac);

    const char* getNume();
    const char* getPrenume();
    char getInitialaTata();
    bool getSex();
    int getVarsta();
    float getInaltime();
    double getGreutate();
    int getNrAlergii();
    const string* getListaAlergii();
    const char* getTipProblema();
    int getGradGravitate();
    int getNrReteteAcumulate();

    static int getContorId();
    const int getIdPacient();

    void setNume(char* nume);
    void setPrenume(char* prenume);
    void setInitialaTata(char initiatalaTata);
    void setSex(bool sex);
    void setVarsta(int varsta);
    void setInaltime(float inaltime);
    void setGreutate(double greutate);
    void setNrAlergii(int nrAlergii);
    void setListaAlergii(string* ListaAlergii, int nrAlergii);
    void setTipProblema(char* tipProblema);
    void setGradGravitate(int gradGravitate);
    void setNrReteteAcumulate(int nrReteteAcumulate);

    friend ostream& operator<<(ostream& out, const Pacient& p);
    friend istream& operator>>(istream& in, Pacient& p);

    Pacient& operator=(const Pacient& pac);

    bool operator==(const Pacient& pac);
    bool operator>=(const Pacient& pac);
    operator int();
    string operator[](int index);

    Pacient operator+(int x);
    Pacient operator+(Pacient a);
    friend Pacient operator+(int x, Pacient a);
    Pacient operator+=(int x);

    Pacient operator-(int x);
    Pacient operator-(Pacient a);
    friend Pacient operator-(int x, Pacient a);
    Pacient operator-=(int x);

    const Pacient& operator++();
    const Pacient operator++(int);

    void calculIMC(Pacient pac);
    //void afisare();

    ~Pacient();
};
const char* Pacient::getNume()
{
    return this->nume;
}
const char* Pacient::getPrenume()
{
    return this->prenume;
}
char Pacient::getInitialaTata()
{
    return this->initialaTata;
}
bool Pacient::getSex()
{
    return this->sex;
}
int Pacient::getVarsta()
{
    return this->varsta;
}
float Pacient::getInaltime()
{
    return this->inaltime;
}
double Pacient::getGreutate()
{
    return this->greutate;
}
int Pacient::getNrAlergii()
{
    return this->nrAlergii;
}
const string* Pacient::getListaAlergii()
{
    return this->listaAlergii;
}
const char* Pacient::getTipProblema()
{
    return this->tipProblema;
}
int Pacient::getGradGravitate()
{
    return this->gradGravitate;
}
int Pacient::getContorId()
{
    return Pacient::contorId;
}
const int Pacient::getIdPacient()
{
    return this->idPacient;
}
int Pacient::getNrReteteAcumulate()
{
    return this->nrReteteAcumulate;
}
void Pacient::setNume(char* nume)
{
    if (this->nume != NULL)
        delete[] this->nume;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}
void Pacient::setPrenume(char* prenume)
{
    if (this->prenume != NULL)
        delete[] this->prenume;
    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);
}
void Pacient::setInitialaTata(char initialaTata)
{
    this->initialaTata = initialaTata;
}
void Pacient::setSex(bool sex)
{
    this->sex = sex;
}
void Pacient::setVarsta(int varsta)
{
    this->varsta = varsta;
}
void Pacient::setInaltime(float inaltime)
{
    this->inaltime = inaltime;
}
void Pacient::setGreutate(double greutate)
{
    this->greutate = greutate;
}
void Pacient::setNrAlergii(int nrAlergii)
{
    this->nrAlergii = nrAlergii;
}
void Pacient::setListaAlergii(string* listaAlergii, int nrAlergii)
{
    if (this->listaAlergii != NULL)
        delete[] this->listaAlergii;
    this->nrAlergii = nrAlergii;
    this->listaAlergii = new string[nrAlergii];
    for (int i = 0; i < nrAlergii; i++)
        this->listaAlergii[i] = listaAlergii[i];
}
void Pacient::setTipProblema(char* tipProblema)
{
    if (this->tipProblema != NULL)
        delete[] this->tipProblema;
    this->tipProblema = new char[strlen(tipProblema) + 1];
    strcpy(this->tipProblema, tipProblema);
}
void Pacient::setGradGravitate(int gradGravitate)
{
    this->gradGravitate = gradGravitate;
}
void Pacient::setNrReteteAcumulate(int nrReteteAcumulate)
{
    this->nrReteteAcumulate = nrReteteAcumulate;
}
Pacient::Pacient():idPacient(contorId++)
{
    this->nume = new char[strlen("AnonimNume") + 1];
    strcpy(this->nume, "AnonimNume");
    this->prenume = new char[strlen("AnonimPrenume") + 1];
    strcpy(this->prenume, "AnonimPrenume");

    this->initialaTata = 'Z';
    this->sex = 0;
    this->varsta = 0;
    this->inaltime = 0;
    this->greutate = 0;
    this->nrAlergii = 0;
    this->listaAlergii = NULL;
    this->tipProblema = NULL;
    this->gradGravitate = -1;
    this->nrReteteAcumulate = 0;
}
Pacient::Pacient(char* nume, char* prenume, char initialaTata) :idPacient(contorId++)
{
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);

    this->initialaTata = initialaTata;
    this->sex = 0;
    this->varsta = 0;
    this->inaltime = 0;
    this->greutate = 0;
    this->nrAlergii = 0;
    this->listaAlergii = NULL;
    this->tipProblema = NULL;
    this->gradGravitate = -1;
    this->nrReteteAcumulate = 0;
}
Pacient::Pacient(char* tipProblema, int gradGravitate) :idPacient(contorId++)
{
    this->nume = new char[strlen("AnonimNume") + 1];
    strcpy(this->nume, "AnonimNume");
    this->prenume = new char[strlen("AnonimPrenume") + 1];
    strcpy(this->prenume, "AnonimPrenume");

    this->initialaTata = 'Z';
    this->sex = 0;
    this->varsta = 0;
    this->inaltime = 0;
    this->greutate = 0;
    this->nrAlergii = 0;
    this->listaAlergii = NULL;
    this->gradGravitate = gradGravitate;

    this->tipProblema = new char[strlen(tipProblema) + 1];
    strcpy(this->tipProblema, tipProblema);
    this->nrReteteAcumulate = 0;
}
Pacient::Pacient(char* nume, char* prenume, char initialaTata, bool sex, int varsta, float inaltime, double greutate, int nrAlergii, string* listaAlergii, char* tipProblema, int gradGravitate, int nrReteteAcumulate) :idPacient(contorId++)
{

    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume) + 1];
    strcpy(this->prenume, prenume);

    this->initialaTata = initialaTata;
    this->sex = sex;
    this->varsta = varsta;
    this->inaltime = inaltime;
    this->greutate = greutate;

    this->nrAlergii = nrAlergii;
    this->listaAlergii = new string[nrAlergii];
    for (int i = 0; i < nrAlergii; i++)
        this->listaAlergii[i] = listaAlergii[i];

    this->gradGravitate = gradGravitate;
    this->tipProblema = new char[strlen(tipProblema) + 1];
    strcpy(this->tipProblema, tipProblema);
    this->nrReteteAcumulate = nrReteteAcumulate;
}
Pacient::Pacient(const Pacient& pac) :idPacient(pac.idPacient)
{

    this->nume = new char[strlen(pac.nume) + 1];
    strcpy(this->nume, pac.nume);

    this->prenume = new char[strlen(pac.prenume) + 1];
    strcpy(this->prenume, pac.prenume);

    this->varsta = pac.varsta;
    this->initialaTata = pac.initialaTata;
    this->sex = pac.sex;
    this->inaltime = pac.inaltime;
    this->greutate = pac.greutate;
    this->nrAlergii = pac.nrAlergii;

    this->listaAlergii = new string[pac.nrAlergii];
    for (int i = 0; i < pac.nrAlergii; i++)
        this->listaAlergii[i] = pac.listaAlergii[i];
    this->gradGravitate = pac.gradGravitate;
    if (pac.tipProblema != NULL)
    {
        this->tipProblema = new char[strlen(pac.tipProblema) + 1];
        strcpy(this->tipProblema, pac.tipProblema);
    }
    else this->tipProblema = NULL;
    this->nrReteteAcumulate = pac.nrReteteAcumulate;
}
Pacient& Pacient::operator=(const Pacient& pac)
{

    if (this != &pac)
    {

        if (this->nume != NULL)
            delete[] this->nume;
        if (this->prenume != NULL)
            delete[] this->prenume;
        if (this->tipProblema != NULL)
            delete[] this->tipProblema;
        if (this->listaAlergii != NULL)
            delete[] this->listaAlergii;

        this->nume = new char[strlen(pac.nume) + 1];
        strcpy(this->nume, pac.nume);

        this->prenume = new char[strlen(pac.prenume) + 1];
        strcpy(this->prenume, pac.prenume);

        this->varsta = pac.varsta;
        this->initialaTata = pac.initialaTata;
        this->sex = pac.sex;
        this->inaltime = pac.inaltime;
        this->greutate = pac.greutate;

        this->nrAlergii = pac.nrAlergii;
        this->listaAlergii = new string[pac.nrAlergii];
        for (int i = 0; i < pac.nrAlergii; i++)
            this->listaAlergii[i] = pac.listaAlergii[i];


        this->gradGravitate = pac.gradGravitate;
        if (pac.tipProblema != NULL)
        {
            this->tipProblema = new char[strlen(pac.tipProblema) + 1];
            strcpy(this->tipProblema, pac.tipProblema);
        }
        this->nrReteteAcumulate = pac.nrReteteAcumulate;
    }
    return *this;
}
bool Pacient::operator==(const Pacient& pac)
{

    if (strcmp(this->nume, pac.nume) == 0 && strcmp(this->prenume, pac.prenume) == 0 && this->initialaTata == pac.initialaTata && this->sex == pac.sex && this->varsta == pac.varsta && this->inaltime == pac.inaltime && this->greutate == pac.greutate && this->nrAlergii == pac.nrAlergii && strcmp(this->tipProblema, pac.tipProblema) == 0 && this->gradGravitate == pac.gradGravitate && this->nrReteteAcumulate == pac.nrReteteAcumulate)
    {
        bool ok = 1;
        for (int i = 0; i < this->nrAlergii; i++)
            if (this->listaAlergii[i] != pac.listaAlergii[i])
            {
                ok = 0;
                break;
            }
        if (ok)
            return true;
    }

    return false;

}
bool Pacient::operator>=(const Pacient& pac)
{

    if (this->gradGravitate >= pac.gradGravitate)
        return true;
    return false;

}
Pacient::operator int()
{
    return (int)this->greutate;
}
string Pacient::operator[](int index)
{

    string a = "\nIndex introdus gresit";
    string b = "\nLista vida";
    if (this->nrAlergii == 0)
    {
        return b;
    }
    else
    {
        if (0 <= index && index < this->nrAlergii)
            return this->listaAlergii[index];
        else
        {
            return a;
        }
    }

}
const Pacient& Pacient::operator++()
{
    this->varsta++;
    return *this;
}
const Pacient Pacient::operator++(int)
{
    Pacient aux(*this);
    this->varsta++;
    return aux;
}
Pacient Pacient::operator+(int x)
{
    Pacient aux = *this;
    aux.varsta = aux.varsta + x;
    return aux;
}
Pacient Pacient::operator+(Pacient a)
{
    Pacient aux;
    aux = a;
    if (a.nume != NULL)
        delete[] a.nume;
    a.nume = new char[strlen(aux.nume) + strlen(this->nume) + 1];
    strcpy(a.nume, aux.nume);
    strcat(a.nume, this->nume);

    if (a.prenume != NULL)
        delete[] a.prenume;
    a.prenume = new char[strlen(aux.prenume) + strlen(this->prenume) + 1];
    strcpy(a.prenume, aux.prenume);
    strcat(a.prenume, this->prenume);

    if (this->tipProblema != NULL && a.tipProblema != NULL)
    {
        delete[] a.tipProblema;
        a.tipProblema = new char[strlen(aux.tipProblema) + strlen(this->tipProblema) + 1];
        strcpy(a.tipProblema, aux.tipProblema);
        strcat(a.tipProblema, this->tipProblema);
    }
    else if (this->tipProblema != NULL)
    {
        delete[] a.tipProblema;
        a.tipProblema = new char[strlen(this->tipProblema) + 1];
        strcpy(a.tipProblema, this->tipProblema);
    }

    a.nrAlergii = a.nrAlergii + this->nrAlergii;
    if (a.listaAlergii != NULL)
        delete[] a.listaAlergii;
    a.listaAlergii = new string[a.nrAlergii];
    for (int i = 0; i < aux.nrAlergii; i++)
        a.listaAlergii[i] = aux.listaAlergii[i];
    for (int i = 0; i < this->nrAlergii; i++)
        a.listaAlergii[i + aux.nrAlergii] = this->listaAlergii[i];

    a.varsta = a.varsta + this->varsta;
    a.inaltime = a.inaltime + this->inaltime;
    a.greutate = a.greutate + this->greutate;
    a.gradGravitate = a.gradGravitate + this->gradGravitate;
    a.nrReteteAcumulate = a.nrReteteAcumulate + this->nrReteteAcumulate;
    return a;
}
Pacient operator+(int x, Pacient a)
{
    a.varsta = a.varsta + x;
    return a;
}
Pacient Pacient::operator+=(int x)
{
    this->varsta += x;
    return *this;
}
Pacient Pacient::operator-(int x)
{
    Pacient aux = *this;
    aux.varsta = aux.varsta - x;
    return aux;
}
Pacient Pacient::operator-(Pacient a)
{
    a.varsta = this->varsta - a.varsta;
    return a;
}
Pacient operator-(int x, Pacient a)
{
    a.varsta = x - a.varsta;
    return a;
}
Pacient Pacient::operator-=(int x)
{
    this->varsta -= x;
    return *this;
}
Pacient::~Pacient()
{
    if (this->nume != NULL)
        delete[] this->nume;
    if (this->prenume = NULL)
        delete[] this->prenume;
    if (this->tipProblema != NULL)
        delete[] this->tipProblema;
    if (this->listaAlergii != NULL)
        delete[] this->listaAlergii;

}
istream& operator>>(istream& in, Pacient& p)
{

    cout << "\nIntroduceti numele pacientului: ";
    char aux[100];
    in >> aux;

    if (p.nume != NULL)
        delete[] p.nume;
    p.nume = new char[strlen(aux) + 1];
    strcpy(p.nume, aux);


    cout << "\nIntroduceti prenumele pacientului: ";
    in >> aux;
    if (p.prenume != NULL)
        delete[] p.prenume;
    p.prenume = new char[strlen(aux) + 1];
    strcpy(p.prenume, aux);


    cout << "\nIntroduceti initiala tatalui: ";
    in >> p.initialaTata;
    cout << "\nIntroduceti sexul pacientului, 1 daca este femeie si 0 daca este barbat: ";
    in >> p.sex;
    cout << "\nIntroduceti varsta pacientului: ";
    in >> p.varsta;
    cout << "\nIntroduceti inaltimea pacientului (cu 2 zecimale): ";
    in >> p.inaltime;
    cout << "\nIntroduceti greutatea pacientului: ";
    in >> p.greutate;
    cout << "\nIntroduceti numarul de alergii ale pacientului: ";
    in >> p.nrAlergii;
    if (p.nrAlergii != 0)
    {

        if (p.listaAlergii != NULL)
            delete[] p.listaAlergii;
        p.listaAlergii = new string[p.nrAlergii];
        cout << "\nCe alergii? ";
        for (int i = 0; i < p.nrAlergii; i++)
            in >> p.listaAlergii[i];
    }

    cout << "\nIntroduceti tipul problemei: ";
    in >> aux;
    if (p.tipProblema != NULL)
        delete[] p.tipProblema;
    p.tipProblema = new char[strlen(aux) + 1];
    strcpy(p.tipProblema, aux);
    cout << "\nIntroduceti gradul de gravitate: ";
    in >> p.gradGravitate;
    cout << "\nIntroduceti numarul de retete acumulate: ";
    in >> p.nrReteteAcumulate;

    return in;
}
ostream& operator<<(ostream& out, const Pacient& p)
{

    out << "\nId  pacient: " << p.idPacient;
    out << "\nNume pacient: " << p.nume;
    out << "\nPrenume pacient: " << p.prenume;
    out << "\nIntiala tata pacient: " << p.initialaTata;
    if (p.sex)
        out << "\nPacientul este femeie. ";
    else out << "\nPacientul este barbat. ";
    out << "\nVarsta pacient: " << p.varsta;
    out << "\nInaltime pacient: " << p.inaltime;
    out << "\nGreutate pacient: " << p.greutate;
    out << "\nNumarul de alergii este: ";
    out << p.nrAlergii;

    if (p.nrAlergii == 0)
        out << "\nNu exista alergii. ";
    else
    {
        out << "\nAlergiile sunt: ";
        for (int i = 0; i < p.nrAlergii; i++)
            out << p.listaAlergii[i] << " ";

    }
    if (p.tipProblema != NULL)
        out << "\nTip problema pacient: " << p.tipProblema;
    else out << "\nNu exista problema. ";
    out << "\nGrad gravitate: " << p.gradGravitate;
    out << "\nNumarul de retete acumulate: " << p.nrReteteAcumulate;
    return out;
}
void Pacient::calculIMC(Pacient pac)   //calculam indicele de masa corporala al pacientului
{
    Pacient aux;
    aux = pac;
    double IMC;
    IMC = aux.greutate / (aux.inaltime * aux.inaltime);
    if (IMC >= 18.5 && IMC <= 24.9)
        cout << "\nPacientul are o greutate normala. ";      //verificam unde se incadreaza pacientul in functie de imc
    else if (IMC < 18.5)
        cout << "\nPacientul este subponderal. ";
    else cout << "\nPacientul este supraponderal. ";
    double GI;              //ii calculam si greutatea ideala
    aux.inaltime = aux.inaltime * 100;
    if (aux.sex == 0)                  //gi se calculeaza diferit in functie de sexul persoanei
    {
        GI = aux.inaltime - 100 - ((aux.inaltime - 150) / 4 + (aux.varsta - 20) / 4);  //daca este barbat
    }
    else GI = aux.inaltime - 100 - ((aux.inaltime - 150) / 2.5 + (aux.varsta - 20) / 6); //daca este femeie
    cout << "\nGreutatea ideala a pacientului este intre : " << GI << " si " << GI - 5 << " de kg";
}
/*void Pacient::afisare()
{
	cout<<"\n\nPacientul are id: "<< this->idPacient;
	cout<<"\nNume "<<this->nume;
	cout<<"\nPrenume "<<this->prenume;
	cout<<"\nIntialaTata: "<< this->initialaTata;
	cout<<"\nVarsta: "<<this->varsta;
	cout<<"\nInaltime: "<<this->inaltime;
	cout<<"\nGreutate: "<<this->greutate;
	if (this->nrAlergii!=0)
	{
		cout<<"\nNr Alergii: "<<this->nrAlergii;
		cout<<"\nLista Alergii: "<<this->listaAlergii;
	}
	cout<<"\nGrad Gravitate: "<<this->gradGravitate;
	cout<<"\nTip Problema: "<<this->tipProblema;
}*/
int Pacient::contorId = 0;
//---------------------------------------------------------------------------------------------------------------------------

class Reteta
{
private:
    char* numeDoctorConsultant;
    char* prenumeDoctorConsultant;
    char* numePacient;
    char* prenumePacient;
    int varstaPacient;
    string diagnostic;
    int nrMedicamente;
    string* listaMedicamente;
    int* data;
public:
    Reteta();
    Reteta(char* numeDoctorConsultant, char* prenumeDoctorConsultant, char* numePacient, char* prenumePacient, int varstaPacient, string diagnostic, int nrMedicamente, string* listaMedicamente, int* data);
    Reteta(char* numeDoctorConsultant, char* prenumeDoctorConsultant);
    Reteta(string diagnostic);
    Reteta(const Reteta& ret);
    Reteta& operator=(const Reteta& ret);

    const char* getNumeDoctorConsultant();
    const char* getPrenumeDoctorConsultant();
    const char* getNumePacient();
    const char* getPrenumePacient();
    int getVarstaPacient();
    string getDiagnostic();
    int getNrMedicamente();
    const string* getListaMedicamente();
    const int* getData();

    void setNumeDoctorConsultant(char* numeDoctorConsultant);
    void setPrenumeDoctorConsultant(char* prenumeDoctorConsultant);
    void setNumePacient(char* numePacient);
    void setPrenumePacient(char* prenumePacient);
    void setVarstaPacient(int varstaPacient);
    void setDiagnostic(string diagnostic);
    void setNrMedicamante(int nrMedicamente);
    void setListaMedicamente(string* listaMedicamente, int nrMedicamente);
    void setData(int* data);

    friend ostream& operator<<(ostream& out, const Reteta& p);
    friend istream& operator>>(istream& in, Reteta& p);

    bool operator==(const Reteta& ret);
    bool operator>=(const Reteta& ret);
    int operator[](int index);

    Reteta operator+(int x);
    Reteta operator+(Reteta a);
    friend Reteta operator+(int x, Reteta a);
    Reteta operator+=(int x);

    Reteta operator-(int x);
    Reteta operator-(Reteta a);
    friend Reteta operator-(int x, Reteta a);
    Reteta operator-=(int x);

    const Reteta& operator++();
    const Reteta operator++(int);

    Reteta verifAlergii(Pacient p, Reteta r);

    ~Reteta();
};
const char* Reteta::getNumeDoctorConsultant()
{
    return this->numeDoctorConsultant;
}
const char* Reteta::getPrenumeDoctorConsultant()
{
    return this->prenumeDoctorConsultant;
}
const char* Reteta::getNumePacient()
{
    return this->numePacient;
}
const char* Reteta::getPrenumePacient()
{
    return this->prenumePacient;
}
int Reteta::getVarstaPacient()
{
    return this->varstaPacient;
}
string Reteta::getDiagnostic()
{
    return this->diagnostic;
}
int Reteta::getNrMedicamente()
{
    return this->nrMedicamente;
}
const string* Reteta::getListaMedicamente()
{
    return this->listaMedicamente;
}
const int* Reteta::getData()
{
    return this->data;
}
void Reteta::setNumeDoctorConsultant(char* numeDoctorConsultant)
{
    if (this->numeDoctorConsultant != NULL)
        delete[] this->numeDoctorConsultant;
    this->numeDoctorConsultant = new char[strlen(numeDoctorConsultant) + 1];
    strcpy(this->numeDoctorConsultant, numeDoctorConsultant);
}
void Reteta::setPrenumeDoctorConsultant(char* prenumeDoctorConsultant)
{
    if (this->prenumeDoctorConsultant != NULL)
        delete[] this->prenumeDoctorConsultant;
    this->prenumeDoctorConsultant = new char[strlen(prenumeDoctorConsultant) + 1];
    strcpy(this->prenumeDoctorConsultant, prenumeDoctorConsultant);
}
void Reteta::setNumePacient(char* numePacient)
{
    if (this->numePacient != NULL)
        delete[] this->numePacient;
    this->numePacient = new char[strlen(numePacient) + 1];
    strcpy(this->numePacient, numePacient);
}
void Reteta::setPrenumePacient(char* prenumePacient)
{
    if (this->prenumePacient != NULL)
        delete[] this->prenumePacient;
    this->prenumePacient = new char[strlen(prenumePacient) + 1];
    strcpy(this->prenumePacient, prenumePacient);
}
void Reteta::setVarstaPacient(int varstaPacient)
{
    this->varstaPacient = varstaPacient;
}
void Reteta::setDiagnostic(string diagnostic)
{
    this->diagnostic = diagnostic;
}
void Reteta::setNrMedicamante(int nrMedicamente)
{
    this->nrMedicamente = nrMedicamente;
}
void Reteta::setListaMedicamente(string* listaMedicamente, int nrMedicamente)
{
    if (this->listaMedicamente != NULL)
        delete[] this->listaMedicamente;
    this->nrMedicamente = nrMedicamente;
    this->listaMedicamente = new string[this->nrMedicamente];
    for (int i = 0; i < this->nrMedicamente; i++)
        this->listaMedicamente[i] = listaMedicamente[i];
}
void Reteta::setData(int* data)
{
    if (this->data != NULL)
        delete[] this->data;
    this->data = new int[3];
    for (int i = 0; i < 3; i++)
        this->data[i] = data[i];
}
Reteta::Reteta()
{
    this->numeDoctorConsultant = new char[strlen("AnonimNumeDoctor") + 1];
    strcpy(this->numeDoctorConsultant, "AnonimNumeDoctor");
    this->prenumeDoctorConsultant = new char[strlen("AnonimPrenumeDoctor") + 1];
    strcpy(this->prenumeDoctorConsultant, "AnonimPrenumeDoctor");
    this->numePacient = new char[strlen("AnonimNumePacient") + 1];
    strcpy(this->numePacient, "AnonimNumePacient");
    this->prenumePacient = new char[strlen("AnonimPrenumePacient") + 1];
    strcpy(this->prenumePacient, "AnonimPrenumePacient");

    this->varstaPacient = 0;
    this->diagnostic = "";
    this->nrMedicamente = 0;
    this->listaMedicamente = NULL;
    this->data = new int[3];
    for (int i = 0; i < 3; i++)
        this->data[i] = 0;
}
Reteta::Reteta(char* numeDoctorConsultant, char* prenumeDoctorConsultant, char* numePacient, char* prenumePacient, int varstaPacient, string diagnostic, int nrMedicamente, string* listaMedicamente, int* data)
{
    this->numeDoctorConsultant = new char[strlen(numeDoctorConsultant) + 1];
    strcpy(this->numeDoctorConsultant, numeDoctorConsultant);
    this->prenumeDoctorConsultant = new char[strlen(prenumeDoctorConsultant) + 1];
    strcpy(this->prenumeDoctorConsultant, prenumeDoctorConsultant);
    this->numePacient = new char[strlen(numePacient) + 1];
    strcpy(this->numePacient, numePacient);
    this->prenumePacient = new char[strlen(prenumePacient) + 1];
    strcpy(this->prenumePacient, prenumePacient);

    this->varstaPacient = varstaPacient;
    this->diagnostic = diagnostic;
    this->nrMedicamente = nrMedicamente;
    this->listaMedicamente = new string[this->nrMedicamente];
    for (int i = 0; i < this->nrMedicamente; i++)
        this->listaMedicamente[i] = listaMedicamente[i];
    this->data = new int[3];
    for (int i = 0; i < 3; i++)
        this->data[i] = data[i];
}
Reteta::Reteta(char* numeDoctorConsultant, char* prenumeDoctorConsultant)
{
    this->numeDoctorConsultant = new char[strlen(numeDoctorConsultant) + 1];
    strcpy(this->numeDoctorConsultant, numeDoctorConsultant);
    this->prenumeDoctorConsultant = new char[strlen(prenumeDoctorConsultant) + 1];
    strcpy(this->prenumeDoctorConsultant, prenumeDoctorConsultant);
    this->numePacient = new char[strlen("AnonimNumePacient") + 1];
    strcpy(this->numePacient, "AnonimNumePacient");
    this->prenumePacient = new char[strlen("AnonimPrenumePacient") + 1];
    strcpy(this->prenumePacient, "AnonimPrenumePacient");

    this->diagnostic = "";
    this->nrMedicamente = 0;
    this->listaMedicamente = NULL;
    this->data = new int[3];
    for (int i = 0; i < 3; i++)
        this->data[i] = 0;
}
Reteta::Reteta(string diagnostic)
{
    this->numeDoctorConsultant = new char[strlen("AnonimNumeDoctor") + 1];
    strcpy(this->numeDoctorConsultant, "AnonimNumeDoctor");
    this->prenumeDoctorConsultant = new char[strlen("AnonimPrenumeDoctor") + 1];
    strcpy(this->prenumeDoctorConsultant, "AnonimPrenumeDoctor");
    this->numePacient = new char[strlen("AnonimNumePacient") + 1];
    strcpy(this->numePacient, "AnonimNumePacient");
    this->prenumePacient = new char[strlen("AnonimPrenumePacient") + 1];
    strcpy(this->prenumePacient, "AnonimPrenumePacient");

    this->varstaPacient = 0;
    this->diagnostic = diagnostic;
    this->nrMedicamente = 0;
    this->listaMedicamente = NULL;
    this->data = new int[3];
    for (int i = 0; i < 3; i++)
        this->data[i] = 0;
}
Reteta::Reteta(const Reteta& ret)
{
    this->numeDoctorConsultant = new char[strlen(ret.numeDoctorConsultant) + 1];
    strcpy(this->numeDoctorConsultant, ret.numeDoctorConsultant);
    this->prenumeDoctorConsultant = new char[strlen(ret.prenumeDoctorConsultant) + 1];
    strcpy(this->prenumeDoctorConsultant, ret.prenumeDoctorConsultant);
    this->numePacient = new char[strlen(ret.numePacient) + 1];
    strcpy(this->numePacient, ret.numePacient);
    this->prenumePacient = new char[strlen(ret.prenumePacient) + 1];
    strcpy(this->prenumePacient, ret.prenumePacient);

    this->varstaPacient = ret.varstaPacient;
    this->nrMedicamente = ret.nrMedicamente;
    this->listaMedicamente = new string[ret.nrMedicamente];
    for (int i = 0; i < this->nrMedicamente; i++)
        this->listaMedicamente[i] = ret.listaMedicamente[i];
    this->diagnostic = ret.diagnostic;
    this->data = new int[3];
    for (int i = 0; i < 3; i++)
        this->data[i] = ret.data[i];
}
Reteta& Reteta::operator=(const Reteta& ret)
{
    if (this != &ret)
    {
        if (this->numeDoctorConsultant != NULL)
            delete[] this->numeDoctorConsultant;
        this->numeDoctorConsultant = new char[strlen(ret.numeDoctorConsultant) + 1];
        strcpy(this->numeDoctorConsultant, ret.numeDoctorConsultant);

        if (this->prenumeDoctorConsultant != NULL)
            delete[] this->prenumeDoctorConsultant;
        if (this->numePacient != NULL)
            delete[] this->numePacient;
        if (this->prenumePacient != NULL)
            delete[] this->prenumePacient;
        this->prenumeDoctorConsultant = new char[strlen(ret.prenumeDoctorConsultant) + 1];
        strcpy(this->prenumeDoctorConsultant, ret.prenumeDoctorConsultant);
        this->numePacient = new char[strlen(ret.numePacient) + 1];
        strcpy(this->numePacient, ret.numePacient);
        this->prenumePacient = new char[strlen(ret.prenumePacient) + 1];
        strcpy(this->prenumePacient, ret.prenumePacient);

        this->varstaPacient = ret.varstaPacient;
        if (this->listaMedicamente != NULL)
            delete[] this->listaMedicamente;
        this->nrMedicamente = ret.nrMedicamente;
        this->listaMedicamente = new string[ret.nrMedicamente];
        for (int i = 0; i < this->nrMedicamente; i++)
            this->listaMedicamente[i] = ret.listaMedicamente[i];

        if (this->data != NULL)
            delete[] this->data;
        this->data = new int[3];
        for (int i = 0; i < 3; i++)
            this->data[i] = ret.data[i];
    }
    return *this;
}
bool Reteta::operator>=(const Reteta& ret)
{

    if (this->nrMedicamente >= ret.nrMedicamente)
        return true;
    return false;

}
bool Reteta::operator==(const Reteta& ret)
{
    if (strcmp(this->numeDoctorConsultant, ret.numeDoctorConsultant) == 0 && strcmp(this->prenumeDoctorConsultant, ret.prenumeDoctorConsultant) == 0 && strcmp(this->numePacient, ret.numePacient) == 0 && strcmp(this->prenumePacient, ret.prenumePacient) == 0 && this->varstaPacient == ret.varstaPacient && this->diagnostic == ret.diagnostic && this->nrMedicamente == ret.nrMedicamente)
    {
        bool ok = 1;
        for (int i = 0; i < this->nrMedicamente; i++)
            if (this->listaMedicamente[i] != ret.listaMedicamente[i])
            {
                ok = 0;
                break;
            }
        if (ok == 0)
            return false;
        for (int i = 0; i < 3; i++)
            if (this->data[i] != ret.data[i])
            {
                ok = 0;
                break;
            }
        if (ok)
            return true;
    }
    return false;
}
int Reteta::operator[](int index)
{
    if (0 <= index && index < 3)
        return this->data[index];
    else
    {
        //cout<<"\nIndex gresit ";
        return -1;
    }
}
Reteta Reteta::operator+(int x)
{
    Reteta aux = *this;
    aux.varstaPacient = aux.varstaPacient + x;
    return aux;
}
Reteta Reteta::operator+(Reteta a)
{
    a.varstaPacient = this->varstaPacient + a.varstaPacient;
    /*Reteta aux;
    aux=a;
    aux.nrMedicamente=a.nrMedicamente;
    if(aux.numeDoctorConsultant!=NULL)
    	delete[] aux.numeDoctorConsultant;
    aux.numeDoctorConsultant=new char[strlen(a.numeDoctorConsultant)+1];
    strcpy(aux.numeDoctorConsultant,a.numeDoctorConsultant);
    if(a.numeDoctorConsultant!=NULL)
    	delete[] a.numeDoctorConsultant;
    a.numeDoctorConsultant=new char[strlen(aux.numeDoctorConsultant)+strlen(this->numeDoctorConsultant)+1];
    strcpy(a.numeDoctorConsultant,aux.numeDoctorConsultant);
    strcat(a.numeDoctorConsultant,this->numeDoctorConsultant);

    a.diagnostic = a.diagnostic + this->diagnostic;

    a.nrMedicamente = a.nrMedicamente + this->nrMedicamente;

    if(aux.listaMedicamente!=NULL)
    	delete[] aux.listaMedicamente;
    for(int i=0; i<aux.nrMedicamente; i++)
    	aux.listaMedicamente[i]=a.listaMedicamente[i];
    if(a.listaMedicamente!=NULL)
    	delete[] a.listaMedicamente;
    a.listaMedicamente=new string [a.nrMedicamente];
    for(int i=0; i<aux.nrMedicamente; i++)
    	a.listaMedicamente[i]=aux.listaMedicamente[i];
    for(int i=aux.nrMedicamente; i<a.nrMedicamente; i++)
    	a.listaMedicamente[i]=this->listaMedicamente[i];
    for(int i=0; i<3; i++)
    	a.data[i]=a.data[i]+this->data[i];*/

    return a;
}
Reteta operator+(int x, Reteta a)
{
    a.varstaPacient = a.varstaPacient + x;
    return a;
}
Reteta Reteta::operator+=(int x)
{
    this->varstaPacient += x;
    return *this;
}
Reteta Reteta::operator-(int x)
{
    Reteta aux = *this;
    aux.varstaPacient = aux.varstaPacient - x;
    return aux;
}
Reteta Reteta::operator-(Reteta a)
{
    a.varstaPacient = this->varstaPacient - a.varstaPacient;
    return a;
}
Reteta operator-(int x, Reteta a)
{
    a.varstaPacient = x - a.varstaPacient;
    return a;
}
Reteta Reteta::operator-=(int x)
{
    this->varstaPacient -= x;
    return *this;
}
istream& operator>>(istream& in, Reteta& p)
{

    cout << "\nIntroduceti numele doctorului consultant: ";
    char aux[100];
    in >> aux;

    if (p.numeDoctorConsultant != NULL)
        delete[] p.numeDoctorConsultant;
    p.numeDoctorConsultant = new char[strlen(aux) + 1];
    strcpy(p.numeDoctorConsultant, aux);

    cout << "\nIntroduceti prenumele doctorului consultant: ";
    in >> aux;
    if (p.prenumeDoctorConsultant != NULL)
        delete[] p.prenumeDoctorConsultant;
    p.prenumeDoctorConsultant = new char[strlen(aux) + 1];
    strcpy(p.prenumeDoctorConsultant, aux);

    cout << "\nIntroduceti numele pacientului: ";
    in >> aux;

    if (p.numePacient != NULL)
        delete[] p.numePacient;
    p.numePacient = new char[strlen(aux) + 1];
    strcpy(p.numePacient, aux);

    cout << "\nIntroduceti prenumele pacientului: ";
    in >> aux;

    if (p.prenumePacient != NULL)
        delete[] p.prenumePacient;
    p.prenumePacient = new char[strlen(aux) + 1];
    strcpy(p.prenumePacient, aux);

    cout << "\nIntroduceti varsta pacientului: ";
    in >> p.varstaPacient;
    cout << "\nCate medicamente exista in reteta? ";
    if (p.listaMedicamente != NULL)
        delete[] p.listaMedicamente;
    in >> p.nrMedicamente;
    if (p.nrMedicamente != 0)
    {
        cout << "\nMedicamentele sunt: ";
        p.listaMedicamente = new string[p.nrMedicamente];
        for (int i = 0; i < p.nrMedicamente; i++)
            in >> p.listaMedicamente[i];
    }
    cout << "\nIntroduceti diagnosticul: ";
    in >> p.diagnostic;

    cout << "Introduceti data eliberarii retetei: ";
    if (p.data != NULL)
        delete[] p.data;
    p.data = new int[3];
    cout << "\nZiua: ";
    int x;
    in >> x;
    p.data[0] = x;
    cout << "\nLuna: ";
    in >> x;
    p.data[1] = x;
    cout << "\nAnul: ";
    in >> x;
    p.data[2] = x;
    return in;
}
ostream& operator<<(ostream& out, const Reteta& p)
{

    out << "\nNumele doctorului consultant: " << p.numeDoctorConsultant;
    out << "\nPrenumele doctorului consultant: " << p.prenumeDoctorConsultant;
    out << "\nNumele pacientului: " << p.numePacient;
    out << "\nPrenumele pacientului: " << p.prenumePacient;
    out << "\nVarsta pacientului: " << p.varstaPacient;
    out << "\nNumarul de medicamente este: " << p.nrMedicamente;
    if (p.nrMedicamente != 0)
    {
        out << "\nMedicamentele sunt: ";
        for (int i = 0; i < p.nrMedicamente; i++)
            out << p.listaMedicamente[i] << " ";
    }
    else out << "\nNu exista medicamente.";
    out << "\nDiagnostic: " << p.diagnostic;
    out << "\nData eliberarii retetei: ";
    for (int i = 0; i < 3; i++)
        if (i == 2)
            out << p.data[i];
        else
            out << p.data[i] << "/";

    return out;
}
const Reteta& Reteta::operator++()
{
    /*this->data[0]++;
    this->data[1]++;
    this->data[2]++;*/
    this->varstaPacient++;
    return *this;
}
const Reteta Reteta::operator++(int)
{
    Reteta aux(*this);
    /*this->data[0]++;
    this->data[1]++;
    this->data[2]++;*/
    this->varstaPacient++;
    return aux;
}
Reteta::~Reteta()
{
    if (this->numeDoctorConsultant != NULL)
        delete[] numeDoctorConsultant;
    if (this->prenumeDoctorConsultant != NULL)
        delete[] this->prenumeDoctorConsultant;
    if (this->numePacient != NULL)
        delete[] this->numePacient;
    if (this->prenumePacient != NULL)
        delete[] this->prenumePacient;
    if (this->data != NULL)
        delete[] data;
    if (this->listaMedicamente != NULL)
        delete[] this->listaMedicamente;
}
Reteta Reteta::verifAlergii(Pacient p, Reteta r)    //verific daca in reteta se afla medicamente la care pacientul este alergic
{
    Reteta aux = r;   //ca sa nu modific r
    //cout<<aux<<endl;
    int n = 0;
    /*if(aux.listaMedicamente!=NULL)
    	delete[] aux.listaMedicamente;
    aux.listaMedicamente=new string[aux.nrMedicamente];*/
    const string* t = p.getListaAlergii();
    int nrAlergii = p.getNrAlergii();
    bool ok;
    for (int i = 0; i < r.nrMedicamente; i++)
    {
        ok = 1;
        for (int j = 0; j < nrAlergii; j++)
            if (r.listaMedicamente[i] == t[j])

            {
                ok = 0;
                break;

            }
        if (ok == 1)
        {
            n++;                        //numar medicamentele din reteta la care pacientul nu e alergic ca sa stiu cata memorie aloc
        }
    }
    if (aux.listaMedicamente != NULL)
        delete[] aux.listaMedicamente;
    aux.listaMedicamente = new string[n];
    n = 0;
    for (int i = 0; i < r.nrMedicamente; i++)
    {
        ok = 1;
        for (int j = 0; j < nrAlergii; j++)
            if (r.listaMedicamente[i] == t[j])

            {
                ok = 0;
                break;

            }
        if (ok == 1)
        {
            aux.listaMedicamente[n] = r.listaMedicamente[i];     //construiesc lista noua in care pun doar medicamentele bune
            n++;
        }
    }

    //cout<<"\nCate sunr dif " <<n<<endl;
    aux.nrMedicamente = n;
    //cout<<aux;
    return aux;

}
//---------------------------------------------------------------------------------------------------------------------------

class Doctor
{
private:
    char* numeDoctor;
    char* prenumeDoctor;
    string specializare;
    int varstaDoctor;
    int nrReteteEliberate;
    bool* ocupat;    //1 daca este ocupat 0 altfel
    const int idDoctor;
    static int contorIdDoctor;
public:
    Doctor();
    Doctor(char* numeDoctor, char* prenumeDoctor, string specializare, int varstaDoctor, int nrReteteEliberate, bool* ocupat);
    Doctor(char* numeDoctor, char* prenumeDoctor);
    Doctor(string specializare);
    Doctor(const Doctor& doc);
    Doctor& operator=(const Doctor& doc);

    const char* getNumeDoctor();
    const char* getPrenumeDoctor();
    string getSpecializare();
    int getVarstaDoctor();
    int getNrReteteEliberate();
    const bool* getOcupat();

    void setNumeDoctor(char* numeDoctor);
    void setPrenumeDoctor(char* prenumeDoctor);
    void setSpecializare(string specializare);
    void setVarstaDoctor(int varstaDoctor);
    void setNrReteteEliberate(int nrReteteEliberate);
    void setOcupat(bool* ocupat);

    friend ostream& operator<<(ostream& out, const Doctor& p);
    friend istream& operator>>(istream& in, Doctor& p);

    bool operator==(const Doctor& doc);
    bool operator>=(const Doctor& doc);
    operator int();

    Doctor operator+(int x);
    Doctor operator+(Doctor a);
    friend Doctor operator+(int x, Doctor a);
    Doctor operator+=(int x);


    Doctor operator-(int x);
    Doctor operator-(Doctor a);
    friend Doctor operator-(int x, Doctor a);
    Doctor operator-=(int x);


    const Doctor& operator++();
    const Doctor operator++(int);

    int operator[](int index);

    friend Doctor operator+(Doctor m, Reteta& a);
    friend Doctor operator+(Reteta& a, Doctor m);

    void disponibilitate(Doctor m, Pacient a);

    ~Doctor();
};
const char* Doctor::getNumeDoctor()
{
    return this->numeDoctor;
}
const char* Doctor::getPrenumeDoctor()
{
    return this->prenumeDoctor;
}
string Doctor::getSpecializare()
{
    return this->specializare;
}
int Doctor::getVarstaDoctor()
{
    return this->varstaDoctor;
}
int Doctor::getNrReteteEliberate()
{
    return this->nrReteteEliberate;
}
const bool* Doctor::getOcupat()
{
    return this->ocupat;
}
void Doctor::setNumeDoctor(char* numeDoctor)
{
    if (this->numeDoctor != NULL)
        delete[] this->numeDoctor;
    this->numeDoctor = new char[strlen(numeDoctor) + 1];
    strcpy(this->numeDoctor, numeDoctor);
}
void Doctor::setPrenumeDoctor(char* prenumeDoctor)
{
    if (this->prenumeDoctor != NULL)
        delete[] this->prenumeDoctor;
    this->prenumeDoctor = new char[strlen(prenumeDoctor) + 1];
    strcpy(this->prenumeDoctor, prenumeDoctor);
}
void Doctor::setOcupat(bool* ocupat)
{
    if (this->ocupat != NULL)
        delete[] this->ocupat;
    this->ocupat = new bool[8];
    for (int i = 0; i < 8; i++)
        this->ocupat[i] = ocupat[i];
}
void Doctor::setSpecializare(string specializare)
{
    this->specializare = specializare;
}
void Doctor::setVarstaDoctor(int varstaDoctor)
{
    this->varstaDoctor = varstaDoctor;
}
void Doctor::setNrReteteEliberate(int nrReteteEliberate)
{
    this->nrReteteEliberate = nrReteteEliberate;
}
Doctor::Doctor() :idDoctor(contorIdDoctor++)
{
    this->numeDoctor = new char[strlen("AnonimNume") + 1];
    strcpy(this->numeDoctor, "AnonimNume");
    this->prenumeDoctor = new char[strlen("AnonimPrenume") + 1];
    strcpy(this->prenumeDoctor, "AnonimPrenume");

    this->ocupat = NULL;
    this->specializare = " ";
    this->varstaDoctor = 0;
    this->nrReteteEliberate = 0;
}
Doctor::Doctor(char* numeDoctor, char* prenumeDoctor, string specializare, int varstaDoctor, int nrReteteEliberatem, bool* ocupat) :idDoctor(contorIdDoctor++)
{
    this->numeDoctor = new char[strlen(numeDoctor) + 1];
    strcpy(this->numeDoctor, numeDoctor);
    this->prenumeDoctor = new char[strlen(prenumeDoctor) + 1];
    strcpy(this->prenumeDoctor, prenumeDoctor);
    this->ocupat = new bool[8];
    for (int i = 0; i < 8; i++)
        this->ocupat[i] = ocupat[i];
    this->specializare = specializare;
    this->varstaDoctor = varstaDoctor;
    this->nrReteteEliberate = nrReteteEliberate;
}
Doctor::Doctor(char* numeDoctor, char* prenumeDoctor) :idDoctor(contorIdDoctor++)
{
    this->numeDoctor = new char[strlen(numeDoctor) + 1];
    strcpy(this->numeDoctor, numeDoctor);
    this->prenumeDoctor = new char[strlen(prenumeDoctor) + 1];
    strcpy(this->prenumeDoctor, prenumeDoctor);

    this->ocupat = NULL;
    this->specializare = " ";
    this->varstaDoctor = 0;
    this->nrReteteEliberate = 0;
}
Doctor::Doctor(string specializare) :idDoctor(contorIdDoctor++)
{
    this->numeDoctor = new char[strlen("AnonimNume") + 1];
    strcpy(this->numeDoctor, "AnonimNume");
    this->prenumeDoctor = new char[strlen("AnonimPrenume") + 1];
    strcpy(this->prenumeDoctor, "AnonimPrenume");
    this->ocupat = NULL;
    this->specializare = specializare;
    this->varstaDoctor = 0;
    this->nrReteteEliberate = 0;
}
Doctor::Doctor(const Doctor& doc) :idDoctor(doc.idDoctor)
{
    this->numeDoctor = new char[strlen(doc.numeDoctor) + 1];
    strcpy(this->numeDoctor, doc.numeDoctor);
    this->prenumeDoctor = new char[strlen(doc.prenumeDoctor) + 1];
    strcpy(this->prenumeDoctor, doc.prenumeDoctor);
    if (doc.ocupat != NULL)
    {
        this->ocupat = new bool[8];
        for (int i = 0; i < 8; i++)
            this->ocupat[i] = doc.ocupat[i];
    }
    else this->ocupat = NULL;
    this->specializare = doc.specializare;
    this->varstaDoctor = doc.varstaDoctor;
    this->nrReteteEliberate = doc.nrReteteEliberate;
}
Doctor& Doctor::operator=(const Doctor& doc)
{
    if (this != &doc)
    {
        if (this->numeDoctor != NULL)
            delete[] numeDoctor;
        if (this->prenumeDoctor != NULL)
            delete[] prenumeDoctor;
        if (this->ocupat != NULL)
            delete[] this->ocupat;
        this->numeDoctor = new char[strlen(doc.numeDoctor) + 1];
        strcpy(this->numeDoctor, doc.numeDoctor);
        this->prenumeDoctor = new char[strlen(doc.prenumeDoctor) + 1];
        strcpy(this->prenumeDoctor, doc.prenumeDoctor);
        if (doc.ocupat != NULL)
        {
            this->ocupat = new bool[8];
            for (int i = 0; i < 8; i++)
                this->ocupat[i] = doc.ocupat[i];
        }
        this->specializare = doc.specializare;
        this->varstaDoctor = doc.varstaDoctor;
        this->nrReteteEliberate = doc.nrReteteEliberate;
    }
    return *this;
}
bool Doctor::operator==(const Doctor& doc)
{
    if (strcmp(this->numeDoctor, doc.numeDoctor) == 0 && strcmp(this->prenumeDoctor, doc.prenumeDoctor) == 0 && this->varstaDoctor == doc.varstaDoctor && this->specializare == doc.specializare && this->nrReteteEliberate == doc.nrReteteEliberate)
    {
        bool ok = 1;
        for (int i = 0; i < 8; i++)
            if (this->ocupat[i] != doc.ocupat[i])
            {
                ok = 0;
                break;
            }
        if (ok)
            return true;
    }

    return false;
}
bool Doctor::operator>=(const Doctor& doc)
{

    if (this->varstaDoctor >= doc.varstaDoctor)
        return true;
    return false;

}
int Doctor::operator[](int index)
{
    if (0 <= index && index < 8)
        return this->ocupat[index];
    //cout<<"Index gresit ";
    return -1;

}
const Doctor& Doctor::operator++()
{
    this->varstaDoctor++;
    return *this;
}
const Doctor Doctor::operator++(int)
{
    Doctor aux(*this);
    this->varstaDoctor++;
    return aux;
}
Doctor Doctor::operator+(int x)
{
    Doctor aux = *this;
    aux.varstaDoctor = aux.varstaDoctor + x;
    return aux;
}
Doctor Doctor::operator+(Doctor a)
{
    Doctor aux;
    aux = a;
    if (a.numeDoctor != NULL)
        delete[] a.numeDoctor;
    a.numeDoctor = new char[strlen(aux.numeDoctor) + strlen(this->numeDoctor) + 1];
    strcpy(a.numeDoctor, aux.numeDoctor);
    strcat(a.numeDoctor, this->numeDoctor);
    if (a.prenumeDoctor != NULL)
        delete[] a.prenumeDoctor;
    a.prenumeDoctor = new char[strlen(aux.prenumeDoctor) + strlen(this->prenumeDoctor) + 1];
    strcpy(a.prenumeDoctor, aux.prenumeDoctor);
    strcat(a.prenumeDoctor, this->prenumeDoctor);
    a.specializare = a.specializare + this->specializare;
    a.varstaDoctor = a.varstaDoctor + this->varstaDoctor;
    a.nrReteteEliberate = a.nrReteteEliberate + this->nrReteteEliberate;
    return a;
}
Doctor operator+(int x, Doctor a)
{
    a.varstaDoctor = a.varstaDoctor + x;
    return a;
}
Doctor Doctor::operator+=(int x)
{
    this->varstaDoctor += x;
    return *this;
}
Doctor Doctor::operator-(int x)
{
    Doctor aux = *this;
    aux.varstaDoctor = aux.varstaDoctor - x;
    return aux;
}
Doctor Doctor::operator-(Doctor a)
{
    a.varstaDoctor = this->varstaDoctor - a.varstaDoctor;
    return a;
}
Doctor operator-(int x, Doctor a)
{
    a.varstaDoctor = x - a.varstaDoctor;
    return a;
}
Doctor Doctor::operator-=(int x)
{
    this->varstaDoctor -= x;
    return *this;
}
Doctor operator+(Doctor m, Reteta& a)    //incrementez doctor m.nrReteteEliberate daca numele si prenumele doctorului consultant de pe reteta r coincid cu numele si prenumele doctorului m
{
    if (strcmp(m.numeDoctor, a.getNumeDoctorConsultant()) == 0 && strcmp(m.prenumeDoctor, a.getPrenumeDoctorConsultant()) == 0)
        m.nrReteteEliberate++;
    return m;
}
Doctor operator+(Reteta& a, Doctor m)
{
    if (strcmp(m.numeDoctor, a.getNumeDoctorConsultant()) == 0 && strcmp(m.prenumeDoctor, a.getPrenumeDoctorConsultant()) == 0)
        m.nrReteteEliberate++;
    return m;
}
istream& operator>>(istream& in, Doctor& p)
{

    cout << "\nIntroduceti numele doctorului: ";
    char aux[100];
    in >> aux;

    if (p.numeDoctor != NULL)
        delete[] p.numeDoctor;
    p.numeDoctor = new char[strlen(aux) + 1];
    strcpy(p.numeDoctor, aux);

    if (p.ocupat != NULL)
        delete[] p.ocupat;
    p.ocupat = new bool[8];

    cout << "\nIntroduceti prenumele doctorului: ";
    in >> aux;
    if (p.prenumeDoctor != NULL)
        delete[] p.prenumeDoctor;
    p.prenumeDoctor = new char[strlen(aux) + 1];
    strcpy(p.prenumeDoctor, aux);

    cout << "\nIntroduceti specializarea doctorului: ";
    in >> p.specializare;

    cout << "\nIntroduceti varsta doctorului: ";
    in >> p.varstaDoctor;

    cout << "\nIntroduceti numarul de retete eliberate de doctor: ";
    in >> p.nrReteteEliberate;

    cout << "\nIntroduceti programul de munca al doctorului pe ziua de astazi: ";
    for (int i = 0; i < 8; i++)
        in >> p.ocupat[i];

    return in;
}
ostream& operator<<(ostream& out, const Doctor& p)
{

    out << "\nId Doctor: " << p.idDoctor;
    out << "\nNume doctor: " << p.numeDoctor;
    out << "\nPrenume doctor: " << p.prenumeDoctor;
    out << "\nSpecializare doctor: " << p.specializare;
    out << "\nVarsta doctor: " << p.varstaDoctor;
    out << "\nNumarul de retete eliberate: " << p.nrReteteEliberate;
    if (p.ocupat != NULL)
    {
        out << "\nProgram de lucru: ";
        for (int i = 0; i < 8; i++)
            out << p.ocupat[i] << " ";
    }
    else out << "\nNu exista program de lucru. ";
    return out;
}
void Doctor::disponibilitate(Doctor m, Pacient a)    //verific daca doctorul m poate primi pacientul a
{
    if (m.specializare != a.getTipProblema())    //trebuie ca specializarea doctorului sa fie aceeasi ca tipul problemei pacientului
        cout << "\nDoctorul " << m.numeDoctor << " " << m.prenumeDoctor << " nu poate primi pacientul " << a.getNume() << " " << a.getPrenume();
    else
    {
        bool ok = 0;
        for (int i = 0; i < 8; i++)
            if (m.ocupat[i] == 0)   //verific daca doctorul are un spatiu liber in program
            {
                ok = 1;
                cout << "\nDoctorul " << m.numeDoctor << " " << m.prenumeDoctor << " poate primi pacientul " << a.getNume() << " " << a.getPrenume() << " la ora " << i + 8;
                break;
            }
        if (ok == 0)      //programul e plin
            cout << "\nDoctorul " << m.numeDoctor << " " << m.prenumeDoctor << " nu poate primi pacientul " << a.getNume() << " " << a.getPrenume() << " astazi";
    }
}

Doctor::~Doctor()
{
    if (this->numeDoctor != NULL)
        delete[] this->numeDoctor;
    if (this->prenumeDoctor = NULL)
        delete[] this->prenumeDoctor;
    if (this->ocupat != NULL)
        delete[] this->ocupat;
}
int Doctor::contorIdDoctor = 0;
//-------------------------------------------------------------------------------------------------------------------------
class Cabinet
{
private:
    char* numeCabinet;
    string specializare;
    int etajLocalizare;
    int nrDoctoriPeCabinet;
    bool deschis;     //1 daca e deschis si 0 daca e inchis
public:
    Cabinet();
    Cabinet(char* numeCabinet, string specializare, int etajLocalizare, bool deschis, int nrDoctoriPeCabinet);
    Cabinet(char* numeCabinet);
    Cabinet(bool deschis, int etajLocalizare);
    Cabinet(const Cabinet& cab);

    Cabinet& operator=(const Cabinet& cab);

    const char* getNumeCabinet();
    string getSpecializare();
    int getEtajLocalizare();
    bool getDeschis();
    int getNrDoctorPeCabinet();

    void setNumeCabinet(char* numeCabinet);
    void setSpecializare(string specializare);
    void setEtajLocalizare(int etajLocalizare);
    void setDeschis(bool deschis);
    void setNrDoctoriPeCabinet(int nrDoctoriPeCabinet);

    friend ostream& operator<<(ostream& out, const Cabinet& p);
    friend istream& operator>>(istream& in, Cabinet& p);

    bool operator==(const Cabinet& cab);
    bool operator>=(const Cabinet& cab);
    char operator[](int index);

    Cabinet operator+(int x);
    Cabinet operator+(Cabinet a);
    friend Cabinet operator+(int x, Cabinet a);
    Cabinet operator+=(int x);

    Cabinet operator-(int x);
    Cabinet operator-(Cabinet a);
    friend Cabinet operator-(int x, Cabinet a);
    Cabinet operator-=(int x);

    friend Cabinet operator+(Cabinet m, Doctor& a);
    friend Cabinet operator+(Doctor& a, Cabinet m);

    const Cabinet& operator++();
    const Cabinet operator++(int);

    void determinareDoctor(Doctor a, Cabinet m);

    ~Cabinet();
};
const char* Cabinet::getNumeCabinet()
{
    return this->numeCabinet;
}
string Cabinet::getSpecializare()
{
    return this->specializare;
}
int Cabinet::getEtajLocalizare()
{
    return this->etajLocalizare;
}
bool Cabinet::getDeschis()
{
    return this->deschis;
}
int Cabinet::getNrDoctorPeCabinet()
{
    return this->nrDoctoriPeCabinet;
}
void Cabinet::setNumeCabinet(char* numeCabinet)
{
    if (this->numeCabinet != NULL)
        delete[] this->numeCabinet;
    this->numeCabinet = new char[strlen(numeCabinet) + 1];
    strcpy(this->numeCabinet, numeCabinet);
}
void Cabinet::setSpecializare(string specializare)
{
    this->specializare = specializare;
}
void Cabinet::setEtajLocalizare(int etajLocalizare)
{
    this->etajLocalizare = etajLocalizare;
}
void Cabinet::setDeschis(bool deschis)
{
    this->deschis = deschis;
}
void Cabinet::setNrDoctoriPeCabinet(int nrDoctoriPeCabinet)
{
    this->nrDoctoriPeCabinet = nrDoctoriPeCabinet;
}
Cabinet::Cabinet()
{
    this->numeCabinet = new char[strlen("AnonimNume") + 1];
    strcpy(this->numeCabinet, "AnonimNume");
    this->specializare = " ";
    this->etajLocalizare = -100;
    this->deschis = 0;
    this->nrDoctoriPeCabinet = 0;
}
Cabinet::Cabinet(char* numeCabinet)
{
    this->numeCabinet = new char[strlen(numeCabinet) + 1];
    strcpy(this->numeCabinet, numeCabinet);
    this->specializare = " ";
    this->etajLocalizare = -100;
    this->deschis = 0;
    this->nrDoctoriPeCabinet = 0;
}
Cabinet::Cabinet(bool deschis, int etajLocalizare)
{
    this->numeCabinet = new char[strlen("AnonimNume") + 1];
    strcpy(this->numeCabinet, "AnonimNume");
    this->specializare = " ";
    this->etajLocalizare = etajLocalizare;
    this->deschis = deschis;
    this->nrDoctoriPeCabinet = 0;
}
Cabinet::Cabinet(char* numeCabinet, string specializare, int etajLocalizare, bool deschis, int nrDoctoriPeCabinet)
{
    this->numeCabinet = new char[strlen(numeCabinet) + 1];
    strcpy(this->numeCabinet, numeCabinet);
    this->specializare = specializare;
    this->etajLocalizare = etajLocalizare;
    this->deschis = deschis;
    this->nrDoctoriPeCabinet = nrDoctoriPeCabinet;
}
Cabinet::Cabinet(const Cabinet& cab)
{
    this->numeCabinet = new char[strlen(cab.numeCabinet) + 1];
    strcpy(this->numeCabinet, cab.numeCabinet);
    this->specializare = cab.specializare;
    this->etajLocalizare = cab.etajLocalizare;
    this->deschis = cab.deschis;
    this->nrDoctoriPeCabinet = cab.nrDoctoriPeCabinet;
}
Cabinet& Cabinet::operator=(const Cabinet& cab)
{
    if (this != &cab)
    {
        if (this->numeCabinet != NULL)
            delete[] this->numeCabinet;
        this->numeCabinet = new char[strlen(cab.numeCabinet) + 1];
        strcpy(this->numeCabinet, cab.numeCabinet);
        this->specializare = cab.specializare;
        this->etajLocalizare = cab.etajLocalizare;
        this->deschis = cab.deschis;
        this->nrDoctoriPeCabinet = cab.nrDoctoriPeCabinet;
    }
    return *this;
}
bool Cabinet::operator>=(const Cabinet& cab)
{

    if (this->nrDoctoriPeCabinet >= cab.nrDoctoriPeCabinet)
        return true;
    return false;

}
bool Cabinet::operator==(const Cabinet& cab)
{
    if (strcmp(this->numeCabinet, cab.numeCabinet) == 0 && this->etajLocalizare == cab.etajLocalizare && this->specializare == cab.specializare && this->deschis == cab.deschis && this->nrDoctoriPeCabinet == cab.nrDoctoriPeCabinet)
        return true;
    return false;
}
char Cabinet::operator[](int index)
{

    if (strlen(this->numeCabinet) == 0)
    {
        cout << "\nCuvant vid ";
        return -1;
    }
    else
    {
        if (0 <= index && index < strlen(this->numeCabinet))
            return this->numeCabinet[index];
        else
        {
            cout << "\nIndex gresit ";
            return -1;
        }
    }
}
Cabinet Cabinet::operator+(int x)
{
    Cabinet aux = *this;
    aux.nrDoctoriPeCabinet = aux.nrDoctoriPeCabinet + x;
    return aux;
}
Cabinet Cabinet::operator+(Cabinet a)
{
    Cabinet aux;
    if (aux.numeCabinet != NULL)
        delete[] aux.numeCabinet;
    aux.numeCabinet = new char[strlen(a.numeCabinet) + 1];
    strcpy(aux.numeCabinet, a.numeCabinet);
    if (a.numeCabinet != NULL)
        delete[] a.numeCabinet;
    a.numeCabinet = new char[strlen(aux.numeCabinet) + strlen(this->numeCabinet) + 1];
    strcpy(a.numeCabinet, aux.numeCabinet);
    strcat(a.numeCabinet, this->numeCabinet);
    a.specializare = a.specializare + this->specializare;
    //a.etajLocalizare = a.etajLocalizare + this->etajLocalizare;
    //a.deschis = a.deschis + this->deschis;
    a.nrDoctoriPeCabinet = a.nrDoctoriPeCabinet + this->nrDoctoriPeCabinet;
    return a;
}
Cabinet operator+(int x, Cabinet a)
{
    a.nrDoctoriPeCabinet = a.nrDoctoriPeCabinet + x;
    return a;
}
Cabinet Cabinet::operator+=(int x)
{
    this->nrDoctoriPeCabinet += x;
    return *this;
}
Cabinet Cabinet::operator-(int x)
{
    Cabinet aux = *this;
    aux.nrDoctoriPeCabinet = aux.nrDoctoriPeCabinet - x;
    return aux;
}
Cabinet Cabinet::operator-(Cabinet a)
{
    a.nrDoctoriPeCabinet = this->nrDoctoriPeCabinet - a.nrDoctoriPeCabinet;
    return a;
}
Cabinet operator-(int x, Cabinet a)
{
    a.nrDoctoriPeCabinet = x - a.nrDoctoriPeCabinet;
    return a;
}
Cabinet Cabinet::operator-=(int x)
{
    this->nrDoctoriPeCabinet -= x;
    return *this;
}
Cabinet operator+(Cabinet m, Doctor& a)   //adun la cabinet m.nrDoctoriPeCabinet doctorul a daca au aceeasi specializare
{
    if (m.specializare == a.getSpecializare())
        m.nrDoctoriPeCabinet++;
    return m;
}
Cabinet operator+(Doctor& a, Cabinet m)
{
    if (m.specializare == a.getSpecializare())
        m.nrDoctoriPeCabinet++;
    return m;
}
istream& operator>>(istream& in, Cabinet& p)
{

    cout << "\nIntroduceti numele cabinetului: ";
    char aux[100];
    in >> aux;

    if (p.numeCabinet != NULL)
        delete[] p.numeCabinet;
    p.numeCabinet = new char[strlen(aux) + 1];
    strcpy(p.numeCabinet, aux);

    cout << "\nIntroduceti specializarea cabinetului: ";
    in >> p.specializare;

    cout << "\nIntroduceti etajul localizarii: ";
    in >> p.etajLocalizare;

    cout << "\nIntroduceti disponibilitatea cabinetului, 1 daca este deschis si 0 daca este inchis: ";
    in >> p.deschis;

    cout << "\nIntroduceti numarul de doctori pe cabinet: ";
    in >> p.nrDoctoriPeCabinet;

    return in;
}
ostream& operator<<(ostream& out, const Cabinet& p)
{
    out << "\nNume cabinet: " << p.numeCabinet;
    out << "\nSpecializare: " << p.specializare;
    out << "\nEtajul Localizarii: " << p.etajLocalizare;
    if (p.deschis == 1)
        out << "\nEste deschis.";
    else out << "\nEste inchis.";
    out << "\nNumarul de doctori pe cabinet: " << p.nrDoctoriPeCabinet;

    return out;
}
const Cabinet& Cabinet::operator++()
{
    this->nrDoctoriPeCabinet++;
    return *this;
}
const Cabinet Cabinet::operator++(int)
{
    Cabinet aux(*this);
    this->nrDoctoriPeCabinet++;
    return aux;
}
void Cabinet::determinareDoctor(Doctor a, Cabinet m)    //verific daca doctorul a se poate duce la cabinetul m
{
    if (a.getSpecializare() == m.specializare && m.nrDoctoriPeCabinet == 0 && m.deschis == 1)   //doctorul si cabinetul trebuie sa aiba aceeasi specializare si cabinetul sa fie deschis si neocupat de alt doctor
        cout << "Doctorul " << a.getNumeDoctor() << " " << a.getPrenumeDoctor() << " poate merge in cabinetul " << m.numeCabinet << " de la etajul " << m.etajLocalizare;
    else cout << "Doctorul " << a.getNumeDoctor() << " " << a.getPrenumeDoctor() << " nu poate merge in cabinetul " << m.numeCabinet;
}
Cabinet::~Cabinet()
{
    if (this->numeCabinet != NULL)
        delete[] this->numeCabinet;
}

int comanda;
list <Pacient> pacient;
list <Reteta> reteta;
list <Doctor> doctor;
list <Cabinet> cabinet;


void meniuInteractiv()
{
    while(comanda!=5)
    {
        cout << "\nBun venit! Introduceti clasa cu care doriti sa lucrati. \nApasati tasta: \n1 pentru clasa Pacient\n2 pentru clasa Reteta\n3 pentru clasa Doctor\n4 pentru clasa Cabinet\n5 pentru Exit\n" << endl;
        cout << endl;
        cin >> comanda;
        switch (comanda)
        {
        case 1:
        {
            int optiuniPacient=0;
            while (optiuniPacient != 5)
            {
                cout << "\nSelectati operatia pe care doriti sa o efectuati:\n1 pentru CREATE\n2 pentru READ\n3 pentru UPDATE\n4 pentru DELETE\n5 pentru BACK\n6 pentru a verifica greutatea pacientului" << endl;
                cout << endl;
                cin >> optiuniPacient;
                switch (optiuniPacient)
                {
                case 1:
                {
                    int optiuniPacientCreate=0;
                    while (optiuniPacientCreate != 5)
                    {
                        cout << "\nSelectati constructorul:\n1 pentru constructorul fara parametri\n2 pentru constructorul cu toti parametrii\n3 pentru constructorul cu parametrii: nume, prenume, initiala tatalui\n4 pentru constructorul cu parametrii: tipul problemei si gravitatea acesteia\n5 pentru back" << endl;
                        cout << endl;
                        cin >> optiuniPacientCreate;
                        switch (optiuniPacientCreate)
                        {
                        case 1:
                        {
                            Pacient p;
                            pacient.push_back(p);
                            break;
                        }
                        case 2:
                        {
                            Pacient p;
                            cin >> p;
                            pacient.push_back(p);
                            break;
                        }
                        case 3:
                        {
                            char* nume;
                            char* prenume;
                            char initialaTata;
                            char Nume[30], Prenume[30];
                            cout << "\nIntroduceti numele pacientului: ";
                            cin >> Nume;
                            cout << "\nIntroduceti prenumele pacientului: ";
                            cin >> Prenume;
                            cout << "\nIntroduceti initiala tatalui pacientului: ";
                            cin >> initialaTata;
                            if (nume != NULL)
                                delete[] nume;
                            if (prenume != NULL)
                                delete[] prenume;
                            nume = new char[strlen(Nume) + 1];
                            prenume = new char[strlen(Prenume) + 1];
                            strcpy(nume, Nume);
                            strcpy(prenume, Prenume);

                            Pacient p(nume, prenume, initialaTata);
                            pacient.push_back(p);
                            break;
                        }
                        case 4:
                        {
                            char* tipProblema;
                            int gradGravitate;
                            char TipProblema[50];
                            cout << "\nIntroduceti tipul problemei: ";
                            cin >> TipProblema;
                            cout << "\nIntroduceti gradul de gravitate: ";
                            cin >> gradGravitate;
                            if (tipProblema != NULL)
                                delete[] tipProblema;
                            tipProblema = new char[strlen(TipProblema) + 1];
                            strcpy(tipProblema, TipProblema);
                            Pacient p(tipProblema, gradGravitate);
                            pacient.push_back(p);
                            break;
                        }
                        case 5:
                        {
                            optiuniPacientCreate=5;
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
                    bool okRead = 1;
                    while (okRead)
                    {
                        cout << "\nSelectati indexul pacientului din lista care doriti sa fie afisat: ";
                        list<Pacient>::iterator index_pacient;
                        int indexPacient;
                        cin >> indexPacient;
                        index_pacient = pacient.begin();
                        advance(index_pacient, indexPacient - 1);
                        if (index_pacient == pacient.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okRead = 0;
                        }
                        else
                            cout << *index_pacient << endl;
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okRead;

                    }
                    optiuniPacient=5;
                    break;
                }
                case 3:
                {
                    bool okUpdate = 1;
                    while (okUpdate)
                    {
                        cout << "\nSelectati indexul pacientului din lista care doriti sa fie updatat: ";
                        list<Pacient>::iterator index_pacient;
                        int indexPacient;
                        cin >> indexPacient;
                        index_pacient = pacient.begin();
                        advance(index_pacient, indexPacient - 1);
                        if (index_pacient == pacient.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okUpdate = 0;
                        }
                        else
                        {
                            Pacient p;
                            cin >> p;
                            *index_pacient = p;
                        }

                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okUpdate;

                    }
                    optiuniPacient=5;
                    break;
                }
                case 4:
                {
                    bool okDelete = 1;
                    while (okDelete)
                    {
                        cout << "\nSelectati indexul pacientului din lista care doriti sa fie sters: ";
                        list<Pacient>::iterator index_pacient;
                        int indexPacient;
                        cin >> indexPacient;
                        index_pacient = pacient.begin();
                        advance(index_pacient, indexPacient - 1);
                        if (index_pacient == pacient.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okDelete = 0;
                        }
                        else
                            pacient.erase(index_pacient);
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okDelete;
                    }
                    optiuniPacient=5;
                    break;
                }
                case 5:
                {
                    optiuniPacient=5;
                    break;
                }
                case 6:
                {
                    bool okVerif = 1;
                    while (okVerif)
                    {
                        cout << "\nSelectati indexul pacientului din lista caruia doriti sa ii calculati greutatea: ";
                        list<Pacient>::iterator Index_pacient;
                        int IndexPacient;
                        cin >> IndexPacient;
                        Index_pacient = pacient.begin();
                        advance(Index_pacient, IndexPacient - 1);
                        if (Index_pacient == pacient.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okVerif = 0;
                        }
                        else
                        {
                            Pacient p;
                            p = *Index_pacient;
                            p.calculIMC(p);
                            cout<<endl;
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okVerif;

                    }
                    optiuniPacient=5;
                    break;
                }
                default:
                {

                    //optiuniPacient=5;
                    cout << "\nComanda gresita";
                    break;
                }
                }
            }
            break;
        }
        case 2:
        {
            int optiuniReteta=0;
            while (optiuniReteta != 5)
            {
                cout << "Selectati operatia pe care doriti sa o efectuati:\n1 pentru CREATE\n2 pentru READ\n3 pentru UPDATE\n4 pentru DELETE\n5 pentru BACK\n6 pentru a verifica daca reteta contine alergii ale pacientului" << endl;
                cout << endl;
                cin >> optiuniReteta;
                switch (optiuniReteta)
                {
                case 1:
                {
                    int optiuniRetetaCreate=0;
                    while (optiuniRetetaCreate != 5)
                    {
                        cout << "\nSelectati constructorul:\n1 pentru constructorul fara parametri\n2 pentru constructorul cu toti parametrii\n3 pentru constructorul cu parametrii: nume doctor si prenume doctor\n4 pentru constructorul cu parametru diagnosticul pacientului\n5 pentru back" << endl;
                        cout << endl;
                        cin >> optiuniRetetaCreate;
                        switch (optiuniRetetaCreate)
                        {
                        case 1:
                        {
                            Reteta r;
                            reteta.push_back(r);
                            break;
                        }
                        case 2:
                        {
                            Reteta r;
                            cin >> r;
                            reteta.push_back(r);
                            break;
                        }
                        case 3:
                        {
                            char* numeDoctor;
                            char* prenumeDoctor;
                            char NumeDoctor[30], PrenumeDoctor[50];
                            cout << "\nIntroduceti numele doctorului consultant: " << endl;
                            cin >> NumeDoctor;
                            cout << "\nIntroduceti numele doctorului consultant: " << endl;
                            cin >> PrenumeDoctor;
                            if (numeDoctor != NULL)
                                delete[] numeDoctor;
                            if (prenumeDoctor != NULL)
                                delete[] prenumeDoctor;
                            numeDoctor = new char[strlen(NumeDoctor) + 1];
                            prenumeDoctor = new char[strlen(PrenumeDoctor) + 1];
                            strcpy(numeDoctor, NumeDoctor);
                            strcpy(prenumeDoctor, PrenumeDoctor);
                            Reteta r(numeDoctor, prenumeDoctor);
                            reteta.push_back(r);
                            break;
                        }
                        case 4:
                        {
                            string diagnostic;
                            cout << "\nIntroduceti diagnosticul pacientului: " << endl;
                            cin >> diagnostic;
                            Reteta r(diagnostic);
                            reteta.push_back(r);
                            break;
                        }
                        case 5:
                        {
                            optiuniRetetaCreate=5;
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
                        cout << "\nSelectati indexul retetei din lista care doriti sa fie afisata: ";
                        list<Reteta>::iterator index_reteta;
                        int indexReteta;
                        cin >> indexReteta;
                        index_reteta = reteta.begin();
                        advance(index_reteta, indexReteta - 1);
                        if (index_reteta == reteta.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okRRead = 0;
                        }
                        else

                            cout << *index_reteta << endl;
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okRRead;

                    }
                    optiuniReteta=5;
                    break;
                }
                case 3:
                {
                    bool okRUpdate = 1;
                    while (okRUpdate)
                    {
                        cout << "\nSelectati indexul retetei din lista care doriti sa fie updatata: ";
                        list<Reteta>::iterator index_reteta;
                        int indexReteta;
                        cin >> indexReteta;
                        index_reteta = reteta.begin();
                        advance(index_reteta, indexReteta - 1);
                        if (index_reteta == reteta.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okRUpdate = 0;
                        }
                        else
                        {
                            Reteta p;
                            cin >> p;
                            *index_reteta = p;
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okRUpdate;


                    }
                    optiuniReteta=5;
                    break;
                }
                case 4:
                {
                    bool okRDelete = 1;
                    while (okRDelete)
                    {
                        cout << "\nSelectati indexul pacientului din lista care doriti sa fie sters: ";
                        list<Reteta>::iterator index_reteta;
                        int indexReteta;
                        cin >> indexReteta;
                        index_reteta = reteta.begin();
                        advance(index_reteta, indexReteta - 1);
                        if (index_reteta == reteta.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okRDelete = 0;
                        }
                        else

                            reteta.erase(index_reteta);
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okRDelete;

                    }
                    optiuniReteta=5;
                    break;
                }
                case 5:
                {
                    optiuniReteta=5;
                    break;
                }
                case 6:
                {
                    bool okVerif = 1;
                    while (okVerif)
                    {
                        cout << "\nSelectati indexul pacientului din lista la care doriti sa se faca verificarea: ";
                        list<Pacient>::iterator Index_pacient;
                        int IndexPacient;
                        cin >> IndexPacient;
                        Index_pacient = pacient.begin();
                        advance(Index_pacient, IndexPacient - 1);
                        if (Index_pacient == pacient.end())
                        {
                            cout << "\nIndex gresit" << endl;
                        }
                        else
                        {
                            cout << "\nSelectati indexul retetei din lista la care doriti sa se faca verificarea: ";
                            list<Reteta>::iterator Index_Reteta;
                            int IndexReteta;
                            cin >> IndexReteta;
                            Index_Reteta = reteta.begin();
                            advance(Index_Reteta, IndexReteta - 1);
                            if (Index_Reteta == reteta.end())
                            {
                                cout << "\nIndex gresit" << endl;
                            }
                            else
                            {
                                Pacient p;
                                Reteta r;
                                p = *Index_pacient;
                                r = *Index_Reteta;
                                cout<<r.verifAlergii(p, r);
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
                    // optiuniReteta=5;
                    cout << "\nComanda gresita";
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            int optiuniDoctor=0;
            while (optiuniDoctor != 5)
            {
                cout << "\nSelectati operatia pe care doriti sa o efectuati:\n1 pentru CREATE\n2 pentru READ\n3 pentru UPDATE\n4 pentru DELETE\n5 pentru back\n6 pentru a verifica daca un doctor anume poate primi un pacient anume" << endl;
                cout << endl;
                cin >> optiuniDoctor;
                switch (optiuniDoctor)
                {
                case 1:
                {
                    int optiuniDoctorCreate;
                    while (optiuniDoctorCreate != 5)
                    {
                        cout << "\nSelectati constructorul:\n1 pentru constructorul fara parametri\n2 pentru constructorul cu toti parametrii\n3 pentru constructorul cu parametrii: numele doctorului si prenumele doctorului\n4 pentru constructorul cu parametrii: specializarea doctorului\n5 pentru back" << endl;
                        cout << endl;
                        cin >> optiuniDoctorCreate;
                        switch (optiuniDoctorCreate)
                        {
                        case 1:
                        {
                            Doctor d;
                            doctor.push_back(d);
                            break;
                        }
                        case 2:
                        {
                            Doctor d;
                            cin >> d;
                            doctor.push_back(d);
                            break;
                        }
                        case 3:
                        {
                            char* numeDoctor;
                            char* prenumeDoctor;
                            char NumeDoctor[30], PrenumeDoctor[50];
                            cout << "\nIntroduceti numele doctorului: " << endl;
                            cin >> NumeDoctor;
                            cout << "\nIntroduceti numele doctorului: " << endl;
                            cin >> PrenumeDoctor;
                            if (numeDoctor != NULL)
                                delete[] numeDoctor;
                            if (prenumeDoctor != NULL)
                                delete[] prenumeDoctor;
                            numeDoctor = new char[strlen(NumeDoctor) + 1];
                            prenumeDoctor = new char[strlen(PrenumeDoctor) + 1];
                            strcpy(numeDoctor, NumeDoctor);
                            strcpy(prenumeDoctor, PrenumeDoctor);
                            Doctor d(numeDoctor, prenumeDoctor);
                            doctor.push_back(d);
                            break;
                        }
                        case 4:
                        {
                            string specializare;
                            cout << "\nIntroduceti specializarea doctorului: ";
                            cin >> specializare;
                            Doctor d(specializare);
                            doctor.push_back(d);
                            break;
                        }
                        case 5:
                        {
                            optiuniDoctorCreate=5;
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
                        cout << "\nSelectati indexul doctorului din lista care doriti sa fie afisat: ";
                        list<Doctor>::iterator index_doctor;
                        int indexDoctor;
                        cin >> indexDoctor;
                        index_doctor = doctor.begin();
                        advance(index_doctor, indexDoctor - 1);
                        if (index_doctor == doctor.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okDRead = 0;
                        }
                        else

                            cout << *index_doctor << endl;
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okDRead;



                    }
                    optiuniDoctor=5;
                    break;
                }
                case 3:
                {
                    bool okDUpdate = 1;
                    while (okDUpdate)
                    {
                        cout << "\nSelectati indexul doctorului din lista care doriti sa fie updatat: ";
                        list<Doctor>::iterator index_doctor;
                        int indexDoctor;
                        cin >> indexDoctor;
                        index_doctor = doctor.begin();
                        advance(index_doctor, indexDoctor - 1);
                        if (index_doctor == doctor.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okDUpdate = 0;
                        }
                        else
                        {
                            Doctor d;
                            cin >> d;
                            *index_doctor = d;
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okDUpdate;


                    }
                    optiuniDoctor=5;
                    break;
                }
                case 4:
                {
                    bool okDDelete = 1;
                    while (okDDelete)
                    {
                        cout << "\nSelectati indexul doctorului din lista care doriti sa fie sters: ";
                        list<Doctor>::iterator index_doctor;
                        int indexDoctor;
                        cin >> indexDoctor;
                        index_doctor = doctor.begin();
                        advance(index_doctor, indexDoctor - 1);
                        if (index_doctor == doctor.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okDDelete = 0;
                        }
                        else

                            doctor.erase(index_doctor);
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okDDelete;

                    }
                    optiuniDoctor=5;
                    break;
                }
                case 5:
                {
                    optiuniDoctor=5;
                    break;
                }
                case 6:
                {
                    bool okDisponibilitate = 1;
                    while (okDisponibilitate)
                    {
                        cout << "\nSelectati indexul pacientului din lista la care doriti sa se faca verificarea: ";
                        list<Pacient>::iterator Index_pacient;
                        int IndexPacient;
                        cin >> IndexPacient;
                        Index_pacient = pacient.begin();
                        advance(Index_pacient, IndexPacient - 1);
                        if (Index_pacient == pacient.end())
                        {
                            cout << "\nIndex gresit" << endl;
                        }
                        else
                        {
                            cout << "\nSelectati indexul doctorului din lista la care doriti sa se faca verificarea: ";
                            list<Doctor>::iterator Index_Doctor;
                            int IndexDoctor;
                            cin >> IndexDoctor;
                            Index_Doctor = doctor.begin();
                            advance(Index_Doctor, IndexDoctor - 1);
                            if (Index_Doctor == doctor.end())
                            {
                                cout << "\nIndex gresit" << endl;
                            }
                            else
                            {
                                Pacient p;
                                Doctor d;
                                p = *Index_pacient;
                                d = *Index_Doctor;
                                d.disponibilitate(d, p);
                                cout<<endl;
                            }
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okDisponibilitate;
                    }
                    break;
                }
                default:
                {
                    //optiuniDoctor=5;
                    cout << "\nComanda gresita";
                    break;
                }
                }
            }
            break;
        }
        case 4:
        {
            int optiuniCabinet=0;
            while (optiuniCabinet != 5)
            {
                cout << "\nSelectati operatia pe care doriti sa o efectuati:\n1 pentru CREATE\n2 pentru READ\n3 pentru UPDATE\n4 pentru DELETE\n5 pentru BACK\n6 pentru a determina daca un doctor anume se poate duce la un cabinet anume" << endl;
                cout << endl;
                cin >> optiuniCabinet;
                switch (optiuniCabinet)
                {
                case 1:
                {
                    int optiuniCabinetCreate;
                    while (optiuniCabinetCreate != 5)
                    {
                        cout << "\nSelectati constructorul:\n1 pentru constructorul fara parametri\n2 pentru constructorul cu toti parametrii\n3 pentru constructorul cu parametrii: numele cabinetului\n4 pentru constructorul cu parametrii: etajul localizarii si disponibilitatea\n5 pentru back" << endl;
                        cout << endl;
                        cin >> optiuniCabinetCreate;
                        switch (optiuniCabinetCreate)
                        {
                        case 1:
                        {
                            Cabinet c;
                            cabinet.push_back(c);
                            break;
                        }
                        case 2:
                        {
                            Cabinet c;
                            cin >> c;
                            cabinet.push_back(c);
                            break;
                        }
                        case 3:
                        {
                            char* numeCabinet;
                            char NumeCabinet[30];
                            cout << "\nIntroduceti numele cabinetului: " << endl;
                            cin >> NumeCabinet;
                            if (numeCabinet != NULL)
                                delete[] numeCabinet;
                            numeCabinet = new char[strlen(NumeCabinet) + 1];
                            strcpy(numeCabinet, NumeCabinet);
                            Cabinet c(numeCabinet);
                            cabinet.push_back(c);
                            break;
                        }
                        case 4:
                        {
                            bool deschis;
                            int etajLocalizare;
                            cout << "\nIntroduceti etajul localizarii: " << endl;
                            cin >> etajLocalizare;
                            cout << "\nIntroduceti disponibilitatea (1 daca este deschis, 0 altfel): " << endl;
                            Cabinet c(deschis, etajLocalizare);
                            cabinet.push_back(c);
                            break;
                        }
                        case 5:
                        {
                            optiuniCabinetCreate=5;
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
                        cout << "\nSelectati indexul cabinetului din lista care doriti sa fie afisat: ";
                        list<Cabinet>::iterator index_cabinet;
                        int indexCabinet;
                        cin >> indexCabinet;
                        index_cabinet = cabinet.begin();
                        advance(index_cabinet, indexCabinet - 1);
                        if (index_cabinet == cabinet.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okCRead = 0;
                        }
                        else

                            cout << *index_cabinet << endl;
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okCRead;

                    }
                    optiuniCabinet=5;
                    break;
                }
                case 3:
                {
                    bool okCUpdate = 1;
                    while (okCUpdate)
                    {
                        cout << "\nSelectati indexul cabinetului din lista care doriti sa fie updatat: ";
                        list<Cabinet>::iterator index_cabinet;
                        int indexCabinet;
                        cin >> indexCabinet;
                        index_cabinet = cabinet.begin();
                        advance(index_cabinet, indexCabinet - 1);
                        if (index_cabinet == cabinet.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okCUpdate = 0;
                        }
                        else
                        {
                            Cabinet d;
                            cin >> d;
                            *index_cabinet = d;
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okCUpdate;


                    }
                    optiuniCabinet=5;
                    break;
                }
                case 4:
                {
                    bool okCDelete = 1;
                    while (okCDelete)
                    {
                        cout << "\nSelectati indexul cabinetului din lista care doriti sa fie sters: ";
                        list<Cabinet>::iterator index_cabinet;
                        int indexCabinet;
                        cin >> indexCabinet;
                        index_cabinet = cabinet.begin();
                        advance(index_cabinet, indexCabinet - 1);
                        if (index_cabinet == cabinet.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okCDelete = 0;
                        }
                        else
                            cabinet.erase(index_cabinet);
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okCDelete;

                    }
                    optiuniCabinet=5;
                    break;
                }
                case 5:
                {
                    optiuniCabinet=5;
                    break;
                }
                case 6:
                {
                    bool okDetDoctor = 1;
                    while (okDetDoctor)
                    {
                        cout << "\nSelectati indexul cabinetului din lista la care doriti sa se faca verificarea: ";
                        list<Cabinet>::iterator Index_cabinet;
                        int IndexCabinet;
                        cin >> IndexCabinet;
                        Index_cabinet = cabinet.begin();
                        advance(Index_cabinet, IndexCabinet - 1);
                        if (Index_cabinet == cabinet.end())
                        {
                            cout << "\nIndex gresit" << endl;
                            //okDetDoctor = 0;
                        }
                        else
                        {
                            cout << "\nSelectati indexul doctorului din lista la care doriti sa se faca verificarea: ";
                            list<Doctor>::iterator Index_Doctor;
                            int IndexDoctor;
                            cin >> IndexDoctor;
                            Index_Doctor = doctor.begin();
                            advance(Index_Doctor, IndexDoctor - 1);
                            if (Index_Doctor == doctor.end())
                            {
                                cout << "\nIndex gresit" << endl;
                                //okDetDoctor = 0;
                            }
                            else
                            {
                                Cabinet c;
                                Doctor d;
                                c = *Index_cabinet;
                                d = *Index_Doctor;
                                c.determinareDoctor(d, c);
                                cout<<endl;
                            }
                        }
                        cout << "\nApasati tasta 1 daca doriti sa continuati, 0 altfel" << endl;
                        cin >> okDetDoctor;
                    }
                    break;
                }
                default:
                {
                    //optiuniCabinet=5;
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
