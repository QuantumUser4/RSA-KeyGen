import math


def controlloNum():
    maxN = 100
    p = int(input("Inserisci un numero minore di 100: "))
    q = int(input("Inserisci un numero minore di 100: "))
    if p > maxN or q > maxN:
        return controlloNum()
    else:
        return p, q


def EulerIndicator(p, q):
    return (p - 1) * (q - 1)


def findCoprimo(num):
    lista = []
    for i in range(2, 10):
        if math.gcd(i, num) == 1:
            lista.append(i)
    return lista[0]


def trovaInverso(e, phi):
    return pow(e, -1, phi)


def result(cop, n, d):
    chiavePublica = [cop, n]
    chiavePrivata = [d, n]
    return chiavePublica, chiavePrivata


if __name__ == "__main__":
    p, q = controlloNum()
    n = p * q
    indEulero = EulerIndicator(p, q)
    coprimo = findCoprimo(indEulero)
    d = trovaInverso(coprimo, indEulero)
    chiavePublica, chiavePrivata = result(coprimo, n, d)
    print("Chiave Publica: ", chiavePublica)
    print("Chiave Privata: ", chiavePrivata)
