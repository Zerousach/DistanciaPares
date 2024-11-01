# DistanciaPares
Los sistemas informáticos utilizan muchas veces un conjunto de llaves públicas y privadas para
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
deben dejarse en 0
