# 🏁 Sistema de Clasificación de Corredores - C++

Programa desarrollado en C++ para registrar, organizar y clasificar corredores según su tiempo promedio por vuelta, utilizando árboles binarios de búsqueda y mecanismos de balanceo tipo AVL.

El sistema permite administrar participantes, calcular sus tiempos promedio y visualizar los resultados en orden ascendente o descendente.

## 🚀 Funcionalidades

- 👤 **Registro de corredores:** permite ingresar el nombre, número asignado, cantidad de vueltas y tiempo total.
- 🔢 **Validación de participantes:** evita registrar dos corredores con el mismo número.
- ⏱️ **Cálculo de tiempo promedio:** calcula automáticamente el tiempo promedio por vuelta.
- 🌳 **Inserción en árbol binario:** organiza los corredores según su tiempo promedio.
- ⚖️ **Balanceo del árbol:** aplica rotaciones para mejorar la distribución de los nodos.
- 📈 **Clasificación ascendente:** muestra los corredores desde el menor hasta el mayor tiempo promedio.
- 📉 **Clasificación descendente:** muestra los corredores desde el mayor hasta el menor tiempo promedio.

## 🧠 Funcionamiento

El programa utiliza un árbol binario de búsqueda para almacenar la información de los corredores.

Cada nodo contiene:

| Atributo | Descripción |
|---|---|
| `nombre` | Nombre del corredor. |
| `numero` | Número de identificación del participante. |
| `vueltas` | Cantidad de vueltas realizadas. |
| `tiempo_total` | Tiempo promedio calculado por vuelta. |
| `izq` | Puntero al subárbol izquierdo. |
| `der` | Puntero al subárbol derecho. |

La organización se realiza utilizando el tiempo promedio como criterio:

- Los tiempos menores se ubican en el subárbol izquierdo.
- Los tiempos mayores o iguales se ubican en el subárbol derecho.

El balanceo utiliza rotaciones simples y dobles para reorganizar los nodos.

## 🛠️ Tecnologías y conceptos aplicados

- Lenguaje de programación: C++.
- Programación estructurada.
- Estructuras dinámicas.
- Árboles binarios de búsqueda.
- Balanceo tipo AVL.
- Punteros y memoria dinámica.
- Recursividad.
- Algoritmos de búsqueda e inserción.
- Recorridos Inorden y orden inverso.

## 📋 Menú del sistema

El programa ofrece las siguientes opciones:

1. Agregar corredor.
2. Mostrar corredores de menor a mayor tiempo.
3. Mostrar corredores de mayor a menor tiempo.
4. Balancear árbol.
5. Salir.

## ▶️ Compilación y ejecución

Compilar utilizando un compilador compatible con C++:

```bash
g++ -std=c++17 Corredores.cpp -o Corredores
```

Ejecutar en Windows:

```cmd
Corredores.exe
```

## 📊 Aplicación práctica

Este proyecto permite representar un sistema básico de clasificación deportiva, donde los participantes se organizan de acuerdo con su rendimiento promedio.

También permite estudiar cómo las estructuras de datos dinámicas facilitan la administración y consulta de información.

## 👨‍💻 Autor

**Diego Escobar**

Ingeniería de Sistemas | Desarrollo de software | Estructuras de datos y algoritmos.

---

⭐ *Desarrollando soluciones computacionales mediante algoritmos, estructuras de datos y programación en C++.*