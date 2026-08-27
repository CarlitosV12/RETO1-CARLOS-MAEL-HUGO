/*
 * ============================================================
 *  Entorno.h — Declaraciones del módulo de detección de entorno
 * ============================================================
 * Este archivo declara las funciones que investigan si el
 * programa se está ejecutando dentro de un entorno aislado.
 *
 * Recuerden: aquí SOLO van declaraciones (el "qué"), no
 * definiciones (el "cómo"). El "cómo" va en Entorno.cpp.
 * ============================================================
 */

#ifndef ENTORNO_H
#define ENTORNO_H

#include <string>
using namespace std;

// TODO: declaren aquí las funciones que van a usar para
// investigar el entorno. Un punto de partida sugerido:
//
// bool estaEnEntornoAislado();
//   -> Devuelve true si el programa detecta que corre dentro
//      de su entorno aislado, false si no.
//
// string obtenerDatoDeRed();
// string obtenerDatoDeSistema();
//   -> Cada una investiga y devuelve UN dato específico del
//      entorno (adaptador de red, hostname, recursos de
//      hardware, procesos típicos de virtualización, etc.)
//      El diseño exacto queda a su criterio de equipo.

bool estaEnEntornoAislado();

#endif
