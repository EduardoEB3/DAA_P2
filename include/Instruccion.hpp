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

#ifndef __INSTRUCCION__
#define __INSTRUCCION__

#include <iostream>

#define INMEDIATO 1
#define DIRECTO 2
#define INDIRECTO 3

#define PUNTOS ':'
#define PUNTO_COMA ';'
#define HASHTAG '#'

using namespace std;

class Instruccion {
 public:
  Instruccion();
  Instruccion(string, string, int, int);
  virtual ~Instruccion() = default;

  void set_nombre_instruccion(string);
  void set_operando(string);
  void set_pos(int);

  string get_nombre_instruccion();
  string get_operando();
  int get_tipo_direccionamiento();
  int get_pos();

  void InformacionInstruccion();
  string tipo_direccionamiento_formateado();
  virtual void ejecutar_instruccion(int, int) = 0;

 private:
  /// Atributo que almacena el nombre de la instrucción
  string nombre_instruccion_;
  /// Atributo que almacena el operando o etiqueta de la instrucción
  string operando_;
  /// Atributo que almacena la posición de la instrucción
  int pos_;
  /// Atributo que almacena el tipo de direccionamiento
  int tipo_direccionamiento_;
};

#endif