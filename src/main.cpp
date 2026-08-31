/*
 * ============================================================
 *  main.cpp — Punto de entrada y orquestador
 * ============================================================
 * Fase 1 - Reto Entorno Aislado
 * ============================================================s
 */

#include <iostream>
#include <string>
#include <stdexcept> // Para capturar error
#include "Entorno.h"
#include "Diagnostico.h"

using namespace std;

// Imprimir lo que esta pasando
void ejecutarAccionRealSimulada() {
    cout << "\n >>> EJECUTANDO ACCION REAL SIMULADA <<< " << endl;
    cout << " Cifrando archivos simulados en Desktop..." << endl;
    cout << " Completado con exito." << endl;
}

int main() {
    cout << "=== Herramienta de Diagnostico de Entorno (PAC Fase 1) ===" << endl;
    cout << " Iniciando recoleccion de datos..." << endl;

  
    InfoEntorno infoResultados;

    // ------------------------------------------------------------
    // 1. Recoleccion de datos usando funciones de Entorno.cpp
    // ------------------------------------------------------------
    
    // Obtenemos nucleos
    infoResultados.CPU_nucleos = obtenerCantidadNucleos();
    
    // Obtenemos hostneme
    char* envHostname = getenv("COMPUTERNAME");
    infoResultados.hostname = (envHostname != nullptr) ? envHostname : "Desconocido";

    // Verificamos si el hostname es sospechoso 
    string detalleHostname = verificarHostname();

    // Verificamos ¿
    bool tieneArtefactosVM = buscarArtefactosSistema();

   
    cout << " Recoleccion completada." << endl;

   
    //  Lógica de Decisión (Control de flujo: IF)
    // Decidimos si el entorno es aislado basándonos en los datos
    
    // Usamos operadores logicos 
    if (infoResultados.CPU_nucleos <= 2 || tieneArtefactosVM || detalleHostname != "Limpio") {
        infoResultados.aislado = true;
        
        // Armamos el detalle para el log
        infoResultados.detalle = "Deteccion: ";
        if (infoResultados.CPU_nucleos <= 2) infoResultados.detalle += "[Bajos Nucleos] ";
        if (tieneArtefactosVM) infoResultados.detalle += "[Archivos VM] ";
        if (detalleHostname != "Limpio") infoResultados.detalle += "[" + detalleHostname + "] ";
    } else {
        infoResultados.aislado = false;
        infoResultados.detalle = "No se detectaron indicadores evidentes de virtualizacion.";
    }

    // Imprimimos resultado  en pantalla
    cout << " Resultado del diagnostico: " << (infoResultados.aislado ? "AISLADO" : "NATIVO") << endl;

    // ------------------------------------------------------------
    // 3. Manejo de archivos
    // ------------------------------------------------------------
    try {
        cout << " Intentando registrar resultado en el log..." << endl;
        // Llamamos a la funcion de diagnosticogo.cpp
        registrarResultado(infoResultados, "logs/diagnostico.log");
        // Si registrarResultado lanza una excepcion no se temrina de ejecurear 
    }
    //https://learn.microsoft.com/es-es/cpp/standard-library/runtime-error-class?view=msvc-170

    catch (const runtime_error& e) {
        // Capturamos el error relanzado 
        cerr << "\n[!] ERROR CRITICO DE DIAGNOSTICO [!]" << endl;
        cerr << "Detalle: " << e.what() << endl;
        cerr << "[!] El programa no puede garantizar el registro del log." << endl;
        cerr << "[!] Abortando ejecucion por seguridad." << endl;
        return 1; // Salimos con error
    }
    catch (const exception& e) {
        // Captura generica por seguridad https://www.geeksforgeeks.org/cpp/exceptionwhat-in-c-with-examples/
        cerr << " Error inesperado: " << e.what() << endl;
        return 1;
    }

    // 4 final 
    // ------------------------------------------------------------
    cout << "----------------------------------------------------" << endl;
    if (infoResultados.aislado) {
        cout << " Entorno AISLADO detectado." << endl;
        cout << " BLOQUEANDO la accion real para evitar analisis." << endl;
        cout << "=== Fin de la ejecucion (Protegido) ===" << endl;
    } else {
        cout << " Entorno NATIVO/SEGURO detectado." << endl;
        cout << " Procediendo con la operacion normal." << endl;
        
        
        
        cout << "=== Fin de la ejecucion ===" << endl;
    }

    return 0;
}
