#include "SetClass.h"

SetClass::SetClass() ///constructorul fara parametri
{
    Size=0;
    maxSize=1; ///presupun ca multimea are cel putin un element
    this->maxSize=maxSize;
    v=new int[this->maxSize];
}

SetClass::SetClass(int maxSize)  ///constructorul cu parametri
{
    if(maxSize<=0)
    {
        std::invalid_argument e("Dimensiunea nu este buna");
        throw e;
    }
    this->maxSize=maxSize;
    v=new int[this->maxSize];
    Size=0;
}

SetClass::~SetClass() ///destructorul
{
    delete[] v;
    maxSize=Size=0;

}

int SetClass::Cautare(int x) ///returneza pozitia elementului cautat, daca exista
{
    int i=0;
    while(v[i]!=x && i<Size)
        i++;
    if(i==Size)
        return -1;
    return i;
}

void SetClass::Stergere(int x)
{
    int i=Cautare(x);
    if(i!=-1)
    {
        for(int j=i;j<Size;j++) ///incepe stergerea de pe pozitia elementului x
            v[j]=v[j+1];
        Size--;
    }
}

void SetClass::Crescator()
{
    for(int i=0;i<Size;i++)
        for(int j=i+1;j<Size;j++)
            if(v[i]>v[j])
                std::swap(v[i], v[j]);
}

void SetClass::Verif() ///verifica daca un element apare o singura data
{
    Crescator(); ///ordoneaza crescator multimea
    for(int i=0;i<Size;i++)
        if(v[i]==v[i+1])
        {
            Stergere(v[i]); ///dupa ordonare daca 2 elemente consecutive sunt egale atunci il sterge pe primul
            i--;
        }
}

void SetClass::Inserare(int x)
{
    if(Size==maxSize)
    {
        maxSize+=1;
        int *aux=new int[maxSize]; ///atribui memorie pentru o multime noua cu un cardinal mai mare cu 1
        for(int i=0;i<Size;i++)
            aux[i]=v[i]; ///copiaza elementele in copie
        delete[] v;
        v=aux;
    }
    v[Size++]=x;
    Verif();
}

int& SetClass::operator[](int i)
{
    if(i<0 || i>=Size)
    {
        std::invalid_argument e("Indexul nu este bun");
        throw e;
    }
    return v[i];
}

SetClass SetClass::operator+(SetClass& a) ///reuniunea a doua multimi
{
    int i;
    SetClass r;
    for(i=0;i<Size;i++)
        r.Inserare(v[i]); ///insereaza mai intai elementele din prima multime
    for(i=0;i<a.Size;i++)
        r.Inserare(a[i]); ///apoi din cea de a doua multime si verifica sa fie in ordine crescatoare si sa apara o singura data
    return r;
}

///supraincarcarea operatorilor < si > pentru compararea cardinalilor

bool SetClass::operator<(SetClass a)
{
    if(Size<a.Size)
        return true;
    return false;
}

bool SetClass::operator>(SetClass a)
{
    if(Size>a.Size)
        return true;
    return false;
}

SetClass SetClass::operator*(int x) ///supraincarcarea operatorului * pentru inmultirea cu un scalar
{
    SetClass w;
    for(int i=0;i<Size;i++)
        w.Inserare(x*v[i]);
    return w;
}

SetClass& SetClass::operator=(const SetClass& v) ///supraincarcarea operatorului =
{
    delete[] this->v;
    this->Size=v.Size;
    this->maxSize=v.maxSize;
    this->v=new int[this->Size];
    for(int i=0;i<this->Size;i++)
        this->v[i]=v.v[i];
    return *this;
}

int SetClass::suma() ///suma elementelor din multime
{
    int s=0;
    for(int i=0;i<Size;i++)
        s+=v[i];
    return s;
}

void SetClass::elemente(SetClass& b, SetClass& c) /// functia salveaza elementele pare si cele impare in doua multimi diferite
{
    for(int i=0;i<Size;i++)
        if(v[i]%2==0)
            b.Inserare(v[i]);
        else
            c.Inserare(v[i]);
}

int SetClass::nr_el() ///numarul de elemente al multimii
{
    return Size;
}

///supraincarcarea operatorilor de afisarea si citirea unei multimi

std::ostream& operator<<(std::ostream& out, const SetClass& v)
{
    for(int i=0;i<v.Size;i++)
        out<<v.v[i]<<" ";
    return out;
}

std::istream& operator>>(std::istream &in, SetClass& v)
{
    delete[] v.v;
    in>>v.maxSize;
    v.Size=v.maxSize;
    v.v=new int[v.Size];
    for(int i=0;i<v.Size;i++)
        in>>v.v[i];
    return in;
}
