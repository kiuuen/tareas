# 2. Crear un programa en Python que pida nombres y la edad, y cree un diccionario con dichos datos.
# Debe imprimir el diccionario y clasificar a las personas en
# dos grupos, 1 grupo los menores a 18 años y el otro los mayores, imprima ambos diccionarios.

import os # para poder usar la terminal
os.system("cls") # lo busque
try:
    try :
        numeroDatos = int(input("Cuantas personas piensas registrar? (numeros enteros) "))
    except :
        print("Error con los datos")
    DiccionarioNombresEdades = {} #creo el diccionario vacio para llenarlo despues en el for
    for n in range(numeroDatos) : # hago un bucle que se ejecuta segun el numero de datos que puso
        nombre = input("Introduce el nombre de la persona ")
        edad = int(input("Introduce la edad de la persona "))
        DiccionarioNombresEdades[nombre] = edad # le agrego valor a cada nombre segun la edad para tener la relacion
# nombre:edad
    DiccionarioMayores = {}
    DiccionarioMenores = {}
    NombresMayores = ""
    NombresMenores = ""
# ya creado puedo hacer como en el anterior y solo comparar con un for que recorra el diccionario
    for nombre, edad in DiccionarioNombresEdades.items() : # recorro los 2 elementos segun los items o ps los datos
        if edad > 17 :
            DiccionarioMayores[nombre] = edad # lo mismo que hice antes pero con los que cumplen la condicion
            NombresMayores = [nombre]
        elif 0 < edad < 18 :
            DiccionarioMenores[nombre] = edad
            NombresMenores = [nombre]
    for nombre in DiccionarioMayores:
        print("Estos son las personas mayores: ", nombre)
         #nombre puede ser n o lo q sea solo recorre la lista
        print(nombre)
    for nombre in DiccionarioMenores: #nombre puede ser n o lo q sea solo recorre la lista
        print("Estos son las personas menores: ", nombre)

except:
    print("Has introducido mal un dato vuelve a intentarlo!")




