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

#include "../include/STORE.hpp"

using namespace std;

STORE::STORE() : Instruccion() {}

STORE::STORE(string instruccion, string operando, int pos,
             int tipo_direccionamiento, RAM& ram)
    : Instruccion(instruccion, operando, pos, tipo_direccionamiento) {
  if (tipo_direccionamiento == INMEDIATO) {
    string error = "Error: No puedes usar direccionamiento inmediato con el " +
                   instruccion;
    throw error;
  }
  ram_ = &ram;
}

STORE::~STORE() { delete[] ram_; }

void STORE::ejecutar_instruccion(int debug, int operando_numero) {
  string error = "Error: No puedes hacer un STORE 0";
  int tipo_direccionamiento = ram_->get_programa()
                                  .get_instruccion(ram_->get_contador())
                                  ->get_tipo_direccionamiento();
  if (tipo_direccionamiento == DIRECTO) {
    if (operando_numero == 0) {
      throw error;
    }
    if ((unsigned long)operando_numero >
        ram_->get_memoria().get_memoria().size()) {
      ram_->get_memoria().set_memoria(operando_numero);
    }
    ram_->get_memoria().set_registro(operando_numero);
  } else if (tipo_direccionamiento == INDIRECTO) {
    if (operando_numero == 0) {
      throw error;
    }
    unsigned long auxiliar = ram_->get_memoria().get_registro(operando_numero);
    if (auxiliar >= ram_->get_memoria().get_memoria().size()) {
      ram_->get_memoria().set_memoria(auxiliar + 1);
    }
    if (operando_numero == 0) {
      throw error;
    }
    ram_->get_memoria().set_registro(auxiliar);
  } else {
    string error = "Error: El direccionamiento no existe";
    throw error;
  }
  if (debug == 1) {
    cout << tipo_direccionamiento_formateado() << endl;
    ram_->IncrementarContador();
    return;
  }
  ram_->IncrementarContador();
}