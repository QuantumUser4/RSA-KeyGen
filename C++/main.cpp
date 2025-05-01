#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void controlloNum(int& p, int& q)
{
    int maxNum = 100;

    cout << "Inserisci un numero (minore di 100): ";
    cin >> p;
    cout << "Inserisci un numero (minore di 100): ";
    cin >> q;

    if (p > maxNum || q > maxNum)
    {
        cout << "I numeri devono essere minori di 100. Ripeti.\n";
        controlloNum(p, q);
    }
}

int EulerIndicator(int p, int q) {
    return (p - 1) * (q - 1); 
}

int findCoprimo(int phi) {
    for (int i = 2; i < phi; i++) {
        if (gcd(i, phi) == 1) {
            return i;
        }
    }
    return -1;
}


int trovaInverso(int e, int phi) {
    int t = 0, newt = 1;
    int r = phi, newr = e;

    while (newr != 0) {
        int quotient = r / newr;
        int temp = newt;
        newt = t - quotient * newt;
        t = temp;

        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }

    if (r > 1) return -1;
    if (t < 0) t += phi;

    return t;
}

int main()
{
    int p = 0, q = 0, n = 0, indEulero = 0, coprimo = 0, d = 0;
    controlloNum(p, q);
    n = p * q;
    indEulero = EulerIndicator(p, q);
    coprimo = findCoprimo(indEulero);
    d = trovaInverso(coprimo, indEulero);
    cout << "Chiave Publica = " << "[" << coprimo << " " << n << "]" << "\n";
    cout << "Chiave Privata = " << "[" << d << " " << n << "]";

    return 0;
}
