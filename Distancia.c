/*Los sistemas informáticos utilizan muchas veces un conjunto de llaves públicas y privadas para
poder asegurar los permisos correctos al momento de acceder a datos. A modo de simplificación,
existen dos llaves una que es conocida por todos, y otra que es conocida por aquellos que tienen
acceso a datos.
Para comprobar la seguridad de un conjunto de claves, se dispone de un programa que genera un
conjunto de valores positivos (o claves) en un arreglo. Para estudiar la seguridad de dicho
conjunto, es necesario saber si existen un par de valores que posean una cierta distancia entre
ellos. Para el cálculo de la distancia considere simplemente que es la resta simple entre el mayor
valor y el menor.

Ejemplo:
Listado de valores: {4 5 7 3 9}
Distancia buscada: 2
La distancia buscada es cumplida por los pares de valores (5,3), (7, 5) y (9,7)

Realice una función iterativa (25 puntos) y otra recursiva (25 puntos) que dado un arreglo de
números enteros y un valor entero que indique la distancia buscada, retorna un arreglo de 3
elementos, donde:
El 1° elemento indica si existe o no un par de valores con la distancia buscada dentro del
arreglo del conjunto de claves. El valor 1 indica que, si existe, mientras que 0 indica que no.
El 2° y 3° elemento indica el par de valores que el algoritmo encontró con la distancia
mencionada. En caso de existir más de un par de valores que cumplan con dicha distancia,
entregue el primer par que encuentre. En caso de no existir dichos pares, estos valores
deben dejarse en 0*/

#include <stdlib.h>
#include <stdio.h>

float * listaParesRecursivo(float * listaPares,int repeti, int i, float * listaFinal){
	float par1, par2;
	if(repeti > 0){
		listaFinal[0] = 1.0;
		if(repeti > 2){	
			if(i < 4){
				if(listaPares[i] >= 10){
					par2 = listaPares[i]/100;
					par1 = listaPares[i-1]+par2;
					if(i == 3){
						listaFinal[2] = par1;
						return listaFinal;
					}
					listaFinal[1] = par1;
					return listaParesRecursivo(listaPares, repeti, i+2, listaFinal); 
				}
				else{
					par2 = listaPares[i]/10;
					par1 = listaPares[i-1]+par2;
					if(i == 3){
						listaFinal[2] = par1;;
						return listaFinal;
					}
					listaFinal[1] = par1;
					return listaParesRecursivo(listaPares, repeti, i+2, listaFinal); 
				}
			}
		}
		else{
			if(listaPares[1] >= 10){
				par2 = listaPares[1]/100;
				par1 = listaPares[0]+par2;
				listaFinal[1] = par1;
				listaFinal[2] = 0;
				return listaFinal;
			}
			else{
				par2 = listaPares[1]/10;
				par1 = listaPares[0]+par2;
				listaFinal[1] = par1;
				listaFinal[2] = 0;
				return listaFinal;
			}
		}
	}
	else{
		if(i < 3){
			listaFinal[i] = 0;
			return listaParesRecursivo(listaPares, 0, i+1, listaFinal);
		}
		else{
			return listaFinal;
		}
	}
}	

float * append(int * lista, int tamanioAntiguo,int a, int b, float * listaPares){
	float * listaNueva = (float*)malloc(sizeof(float)*(tamanioAntiguo+2));
	int i = 0;
	if(tamanioAntiguo >= 2){
		for(i = 0; i < tamanioAntiguo; i++){
			listaNueva[i] = listaPares[i];
		}
		listaNueva[i] = lista[a];
		listaNueva[i+1] = lista[b];
		return listaNueva;
	}
	else{
		listaNueva[i] = lista[a];
		listaNueva[i+1] = lista[b];
		return listaNueva;
	}
}

float * distanciaIterativa(int * lista, int tamanio, int distancia){
	float par1, par2;
	int i,j, distanciaBuscada, numerosLista, repeti;
	float * listaPares;
	int numeroBase;
	float * listaFinal = (float*)malloc(sizeof(float)*(3));
	repeti = 0;
	for(i = 0; i < tamanio ; i++){
		numeroBase = lista[i];
		for(j = 0; j < tamanio ; j++){
			distanciaBuscada = lista[j] - numeroBase;
			if(distanciaBuscada == distancia){
				listaPares = append(lista, repeti, i, j, listaPares);
				repeti = repeti +2;
			}
			else{
				printf("Buscando... \n");
			}
		}
	}
	printf("Finalizado...\n");
	if(repeti > 0){
		listaFinal = listaParesRecursivo(listaPares, repeti, 1, listaFinal);
		return listaFinal;
	}
	else{
		listaFinal = listaParesRecursivo(listaPares, 0, 0, listaFinal);
		return listaFinal;
	}
}

float * distanciaRecursiva(int * lista, int tamanio, int distancia, float * listaPares, int repeti, int i, int j){
	float par1, par2;
	int distanciaBuscada, numerosLista;
	int numeroBase;
	float * listaFinal = (float*)malloc(sizeof(float)*(3));
	if(i < tamanio){
		numeroBase = lista[i];
		if(j < tamanio){
			distanciaBuscada = lista[j] - numeroBase;
			if(distanciaBuscada == distancia){
				listaPares = append(lista, repeti, i, j, listaPares);
				return distanciaRecursiva(lista, tamanio, distancia, listaPares, repeti+2, i, j+1);
			}
			else{
				printf("Buscando... \n");
				return distanciaRecursiva(lista, tamanio, distancia, listaPares, repeti, i, j+1);
			}
		}
		else{
			return distanciaRecursiva(lista, tamanio, distancia, listaPares, repeti, i+1, 0);
		}
	}
	printf("Finalizado...\n");
	if(repeti > 0){
		listaFinal = listaParesRecursivo(listaPares, repeti, 1, listaFinal);
		return listaFinal;
	}
	else{
		listaFinal = listaParesRecursivo(listaPares, 0, 0, listaFinal);
		return listaFinal;
	}
}

int main(){
	int distancia, eleccion, tamanio, i, repeti;
	float * resultado;
	int * lista;
	printf("Bienvenido al busca distancia, diga su distancia preferida: ");
	scanf("%d", &distancia);
	printf("Su distancia es: %d\nDesea  generar usted los numeros o que sean aleatorios (1 para elegir, 2 para aleatorio): ",distancia); 
	scanf("%d", &eleccion);
	switch(eleccion){
		case 1:
			printf("Usted selecciono eleccion... de que tamaño sera su lista?: ");
			scanf("%d", &tamanio);
			printf("Diga sus numeros");
			lista = (int*)malloc(sizeof(int)*tamanio);
			for(i = 0; i<tamanio; i++){
				scanf("%d", &lista[i]);
			}
			break;
		case 2:
			printf("Usted selecciono aleatorio... de que tamaño sera su lista?: ");
			scanf("%d", &tamanio);
			lista = (int*)malloc(sizeof(int)*tamanio);
			for(i = 0; i<tamanio; i++){
				lista[i] = rand()%101;
				printf("%d ", lista[i]);
			}
			break;
	}
	printf("Desea utilizarlo iterativamente o recursivamente? \n1 para iterativo, 2 para recursivo: ");
	scanf("%d", &eleccion);
	switch(eleccion){
		case 1:;
			resultado = distanciaIterativa(lista, tamanio, distancia);
			printf("Esta es su lista de pares! (si el primer valor es 0, no existe ningun par que cumpla lo solicitado)\n");
			for(i = 0; i<3; i++){
				printf("%.2f ", resultado[i]);
			}
			break;
		case 2:;
			float * listaPares;
			repeti = 0;
			resultado = distanciaRecursiva(lista, tamanio, distancia, listaPares, repeti, 0, 0);
			printf("Esta es su lista de pares! (si el primer valor es 0, no existe ningun par que cumpla lo solicitado)\n");
			for(i = 0; i<3; i++){
				printf("%.2f ", resultado[i]);
			}
			break;
	}
	return 0;
}