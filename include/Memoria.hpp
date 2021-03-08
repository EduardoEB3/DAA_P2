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

#ifndef __MEMORIA__
#define __MEMORIA__

#include <iostream>
#include <vector>

using namespace std;

class Memoria {
 public:
  Memoria();
  ~Memoria();

  void set_acumulador(int);
  void set_registro(int);
  void set_registro_valor(int, int);
  void set_memoria(int);

  int get_acumulador();
  int get_registro(int);
  vector<int> get_memoria();

  void WriteMemoria();

 private:
  vector<int> registros_;
};

#endif