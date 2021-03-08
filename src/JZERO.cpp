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

#include "../include/JZERO.hpp"

using namespace std;

JZERO::JZERO() : Instruccion() {}

JZERO::JZERO(string instruccion, string operando, int pos,
             int tipo_direccionamiento, RAM& ram)
    : Instruccion(instruccion, operando, pos, tipo_direccionamiento) {
  if (tipo_direccionamiento != DIRECTO) {
    string error =
        "Error: Sólo puedes usar direccionamiento directo con la "
        "instrucción " +
        instruccion;
    throw error;
  }
  ram_ = &ram;
}

JZERO::~JZERO() { delete[] ram_; }

void JZERO::ejecutar_instruccion(int debug, int operando_numero) {
  bool comprobar = false;
  if (ram_->get_memoria().get_acumulador() == 0) {
    if (ram_->get_programa().get_etiquetas().find(get_operando()) !=
        ram_->get_programa().get_etiquetas().end()) {
      ram_->set_contador(
          ram_->get_programa().get_etiquetas().find(get_operando())->second);
      comprobar = true;
    }
  }
  if (comprobar == false) {
    ram_->IncrementarContador();
  }
  if (debug == 1) {
    cout << tipo_direccionamiento_formateado() << ". El PC apunta a "
         << ram_->get_contador() << ". El acumulador tiene "
         << ram_->get_memoria().get_acumulador() << endl;
    return;
  }
}