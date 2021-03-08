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

#include "../include/READ.hpp"

using namespace std;

READ::READ() : Instruccion() {}

READ::READ(string instruccion, string operando, int pos,
           int tipo_direccionamiento, RAM& ram)
    : Instruccion(instruccion, operando, pos, tipo_direccionamiento) {
  if (tipo_direccionamiento == INMEDIATO) {
    string error = "Error: No puedes usar direccionamiento inmediato con el " +
                   instruccion;
    throw error;
  }
  ram_ = &ram;
}

READ::~READ() { delete[] ram_; }

void READ::ejecutar_instruccion(int debug, int operando_numero) {
  if (operando_numero == 0) {
    string error = "Error: No puedes hacer un READ 0";
    throw error;
  }
  ram_->get_memoria().set_registro_valor(operando_numero,
                                         ram_->get_cintaentrada().get_valor());
  ram_->get_cintaentrada().IncremetarCabezal();
  if (debug == 1) {
    cout << "READ: lee el valor " << ram_->get_cintaentrada().get_valor()
         << " y lo almacena en " << operando_numero << endl;
    ram_->IncrementarContador();
    return;
  }
  ram_->IncrementarContador();
}