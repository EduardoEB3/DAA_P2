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

#ifndef __READ__
#define __READ__

#include <iostream>
#include <vector>

#include "Instruccion.hpp"
#include "RAM.hpp"

using namespace std;

class READ : public Instruccion {
 public:
  READ();
  READ(string, string, int, int, RAM&);
  ~READ();
  void ejecutar_instruccion(int, int);

 private:
  RAM* ram_;
};

#endif