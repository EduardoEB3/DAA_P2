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

#ifndef __CintaSalida__
#define __CintaSalida__

#include <iostream>
#include <vector>

#include "Cinta.hpp"

using namespace std;

class CintaSalida : public Cinta {
 public:
  CintaSalida();
  CintaSalida(char*);
  ~CintaSalida();

  void WriteFile();
  void WriteTapeScreen();
};

#endif