#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class plata_cash;
class plata_card;
class plata_cec;
template <class T>
class Gestiune;
struct data_platii
{
   int zi,luna,an;
};
class plata
{
    friend class gestiune;
    data_platii data;
    int suma;
    public:
    plata (data_platii a, int s)
    {
        data=a;
        suma=s;

    }
    plata()
    {

    }
    virtual void citire(istream &in)
    {
        in>>data.zi>>data.luna>>data.an;
        in>>suma;
    }
    virtual void afisare(ostream &out)
{
    out<<data.zi<<" "<<data.luna<<" "<<data.an<<endl;
        out<<suma<<endl;
}
    friend istream & operator >> (istream &in, plata &a)
    {
        a.citire(in);
    return in;
    }
    friend ostream & operator << (ostream &out, plata &a)
    {
        a.afisare(out);
        return out;
    }


};
class plata_cash:public plata
{

};
class plata_cec:public plata
{

};
class plata_card:public plata
{
    friend class gestiune;
    string nr_card;
    public:
    plata_card(){}
    plata_card(data_platii a,int s, string nr):plata(a,s)
    {
        nr_card=nr;
    }
    void citire(istream &in)
    {
        plata::citire(in);
        in>>nr_card;
    }
    void afisare(ostream &out)
    {
        plata::afisare(out);
        out<<nr_card<<endl;
    }


};
template <class T>
class Gestiune
{

    int nr_plati,n;
      T *v;
      public:
          Gestiune(){}
    Gestiune(int n)
    {
        v=new T[n];
        nr_plati=n;
    }
    Gestiune (const Gestiune &a)
    {
        v=new T[a.nr_plati];
        nr_plati=a.nr_plati;
        for (int i=0;i<nr_plati;i++)
            v[i]=a.v[i];

    }
    Gestiune operator += (T x)
    {
            v[nr_plati]=x;
            nr_plati++;
    }
    void citire()
    {

        for (int i=0;i<nr_plati;i++)
            cin>>v[i];
    }
    void afisare()
    {
        for (int i=0;i<nr_plati;i++)
            cout<<v[i]<<" ";
    }
    ~Gestiune ()
    {
        delete []v;
    }

};
template<>
class Gestiune<char*>
{
public:
    int nr_plati;
    char** nume;

    Gestiune(){}
    Gestiune(int size,int nr)
    {
        nr_plati=nr;

        nume=new char*[size];
        for (int i=0;i<nr;i++)
            nume[i]=new char[20];
    }
    Gestiune (const Gestiune& a)
    {
        nr_plati=a.nr_plati;
        nume=new char*[a.nr_plati];
        int i;
        for (i=0;i<nr_plati;i++);
        nume[i]=a.nume[i];
    }
    void citire()
    {
        for (int i=0;i<nr_plati;i++)
            cin.getline(nume[i],20);


    }
    void afisare()
    {
        for (int i=0;i<nr_plati;i++)
        cout<<nume[i]<<endl;
    }

    Gestiune operator +=(char x)
    {

        nr_plati++;
    }
    ~Gestiune()
    {
        delete []nume;
    }
};
int main()
{
    Gestiune <char*> x(20,3);
    x.citire();
    x.afisare();

        //Gestiune <plata_card>x(2);
        //x.citire();
        //x.afisare();

    return 0;
}
