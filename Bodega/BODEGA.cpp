/*********************************
* AUTOR : DIEGO ESCOBAR
* FECHA DE CREACION : 28/6/2018
/*********************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<unistd.h>
#include<fstream>
#include<cstdlib>
#include<string>
#include<cctype>
#include<windows.h>
#include<math.h>
#include <ctime>
#include <vector>

#define MAX 80
#define VALOR_CENTINELA -1

using namespace std;

struct producto
{
	int codigo;
	char nombre[MAX];
	float costo;
	float precio;
	int cantidad;
	int codigoVendido;
	char nombreVendido[MAX];
	float costoVendido;
	float precioVendido;
	int cantidadVendida;
};

typedef struct producto Producto;

void menuPrincipal();
void menuInsertar();
void menuBuscar();
void menuEliminar();
void menuMostrar();
void menuModificar();
void menuVender();
void menuMostrarVentas();

Producto *obtenerProductos(int *n);
char existeProducto(int codigoProducto, Producto *producto);
char insertarProducto(Producto producto); 
char eliminarProducto(int codigoProducto);
char modificarProducto(Producto producto);
char guardarReporte();
char guardarReporteVentas();
char venderProducto(Producto producto);
 
int leecad(char *cad, int n);
 
char linea[MAX];

int main()
{
	setlocale(LC_ALL, "spanish");
	menuPrincipal();
}


void menuPrincipal()
{
	int op1,op2 = 1;
	
	time_t now = time(0);

	tm * time = localtime(&now);

	vector<string> dia_semana;
	dia_semana.push_back("Domingo");
	dia_semana.push_back("Lunes");
	dia_semana.push_back("Martes");
	dia_semana.push_back("Miercoles");
	dia_semana.push_back("Jueves");
	dia_semana.push_back("Viernes");
	dia_semana.push_back("Sabado");

	vector<string> mes;
	mes.push_back("Enero");
	mes.push_back("Febrero");
	mes.push_back("Marzo");
	mes.push_back("Abril");
	mes.push_back("Mayo");
	mes.push_back("Junio");
	mes.push_back("Julio");
	mes.push_back("Agosto");
	mes.push_back("Septiembre");
	mes.push_back("Octubre");
	mes.push_back("Noviembre");
	mes.push_back("Diciembre");

	int year = 1900 + time->tm_year;
	
	do
	{
		system("cls");
		cout <<"\nHoy " << dia_semana[time->tm_wday] << ", ";
		cout <<time->tm_mday<<" de "<<mes[time->tm_mon]<<" del "<< year<<endl;
		cout <<time->tm_hour<<":"<<time->tm_min << ":"<<time->tm_sec<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\tMENU PRINCIPAL\n\n";
		cout<<"\n\t\t\t\t\t\t\t\t[1] .Insertar nuevo producto\n";
		cout<<"\n\t\t\t\t\t\t\t\t[2] .Mostrar listado de producto\n";
		cout<<"\n\t\t\t\t\t\t\t\t[3] .Eliminar un producto\n";
		cout<<"\n\t\t\t\t\t\t\t\t[4] .Buscar producto por codigo\n";
		cout<<"\n\t\t\t\t\t\t\t\t[5] .Modificar un producto\n";
		cout<<"\n\t\t\t\t\t\t\t\t[6] .Vender producto\n";
		cout<<"\n\t\t\t\t\t\t\t\t[7] .Mostrar productos vendidos\n";
		cout<<"\n\t\t\t\t\t\t\t\t[8] .Salir\n";
		cout<<"\n\n\t\t\t\t\t\t\t\tIngrese su opcion: [ ]\b\b";
		cin>>op1;
		switch(op1)
		{
			case 1:
			{
				menuInsertar();
			}
			break;
			
			case 2:
			{
				menuMostrar();
			}
			break;
			
			case 3:
			{
				menuEliminar();
			}	
			break;
			
			case 4:
			{
				menuBuscar();
			}	
			break;
			
			case 5:
			{
				menuModificar();
			}	
			break;
			
			case 6:
			{
				menuVender();
			}
			break;
			
			case 7:
			{
				menuMostrarVentas();
			}	
			break;
			
			case 8:
			{
				for(int i=0;i<2;i++)
				{
					system("cls");
					cout<<"\n\n\t\t\t\t\t\t\t\t\tSaliendo del programa ";sleep(1);cout<<".";sleep(1);cout<<".";sleep(1);cout<<".";
				}
				exit(0);
			}	
		}
		
	}while(op2 == 1);
}


void menuInsertar()
{
	Producto producto;
	int codigoProducto = 0;
	char repite = 1;
	char respuesta[MAX];
	
	do
	{
		system("cls");
		cout<<"\n\t\t\t\t\t\t\t\t\t\tINSERTAR PRODUCTO\n\n";
		cout<<"\n\n\t\t\t\t\t\t\t\tCodigo del producto: ";
		cin>>codigoProducto;
		
		if(!existeProducto(codigoProducto, &producto))
		{
			producto.codigo = codigoProducto;
			
			cout<<"\n\n\t\t\t\t\t\t\t\tNombre del producto: ";
			cin>>producto.nombre;
			cout<<"\n\n\t\t\t\t\t\t\t\tCosto del producto ($): ";
			cin>>producto.costo;
			cout<<"\n\n\t\t\t\t\t\t\t\tPrecio del producto ($): ";
			cin>>producto.precio;
			cout<<"\n\n\t\t\t\t\t\t\t\tCantidad: ";
			cin>>producto.cantidad;
			
			if(insertarProducto(producto))
			{
				cout<<"\n\n\t\t\t\t\t\t\t\tEl producto fue insertado correctamente";
			}
		}
		else
		{
			cout<<"\n\n\t\t\t\t\t\t\t\tEl codigo de producto ya existe.\n";
			cout<<"\t\t\t\t\t\t\t\tNo puede ingresar dos productos distintos con el mismo codigo.\n\n";
		}
		
		cout<<"\n\n\t\t\t\t\t\t\t\tDesea seguir ingresando productos? [S/N]: ";
		cin>>respuesta;
		
		if(!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0))
		{
			repite = 0;
		}
		
	}while(repite);
}


void menuBuscar()
{
	Producto producto;
	int codigoProducto;
	char repite = 1;
	char respuesta[MAX];
	
	do
	{
		system("cls");
		cout<<"\n\t\t\t\t\t\t\t\tBUSCAR PRODUCTO POR CODIGO\n\n";
		cout<<"\n\n\t\t\t\t\t\t\t\tCodigo de producto: ";
		cin>>codigoProducto;
		
		if(existeProducto(codigoProducto, &producto))
		{
			printf("\n\n\t\t\t\t\t\t\t\tCodigo del producto: %d",producto.codigo);
			printf("\n\t\t\t\t\t\t\t\tNombre del producto: %s",producto.nombre);
			printf("\n\t\t\t\t\t\t\t\tCosto del producto: %.1f $",producto.costo);
			printf("\n\t\t\t\t\t\t\t\tPrecio del producto: %.1f $",producto.precio);
			printf("\n\t\t\t\t\t\t\t\tCantidad: %d",producto.cantidad);
		}
		else
		{
			printf("\n\n\t\t\t\t\t\t\t\tEl producto de codigo %d no existe.\n",codigoProducto);
		}
		
		cout<<"\n\n\t\t\t\t\t\t\t\tDesea seguir buscando algun producto? [S/N]: ";
		cin>>respuesta;
		
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) 
		{
			repite = 0;
		}
		
	}while(repite);
}


void menuEliminar()
{
	Producto producto;
	int codigoProducto;
	char repite = 1;
	char respuesta[MAX];
	
	do
	{
		system("cls");
		cout<<"\n\t\t\t\t\t\t\t\tELIMINAR PRODUCTO POR CODIGO\n\n";
		cout<<"\n\n\t\t\t\t\t\t\t\tCodigo de producto: ";
		cin>>codigoProducto;
		
		if(existeProducto(codigoProducto, &producto))
		{
			printf("\n\n\t\t\t\t\t\t\t\tCodigo del producto: %d",producto.codigo);
			printf("\n\t\t\t\t\t\t\t\tNombre del producto: %s",producto.nombre);
			printf("\n\t\t\t\t\t\t\t\tCosto del producto: %.1f $",producto.costo);
			printf("\n\t\t\t\t\t\t\t\tPrecio del producto: %.1f $",producto.precio);
			printf("\n\t\t\t\t\t\t\t\tCantidad: %d",producto.cantidad);
			
			cout<<"\n\n\t\t\t\t\t\t\t\tSeguro que desea eliminar el producto? [S/N]: ";
			cin>>respuesta;
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) 
			{
				if (eliminarProducto(codigoProducto)) 
				{
					printf("\n\n\t\t\t\t\t\t\t\tProducto eliminado satisfactoriamente.\n");
				}
				 else 
				{
					printf("\n\n\t\t\t\t\t\t\t\tEl producto no pudo ser eliminado\n");
				}
			}
		}
		else
		{
			cout<<"\n\n\t\t\t\t\t\t\t\tEl producto no existe.\n";
		}
		
		cout<<"\n\n\t\t\t\t\t\t\t\tDesea eliminar otro producto? [S/N]: ";
		cin>>respuesta;
		
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) 
		{
			repite = 0;
		}
		
	}while(repite);
}


void menuMostrar()
{
	Producto *productos;
	int numeroProductos;
	int i;
	float costoTotal;
	float precioTotal;
	int cantidadTotal;
	char respuesta[MAX];
	
	system("cls");
	productos = obtenerProductos(&numeroProductos);
	
	if(numeroProductos == 0)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tEl archivo esta vacio\n";
		system("pause>null");
	}
	else
	{
		printf("\n\t\t\t\t\t\t\t\t\tLISTADO DE PRODUCTOS REGISTRADOS\n\n");
		printf("\n\t\t\t\t\t\t------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t%8s\t%-20s%15s%15s%10s\n", "CODIGO", "NOMBRE", "COSTO $", "PRECIO $", "CANTIDAD");
		printf("\n\t\t\t\t\t\t------------------------------------------------------------------------------\n");
 
		costoTotal = 0;
		precioTotal = 0;
		cantidadTotal = 0;
		for (i = 0; i < numeroProductos; i++) 
		{
			if (productos[i].codigo != VALOR_CENTINELA) 
			{
				printf("\n\t\t\t\t\t\t%7d \t%-20.20s%15.1f%15.1f%8d\n", productos[i].codigo, productos[i].nombre, productos[i].costo, productos[i].precio, productos[i].cantidad);
				costoTotal += productos[i].costo;
				precioTotal += productos[i].precio;
				cantidadTotal += productos[i].cantidad;
			}
		}
		printf("\n\t\t\t\t\t\t------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t\t\t\t      TOTAL: %15.1f%15.1f%8d\n", costoTotal, precioTotal, cantidadTotal);
 
		printf("\n\t\t\t\t\t\t\tDesea guardar el reporte en un archivo de texto? [S/N]: ");
		leecad(respuesta, MAX);
 
		if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) 
		{
			if (guardarReporte()) 
			{
				printf("\n\t\t\t\t\t\t\t\tEl reporte fue guardado con éxito\n");
			}
			else 
			{
				printf("\n\t\t\t\t\t\t\t\tOcurrió un error al guardar el reporte\n");
			}
 
			system("pause>nul");
		}
	}
}


void menuModificar()
{
	Producto producto;
	int codigoProducto;
	char repite = 1;
	char respuesta[MAX];
 
	do 
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t\tMODIFICAR PRODUCTO POR CÓDIGO\n\n");
 
		cout<<"\n\n\t\t\t\t\t\t\t\tCódigo de producto: ";
		cin>>codigoProducto;

		if (existeProducto(codigoProducto, &producto)) 
		{
			printf("\n\n\t\t\t\t\t\t\t\tNombre del producto: %s", producto.nombre);
			printf("\n\t\t\t\t\t\t\t\tCosto del producto ($): %.1f\n", producto.costo);
			printf("\n\t\t\t\t\t\t\t\tPrecio del producto ($): %.1f", producto.precio);
			printf("\n\t\t\t\t\t\t\t\tCantidad: %d", producto.cantidad);
 
			printf("\n\n\t\t\t\t\t\t\t\tElija los datos a modificar\n");
 
			printf("\n\n\t\t\t\t\t\t\t\tNombre del producto actual: %s", producto.nombre);
			printf("\n\t\t\t\t\t\t\t\tDesea modificar el nombre del producto? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) 
			{
				printf("\n\t\t\t\t\t\t\t\tNuevo nombre del producto: ");
				leecad(producto.nombre, MAX);
			}
 
			printf("\n\n\t\t\t\t\t\t\t\tCosto del producto actual: %.1f", producto.costo);
			printf("\n\t\t\t\t\t\t\t\tDesea modificar el costo del producto? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) 
			{
				printf("\n\t\t\t\t\t\t\t\tNuevo costo del producto: ");
				leecad(linea, MAX);
				sscanf(linea, "%f", &producto.costo);
			}
 
			printf("\n\n\t\t\t\t\t\t\t\tPrecio del producto actual: %.1f", producto.precio);
			printf("\n\t\t\t\t\t\t\t\tDesea modificar el precio del producto? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) 
			{
				printf("\n\t\t\t\t\t\t\t\tNuevo precio del producto: ");
				leecad(linea, MAX);
				sscanf(linea, "%f", &producto.precio);
			}
 
			printf("\n\n\t\t\t\t\t\t\t\tCantidad del producto actual: %d", producto.cantidad);
			printf("\n\t\t\t\t\t\t\t\tDesea modificar la cantidad del producto? [S/N]: ");
			leecad(respuesta, MAX);
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) 
			{
				printf("\n\t\t\t\t\t\t\t\tNueva cantidad del producto: ");
				leecad(linea, MAX);
				sscanf(linea, "%d", &producto.cantidad);
			}
 
			printf("\n\n\t\t\t\t\t\t\t\tEstá seguro que desea modificar los datos del producto? [S/N]: ");
			leecad(respuesta, MAX);
 
			if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) 
			{
				if (modificarProducto(producto))
				{
					printf("\n\n\t\t\t\t\t\t\t\tEl producto fue modificado correctamente\n");
 
				}
				else 
				{
					printf("\n\n\t\t\t\t\t\t\t\tOcurrió un error al intentar modificar el producto\n");
					printf("\n\t\t\t\t\t\t\t\tInténtelo mas tarde\n");
				}
			}
		} 
		else 
		{
			printf("\n\n\t\t\t\t\t\t\t\tEl producto de código %d no existe.", codigoProducto);
		}
 
		printf("\n\n\t\t\t\t\t\t\t\tDesea modificar algún otro producto? [S/N]: ");
		leecad(respuesta, MAX);
 
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) 
		{
			repite = 0;
		}
 
	}while(repite);
}


void menuVender()
{
	Producto producto;
	int codigoProducto;
	char repite = 1;
	char respuesta[MAX], op;
	float vender,total = 0;
	
	do
	{
		system("cls");
		cout<<"\n\t\t\t\t\t\t\t\tVENDER PRODUCTO POR CODIGO\n\n";
		cout<<"\n\n\t\t\t\t\t\t\t\tCodigo de producto: ";
		cin>>codigoProducto;
		
		if(existeProducto(codigoProducto, &producto))
		{
			printf("\n\n\t\t\t\t\t\t\t\tCodigo del producto: %d",producto.codigo);
			printf("\n\t\t\t\t\t\t\t\tNombre del producto: %s",producto.nombre);
			printf("\n\t\t\t\t\t\t\t\tCosto del producto: %.1f $",producto.costo);
			printf("\n\t\t\t\t\t\t\t\tPrecio del producto: %.1f $",producto.precio);
			printf("\n\t\t\t\t\t\t\t\tCantidad: %d",producto.cantidad);
			
			cout<<"\n\n\t\t\t\t\t\t\t\tDigite la cantidad que desea vender: ";
			cin>>vender;
			
			if(vender >= 1 && vender <= producto.cantidad)
			{
				producto.codigoVendido = producto.codigo;
				producto.costoVendido = producto.costo;
				producto.cantidadVendida = vender;
				producto.cantidad = producto.cantidad - vender;
				vender = vender * producto.precio;
				producto.precioVendido = vender;
				cout<<"\n\n\t\t\t\t\t\t\t\tPrecio a pagar: "<<vender;
				cout<<"\n\n\t\t\t\t\t\t\t\tTotal a Pagar: "<<total;
				cout<<"\n\n\t\t\t\t\t\t\t\tDesea llevarselo [S/N]:";
				cin>>op;
				if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) 
				{
					total += vender;
					cout<<"\n\n\t\t\t\t\t\t\t\tTotal a Pagar: "<<total;
					if(modificarProducto(producto))
					{
						if(venderProducto(producto))
						{
							cout<<"\n\n\t\t\t\t\t\t\t\tProceso de venta terminado";
						}
						else
						{
							cout<<"\n\n\t\t\t\t\t\t\t\tNo se pudo insertar los datos";
						}
					}
					else
					{
						cout<<"\n\n\t\t\t\t\t\t\t\tOcurrio un error al ejecutar el proceso";
					}
				}
				else
				{
					total = vender - total; 
				}
			}
			else
			{
				cout<<"\n\n\t\t\t\t\t\t\t\tCantidad incorrecta";
			}
		}
		else
		{
			printf("\n\n\t\t\t\t\t\t\t\tEl producto de codigo %d no existe.\n",codigoProducto);
		}
		
		cout<<"\n\n\t\t\t\t\t\t\t\tDesea seguir vendiendo algun producto? [S/N]: ";
		cin>>respuesta;
		
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) 
		{
			repite = 0;
		}
		
	}while(repite);
}


void menuMostrarVentas()
{
	Producto *productos;
	int numeroProductos;
	int i;
	float costoTotal;
	float precioTotal;
	int cantidadTotal;
	char respuesta[MAX];
	system("cls");
	productos = obtenerProductos(&numeroProductos);
 
	if (numeroProductos == 0) 
	{
		printf("\n\t\t\t\t\t\t\t\tEl archivo está vacío!!\n");
		system("pause>null");
	} 
	else 
	{
		printf("\n\t\t\t\t\t\t\t\t\t==> LISTADO DE PRODUCTOS VENDIDOS <==\n");
		printf("\n\n\t\t\t\t\t\t------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t%8s\t%-20s%15s%15s%10s\n", "CODIGO", "NOMBRE", "PRECIO $", "TOTAL VENTA $", "CANTIDAD");
		printf("\n\t\t\t\t\t\t------------------------------------------------------------------------------\n");
 
		costoTotal = 0;
		precioTotal = 0;
		cantidadTotal = 0;
		for (i = 0; i < numeroProductos; i++) 
		{
			if (productos[i].codigoVendido != VALOR_CENTINELA) 
			{
				printf("\n\t\t\t\t\t\t%7d \t%-20.20s%15.1f%15.1f%8d\n", productos[i].codigoVendido, productos[i].nombre, productos[i].precio, productos[i].precioVendido, productos[i].cantidadVendida);
				costoTotal += productos[i].costoVendido;
				precioTotal += productos[i].precioVendido;
				cantidadTotal += productos[i].cantidadVendida;
			}
		}
		printf("\n\t\t\t\t\t\t------------------------------------------------------------------------------\n");
		printf("\n\t\t\t\t\t\t\t\t\t      TOTAL: %15.1f%15.1f%8d\n", costoTotal, precioTotal, cantidadTotal);
 
		printf("\n\n\t\t\t\t\t\t\tDesea guardar el reporte en un archivo de texto? [S/N]: ");
		leecad(respuesta, MAX);
 
		if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) 
		{
			if (guardarReporteVentas())
			{
				printf("\n\n\t\t\t\t\t\t\t\t\tEl reporte fue guardado con éxito\n");
			} 
			else 
			{
				printf("\n\n\t\t\t\t\t\t\t\t\tOcurrió un error al guardar el reporte\n");
			}
 
			system("pause>null");
		}
	}
}


Producto *obtenerProductos(int *n)
{
	FILE *archivo;
	Producto producto;
	Producto *productos;
	int i;
 
	archivo = fopen("Bodega.dat", "rb");
 
	if (archivo == NULL) 
	{
		*n = 0;
		productos = NULL;
	} 
	else 
	{
		fseek(archivo, 0, SEEK_END);
		*n = ftell(archivo) / sizeof(Producto);
		productos = (Producto *)malloc((*n) * sizeof(Producto));
 
		fseek(archivo, 0, SEEK_SET);
		fread(&producto, sizeof(producto), 1, archivo);
		i = 0;
		while (!feof(archivo)) 
		{
			productos[i++] = producto;
			fread(&producto, sizeof(producto), 1, archivo);
		}
 
		fclose(archivo);
	}
 
	return productos;
}


char existeProducto(int codigoProducto, Producto *producto)
{
	FILE *archivo;
	char existe;
 
	archivo = fopen("Bodega.dat", "rb");
 
	if (archivo == NULL) 
	{
		existe = 0;
	} 
	else 
	{
		existe = 0;
 
		fread(&(*producto), sizeof(*producto), 1, archivo);
		while (!feof(archivo)) 
		{
			if ((*producto).codigo == codigoProducto) 
			{
				existe = 1;
				break;
			}
			fread(&(*producto), sizeof(*producto), 1, archivo);
		}
 
		fclose(archivo);
	}
 
	return existe;
}


char insertarProducto(Producto producto)
{
	FILE *archivo;
	char insercion;
 
	archivo = fopen("Bodega.dat", "ab");
 
	if (archivo == NULL) 
	{
		insercion = 0;
	} 
	else 
	{
		fwrite(&producto, sizeof(producto), 1, archivo);
		insercion = 1;

		fclose(archivo);
	}
 
	return insercion;
}


char eliminarProducto(int codigoProducto)
{
	FILE *archivo;
	FILE *auxiliar;
	Producto producto;
	char elimina;
 
	archivo = fopen("Bodega.dat", "r+b");
 
	if (archivo == NULL) 
	{
		elimina = 0;
	} 
	else 
	{
 
		elimina = 0;
		fread(&producto, sizeof(producto), 1, archivo);
		while (!feof(archivo)) 
		{
			if (producto.codigo == codigoProducto) 
			{
				fseek(archivo, ftell(archivo) - sizeof(producto), SEEK_SET);
				producto.codigo = VALOR_CENTINELA;
				fwrite(&producto, sizeof(producto), 1, archivo);
				elimina = 1;
				break;
			}
			fread(&producto, sizeof(producto), 1, archivo);
		}
 
		fclose(archivo);
	}
 
	return elimina;
}


char modificarProducto(Producto producto)
{
	FILE *archivo;
	char modifica;
	Producto producto2;
 
	archivo = fopen("Bodega.dat", "rb+");
 
	if (archivo == NULL) 
	{
		modifica = 0;
	} 
	else 
	{
		modifica = 0;
		fread(&producto2, sizeof(producto2), 1, archivo);
		while (!feof(archivo)) 
		{
			if (producto2.codigo == producto.codigo) 
			{
				fseek(archivo, ftell(archivo) - sizeof(producto), SEEK_SET);
				fwrite(&producto, sizeof(producto), 1, archivo);
				modifica = 1;
				break;
			}
			fread(&producto2, sizeof(producto2), 1, archivo);
		}
		fclose(archivo);
	}
 
	return modifica;
}


char guardarReporte()
{
	FILE *archivo;
	char guardado;
	Producto *productos;
	int numeroProductos;
	int i;
	float costoTotal;
	float precioTotal;
	int cantidadTotal;
 
	productos = obtenerProductos(&numeroProductos);
 
	if(numeroProductos == 0) 
	{
		guardado = 0;
	} 
	else 
	{
		archivo = fopen("Bodega.txt", "w");
 
		if(archivo == NULL) 
		{ 
			guardado = 0;	
			
		}
		else 
		{
			fprintf(archivo, "\n\t\t    ==> LISTADO DE PRODUCTOS REGISTRADOS <==\n");
			fprintf(archivo, " ------------------------------------------------------------------------------\n");
			fprintf(archivo, "%8s\t%-20s%15s%15s%10s\n", "CODIGO", "NOMBRE", "COSTO $", "PRECIO $", "CANTIDAD");
			fprintf(archivo, " ------------------------------------------------------------------------------\n");
 
			costoTotal = 0;
			precioTotal = 0;
			cantidadTotal = 0;
			for (i = 0; i < numeroProductos; i++) 
			{
				if (productos[i].codigo != VALOR_CENTINELA) 
				{
					fprintf(archivo, "%7d \t%-20.20s%15.1f%15.1f%8d\n", productos[i].codigo, productos[i].nombre, productos[i].costo, productos[i].precio, productos[i].cantidad);
					costoTotal += productos[i].costo;
					precioTotal += productos[i].precio;
					cantidadTotal += productos[i].cantidad;
				}
			}
			fprintf(archivo, " ------------------------------------------------------------------------------\n");
			fprintf(archivo, "\t\t\t      TOTAL: %15.1f%15.1f%8d", costoTotal, precioTotal, cantidadTotal);
 
			guardado = 1;
 
			fclose(archivo);
		}
	}
 
	return guardado;
}


char guardarReporteVentas()
{
	FILE *archivos;
	char guardado;
	Producto *productos;
	int numeroProductos;
	int i;
	float costoTotal;
	float precioTotal;
	int cantidadTotal;
 
	productos = obtenerProductos(&numeroProductos);
 
	if(numeroProductos == 0) 
	{
		guardado = 0;
	} 
	else 
	{
		archivos = fopen("vender.txt", "w");
 
		if(archivos == NULL) 
		{ 
			guardado = 0;
 
		}
		else 
		{
			fprintf(archivos, "\n\t\t    ==> LISTADO DE PRODUCTOS VENDIDOS <==\n");
			fprintf(archivos, " ------------------------------------------------------------------------------\n");
			fprintf(archivos, "%8s\t%-20s%15s%15s%10s\n", "CODIGO", "NOMBRE", "PRECIO $", "TOTAL VENTA $", "CANTIDAD");
			fprintf(archivos, " ------------------------------------------------------------------------------\n");
 
			costoTotal = 0;
			precioTotal = 0;
			cantidadTotal = 0;
			for (i = 0; i < numeroProductos; i++) 
			{
				if (productos[i].codigo != VALOR_CENTINELA) 
				{
					fprintf(archivos, "%7d \t%-20.20s%15.1f%15.1f%8d\n", productos[i].codigoVendido, productos[i].nombreVendido, productos[i].costoVendido, productos[i].precioVendido, productos[i].cantidadVendida);
					costoTotal += productos[i].costoVendido;
					precioTotal += productos[i].precioVendido;
					cantidadTotal += productos[i].cantidadVendida;
				}
			}
			fprintf(archivos, " ------------------------------------------------------------------------------\n");
			fprintf(archivos, "\t\t\t      TOTAL: %15.1f%15.1f%8d", costoTotal, precioTotal, cantidadTotal);
 
			guardado = 1;
 
			fclose(archivos);
		}
	}
 
	return guardado;
}


int leecad(char *cad, int n)
{
	int i, c;
 
	c = getchar();
	if (c == EOF) 
	{
		cad[0] = '\0';
		return 0;
	}
 
	if (c == '\n') 
	{
		i = 0;
	} 
	else 
	{
		cad[0] = c;
		i = 1;
	}

	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) 
	{
		cad[i] = c;
	}
	cad[i] = '\0';
 
 
	if (c != '\n' && c != EOF)
		while ((c = getchar()) != '\n' && c != EOF);
		
	return 1;
}


char venderProducto(Producto producto)
{
	FILE *archivos;
	char insercion;
 
	archivos = fopen("vender.dat", "ab");
 
	if (archivos == NULL) 
	{
		insercion = 0;
	} 
	else 
	{
		fwrite(&producto, sizeof(producto), 1, archivos);
		insercion = 1;

		fclose(archivos);
	}
 
	return insercion;
}
