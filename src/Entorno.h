/*
 * ============================================================
 *  Entorno.h — Declaraciones del módulo de detección de entorno
 * ============================================================
 */

#ifndef ENTORNO_H
#define ENTORNO_H

#include <string>

// Verificar la cantidad de nuecles del procesador
int obtenerCantidadNucleos();

// Verificar rutas comunes de máquinas virtuales en el sistema de archivos
bool buscarArtefactosSistema();

// Verificar si el hostname de la máquina coincide con nombres tipicos
std::string verificarHostname();

// Función principal
bool estaEnEntornoAislado();

#endif 
