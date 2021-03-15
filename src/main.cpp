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

#include <fstream>
#include <iostream>

#include "../include/CintaEntrada.hpp"
#include "../include/CintaSalida.hpp"
#include "../include/Programa.hpp"
#include "../include/RAM.hpp"

using namespace std;

void help();
void menu(RAM&);

int main(int argc, char* argv[]) {
  if (argc == 2 && string(argv[1]) == "--help") {
    help();
    return 1;
  } else if (argc != 5) {
    cout << "Modo de empleo: ./main ../ejemplosRAM/testX.ram "
            "input_tape.in output_tape.out debug"
         << endl;
    cout << "Pruebe './main --help' para más información." << endl;
    return 1;
  } else {
    try {
      CintaEntrada Cinta_Entrada(argv[2]);
      CintaSalida Cinta_Salida(argv[3]);
      int debug = atoi(argv[4]);
      RAM Ram(string(argv[1]), Cinta_Entrada, Cinta_Salida);
      if (debug == 0) {
        Ram.ejecutar_RAM(debug);
        cout << "El número de instrucciones ejecutadas son: "
             << Ram.get_numero_instrucciones() << endl;
      } else if (debug == 1) {
        menu(Ram);
      } else {
        cout << "La opción introducida no es válida" << endl;
        cout << "Ponga 0 si desea ejecutar todo el programa, en cambio "
                "ponga "
                "un 1 si desea desplegar un menú"
             << endl;
      }
    } catch (string& error) {
      cout << error << endl;
    } catch (...) {
      cout << "Saliendo..." << endl;
    }
  }
  return 0;
}

void help() {
  cout << "---------------------------- MODO DE USO "
          "-----------------------------------------"
       << endl;
  cout << "Debe ponerlo de la forma: ./main ../ejemplosRAM/testX.ram "
          "input_tape.in output_tape.out debug"
       << endl;
  cout << "Donde testX.ram es el fichero con el progrma que desea realizar "
       << endl;
  cout << "Donde input_tape.in es el fichero que contiene la cinta de entrada"
       << endl;
  cout << "Donde output_tape.out es el fichero que contiene la cinta de salida"
       << endl;
  cout << "Donde debug contiene la forma en la que desea ejecutar" << endl;
}

void menu(RAM& Ram) {
  char opcion;
  do {
    cout << ">h" << endl;
    cout << "r: ver los registros" << endl;
    cout << "t: traza" << endl;
    cout << "e: ejecutar" << endl;
    cout << "s: desensamblador" << endl;
    cout << "i: ver cinta entrada" << endl;
    cout << "o: ver cinta salida" << endl;
    cout << "h: ayuda" << endl;
    cout << "x: salir" << endl;
    cout << "> ";

    cin >> opcion;
    cout << endl;

    switch (opcion) {
      case 'r':
        cout << "Memoria:";
        Ram.get_memoria().WriteMemoria();
        break;
      case 't':
        cout << "Traza:" << endl;
        Ram.ejecutar_RAM(1);
        cout << endl;
        break;
      case 'e':
        cout << "Ejecutar:" << endl;
        Ram.ejecutar_RAM(0);
        cout << "El número de instrucciones ejecutadas son: "
             << Ram.get_numero_instrucciones() << endl;
        opcion = 'x';
        break;
      case 's':
        cout << "Desensamblar:" << endl;
        Ram.get_programa().WritePrograma();
        break;
      case 'i':
        cout << "Cinta de entrada: ";
        Ram.get_cintaentrada().WriteTapeScreen();
        cout << endl;
        break;
      case 'o':
        cout << "Cinta de salida: ";
        Ram.get_cintasalida().WriteTapeScreen();
        cout << endl;
        break;
      case 'h':
        cout << "Ayuda:" << endl;
        help();
        cout << endl;
        break;
      case 'x':
        cout << "Saliendo..." << endl;
        break;
      default:
        cout << "---Opción inválida---" << endl;
        break;
    }
  } while (opcion != 'x');
}
