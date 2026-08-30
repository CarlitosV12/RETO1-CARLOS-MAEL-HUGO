/*
 * ============================================================
 *  Entorno.h — Declaraciones del módulo de detección de entorno
 * ============================================================
 */

#ifndef ENTORNO_H
#define ENTORNO_H

#include <string>

// 1. Verificar la cantidad de nuecles del procesador
int obtenerCantidadNucleos();

// 2. Verificar rutas comunes de máquinas virtuales en el sistema de archivos
bool buscarArtefactosSistema();

// 3. Verificar si el hostname de la máquina coincide con nombres tipicos
std::string verificarHostname();

// Función principal
bool estaEnEntornoAislado();

#endif 
