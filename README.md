# *[Tour de México ]*
---
#### Materia: *Análisis y Diseño de Algoritmos (TC2017)*

#### Semestre: *Otoño 2019*

##### Campus: *Santa Fe*

##### Integrantes:
1. *[Juan Francisco Gortarez Ricardez]* *[A01021926]*
2. *[Jorge Damián Palacios Hristova]* *[A01654203]*

---
## 1. Aspectos generales

### 1.1 Requerimientos

A continuación se mencionan los requerimientos mínimos del proyecto, favor de tenerlos presente para que cumpla con todos.

* El equipo tiene la libertad de elegir el problema a resolver.
* El proyecto deberá utilizar [OpenMP](https://www.openmp.org/) para la implementación del código paralelo.
* Todo el código y la documentación del proyecto debe alojarse en este repositorio de GitHub. Favor de mantener la estructura de carpetas propuesta.

### 1.2 Estructura del repositorio
El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz de todo el proyecto
    - README.md			# este archivo
    - secuencial		# Carpeta con la solución secuencial
    - paralelo			# Carpeta con la solución paralela
    - docs              # Carpeta con los documentos, tablas, gráficas, imágenes
```

### 1.3 Documentación  del proyecto

Como parte de la entrega final del proyecto, se debe incluir la siguiente información:

* Descripción del problema a resolver.
* Descripción de la solución secuencial con referencia (enlace) al código secuencial alojado en la carpeta [Secuencial](Secuencial/).
* Análisis de los inhibidores de paralelismo presente y una explicación de cómo se solucionaron.
* Descripción de la solución paralela con referencia (enlace) al código paralelo alojado en la carpeta [Paralelo](Paralelo/).
* Tabla de resultados con los tiempos de ejecución medidos para cada variante de la solución secuencial vs. la solución paralela, teniendo en cuenta: 5 tamaños diferentes de las entradas, 5 opciones diferentes de números de CPU (threads), 4 ocpiones diferentes de balanceo (*auto, guided, static, dynamic*).
* Gráfica(s) comparativa(s) de los resultados obtenidos en las mediciones.
* Interpretación de los resultados obtenidos.
* Guía paso a paso para la ejecución del código y replicar los resultados obtenidos.
* El código debe estar documentado siguiendo los estándares definidos para el lenguaje de programación seleccionado.

## 2. Descripción del problema

El problema que se busca representar en este código es representar la carrera del Tour de Francia, en este caso la carrera se llama Tour de México, en el código paralelo se representan a los corredores con threads los cuales pueden sufrir un accidente del 10% por tick y pasan por x cantidad de etapas. 

## 3. Solución [Secuencial](Secuencial/).

Para resolver el problema de forma secuencial lo que se hizo fue crear un vector de ints que representan a los corredores, asi mismo se usa una función para crear accidentes aleatorios a los competidores con una probabilidad del 10%, depués el tiempo se mide conforme el vector de corredores recorre cada etapa y va avanzando el tiempo y se suma al contador del tiempo 0.0002 segundos el cual es el tiempo que pierde un corredor por un accidente. El programa se puede encontrar en: [Secuencial](Secuencial/).

## 4. Análisis de los inhibidores del paralelismo

Para el código paralelo existen dos importamtes inhibidores los cuales son los siguientes: 

* Las funciones de print y de accidentes no pueden ser paralelizadas debido a que deben de ocurrir para un unico corredor           lo cual lo hace independiente a los demás.
* Solamente el ciclo interno es paralelizable dado que las etapas se deben de recorrer en orden.

## 5. Solución [Paralelo](Paralelo/).

Para la solución en paralelo lo que se hizo fue crear un 2 ciclos para que el programa pudiera representar los corredores usando threads, la solución se parece mucho a la secuencial debido a que el programa representa a los corredores y las etapas según sean especificadas por el usuario al igual hay eventos aleatorios lo cual afecta lops tiempos de los corredores. Se uso un pragma para paralelizar el ciclo que simula los corredores que van avanzado por las etapas que son especificados por el usuario a la hora de correr el programa.

## 6. Tabla de resultados

La tabla de resultados se incluye en un pdf en la parte de [Documentos](Docs/). la tabla es una muestra de diferentes tiempos que se tomaron según las especificaciones cambiando el número de threads, al igual se incluye la gráfica de como varía el tiempo en los códigos secuencial y los tipos de paralelo.

## 7. Gráfica(s) comparativa(s)

Las gráficas comparando los dos tipos de algoritmos y sus tipos se encuentra en el pdf de: [Documentos](Docs/).

## 8. Interpretación de los resultados
 
Como se puede observar en los resultados de tiempo en las 5 entradas diferentes que se tomaron durante la ejecución del programa se puede notar que el algoritmo secuencial tomó significantemente más tiempo que el paralelo. Esto probablemente se debe a la forma en que esta paralelizado el programa. Porque nosotros usamos una thread para simular un corredor, nos 'saltamos' la necesidad de tener un tercer ciclo, lo cual reduce la complejidad de O(n^3) en el secuencial a O(n^2). Esto se puede ver en nuestra sección de: [Documentos](Docs/). De la misma manera se puede observar como varía el código paralelo según su tipo. Nostros esperábamos que mientras más incrementaramos el número de corredores se acortaría la diferencia entre el secuencial y el paralelo por el incremento del overhead, sin embargo ocurrió lo contrario. Esto se puede deber a la reducción de complejidad mencionada previamente. 

Finalmente, en lo referente a los diferentes métodos de paralelización, la diferencia fue mínima. En general, el método estático fue el más lento, mientras que el dinámico fue el segundo más tardado en cantidades bajas de competidores, pero en cantidades más altas terminó siendo el mejor método. 

## 9. Guía paso a paso

### Secuencial
* Descargar el código
* El código secuencial se encuentra en el folder secuencial. Se compila asi: g++ Proyecto_Final_Seq.cpp -o PFS.
* Una vez compilado, se corre de la siguiente manera (en Linux/Mac): ./PFS <num. etapas> <num. competidores>. En Windows, se corre así: PFS.exe <num. etapas> <num. competidores>

### Paralelo
* Descargar el código
* El código paralelo se encuentra en el folder paralelo. Se compila así: g++ -fopenmp Proyecto_Final -o Proyecto_Final
* Una vez compilado, se corre de la siguiente manera: ./Proyecto_Final <num. etapas> <num. competidores>. Se puede especificar la manera de paralelización usando OMP_SCHEDULE=(dynamic/guided/auto), <chunk_size> antes del ./


## 10. Referencias

https://www.openmp.org/wp-content/uploads/OpenMP-4.0-C.pdf 
