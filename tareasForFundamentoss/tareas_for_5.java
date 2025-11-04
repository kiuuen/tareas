// 5. Imprima en pantalla lo siguiente:
//Escriba el numero para la secuencia: 5
// 1
// 22
// 333
// 4444
// 55555
//Escriba el numero para la secuencia: 10
// 1
// 22
// 333
// 4444
// 55555
//666666
//7777777
//88888888
//999999999
//10101010101010101010
//Escriba el numero para la secuencia: -4
//-4-4-4-4
//-3-3-3
//-2-2
//-1
//Escriba el numero para la secuencia: -7
//-7-7-7-7-7-7-7
//-6-6-6-6-6-6
//-5-5-5-5-5
//-4-4-4-4
//-3-3-3
//-2-2
//-1
import java.util.Scanner;
public class tareas_for_5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Escriba el número para la secuencia: ");
        int limite = sc.nextInt();
        if (limite>=0) {
            for (int n = 1;
                n<=limite;
                n++) {
                    System.out.println(); // cada vuelta va a saltar de linea
                    for (int i = 1; // for anidado, va a imprimir n veces n
                        i<=n;
                        i++) {
                            System.out.print(n);
                            }
                    }
        }
        if (limite < 0) { // copie y pegue pero ahora si es negativo, empieza de arriba para abajo
            for (int n = limite; // n es el limite
                n<=-1; // hasta que llegue a -1
                n++) { // va sumarle 1 al limite, si es -7 hara -6 -5 ... -1
                    System.out.println(); 
                    for (int i = 1; 
                        i<=-n; // se repetira esto -n veces, si el limite es -7, lo hara 7 veces, si es -6 6 
                        i++) {
                            System.out.print(n);
                            }
                    }
        }

        }
    }   
