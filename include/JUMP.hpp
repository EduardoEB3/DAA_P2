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

#ifndef __JUMP__
#define __JUMP__

#include <iostream>
#include <vector>

#include "Instruccion.hpp"
#include "RAM.hpp"

using namespace std;

class JUMP : public Instruccion {
 public:
  JUMP();
  JUMP(string, string, int, int, RAM&);
  ~JUMP();
  void ejecutar_instruccion(int, int);

 private:
  RAM* ram_;
};

#endif