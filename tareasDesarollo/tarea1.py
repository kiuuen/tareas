# 1. Crear un programa en Python que 
# permita crear una lista de 10 números aleatorios, que imprima la lista y 
# obtenga cuántos son mayores a 10.
import random
listaNumeros = [] # creo una lista vacia para usarla luego
numero = 0; # nomas la creo primero para usarla

for n in range(10) :
    numero = random.randint(1,20); ## creo numeros del 1 al 20 hasta que los elementos de la lista sea 10
    listaNumeros.append(numero); ## agrega el nuevo numero a la lista

listaNumeros.sort() ## la ordeno de menor a mayor
print("se genero estos 10 numeros", listaNumeros);

listaMayores10 = []
for n in listaNumeros : # recorro la lista elemento por elemento
    if n > 10 :  
        listaMayores10.append(n) # todos los mayores a 10 los agrego a una nueva lista
        
print("los numeros mayores a 10 son", listaMayores10);     