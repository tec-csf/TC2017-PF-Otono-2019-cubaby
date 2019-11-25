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

*[Incluya aquí la descripción de la solución paralela.]*

## 6. Tabla de resultados

La tabla de resultados se incluye en un pdf en la parte de [Documentos](Docs/). la tabla es una muestra de diferentes tiempos que se tomaron según las especificaciones cambiando el número de threads, al igual se incluye la gráfica de como varía el tiempo en los códigos secuencial y los tipos de paralelo.

## 7. Gráfica(s) comparativa(s)

La gráfica comparando los dos tipos de algoritmos se encuentra en el pdf de: [Documentos](Docs/).

## 8. Interpretación de los resultados
 
Como se puede observar en los resultados de tiempo en las 5 entradas diferentes que se tomaron a la hora de correr cada uno de los programas se puede notar que el algoritmo secuencial tomo significante más tiempo que el paralelo y esto se debe a la forma en que esta paralelizado el programa este reliza las tareas de forma simultánea lo cual hace que el tiempo se reduzca en una gran cantidad como se puede ver en el pdf de: [Documentos](Docs/). De la misma manera se puede observar como varía el código paralelo según su tipo. Esto se ve en la sección [Documentos](Docs/). al igual se incluye sus gráficas.

## 9. Guía paso a paso

*[Incluya aquí la guía para la ejecución de los códigos.]*

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
