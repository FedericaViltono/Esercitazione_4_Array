#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "Utils.hpp"

using namespace std;

bool ReadData(const string& filename, 
                double& S, 
                size_t& n, 
                double*& w,
                double*& r)
{   
    //apro il file
    ifstream file;
    file.open(filename);

    if (file.fail()) 
    {
        cerr << "Errore nell'apertura del file input " << filename << endl;
        return false;
    }

    string line; //lettura riga per riga del file

    //leggo S
    getline(file, line);
    istringstream convertS(line); 
    string temp; //variabile temporanea che serve per memorizzare la parte prima del ;
    getline(convertS, temp, ';'); //memorizza la parte di convertS prima di ; in temp (; viene ignorato)
    convertS >> S; //assegna a S il valore numerico 

    //leggo n
    getline(file, line);
    istringstream convertN(line); 
    string temp2; //variabile temporanea che serve per memorizzare la parte prima del ;
    getline(convertN, temp2, ';'); //memorizza la parte di convertN prima di ; in temp (; viene ignorato)
    convertN >> n; //assegna a N il valore numerico

    //leggo w e r
    w = new double[n];
    r = new double[n];

    getline(file, line); //legge la riga w;r
    
    for (unsigned int i = 0; i < n; i++) 
    {
        getline(file, line);
        istringstream convertWR(line);
        convertWR >> w[i]; //estrae il primo valore di convertWR
        convertWR.ignore(); //ignora il punto e virgola
        convertWR >> r[i]; //estrae il secondo valore di convertWR
    }

    //chiudo il file
    file.close();
    return true;
}


string ArrayToString(const size_t& n, 
                        const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}


double ComputeRateOfReturn(const size_t& n, 
                            const double* const& w,
                            const double* const& r) 
{
    double rate = 0.0;
    for (unsigned int i = 0; i < n; ++i) 
        rate += w[i] * r[i];

    return rate;
}


bool WriteResults(const string& filename, 
                    const double& S, 
                    const size_t& n, 
                    const double* const& w,
                    const double* const& r,
                    const double& rate, 
                    const double& V)
{   
    //apro il file
    ofstream file;
    file.open(filename);

    if (file.fail()) 
    {   
        cerr << "Errore nell'apertura del file output" << filename << endl;
        return false;
    }

    //stampo i risultati nel formato corretto
    file << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    file << "w = " << ArrayToString(n, w) << endl;
    file << "r = " << ArrayToString(n, r) << endl;
    file << "Rate of return of the portfolio: " << fixed << setprecision(4) << rate << endl;
    file << "V: " << fixed << setprecision(2) << V << endl;

    //chiudo il file
    file.close();
    return true;
}





