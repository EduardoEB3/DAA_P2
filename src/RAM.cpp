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

#include "../include/RAM.hpp"

#include <sstream>

using namespace std;

/// Constructor por defecto
RAM::RAM() {
  contador_programa_ = 0;
  numero_instruciones_ = 0;
}

/// Sobrecarga del constructor
RAM::RAM(string nombre_fichero, CintaEntrada& cinta_entrada,
         CintaSalida& cinta_salida)
    : programa_(nombre_fichero, *this) {
  cinta_entrada_ = cinta_entrada;
  cinta_salida_ = cinta_salida;
  contador_programa_ = 0;
  numero_instruciones_ = 0;
}

/// Destructor
RAM::~RAM() {}

void RAM::set_contador(int num_linea) { contador_programa_ = num_linea; }

unsigned long RAM::get_contador() { return contador_programa_; }

int RAM::get_numero_instrucciones() { return numero_instruciones_; }

Programa& RAM::get_programa() { return programa_; }

Memoria& RAM::get_memoria() { return memoria_; }

CintaSalida& RAM::get_cintasalida() { return cinta_salida_; }

CintaEntrada& RAM::get_cintaentrada() { return cinta_entrada_; }

void RAM::ejecutar_RAM(int debug) {
  while (contador_programa_ < programa_.get_programa_real().size()) {
    numero_instruciones_++;
    if (programa_.get_instruccion(contador_programa_) == 0) {
      contador_programa_++;
    }
    stringstream valor(
        programa_.get_instruccion(contador_programa_)->get_operando());
    int operando_numero = 0;
    valor >> operando_numero;

    try {
      programa_.get_instruccion(contador_programa_)
          ->ejecutar_instruccion(debug, operando_numero);
    } catch (string& error) {
      contador_programa_ = programa_.get_programa_real().size() - 1;
      throw;
    }

    if (debug == 1) {
      if (programa_.get_instruccion(contador_programa_)
              ->get_nombre_instruccion() == HALTS) {
        contador_programa_ = 0;
      }
      return;
    }
  }
}

void RAM::IncrementarContador() { contador_programa_++; }