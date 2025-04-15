#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#include "src/Utils.hpp"

using namespace std;

int main() 
{   
    string inputFileName = "data.txt";
    double S = 0; 
    size_t n = 0; 
    double* w = nullptr; //inizializzazione puntatore per w
    double* r = nullptr; //inizializzazione puntatore per r

    //leggo i dati dal file in input
    if (!ReadData(inputFileName, S, n, w, r)) 
    {
        cerr << "Errore nella lettura del file data.txt";
        return 1;
    }
    else
        cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
        cout << "w = " << ArrayToString(n, w) << endl;
        cout << "r = " << ArrayToString(n, r) << endl;

    //calcolo il tasso di rendimento
    double RateOfReturn = ComputeRateOfReturn(n, w, r);
    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << RateOfReturn << endl;

    //calcolo il valore finale nel portafoglio
    double V = 0;
    V = S * (1 + RateOfReturn);
    cout << "V: " << fixed << setprecision(2) << V << endl;

    //scrivo i risultati nel file di output
    if (!WriteResults("result.txt", S, n, w, r, RateOfReturn, V)) 
    {
        cerr << "Errore nella scrittura dei risultati nel file";
        return 1;
    }

    delete[] w;
    delete[] r;

    return 0;
}

