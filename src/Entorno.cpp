/*
 * ============================================================
 *  Entorno.cpp — Definiciones del módulo de detección de entorno
 * ============================================================
 */

#include "Entorno.h"
#include <iostream>
#include <thread> //Libreria para la funcion de nucleos
#include <fstream>

using namespace std;

// 1. Verificar la cantidad de núcleos del procesador
int obtenerCantidadNucleos() {
    // hardware_concurrency() devuelve el número de núcleos lógicos.
    // En las máquinas virtuales de laboratorio suelen estar limitados a 1 o 2.
    unsigned int nucleos = thread::hardware_concurrency();
    return nucleos; 

    //https://stackoverflow.com/questions/150355/programmatically-find-the-number-of-cores-on-a-machine
    
}


// 2. Verificar rutas comunes en el sistema de archivos

bool buscarArtefactosSistema() {
    // Buscamos rutas comunes instalados en Windows
    string rutasVirtualizacion[] = {
        "C:\\Windows\\System32\\drivers\\VBoxMouse.sys", //Virtual Box 
        "C:\\Windows\\System32\\drivers\\vboxguest.sys", //Virtual Box
        "C:\\Windows\\System32\\drivers\\vmhgfs.sys" //VM
    };
    

    // Usamos un ciclo for que leea las 3 rutas , en caso de que se abra el archivo significa que el archivo se encontre
    for (int i = 0; i < 3; i++) {
        ifstream archivo(rutasVirtualizacion[i]);
        if (archivo.is_open()) {
            return true; // Si logra abrir el archivo es porque existie 
        }
    }
    return false; // Si no se encontro el archivo es porque no existen 

    //Uso de IA para paras rutas exactas en sien si 
}

// 3. Sacar Hostname 
string verificarHostname() {

    // Obtenemos el nombre del equipo de las variables de entorno 
    // https://www.ibm.com/docs/es/i/7.5.0?topic=functions-getenv-search-environment-variables}

    char* ptrNombreEquipo = getenv("COMPUTERNAME");
    

    // Usamo snew para crear un arreglo dinámico
    int numNombres = 6;
    string* hostnamesSospechosos = new string[numNombres];
    
    // Nombres tipicos que se asignan en laboratorios
    hostnamesSospechosos[0] = "SANDBOX";
    hostnamesSospechosos[1] = "VIRUS";
    hostnamesSospechosos[2] = "MALWARE";
    hostnamesSospechosos[3] = "VIRTUAL"; 
    hostnamesSospechosos[4] = "VM";
    hostnamesSospechosos[5] = "BOX"; 
    
    string resultado = "Limpio";
    
    // Contador 
    int w = 0;
    
    // Uso de bucle while
    while (w < numNombres) {
        // Usamos .find() para ver si el hostname actual contiene alguna de las palabras clave
        //https://www.geeksforgeeks.org/cpp/std-find-in-cpp/

        if (hostnameActual.find(hostnamesSospechosos[w]) != string::npos) {
            resultado = "Hostname detectado (" + hostnamesSospechosos[w] + ")";
            break; // Rompemos el while si encontramos una coincidencia
        }
        w++;
    }

    // Uso de delete[] para liberar la memoria del puntero
    delete[] hostnamesSospechosos; 
    
    return resultado;
}

// Función 
bool estaEnEntornoAislado() {
    bool aislado = false;
    
    int nucleos = obtenerCantidadNucleos();
    bool tieneArchivosVM = buscarArtefactosSistema();
    string indicadorHostname = verificarHostname(); 
    

    // Si tiene 2 núcleos o menos, O tiene archivos, O el hostname es sospechoso
    //Se deben cumplir al menos una condicion 
    if (nucleos <= 2 || tieneArchivosVM || indicadorHostname != "Limpio") {
        aislado = true;
    }
    
    return aislado;
}
