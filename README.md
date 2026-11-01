# Situación Problema 2: Alta demanda para los Proveedores de Servicios de Internet (ISP)

**Análisis y diseño de algoritmos avanzados · Grupo 602 · Equipo XX**

| Integrante | Matrícula |
|---|---|
| Carlos Delgado Contreras | A01712819 |
| Andrea Iliana Cantú Mayorga | A01753419 |
| Jesus Rodriguez Mendoza | A01713550 |

## El problema

En 2020 la pandemia de COVID-19 movió el trabajo y la escuela a un modelo remoto. Eso aumentó mucho la transmisión de datos por Internet y volvió indispensables a los proveedores de servicios de Internet (ISP).

Este proyecto busca mejorar el servicio de Internet en una población pequeña con algoritmos de grafos. Las colonias son los nodos, y las conexiones entre ellas son aristas con un peso: la distancia en kilómetros o la capacidad de transmisión de datos.

El programa responde estas preguntas:

| Punto | Pregunta | Algoritmo |
|---|---|---|
| 1 | ¿Cuál es la distancia mínima de cableado de fibra óptica entre cada par de colonias? | Floyd-Warshall, O(n³) |
| 2 | ¿Cuál es la ruta óptima para visitar todas las colonias y regresar al origen? | TSP por búsqueda exacta (permutaciones) |
| 3 | ¿Cuál es el flujo máximo de información de la primera colonia a la última? | Ford-Fulkerson con BFS (Edmonds-Karp) |
## Formato del archivo de entrada

```
n                      ← número de colonias
matriz n × n           ← distancias en km entre colonias
matriz n × n           ← capacidades máximas de flujo de datos
n líneas (x,y)         ← ubicación de cada central
(x,y)                  ← ubicación de la nueva central
```

Los casos de prueba están en `src/Entradas/` y las salidas esperadas en `src/Salidas/`.

## Compilar y ejecutar

Se necesita un compilador de C++17 (por ejemplo, `g++` o `clang++`).

```bash
cd src
g++ -std=c++17 -o main main.cpp
```

Para ejecutar con un archivo de entrada:

```bash
./main Entradas/E5_Entrada_1.txt
```

Si no se pasa ningún archivo, el programa usa `Entradas/E5_Entrada_2.txt`. Las rutas son relativas a `src/`, así que hay que ejecutarlo desde esa carpeta.

Para comparar con la salida esperada:

```bash
./main Entradas/E5_Entrada_1.txt > mi_salida.txt
diff mi_salida.txt Salidas/E5_Salida_1.txt
```
