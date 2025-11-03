// 6. Escribir un programa en el que dado el nombre de un mes y si el año es
// o no bisiesto, deducir el número de días del mes
import java.util.Scanner;
public class sep19_6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("introduce el mes");
        String mes = scanner.nextLine().toLowerCase(); // pasarlo a minuscula todo
        System.out.println("introduce el ano");
        int ano = scanner.nextInt();
        boolean bisiesto = false;
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) { //formula para ano bisiesto, lo busque la neta
            bisiesto = true;
        }
        int dias = 0;
        if (mes.equals("febrero")) {
            if (bisiesto) {
                dias = 29;
            } else {
                dias = 28;
            }
        } else if (mes.equals("enero") || mes.equals("marzo") || mes.equals("mayo") || mes.equals("julio") || mes.equals("agosto") || mes.equals("octubre") || mes.equals("diciembre")) {
            dias = 31;
        } else if (mes.equals("abril") || mes.equals("junio") || mes.equals("septiembre") || mes.equals("noviembre")) {
            dias = 30;
        } else {
            System.out.println("mes invalido");
            return;
        }
        System.out.println("el mes de " + mes + " tiene " + dias + " dias"); // vi que era mas facil poner variables asi que con %d
    }
} // supuse que era mas facil solo listar los meses que van, no hacerlo como con alguna regla de si no si no si
// es dificil de usar yo creo cuando tienes que escribir el mes en lugar de seleccionar de una lista
// pero me dio flojera contar con esos casos
// pero se q se puede