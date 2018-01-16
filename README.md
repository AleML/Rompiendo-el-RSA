#FUENTE PARA PROBLEMA DE PROGRAMACI�N.

�NO! NO ES UN VERDADERO ALGORITMO PARA VULNERAR LA ENCRIPTACI�N RSA
ESA COSA ES MUY SEGURA.

El nombre del problema es "Rompiendo el RSA".

El objetivo de este es puramente did�ctico. Consiste en intentar
vulnerar el algoritmo RSA (cuando los valores de los n�meros secretos
'p' y 'q' son peque�os) para comprender el funcionamiento de este algoritmo.

El c�digo aqu� alojado no est� optimizado para manejar n�meros
mayores a 64 bits.

El paradigma usado es: programaci�n estructurada.

#Directorio ./management:

En este directorio est� un manejador para generar casos de prueba,
generar llaves, encriptar, desencriptar, etc., con el fin de facilitar
la comprovaci�n de los resultados de la soluci�n ideada.

#Directorio ./solution:

Aqu� se encuentra una propuesta de soluci�n. Todo lo necesario est� en un
mismo archivo.

#Directorio ./libs:

Est� la librer�a usada para el manejador. En concreto es s�lo la interfaz

#Directorio ./src:

Est� la implementaci�n de la librer�a.
