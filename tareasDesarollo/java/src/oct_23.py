#1. Desarrolle un programa en Python que cree una lista e 
# inicialice con 5 cadenas de caracteres leídas por teclado. Copia los elementos
# de la lista en otra lista pero en orden inverso, y muestra sus elementos por la pantalla.
print("Introduce una lista de 5 palabras")
n = 0
lista = []
for n in range(1,6) :
    n = n
    cadenas = input("Introduce la {} palabra\n".format(str(n)))
    lista.append(cadenas)
print("La lista es {}".format(str(lista)))
listaInvertida = lista[::-1] # clona los elementos de lista a listaInvertida, pero invertidos
print("La lista invertida es {}".format(str(listaInvertida)))