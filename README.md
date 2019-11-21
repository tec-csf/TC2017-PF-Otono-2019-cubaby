# *[Tour de México ]*
---
#### Materia: *Análisis y Diseño de Algoritmos (TC2017)*

#### Semestre: *Otoño 2019*

##### Campus: *Santa Fe*

##### Integrantes:
1. *[Juan Francisco Gortarez Ricardez]* *[A01021926]*
2. *[Jorge Dmián Palacios Hristova]* *[A01654203]*

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

Para resolver el problema de forma secuencial lo que se hizo fue crear un vector de ints que representan a los corredores, asi mismo se usa una función para crear accidentes aleatorios a los competidores con una probabilidad del 10%, depués el tiempo se mide conforme el vector de corredores recorre cada etapa y va avanzando el tiempo y se suma al contador del tiempo 0.0002 segundos el cual es el tiempo que pierde un corredor por un accidente. 

## 4. Análisis de los inhibidores del paralelismo

Para el código paralelo existen dos importamtes inhibidores los cuales son los siguientes: 

* Las funciones de print y de accidentes no pueden ser paralelizadas debido a que deben de ocurrir para un unico corredor           lo cual lo hace independiente a los demás.
* Solamente el ciclo interno es paralelizable dado que las etapas se deben de recorrer en orden.

## 5. Solución [Paralelo](Paralelo/).

*[Incluya aquí la descripción de la solución paralela.]*

## 6. Tabla de resultados

*[Incluya aquí la tabla con los resultados de las mediciones.]*

## 7. Gráfica(s) comparativa(s)

*[Incluya aquí la(s) gráfica(s) comparativa(s).]*

## 8. Interpretación de los resultados

*[Incluya aquí la interpretación de los resultados.]*

## 9. Guía paso a paso

*[Incluya aquí la guía para la ejecución de los códigos.]*

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
