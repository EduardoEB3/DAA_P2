/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Eduardo Expósito Barrera
 * @date 26 Feb 2021
 * @brief P2
 * @email: alu0101230382@ull.edu.es
 *
 * @see https://es.qaz.wiki/wiki/Random-access_machine
 *
 */

#ifndef __RAM__
#define __RAM__

#include <iostream>

#include "CintaEntrada.hpp"
#include "CintaSalida.hpp"
#include "Memoria.hpp"
#include "Programa.hpp"

using namespace std;

class RAM {
 public:
  RAM();
  RAM(string, CintaEntrada &, CintaSalida &);
  ~RAM();

  void set_contador(int);

  unsigned long get_contador();
  int get_numero_instrucciones();
  Programa &get_programa();
  Memoria &get_memoria();
  CintaSalida &get_cintasalida();
  CintaEntrada &get_cintaentrada();

  void ejecutar_RAM(int);
  void IncrementarContador();

 private:
  /// Atributo que almacena el programa
  Programa programa_;
  /// Atributo que almacena la memoria
  Memoria memoria_;
  /// Atributo que almacena la cinta de entrada
  CintaEntrada cinta_entrada_;
  /// Atributo que almacena la cinta de salida
  CintaSalida cinta_salida_;
  /// Atributo que almacena el contador del programa
  unsigned long contador_programa_;
  /// Atributo que almacena el númeor de instrucciones ejecutadas
  int numero_instruciones_;
};

#endif