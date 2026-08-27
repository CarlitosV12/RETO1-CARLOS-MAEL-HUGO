/*
 * ============================================================
 *  main.cpp — Punto de entrada
 * ============================================================
 * Este archivo debe quedar corto: solo orquesta las llamadas
 * a las funciones definidas en los otros módulos. La lógica
 * real vive en Entorno.cpp y Diagnostico.cpp.
 * ============================================================
 */

#include <iostream>
#include "Entorno.h"
#include "Diagnostico.h"
using namespace std;

int main() {

    cout << "=== Herramienta de diagnostico de entorno ===" << endl;

    // TODO: llamen a su(s) función(es) de detección de Entorno.h
    bool aislado = estaEnEntornoAislado();

    // TODO: arma la estructura con los datos recolectados
    InfoEntorno resultado;
    resultado.aislado = aislado;
    resultado.detalle = "TODO: describir que se detecto";

    if (aislado) {
        cout << "Entorno aislado detectado. No se ejecuta la accion real." << endl;
        // TODO: aqui pueden usar excepciones para bloquear la
        // accion "real" del programa, tal como se definio en
        // las instrucciones del reto.
    } else {
        cout << "No se detecto aislamiento. Ejecutando accion..." << endl;
        // TODO: la accion que su equipo decidio simular
    }

    // Registro del resultado en archivo (carpeta logs/)
    registrarResultado(resultado, "logs/diagnostico.log");

    return 0;
}
