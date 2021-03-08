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

#include "../include/Programa.hpp"

#include "../include/ADD.hpp"
#include "../include/DIV.hpp"
#include "../include/HALT.hpp"
#include "../include/JGTZ.hpp"
#include "../include/JUMP.hpp"
#include "../include/JZERO.hpp"
#include "../include/LOAD.hpp"
#include "../include/MULT.hpp"
#include "../include/READ.hpp"
#include "../include/STORE.hpp"
#include "../include/SUB.hpp"
#include "../include/WRITE.hpp"

using namespace std;

/// Constructor por defecto
Programa::Programa() {}

/// Sobrecarga del constructor
Programa::Programa(string fichero_programa, RAM& ram) {
  CrearPrograma(ReadFile(fichero_programa), ram);
}

/// Destructor
Programa::~Programa() {}

vector<Instruccion*> Programa::get_programa_real() { return programa_real_; }

Instruccion* Programa::get_instruccion(int contador_programa) {
  return programa_real_[contador_programa];
}

map<string, int> Programa::get_etiquetas() { return etiquetas_; }

vector<string> Programa::ReadFile(string fichero_programa) {
  vector<string> programa;
  fstream fichero;
  fichero.open(fichero_programa, ios::in);

  bool halt = false;
  if (fichero.fail()) {
    string error = "No se puede abrir el fichero de entrada porque no existe";
    throw error;
  } else {
    while (!fichero.eof()) {
      string instruccion;
      fichero >> instruccion;
      if (instruccion.front() == PUNTO_COMA ||
          instruccion.front() == HASHTAG) {  // Comentario
        getline(fichero, instruccion);
      } else if (instruccion.back() == PUNTOS) {  // Etiqueta
        programa.push_back(PasarMayusculas(instruccion));
      } else if (instruccion == "halt" ||
                 instruccion == HALTS) {  // Caso del HALT
        programa.push_back(PasarMayusculas(instruccion));
        halt = true;
      } else {  // Resto de instrucciones
        string aux;
        aux = instruccion;
        aux += ESPACIO;
        fichero >> instruccion;
        if (instruccion.size() != 0) {
          aux += instruccion;
          programa.push_back(PasarMayusculas(aux));
        }
      }
    }
  }
  if (!halt) {
    string error = "El programa no contiene la instrucción HALT";
    throw error;
  }
  fichero.close();
  return programa;
}

void Programa::CrearPrograma(vector<string> programa, RAM& ram) {
  programa_real_.resize(programa.size());
  for (unsigned long i = 0; i < programa.size(); i++) {
    if (programa[i].back() == PUNTOS) {  // Es etiqueta
      programa[i].pop_back();
      if (etiquetas_.find(programa[i]) != etiquetas_.end()) {
        string error =
            "Error: No puede tener un programa con etiquetas del mismo nombre";
        throw error;
      }
      etiquetas_.insert(make_pair(programa[i], i));
      programa[i].push_back(PUNTOS);
    } else if (programa[i] == HALTS) {
      programa_real_[i] = new HALT(programa[i], "", i, DIRECTO, ram);
    } else {
      string nombre_instruccion;
      for (unsigned long j = 0; j < programa[i].size(); j++) {
        if (programa[i][j] != ESPACIO) {
          nombre_instruccion += programa[i][j];
        } else {
          break;
        }
      }
      int tipo_direccionamiento;
      string auxiliar;
      for (int j = programa[i].size() - 1; j >= 0; j--) {
        if (programa[i][j] == ASTERISCO) {
          tipo_direccionamiento = INDIRECTO;
        } else if (programa[i][j] == IGUAL) {
          tipo_direccionamiento = INMEDIATO;
        } else if (programa[i][j] != ESPACIO) {
          tipo_direccionamiento = DIRECTO;
          auxiliar += programa[i][j];
        } else {
          break;
        }
      }
      string operando;
      for (int j = auxiliar.size() - 1; j >= 0; j--) {
        if (nombre_instruccion == JUMPS || nombre_instruccion == JZEROS ||
            nombre_instruccion == JGTZS || isdigit(auxiliar[j])) {
          operando += auxiliar[j];
        } else {
          string error =
              "Error: El direccionamiento introducido no es válido. Línea " +
              to_string(i) + "-" + to_string(i + 1);
          throw error;
        }
      }
      if (nombre_instruccion == LOADS) {
        programa_real_[i] = new LOAD(nombre_instruccion, operando, i,
                                     tipo_direccionamiento, ram);
      } else if (nombre_instruccion == STORES) {
        programa_real_[i] = new STORE(nombre_instruccion, operando, i,
                                      tipo_direccionamiento, ram);
      } else if (nombre_instruccion == ADDS) {
        programa_real_[i] = new ADD(nombre_instruccion, operando, i,
                                    tipo_direccionamiento, ram);
      } else if (nombre_instruccion == SUBS) {
        programa_real_[i] = new SUB(nombre_instruccion, operando, i,
                                    tipo_direccionamiento, ram);
      } else if (nombre_instruccion == MULTS) {
        programa_real_[i] = new MULT(nombre_instruccion, operando, i,
                                     tipo_direccionamiento, ram);
      } else if (nombre_instruccion == DIVS) {
        programa_real_[i] = new DIV(nombre_instruccion, operando, i,
                                    tipo_direccionamiento, ram);
      } else if (nombre_instruccion == READS) {
        programa_real_[i] = new READ(nombre_instruccion, operando, i,
                                     tipo_direccionamiento, ram);
      } else if (nombre_instruccion == WRITES) {
        programa_real_[i] = new WRITE(nombre_instruccion, operando, i,
                                      tipo_direccionamiento, ram);
      } else if (nombre_instruccion == JUMPS) {
        programa_real_[i] = new JUMP(nombre_instruccion, operando, i,
                                     tipo_direccionamiento, ram);
      } else if (nombre_instruccion == JGTZS) {
        programa_real_[i] = new JGTZ(nombre_instruccion, operando, i,
                                     tipo_direccionamiento, ram);
      } else if (nombre_instruccion == JZEROS) {
        programa_real_[i] = new JZERO(nombre_instruccion, operando, i,
                                      tipo_direccionamiento, ram);
      } else {
        string error =
            "ERROR: La instrucción " + nombre_instruccion +
            " no es válida. Está situada en la línea: " + to_string(i) + "-" +
            to_string(i + 1);
        throw error;
      }
    }
  }
}

string Programa::PasarMayusculas(string cadena) {
  for (unsigned long i = 0; i < cadena.size(); i++) {
    cadena[i] = toupper(cadena[i]);
  }
  return cadena;
}

void Programa::WritePrograma() {
  string tipo_direccionamiento = " ";
  for (unsigned long i = 0; i < programa_real_.size(); i++) {
    tipo_direccionamiento = ESPACIO;
    if (programa_real_[i] != 0) {
      if (programa_real_[i]->get_tipo_direccionamiento() == INDIRECTO) {
        tipo_direccionamiento += ASTERISCO;
      } else if (programa_real_[i]->get_tipo_direccionamiento() == INMEDIATO) {
        tipo_direccionamiento += IGUAL;
      }
      cout << programa_real_[i]->get_nombre_instruccion()
           << tipo_direccionamiento << programa_real_[i]->get_operando()
           << endl;
    }
  }
  cout << endl;
  cout << "Etiquetas:" << endl;
  for (auto it = etiquetas_.begin(); it != etiquetas_.end(); ++it) {
    cout << "La etiqueta " << it->first << " está en la línea " << it->second
         << endl;
  }
  cout << endl;
}
