/*
 * ============================================================
 *  Diagnostico.cpp — Definiciones: procesamiento y registro
 * ============================================================
 */

#include "Diagnostico.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

// TODO: implementen el registro en archivo, con manejo de
// excepciones. Aquí tienen un esqueleto de partida:

void registrarResultado(const InfoEntorno& info, const string& rutaLog) {
    try {
        ofstream log(rutaLog, ios::out | ios::app);

        // Si el archivo no se pudo abrir, lanzamos una excepción
        // en vez de dejar que el programa falle en silencio.
        if (!log.is_open()) {
            throw runtime_error("No se pudo crear o abrir el archivo de log: " + rutaLog);
        }

        // TODO: escriban aquí el resultado del diagnóstico en el
        // formato que decidan (incluyan al menos: si se detectó
        // aislamiento o no, y el detalle de qué se evaluó).
        log << "=== Resultado del diagnostico ===" << endl;
        log << "Hostname: " << info.hostname << endl; 
        log << "CPU nucleos: " << info.CPU_nucleos << endl;
        log << "RAM disponible: " << info.RAM_disponible << " GB" << endl;
        log << "Adaptador de red virtual: " << (info.adaptadorRedVirtual ? "si" : "no") << endl;
        log << "Aislado: " << (info.aislado ? "si" : "no") << endl;
        log << "Detalle: " << info.detalle << endl;

        log.close();
        cout << "Resultado registrado en: " << rutaLog << endl;

    } catch (const exception& e) {
        cout << "Error al registrar el resultado: " << e.what() << endl;
        // TODO: decidan si además de avisar en pantalla quieren
        // relanzar la excepción (throw;) para que main() la maneje.
        throw; // relanzamos la excepción para que main() la maneje dandole el control de decidir si se
        // quiere continuar o abortar la ejecución del programa.
    }
}
