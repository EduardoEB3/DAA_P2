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

#ifndef __PROGRAMA__
#define __PROGRAMA__

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#define HALTS "HALT"
#define LOADS "LOAD"
#define ADDS "ADD"
#define DIVS "DIV"
#define JGTZS "JGTZ"
#define JUMPS "JUMP"
#define JZEROS "JZERO"
#define MULTS "MULT"
#define READS "READ"
#define STORES "STORE"
#define SUBS "SUB"
#define WRITES "WRITE"

#define ASTERISCO '*'
#define IGUAL '='
#define ESPACIO ' '

#include "Instruccion.hpp"

class RAM;

using namespace std;

class Programa {
 public:
  Programa();
  Programa(string, RAM&);
  ~Programa();

  vector<Instruccion*> get_programa_real();
  Instruccion* get_instruccion(int);
  map<string, int> get_etiquetas();

  vector<string> ReadFile(string);
  void CrearPrograma(vector<string>, RAM&);
  string PasarMayusculas(string);
  void WritePrograma();

 private:
  /// Atributo que almacena un vector de instrucciones
  vector<Instruccion*> programa_real_;
  /// Atributo que almacena el conjunto de etiquetas que contienen su nombre y
  /// la línea
  map<string, int> etiquetas_;
};

#endif