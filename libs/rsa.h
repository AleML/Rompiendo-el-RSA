/**
 * Funciones necesarias para el uso del algoritmo RSA.
 * Estas funciones son con motivos didacticos y no
 * est�n contempladas para el uso real en producci�n
 * debido a que el tama�o de los n�meros que son
 * capaces de manejar no son lo sufucuentemente grandes
 * para hacer efectivo este algoritmo.
 *
 * Para m�s informaci�n, mirar: https://www.youtube.com/watch?v=CMe0COxZxb0
 */
#ifndef _RSA_H_
#define _RSA_H_

#include <cmath>
#include <vector>
#include <time.h>
#include <cstdlib>

/**
 * @description Estructura que contiene los datos de
 * un par de llaves RSA, as� como las mismas llaves.
 */
struct KeyPair {
    KeyPair(){}
    KeyPair(
        long long priv,
        long long pub,
        long long n,
        long long phi_n,
        long long _p,
        long long _q):
            private_key(priv),
            public_key(pub),
            mod(n),
            phi_mod(phi_n),
            p(_p),
            q(_q){}

    long long private_key;
    long long public_key;
    long long mod;
    long long phi_mod;
    long long p;
    long long q;
};

///Variables compartidas por funciones.
std::vector<long long>  prime_numbers(1, 2);///Contenedor para los numeros primos.
                  long  prime_it;///Iterador para los n�meros primos.

/**
 * @description Genera el par de llaves RSA y sus datos
 * asociados.
 *
 * @param int
 *   Cantidad de n�meros primos entre los cuales escoger
 *   Para las operaciones.
 * @return KeyPair
 */
KeyPair generate_rsa_key_pair(int);

/**
 * @description Convierte un n�mero entero positivo de notaci�n decimal
 * a su correspondiente notaci�n binaria. Si estas condiciones no se
 * cumplen. el resultado podr�a estar errado.
 *
 * @return std::vector<int>
 */
std::vector<int> parse_binary(long long);

/**
 * @description S�lo imprime el n�mero en binario que se le pase.
 *
 * @param std::vector<int>
 *   El n�mero.
 */
void print_binary(std::vector<int>);

/**
 * @description Calcula el inverso multiplicativo modular de un n�mero
 * dentro de otro mayor a �l usando el algoritmo extendido de euclides.
 *
 * Para entender mejor esta funci�n, mirar: https://www.youtube.com/watch?v=JGyFkl5_KHM
 *
 * @param long long.
 *   El n�mero dentro del cuerpo.
 * @param long long.
 *   El cuerpo en el que se buscar� el inverso.
 * @return long long.
 */
long long inv(long long, long long);

/**
 * @description Elige una posici�n aleatoria igual o mayor
 * a la cantidad de n�mero primos que existan en el contenedor
 * de n�meros primos (prime_numbers).
 *
 * @return int
 */
int generate_position(void);

/**
 * @description Ejecuta una potenciaci�n m�dulo de un n�mero. Usada
 * para el cifrado, descifrado o fimado con RSA.
 *
 * Para m�s informaci�n, mirar: https://www.youtube.com/watch?v=C2-kLqWfBaE
 *
 * @param long long
 * N�mero base.
 * @param std::vector<int>
 * Exponente en binario.
 * @param long long
 * m�dulo.
 * @return long long
 */
long long exec_pow(long long, std::vector<int>, long long);

/**
 * @description Genera la cantidad de primos que se le indiquen.
 *
 * @param int
 *   La cantidad de primos a generar.
 */
void generate_prime_numbers(int);

/**
 * @description Pasa al siguiente primo wn funci�n del iterador.
 * Si no hay m�s primos, calcula el que sigue y lo retorna.
 *
 * @return long long
 */
long long next_prime(void);

/**
 * @description Calcula los factores primos de un n�mero
 * que es producto de dos n�meros primos. Si el arumento no
 * cumple con esta condici�n, el resultado ser� errado.
 *
 * @param long long
 *   El n�mero a factorizar.
 * @return std::vector<long long>
 */
std::vector<long long> factors_of(long long);

/**
 * @description Encripta un mensaje de texto,
 *
 * @param long long
 *   La llave p�blica.
 * @param long long
 *   El modulo de cifra.
 * @param string
 *   El mensaje.
 * @return std::vector<long long>
 */
std::vector<long long> encript(long long, long long, std::string);

/**
 * @description Desencripta un mensaje de texto, recibiendo el
 * criptograma.
 *
 * @param long long
 *   La llave privada.
 * @param long long
 *   El m�dulo de crifra.
 * @param std::vector<long long>
 *   El criptograma.
 * @return std::string
 */
std::string decript(long long, long long, std::vector<long long>);

#include "../src/rsa.cpp"

#endif // _RSA_H_
