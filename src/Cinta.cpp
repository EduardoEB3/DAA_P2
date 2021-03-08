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

#include "../include/Cinta.hpp"

#include <fstream>

using namespace std;

/// Constructor por defecto
Cinta::Cinta() { cabezal_ = 0; };

/// Sobrecarga del constructor
Cinta::Cinta(char* nombre_fichero) {
  nombre_fichero_ = nombre_fichero;
  cabezal_ = 0;
}

void Cinta::set_nombre_fichero(char* nombre_fichero) {
  nombre_fichero_ = nombre_fichero;
}

void Cinta::set_cabezal(unsigned long cabezal) { cabezal_ = cabezal; }

void Cinta::set_cinta(vector<int> cinta) { cinta_ = cinta; }

void Cinta::set_valor(int valor) { cinta_.push_back(valor); }

char* Cinta::get_nombre_fichero() { return nombre_fichero_; }

unsigned long Cinta::get_cabezal() { return cabezal_; }

vector<int> Cinta::get_cinta() { return cinta_; }

int Cinta::get_valor() { return cinta_[cabezal_]; }

void Cinta::IncremetarCabezal() {
  if (cabezal_ != cinta_.size() - 1) {
    cabezal_++;
  }
}