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

#include "../include/CintaEntrada.hpp"

#include <fstream>

using namespace std;

/// Constructor por defecto
CintaEntrada::CintaEntrada() : Cinta(){};

/// Sobrecarga del constructor
CintaEntrada::CintaEntrada(char* nombre_fichero) : Cinta(nombre_fichero) {
  ReadFile();
}

/// Destructor
CintaEntrada::~CintaEntrada() {}

void CintaEntrada::ReadFile() {
  fstream fichero;
  fichero.open(get_nombre_fichero(), ios::in);

  if (fichero.fail()) {
    string error = "No se puede abrir el fichero de entrada porque no existe";
    throw error;
  } else {
    while (!fichero.eof()) {
      int numero;
      fichero >> numero;
      set_valor(numero);
    }
  }
  fichero.close();
}

void CintaEntrada::WriteTapeScreen() {
  for (unsigned long i = 0; i < get_cinta().size(); i++) {
    cout << get_cinta()[i] << " ";
  }
  cout << endl;
  cout << "Cabezal: " << get_cabezal() << endl;
}
