# 2. De tarea, hacer el mismo ejercicio 1 en python.
while True:
    producto = input("\033[34mIntroduce el producto: ")
    if producto.strip() == "":
        print("\033[31mError el producto no puede estar vacio")
        continue
    if producto.isdigit():
        print("\033[31mError el producto no puede ser solo numeros")
        continue
    if len(producto) < 3:
        print("\033[31mError el producto debe tener al menos 3 letras")
        continue
    try:
        cantidad = int(input("\033[33mIntroduce la cantidad: "))
        if cantidad <= 0:
            print("\033[31mError la cantidad debe ser mayor a 0")
            continue
    except:
        print("\033[31mError debes ingresar un numero entero")
        continue
    try:
        precio = float(input("\033[32mIntroduce el precio unitario: "))
        if precio <= 0:
            print("\033[31mError el precio debe ser mayor a 0")
            continue
    except:
        print("\033[31mError debes ingresar un numero valido")
        continue
    if cantidad > 50:
        total = cantidad * precio * 0.85
        print(f"\033[32mEl costo de {cantidad} cantidades de {producto} con 15% de descuento es: {total:.2f}")
    else:
        total = cantidad * precio
        print(f"\033[32mEl costo de {cantidad} cantidades de {producto} (sin descuento) es: {total:.2f}")
    respuesta = input("\033[34mDeseas realizar otra consulta? S/N: ")
    if respuesta.upper() == "N":
        break
