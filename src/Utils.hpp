#pragma once
#include <string>

using namespace std;

// ReadData legge i dati dal file in input
// filename: nome del file in input
// S: importo iniziale di denaro
// n: numero di asset nel portafoglio
// w: pesi delle attività nel portafoglio
// r: rendimento delle attvità nel portafoglio
// restituisce il risultato di lettura (vero è successo, falso è errore)
bool ReadData(const string& filename, 
                double& S, 
                size_t& n, 
                double*& w,
                double*& r);


// ArrayToString esporta un vettore all'interno di una stringa
// n: dimensione del vettore
// v: vettore
// restituisce la stringa risultante
string ArrayToString(const size_t& n,
                        const double* const& v);  


// ComputeRateOfReturn calcola il tasso di rendimento
// n: numero di asset nel portafoglio
// w: pesi delle attività nel portafoglio
// r: rendimento delle attvità nel portafoglio
// restituisce il valore del tasso di rendimento
double ComputeRateOfReturn(const size_t& n, 
                            const double* const& w,
                            const double* const& r);


// WriteResults scrive i risultati nel file di output
// filename: nome del file in output
// S: importo iniziale di denaro
// n: numero di asset nel portafoglio
// w: pesi delle attività nel portafoglio
// r: rendimento delle attvità nel portafoglio
// rate: tasso di rendimento
// V: importo finale di denaro
// restituisce il risultato di scrittura (vero è successo, falso è errore)
bool WriteResults(const string& filename, 
                    const double& S, 
                    const size_t& n, 
                    const double* const& w,
                    const double* const& r,
                    const double& rate, 
                    const double& V);



