/*
 * ============================================================
 *  Diagnostico.h — struct de resultados + procesamiento y registro
 * ============================================================
 * Este archivo agrupa:
 *   1) La estructura que guarda los datos recolectados del
 *      entorno (requisito: uso de struct).
 *   2) Las funciones que procesan esos datos y generan el
 *      archivo de registro (requisito: manejo de archivos +
 *      excepciones + al menos un puntero o referencia).
 * ============================================================
 */

#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include <string>
using namespace std;

// TODO: completen esta estructura con los datos que su equipo
// decida recolectar del entorno. Ejemplo de punto de partida:
struct InfoEntorno {
    bool aislado;
    string detalle;       // qué se detectó y por qué
    // agreguen aquí los campos que necesiten
};

// TODO: declaren aquí sus funciones de procesamiento y registro.
// Sugerencia (usen puntero o referencia para pasar InfoEntorno,
// no la copien completa):
//
// void registrarResultado(const InfoEntorno& info, const string& rutaLog);
//   -> Escribe el resultado en el archivo de log (carpeta /logs).
//      Debe usar try/catch para manejar el caso de que el
//      archivo no se pueda crear o abrir.

void registrarResultado(const InfoEntorno& info, const string& rutaLog);

#endif
