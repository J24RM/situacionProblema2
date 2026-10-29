#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;


// Complejidad temporal: O(n^3) por los tres ciclos anidados de Floyd-Warshall
// (la impresión es O(n^2), así que domina O(n^3)).
void floyd(vector<vector<int>> D) {
    int n = D.size();
    for(int k = 0; k < n; k++)           
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    cout << "Punto 1" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i != j){
                cout << "Colonia " << i + 1 << " a " << "colonia " << j + 1 << ": " << D[i][j] << endl;
            }
        }
        cout << endl << endl;
    }

}

int main(int argc, char* argv[]) {
    // Archivo de entrada: se puede pasar como argumento, si no se usa el de ejemplo
    string nombreArchivo = (argc > 1) ? argv[1] : "Entradas/E5_Entrada_2.txt";

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

    floyd(distancias);

    return 0;
}
