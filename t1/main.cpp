#include <iostream>
#include "SetClass.h"
#include <cassert>

using namespace std;

int main()
{
    SetClass v;
    v.Inserare(6);
    v.Inserare(3);
    v.Inserare(3);
    v.Inserare(9);
    cout<<"Multimea dupa inserari: "<<v<<"\n\n";

    SetClass w, r, p;
    cin>>w;
    w.Verif();
    cout<<"Multimea citita de la tastatura: "<<w<<"\n\n";

    r=w+v;
    cout<<"Reuniunea celor doua multimi: "<<r<<"\n\n";
    r.~SetClass();

    p=w*3;
    cout<<"Multimea rezultata dupa inmultirea cu un scalar: "<<p<<"\n\n";
    p.~SetClass();

    bool a=v<w;
    if(a)
        cout<<"Cardinalul primei multimi este mai mic decat cardinalul celeilalte\n\n";
    else
        cout<<"Cardinalul primei multimi nu este mai mic decat cardinalul celeilalte\n\n";

    cout<<"Suma elementelor din una dintre multimi: "<<v.suma()<<"\n\n";

    SetClass b, c;
    w.elemente(b, c);
    cout<<"Elementele pare din multime: "<<b<<"\n\n";
    cout<<"Elementele impare din multime: "<<c<<"\n\n";


    cout<<"Numarul de elemente din multime: "<<v.nr_el();


    b.~SetClass();
    c.~SetClass();

    v.~SetClass();
    w.~SetClass();
    return 0;
}
