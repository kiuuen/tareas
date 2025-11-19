/*Ejercicio 1: Clase con responsabilidades claras y validaciones mínimas

Cree una clase ProductoSimple con los atributos privados:

nombre

precio

cantidad

Requisitos:

El constructor debe validar:

nombre no vacío

precio mayor que 0

cantidad ≥ 0

Debe incluir métodos:

incrementarCantidad(int n)

decrementarCantidad(int n)

mostrarInformacion()

Este ejercicio solo busca reforzar encapsulamiento + getters/setters con reglas básicas. */

import java.util.Scanner;

class ProductoSimple {
    private String Nombre;
    private double Precio;
    private int Cantidad;
    public ProductoSimple(String nombre, double precio) {
        if (!nombre.isEmpty() && precio > 0)  { 
            Precio = precio;
            Nombre = nombre;   
        } else {
            throw new IllegalArgumentException("Cantidad incorrecta, introduce con cantidades posibles, no vacías");
        }
    }
    public void incrementarCantidad(int cantidadAumentar) {
        if (cantidadAumentar > 0) {
            Cantidad += cantidadAumentar;
        } else {
            throw new IllegalArgumentException("Cantidad incorrecta, introduce con cantidades posibles, mayores a 0");
        }
    }
    public void decrementarCantidad(int cantidadReducir) {
        if (cantidadReducir > 0 && cantidadReducir <= Cantidad) {
            Cantidad -= cantidadReducir;
        } else {
            throw new IllegalArgumentException("Cantidad incorrecta, introduce con cantidades posibles, mayores a 0 y menor a la cantidad que tienes");
        }
    }
    public String getNombre() {
        return Nombre;
        }
    }
}


public class practica_POO_1 {


}
