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

#include "../include/MULT.hpp"

using namespace std;

MULT::MULT() : Instruccion() {}

MULT::MULT(string instruccion, string operando, int pos,
           int tipo_direccionamiento, RAM& ram)
    : Instruccion(instruccion, operando, pos, tipo_direccionamiento) {
  ram_ = &ram;
}

MULT::~MULT() { delete[] ram_; }

void MULT::ejecutar_instruccion(int debug, int operando_numero) {
  int tipo_direccionamiento = ram_->get_programa()
                                  .get_instruccion(ram_->get_contador())
                                  ->get_tipo_direccionamiento();
  if (tipo_direccionamiento == DIRECTO) {
    ram_->get_memoria().set_acumulador(
        ram_->get_memoria().get_acumulador() *
        ram_->get_memoria().get_registro(operando_numero));
  } else if (tipo_direccionamiento == INDIRECTO) {
    int aux = ram_->get_memoria().get_registro(operando_numero);
    ram_->get_memoria().set_acumulador(ram_->get_memoria().get_acumulador() *
                                       aux);
  } else if (tipo_direccionamiento == INMEDIATO) {
    ram_->get_memoria().set_acumulador(ram_->get_memoria().get_acumulador() *
                                       operando_numero);
  } else {
    string error = "Error: El direccionamiento no existe";
    throw error;
  }
  if (debug == 1) {
    cout << tipo_direccionamiento_formateado() << ". En el acumulador tenemos "
         << ram_->get_memoria().get_acumulador() << endl;
    cout << tipo_direccionamiento_formateado() << endl;
    ram_->IncrementarContador();
    return;
  }
  ram_->IncrementarContador();
}