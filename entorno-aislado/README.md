## Nuestro entorno aislado
## Herramienta elegida

**Herramienta:** VMware Workstation Pro

**Por qué la elegimos:** Se eligio esa herramienta, debido a su excelente redimiento y estabildiad al virtualziar sistemas Windows 10, la facilidad para poder gestionar la configuracion para lograr elaborar el reto. Y la otra sencilla razon, es porque es la que uso normalmente para el trabajo en el que se implique el uso de maquinas virtuales.

## Requisitos para replicar nuestro entorno

- Sistema operativo host usado: Windows 11
- Versión de la herramienta: VMware® Workstation Pro 25H2u1 v25.0.1.25219725
**Para poder observar de mejor manera la version usamos el comando : "C:\Program Files (x86)\VMware\VMware Workstation\vmware.exe" -v**
- Sistema operativo invitado (guest): Windows 10 Pro (64-bit)
- Recursos asignados a la VM: 4GB RAM, 2 núcleos de CPU, 60GB de disco dinámico

## Pasos para armar el entorno
1. Primero descargamos e instalamos la herramienta VMware Workstation Pro, en nuestro sistema operativo (en nuestro caso Windows 11) desde su web oficial ejecutando el instalador con permisos de administrador.
**Web para descargar WMware: https://www.vmware.com/products/desktop-hypervisor/workstation-and-fusion**
2. Después descargamos la imagen ISO de Windows 10 dede la pagina de Microsoft utilizando la herramienta de creacion de medios (Media Creation Tools), guardando el archivo como Windows10.iso
**Web para descargar la imagen ISO de Windows: https://www.microsoft.com/es-es/software-download/windows10**
3. Despues de tener los recursos y elementos que se necesitan, abrimos VMware y en la parte superior seleccionar la opcion de File > New Virtual Machine, para iniciar el asistente de crearcion de maquinas virtuales.
4. Se abrira una pestaña que nos pregunta el tipo de configuracion, nosotros seleccionaremos Typical(recommended) y hacer click en Next.
5. Elegir la opcion de Installer disc image file (iso), hacer click en Browse..., y seleccionamos el archivo antes descargado de la imagen iso de Windows 10, y le damos en Next.
6. Luego nos preguntara si le queremos asignar un nombre a nuestra maquina, en nuestro caso para que tenga asimilacion con la tarea elegios el nombre VM-Reto1, y definimos donde queremos que se guarde nuestra maquina.
7. Despues nos preguntara el tipo de especificacion de la memoria que le queremos asignar de forma dinamica, en nuestro caso para que sea estable sin exigirle mucho a nuestro equipo fisico decidimos que fuera de 60GB y seleccionamos la opcion de Store Virtual disk as a single file.
8. En seguida, selecionamos la opcion de Customize Hardware... para ajustar las especificaciones (esto esta ligado al comentario anterior, donde debemos ajusatrlas sin exigir mucho al equipo fisico):
    - En la pestaña Memory, asignaremos 4GB de RAM (4096MB)
    - En la pestaña Processors, asignar 2 nucleos de procesador (CPU Cores)
9. En la misma pestaña del Hardware, seleccionar el dispisitivo Network Adapter y cambiar la configuracion de conexion de NAT a Host-Only: A private network shared with the host para aislar el entorno.
10. Despues de customizar nuesta maquina virtual para poder ejecutar el Reto, hacemos click en Close y luego en Finish.
11. Encendemos la VM haciendo click en Power on this virtual machine.
12. En ocasiones debido al tiempo de arranque, nuestra maquina quedara en negro, ya que se intento inicar por red sin encontrar sistema, lo que desplego un cuadro azul titulado Boot Manager. Dentro de este menu, nos moveremos hasta la casilla EFI VMware Virtual SATA CDROM Drive (1.0) presionando la tecla Enter.
13. Despues nos aparecera otro menu que nos da a escoger la edicion con la qeu queremos descargar el Windows 10, en nuestro caso escogimos la edicion Windows 10 Pro y hacemos click en Siguiente.
14. Aceptamos los terminos de licencia y selecionamos el tipo de instalacion Personalizada: instalar solo Windows (avanzado).
15. Seleccionamos la opcion de espacio sin asignar de 60GB (Esapcio sin asignar en el disco 0), hacer click en siguiente para iniciar la instalacion.
16. Y ya para finalizar, creamos una cuenta de usuario local sin vincular a una cuenta de Microsoft (ya que nuestra vm no tiene conexion a internet) 

## Configuración de red aislada

**Tipo de red usada:** Host-only

**Cómo la configuramos:** En los ajustes del hardware de la VM dentro de VMware (Virtual Machine Settings > Network Adapter), cambiamos la interfaz de red de NAT a la opcion de Host-Only: A private network shared with the host

**Cómo verificamos que el aislamiento funciona:**  Abrimos PowerShell dentro de la VM y ejecutamos el comando ping 8.8.8.8. Y como es de esperarse el programa nos lanzo el comentario de "Error en la transmision", confirmando que nuestra maquina no tiene salida a internet

## Snapshot

**Nombre del snapshot base:** 2026-08-29_entorno-limpio-windows

**Qué contiene:** Instalación limpia y funcional de Windows 10 Pro en VMware Workstation Pro. Cuenta con el adaptador de red configurado en modo Host-Only, sin salida a Internet y listo para la ejecución de pruebas de diagnóstico y desarrollo en C++.

## Evidencia
### 1. Administrador de Snapshot en VMware
Se tomo una captura de pantalla del estado base funcional del sistema operativo antes de instalar las herramientas para el diagnostico.
![Snapshot VMware](docs/snapshot_evidencia.png)

### 2. Prueba de Aislamiento de Red
Desde la consola de Powershell se ejecuto la prueba de conectividad hacia un servidor DNS publico "ping 8.8.8.8" . El resultado fallo, probando que no hay conectividad.
![Aislamiento](docs/ping_aislamiento.png)

