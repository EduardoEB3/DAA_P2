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

#ifndef __Cinta__
#define __Cinta__

#include <iostream>
#include <vector>

using namespace std;

class Cinta {
 public:
  Cinta();
  Cinta(char*);
  virtual ~Cinta() = default;

  void set_nombre_fichero(char*);
  void set_cabezal(unsigned long);
  void set_cinta(vector<int>);
  void set_valor(int);

  char* get_nombre_fichero();
  unsigned long get_cabezal();
  vector<int> get_cinta();
  int get_valor();

  // void ReadFile();
  void IncremetarCabezal();
  virtual void WriteTapeScreen() = 0;

 private:
  /// Atributo que contiene el nombre del fichero de lectura
  char* nombre_fichero_;
  /// Atributo que contiene el cabezal de la cinta
  unsigned long cabezal_;
  /// Atributo que almacena los valores de la cinta de entrada
  vector<int> cinta_;
};

#endif