#2. Escriba un programa en python que permita crear una lista de palabras y que, a continuación de cuatro opciones:
#Contar: Pide una cadena, y debe decir cuantas veces aparece en la lista.
#Modificar: Pide una cadena, y otra cadena a modificar, y modifica todas las apariciones de la primera cadena por la segunda en la lista creada.
#Eliminar: Pide una cadena, y la elimina de la lista.
#Mostrar: Muestra la lista de cadenas.
#Terminar: Termina el program
import time
global menu
menu = 1
lista = []
numeroListas = int(input("Cuantas cadenas deseas introducir?"))
print("Introduce una lista de {} palabras".format(int(numeroListas)))
n = 0
lista = []
for n in range(0,numeroListas) :
    n = n
    cadenas = input("Introduce la {} palabra\n".format(int(n+1)))
    lista.append(cadenas)
    
def repetir():
    global menu
    eleccion = input("Deseas volver al menu? s/n")
    eleccionMinuscula = eleccion.lower()
    if eleccionMinuscula == "s" :
        menu = 1
    else :
        menu = 6
        
while True:
    match menu:
        case 1:
            eleccionMenu = input("Elige una de estas 4 opciones\n1) Contar\n2) Modificar\n3)Eliminar\n4)Mostrar\n5)Terminar")
            eleccionMenuInt = int(eleccionMenu)
            if eleccionMenuInt == 1 :
                menu = 2
            if eleccionMenuInt == 2 :
                menu = 3
            if eleccionMenuInt == 3 :
                menu = 4    
            if eleccionMenuInt == 4 :
                menu = 5
            if eleccionMenuInt == 5 :
                menu = 6  
        case 2:
            print("Esta era tu lista {}".format(str(lista)))
            palabraContar = input("Que palabra quieres contar para ver cuantas veces aparece?")
            listaContada = lista.count(palabraContar)
            print("Estas son las veces que aparece {}".format(listaContada))
            repetir()
        case 3:
            print("Esta era tu lista {}".format(str(lista)))
            cadenaNueva = input("Introduce la cadena nueva que vas a meter")
            cadenaQuitar = input("Que cadena deseas reemplazar por {}".format(cadenaNueva))
            for n in range(len(lista)): # recorro el tamaño de la lista
                if lista[n] == cadenaQuitar :
                    lista[n] = cadenaNueva # cada que halla un cadenaQuitar lo reemplaza por cadenaNueva
            print("Se ha cambiado {} por {}".format(str(cadenaQuitar),str(cadenaNueva)))
            print("La lista ahora es {}".format(lista))
            repetir()
        case 4:
            print("Esta era tu lista {}".format(str(lista)))
            cadenaEliminar = input("Que cadena deseas eliminar?")
            for m in lista[:]: # esto crea una copia de lista, asi cuando le quite mas de 1 elemento a lista siga recorriendo (elementos repetidos), al no usar range m toma el valor de cada elemento de la lista
                    if m == cadenaEliminar:
                        lista.remove(cadenaEliminar) #cada que aparezca en la lista la quita
            print("Se ha quitado {} de la lista".format(cadenaEliminar))
            print("La lista ahora es {}".format(lista))
            repetir()
        case 5:
            print("Esta era tu lista {}".format(lista))
            repetir()
        case 6:
            i = " . "

            for n in range(1):
                print("Saliendo del programa", end="")
                for m in range(4):
                    print(i, end="")
                    time.sleep(0.5)
            print("Listo!")
            break