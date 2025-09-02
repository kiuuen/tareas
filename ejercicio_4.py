# 4. De tarea, hacer el mismo ejercicio 3 en python.

while True:
    nombre = input("\033[34mIntroduce el nombre del estudiante: ")
    if nombre.strip() == "":
        print("\033[31mError el nombre no puede estar vacio")
        continue
    if nombre.isdigit():
        print("\033[31mError el nombre no puede ser solo numeros")
        continue
    if len(nombre) < 3:
        print("\033[31mError el nombre debe tener al menos 3 letras")
        continue
    try:
        cal_1 = float(input("\033[33mIntroduce la calificacion 1: "))
        if cal_1 < 0 or cal_1 > 100:
            print("\033[31mError la calificacion debe estar entre 0 y 100")
            continue
    except:
        print("\033[31mError debes ingresar un numero valido")
        continue
    try:
        cal_2 = float(input("\033[33mIntroduce la calificacion 2: "))
        if cal_2 < 0 or cal_2 > 100:
            print("\033[31mError la calificacion debe estar entre 0 y 100")
            continue
    except:
        print("\033[31mError debes ingresar un numero valido")
        continue
    try:
        cal_3 = float(input("\033[33mIntroduce la calificacion 3: "))
        if cal_3 < 0 or cal_3 > 100:
            print("\033[31mError la calificacion debe estar entre 0 y 100")
            continue
    except:
        print("\033[31mError debes ingresar un numero valido")
        continue

    if cal_1 < 60 or cal_2 < 60 or cal_3 < 60:
        print(f"\033[32mEstudiante: {nombre}, Calificacion final: NA (No Acreditado)")
    else:
        promedio = (cal_1 + cal_2 + cal_3) / 3
        print(f"\033[32mEstudiante: {nombre}, Calificacion final: {promedio:.2f}")
    respuesta = input("\033[34mDeseas registrar otro estudiante? S/N: ")
    if respuesta.upper() == "N":
        break
