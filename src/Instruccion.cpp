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

#include "../include/Instruccion.hpp"

using namespace std;

/// Constructor por defecto
Instruccion::Instruccion() { pos_ = 0; }

/// Sobrecarga del constructor
Instruccion::Instruccion(string nombre_instruccion, string operando, int pos,
                         int tipo_direccionamiento) {
  nombre_instruccion_ = nombre_instruccion;
  pos_ = pos;
  operando_ = operando;
  tipo_direccionamiento_ = tipo_direccionamiento;
}

void Instruccion::set_nombre_instruccion(string nombre_instruccion) {
  nombre_instruccion_ = nombre_instruccion;
}

void Instruccion::set_operando(string operando) { operando_ = operando; }

void Instruccion::set_pos(int pos) { pos_ = pos; }

string Instruccion::get_nombre_instruccion() { return nombre_instruccion_; }

string Instruccion::get_operando() { return operando_; }

int Instruccion::get_tipo_direccionamiento() { return tipo_direccionamiento_; }

int Instruccion::get_pos() { return pos_; }

void Instruccion::InformacionInstruccion() {
  cout << "Nombre instrucción: " << nombre_instruccion_ << endl;
  cout << "Operando: " << operando_ << endl;
  cout << "Posición: " << pos_ << endl;
  cout << "Tipo de direccionamiento: " << tipo_direccionamiento_ << endl;
}

string Instruccion::tipo_direccionamiento_formateado() {
  string direccionamiento;
  if (tipo_direccionamiento_ == DIRECTO) {
    direccionamiento = "El direccionamiento de la instrucción " +
                       nombre_instruccion_ +
                       " es directo y tiene como operando " + operando_;
  } else if (tipo_direccionamiento_ == INDIRECTO) {
    direccionamiento = "El direccionamiento de la instrucción " +
                       nombre_instruccion_ +
                       " es indirecto y tiene como operando " + operando_;
  } else {
    direccionamiento = "El direccionamiento de la instrucción " +
                       nombre_instruccion_ +
                       " es inmediato y tiene como operando " + operando_;
  }
  return direccionamiento;
}
