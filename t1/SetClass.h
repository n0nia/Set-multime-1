#ifndef SETCLASS_H
#define SETCLASS_H

#include <iostream>
#include <exception>
#include <stdexcept>

class SetClass
{
    int *v;
    int Size, maxSize;
    public:
        SetClass();
        SetClass(int);
        ~SetClass();
        friend std::ostream& operator<<(std::ostream&, const SetClass&);
        friend std::istream& operator>>(std::istream&, SetClass&);
        void Verif();
        void Inserare(int);
        void Stergere(int);
        int Cautare(int);
        void Crescator();
        SetClass& operator=(const SetClass&);
        int& operator[](int);
        bool operator<(SetClass);
        bool operator>(SetClass);
        SetClass operator+(SetClass&);
        SetClass operator*(int);
        int suma();
        void elemente(SetClass&, SetClass&);
        int nr_el();
};

#endif // SETCLASS_H
