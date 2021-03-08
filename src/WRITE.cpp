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

#include "../include/WRITE.hpp"

using namespace std;

WRITE::WRITE() : Instruccion() {}

WRITE::WRITE(string instruccion, string operando, int pos,
             int tipo_direccionamiento, RAM& ram)
    : Instruccion(instruccion, operando, pos, tipo_direccionamiento) {
  ram_ = &ram;
}

WRITE::~WRITE() { delete[] ram_; }

void WRITE::ejecutar_instruccion(int debug, int operando_numero) {
  int tipo_direccionamiento = ram_->get_programa()
                                  .get_instruccion(ram_->get_contador())
                                  ->get_tipo_direccionamiento();
  if (operando_numero == 0 && tipo_direccionamiento == DIRECTO) {
    string error = "Error: No se puede hacer WRITE 0";
    throw error;
  } else if (tipo_direccionamiento == DIRECTO) {
    ram_->get_cintasalida().set_valor(
        ram_->get_memoria().get_registro(operando_numero));
  } else if (tipo_direccionamiento == INDIRECTO) {
    int auxiliar = ram_->get_memoria().get_registro(operando_numero);
    ram_->get_cintasalida().set_valor(
        ram_->get_memoria().get_registro(auxiliar));
  } else if (tipo_direccionamiento == INMEDIATO) {
    ram_->get_cintasalida().set_valor(operando_numero);
  }
  ram_->get_cintasalida().IncremetarCabezal();
  if (debug == 1) {
    cout << tipo_direccionamiento_formateado() << endl;
    ram_->IncrementarContador();
    return;
  }
  ram_->IncrementarContador();
}