TSP
======

> Implementación de algunas heurísticas para resolver el TSP euclídeo.

## Algoritmos desarrollados
#### Vecino más cercano
Este es un algoritmo greedy que empezando en una ciudad arbitraria, continua dirigiéndose siempre a la ciudad más cercana de las que no se han visitado.

#### Mejor inserción
Este algoritmo, partiendo de una solución parcial de 2 ciudades, inserta una nueva ciudad en aquella posición de la ruta que suponga menos incremento en el coste total.

#### Lin-Kernihgan, k = 2
Este algoritmo parte de una solución del problema y en cada iteración elige dos caminos aleatorios entre ciudades y los intercambia. En caso de ser esta nueva solución mejor que la anterior, se continúa mutando a partir de esta, si no, se vuelve a la anterior.

## Binarios
Para este proyecto hemos desarrollado 4 programas que al compilar serán puestos en la carpeta ````bin/````. Hay un programa por cada algoritmo además de otro programa para calcular el coste de la ruta óptima calculada por TSPLib.
Para utilizar tales programas:
````sh
$> bin/best_insertion data/a280.tsp cost
2934
$> bin/lkh data/eil76.tsp path
[... las ciudades en orden ... ]
$> bin/nearest_neighbour data/eil101.tsp cost
811
$> bin/<algoritmo> <data-file> [path|cost]

$ bin/optimum-cost a280
2579
````

## Directorios
* ````./data````: instancias del problema para probar nuestros algoritmos.
* ````./scripts````: archivos para facilitar algunas tareas habituales.
* ````./src````: código fuente desarrollado para resolver los problemas.

## Tareas
#### Make
* ````make````: compila los binarios.
* ````make pdf````: compila el pdf con la memoria a partir del archivo latex.
* ````make compare````: lanza el script que ejecuta los algoritmos y los compara.
* ````make graph-comparison````: muestra una gráfica en la que se ven los resultados de la comparación

#### Visualización
Hemos desarrollado scripts para facilitar la visualización de los recorridos que realizarían cada uno de nuestros algoritmos.

````sh
$> scripts/best_insertion.sh data/a280.tsp
$> scripts/lkh.sh data/kroA100.tsp
$> scripts/nearest_neighbour.tsp data/berlin52.tsp
````
