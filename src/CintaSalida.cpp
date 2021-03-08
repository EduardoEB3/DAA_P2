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

#include "../include/CintaSalida.hpp"

#include <fstream>

using namespace std;

/// Constructor por defecto
CintaSalida::CintaSalida() : Cinta(){};

/// Sobrecarga del constructor
CintaSalida::CintaSalida(char* nombre_fichero) : Cinta(nombre_fichero) {
  WriteFile();
}

/// Destructor
CintaSalida::~CintaSalida() {}

void CintaSalida::WriteFile() {
  fstream fichero;
  fichero.open(get_nombre_fichero(), ios::out);
  if (fichero.fail()) {
    string error = "No se puede abrir el fichero de salida";
    throw error;
  } else {
    for (unsigned long i = 0; i < get_cinta().size(); i++) {
      fichero << get_cinta()[i] << endl;
    }
  }
  fichero.close();
}

void CintaSalida::WriteTapeScreen() {
  for (unsigned long i = 0; i < get_cinta().size(); i++) {
    cout << get_cinta()[i] << " ";
  }
  cout << endl;
  cout << "Cabezal: " << get_cabezal() << endl;
}
