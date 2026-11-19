# 📦 Sistema de Gestión de Bodega - C++

Programa desarrollado en C++ para la administración de inventarios y el control de ventas de una bodega. Permite registrar productos, consultar existencias, actualizar información, eliminar registros y gestionar las ventas realizadas mediante un menú interactivo en consola.

## 🚀 Funcionalidades

- ➕ **Insertar productos:** registra nuevos productos con código, nombre, costo, precio y cantidad disponible.
- 📋 **Mostrar inventario:** presenta el listado de productos registrados y sus respectivos valores totales.
- 🔎 **Buscar productos:** permite localizar productos mediante su código.
- ✏️ **Modificar productos:** actualiza el nombre, costo, precio o cantidad de un producto.
- 🗑️ **Eliminar productos:** permite eliminar registros del inventario mediante su código.
- 💰 **Vender productos:** procesa ventas, calcula el importe correspondiente y actualiza las existencias.
- 🧾 **Consultar ventas:** muestra los productos vendidos, cantidades y valores de las operaciones.
- 📊 **Generar reportes:** permite guardar reportes del inventario y de las ventas en archivos de texto.

## 🧠 Características técnicas

- Programación estructurada en C++.
- Uso de estructuras (`struct`) para organizar los datos de los productos.
- Manejo de archivos binarios para almacenar información.
- Lectura y escritura de archivos.
- Gestión de memoria dinámica.
- Búsqueda y modificación de registros.
- Uso de funciones para organizar las operaciones del programa.
- Cálculo de costos, precios y cantidades.

## 💾 Archivos de almacenamiento

| Archivo | Función |
|---|---|
| `Bodega.dat` | Almacena los registros del inventario. |
| `vender.dat` | Almacena los registros de ventas. |
| `Bodega.txt` | Contiene el reporte del inventario. |
| `vender.txt` | Contiene el reporte de ventas. |

## 🛠️ Tecnologías

- Lenguaje de programación: C++.
- Entorno: aplicación de consola.
- Almacenamiento: archivos binarios y de texto.
- Bibliotecas: estándar de C/C++ y bibliotecas específicas de Windows.

## ▶️ Ejecución

Compilar:

```bash
g++ BODEGA.cpp -o BODEGA
```

Ejecutar:

```bash
BODEGA.exe
```

**Nota:** El código utiliza bibliotecas específicas de Windows, por lo que su compilación requiere un entorno compatible.

## 👨‍💻 Autor

**Diego Escobar**

Proyecto de programación en C++ orientado a la gestión de inventarios, almacenamiento de información y control de ventas.