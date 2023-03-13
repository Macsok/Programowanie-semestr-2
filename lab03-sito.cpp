#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

///////////////////////////
class Sito_1{
    const int N = 1000;
    int tab[1000];

public:
    Sito_1();
    bool sprawdz(int);
    void odsiej();
    void wyswietl();
};

///////////////////////////

class Sito_2{
    int* tab;
    int N;

public:
    Sito_2(int);
    ~Sito_2();
    bool sprawdz(int);
    void odsiej();
    void wyswietl();
};

///////////////////////////

class Sito_3{
    vector <int> tab;
    int N;

public:
    Sito_3(int);
    bool sprawdz(int);
    void odsiej();
    void wyswietl();
};

///////////////////////////

int main()
{
    int x = 24;
    Sito_2 sito(9000000);
    //cout << sito.sprawdz(x) << "\n\n";
    sito.odsiej();
    //sito.wyswietl();

    cout << "x: ";
    cin >> x;
    cout << sito.sprawdz(x);
    return 0;
}

///////////////////////////

Sito_1::Sito_1() {
    for(int i = 0; i < N; i++) {
        tab[i] = i;
    }
}

bool Sito_1::sprawdz(int n) {
    if(n == 0 || n == 1) return false;
    if(tab[1] == 1) {
        Sito_1 nowe;
        nowe.odsiej();
        return nowe.sprawdz(n);
    }
    return tab[n];
}

void Sito_1::odsiej() {
    tab[0] = tab[1] = 0;
    for(int i = 2; i <= sqrt(N); i++) {
        for(int k = i + 1; k <= N; k++) {
            if(tab[k] % i == 0) tab[k] = 0;
        }
    }
}

void Sito_1::wyswietl() {
    if(tab[1] == 0) {
        for(int i = 0; i < N; i++) {
            if(tab[i] != 0) cout << tab[i] << endl;
        }
    }
    else cout << "nie odsiano" << endl;
}

///////////////////////////

Sito_2::Sito_2(int n) {
    this->N = n + 1;
    tab = new int[N];
    for(int i = 0; i <= N; i++) {
        tab[i] = i;
    }
}

bool Sito_2::sprawdz(int n) {
    if(n == 0 || n == 1) return false;
    if(tab[1] == 1) {
        Sito_2 nowe(n);
        nowe.odsiej();
        return nowe.sprawdz(n);
    }
    return tab[n];
}

void Sito_2::odsiej() {
    tab[0] = tab[1] = 0;
    for(int i = 2; i <= sqrt(N); i++) {
        for(int k = i + 1; k <= N; k++) {
            if(tab[k] % i == 0) tab[k] = 0;
        }
    }
}

void Sito_2::wyswietl() {
    if(tab[1] == 0) {
        for(int i = 0; i < N; i++) {
            if(tab[i] != 0) cout << tab[i] << endl;
        }
    }
    else cout << "nie odsiano" << endl;
}

Sito_2::~Sito_2() {
    delete tab;
    cout << "usunieto" << endl;
}

///////////////////////////

Sito_3::Sito_3(int n) {
    this->N = n + 1;
    for(int i = 0; i <= N; i++) {
        tab.push_back(i);
    }
}

bool Sito_3::sprawdz(int n) {
    if(n == 0 || n == 1) return false;
    if(tab.at(1) == 1) {
        Sito_2 nowe(n);
        nowe.odsiej();
        return nowe.sprawdz(n);
    }
    return tab.at(n);
}

void Sito_3::odsiej() {
    tab.at(0) = tab.at(1) = 0;
    for(int i = 2; i <= sqrt(N); i++) {
        for(int k = i + 1; k <= N; k++) {
            if(tab.at(k) % i == 0) tab.at(k) = 0;
        }
    }
}

void Sito_3::wyswietl() {
    if(tab.at(1) == 0) {
        for(int i = 0; i < N; i++) {
            if(tab.at(i) != 0) cout << tab.at(i) << endl;
        }
    }
    else cout << "nie odsiano" << endl;
}
