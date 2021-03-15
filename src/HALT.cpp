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

#include "../include/HALT.hpp"

using namespace std;

HALT::HALT() : Instruccion() {}

HALT::HALT(string instruccion, string operando, int pos,
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

HALT::~HALT() { delete[] ram_; }

void HALT::ejecutar_instruccion(int debug, int operando_numero) {
  if (debug == 1) {
    cout << "La instrucción HALT tiene un direccionamiento directo. En este "
            "punto acaba el programa y escribo la cinta de salida en el fichero"
         << endl;
    throw this;
  }
  ram_->IncrementarContador();
  ram_->get_cintasalida().WriteFile();
}