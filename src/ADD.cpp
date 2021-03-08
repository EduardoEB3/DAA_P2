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

#include "../include/ADD.hpp"

using namespace std;

ADD::ADD() : Instruccion() {}

ADD::ADD(string instruccion, string operando, int pos,
         int tipo_direccionamiento, RAM& ram)
    : Instruccion(instruccion, operando, pos, tipo_direccionamiento) {
  ram_ = &ram;
}

ADD::~ADD() { delete[] ram_; }

void ADD::ejecutar_instruccion(int debug, int operando_numero) {
  int tipo_direccionamiento = ram_->get_programa()
                                  .get_instruccion(ram_->get_contador())
                                  ->get_tipo_direccionamiento();
  int acumulador = ram_->get_memoria().get_acumulador();
  if (tipo_direccionamiento == DIRECTO) {
    ram_->get_memoria().set_acumulador(
        acumulador + ram_->get_memoria().get_registro(operando_numero));
  } else if (tipo_direccionamiento == INDIRECTO) {
    int auxiliar = ram_->get_memoria().get_registro(operando_numero);
    ram_->get_memoria().set_acumulador(acumulador + auxiliar);
  } else if (tipo_direccionamiento == INMEDIATO) {
    ram_->get_memoria().set_acumulador(acumulador + operando_numero);
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