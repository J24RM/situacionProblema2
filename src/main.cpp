#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char* argv[]) {
    // Archivo de entrada: se puede pasar como argumento, si no se usa el de ejemplo
    string nombreArchivo = (argc > 1) ? argv[1] : "Entradas/E5_Entrada_1.txt";

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    // Número de colonias
    int n;
    archivo >> n;

    // Matriz de distancias en kms entre colonias
    vector<vector<int>> distancias(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            archivo >> distancias[i][j];
        }
    }

    // Matriz de capacidades máximas de flujo de datos
    vector<vector<int>> capacidades(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            archivo >> capacidades[i][j];
        }
    }

    // Ubicación de las centrales con formato (x,y); también acepta "(x, y)"
    vector<pair<int, int>> centrales(n);
    char c;
    for (int i = 0; i < n; i++) {
        archivo >> c >> centrales[i].first >> c >> centrales[i].second >> c;
    }

    // Ubicación de la nueva central
    pair<int, int> nuevaCentral;
    archivo >> c >> nuevaCentral.first >> c >> nuevaCentral.second >> c;

    archivo.close();


    //
    // AL FINAL BORREN ESTO. 
    //
    // Mostrar lo leído para verificar
    cout << "N = " << n << endl;

    cout << "\nDistancias:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << distancias[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nCapacidades:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << capacidades[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nCentrales:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "(" << centrales[i].first << "," << centrales[i].second << ")" << endl;
    }

    cout << "\nNueva central: (" << nuevaCentral.first << "," << nuevaCentral.second << ")" << endl;

    return 0;
}
