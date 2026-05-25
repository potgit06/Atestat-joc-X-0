#include <iostream>
using namespace std;


void afiseazaTabla(char tabla[3][3]);
bool verificaCastigator(char tabla[3][3], char jucator);
bool estePlina(char tabla[3][3]);
bool esteValid(int linie, int coloana, char tabla[3][3]);
void joc();

int main() {
    joc();
    return 0;
}

void joc() {
   
    char tabla[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char jucator = 'X';
    int linie, coloana;
   
   
    while (true) {
        afiseazaTabla(tabla);
       
       
        cout << "Jucatorul " << jucator << ", introduceți linia și coloana (1-3): ";
        cin >> linie >> coloana;
       
       
        linie -= 1;
        coloana -= 1;
       
       
        if (esteValid(linie, coloana, tabla)) {
            tabla[linie][coloana] = jucator;
           
           
            if (verificaCastigator(tabla, jucator)) {
                afiseazaTabla(tabla);
                cout << "Felicitări! Jucătorul " << jucator << " a câștigat!" << endl;
                break;
            }
           
           
            if (estePlina(tabla)) {
                afiseazaTabla(tabla);
                cout << "Este o remiză!" << endl;
                break;
            }
           
           
            jucator = (jucator == 'X') ? 'O' : 'X';
        } else {
            cout << "Mișcarea este invalidă. Încercați din nou." << endl;
        }
    }
}

void afiseazaTabla(char tabla[3][3]) {
   
    cout << "Tabla de joc:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tabla[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

bool verificaCastigator(char tabla[3][3], char jucator) {
   
    for (int i = 0; i < 3; i++) {
       
        if (tabla[i][0] == jucator && tabla[i][1] == jucator && tabla[i][2] == jucator) return true;
       
        if (tabla[0][i] == jucator && tabla[1][i] == jucator && tabla[2][i] == jucator) return true;
    }
   
    if (tabla[0][0] == jucator && tabla[1][1] == jucator && tabla[2][2] == jucator) return true;
    if (tabla[0][2] == jucator && tabla[1][1] == jucator && tabla[2][0] == jucator) return true;
   
    return false;
}

bool estePlina(char tabla[3][3]) {
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabla[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool esteValid(int linie, int coloana, char tabla[3][3]) {
   
    return (linie >= 0 && linie < 3 && coloana >= 0 && coloana < 3 && tabla[linie][coloana] == ' ');
}