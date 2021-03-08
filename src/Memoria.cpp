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

#include "../include/Memoria.hpp"

using namespace std;

Memoria::Memoria() { registros_.resize(4); }

Memoria::~Memoria() {}

void Memoria::set_acumulador(int numero) { registros_[0] = numero; }

void Memoria::set_registro(int numero_registro) {
  registros_[numero_registro] = registros_[0];
}

void Memoria::set_registro_valor(int numero_registro, int valor) {
  registros_[numero_registro] = valor;
}

void Memoria::set_memoria(int tamano) { registros_.resize(tamano); }

int Memoria::get_acumulador() { return registros_[0]; }

int Memoria::get_registro(int num_registro) { return registros_[num_registro]; }

vector<int> Memoria::get_memoria() { return registros_; }

void Memoria::WriteMemoria() {
  cout << endl;
  for (unsigned long i = 0; i < registros_.size(); i++) {
    cout << "Registro " << i << ": " << registros_[i] << endl;
  }
  cout << endl;
}
