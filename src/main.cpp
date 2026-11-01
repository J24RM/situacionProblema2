#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <numeric>   // std::iota para rellenar vectores secuenciales
#include <algorithm> // std::next_permutation y std::min
#include <climits>   // INT_MAX para infinito

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

// ====== Sección Punto 2: TSP mediante busqueda exacta =======

// funcion auxiliar visula
// Convierte un indice a su letra correspondiente (0 -> A, 1 -> B, etc.)
char nodoALetra(int indice) {
    return 'A' + indice;
}

// funcion de Evaluacion de una ruta cerrada 
// evalua (origen -> secuencia -> origen) y retorna la distancia total
int calcularCostoRuta(const vector<vector<int>>& distancias, const vector<int>& rutaIntermedia) {
    int costoTotal = 0;
    int nodoActual = 0; // Comenzamos desde la colonia 0 (A)
    //1. Sumar distancias entre nodos intermedios (secuencia) consecutivos
    for (int siguienteNodo : rutaIntermedia){
        costoTotal += distancias[nodoActual][siguienteNodo];
        nodoActual = siguienteNodo;
    }
    //2. Sumar distancia desde el último nodo de vuelta al origen
    costoTotal += distancias[nodoActual][0];

    return costoTotal;
}

// Si la rutaIntermedia contiene [1,2,3,4], la ruta completa es 0 -> 1 -> 2 -> 3 -> 4 -> 0
// Por ende la suma es distancias[0][1] + distancias[1][2] + distancias[2][3] + distancias[3][4] + distancias[4][0]

//Motor del TSP

void resolverTSP(const vector<vector<int>>& distancias) {
    int n = distancias.size();

    //1. generamos el vector con los nodos intermedios (1 a n-1) para permutarlos
    // de aqui sale la ruta intermedia que se va a evaluar ej: [1, 2, 3, 4]
    vector<int> rutaIntermedia(n - 1);
    iota(rutaIntermedia.begin(), rutaIntermedia.end(), 1); // Rellenar con [1, 2, ..., n-1]

    int costoMinimo = INT_MAX;
    vector<int> mejorRuta;

    // 2. Exploración exhaustiva de todas las permutaciones de la ruta intermedia
    do {
        //2.1 Evaluar el costo de la ruta actual
        int costoActual = calcularCostoRuta(distancias, rutaIntermedia);

        //2.2 Actualizar la mejor ruta si encontramos un costo menor
        if (costoActual < costoMinimo) {
            costoMinimo = costoActual;
            mejorRuta = rutaIntermedia;
        }
    } while (next_permutation(rutaIntermedia.begin(), rutaIntermedia.end()));

    // Imprimir la mejor ruta encontrada
    cout <<"Punto 2: Ruta del repartidor de correspondencia\n" << endl;
    cout <<"Ruta optima: " << nodoALetra(0) << " -> ";
    for (int nodo : mejorRuta) {
        cout << nodoALetra(nodo) << " -> ";
    }
    cout << "A" << endl;
    cout << "Costo mínimo: " << costoMinimo << endl;
}



// ===== Fin Sección Punto 2 =======

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


    //Debug: distancias de prueba 
    vector<vector<int>> distanciasDebug = {
        { 0, 16, 45, 32},
        {16,  0, 18, 21},
        {45, 18,  0,  7},
        {32, 21,  7,  0}
    };

    //Punto 2
    resolverTSP(distanciasDebug);

    // Punto 3


    //Punto 4

    return 0;
}
