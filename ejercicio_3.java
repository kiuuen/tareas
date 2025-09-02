// 3. Elaborar un programa en Java que lea los datos de   un estudiante (nombre y tres calificaciones
// parciales) e imprima el nombre y la calificación final de acuerdo con lo siguiente:
// para aprobar el curso debe tener 60 o más en cada una de las tres calificaciones, la calificación final será
// el promedio. En caso de haber reprobado uno o más exámenes ordinarios,
// la calificación final será NA (No Acreditado).

// aqui intenté manejar el try y catch ademas el if

import java.util.Scanner;

public class ejercicio_3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("\033[34mIntroduce el nombre del estudiante: ");
            String nombre = scanner.nextLine();
            if (nombre.trim().isEmpty()) {
                System.out.print("\033[31mError el nombre no puede estar vacio\n");
                continue;
            }
            if (nombre.matches("\\d+")) {
                System.out.print("\033[31mError el nombre no puede ser solo numeros\n");
                continue;
            }
            if (nombre.length() < 3) {
                System.out.print("\033[31mError el nombre debe tener al menos 3 letras\n");
                continue;
            }

            double cal_1, cal_2, cal_3;
            try {
                System.out.print("\033[33mIntroduce la calificacion 1: ");
                cal_1 = Double.parseDouble(scanner.nextLine());
                if (cal_1 < 0 || cal_1 > 100) {
                    System.out.print("\033[31mError la calificacion debe estar entre 0 y 100\n");
                    continue;
                }
            } catch (Exception e) {
                System.out.print("\033[31mError debes ingresar un numero valido\n");
                continue;
            }
            try {
                System.out.print("\033[33mIntroduce la calificacion 2: ");
                cal_2 = Double.parseDouble(scanner.nextLine());
                if (cal_2 < 0 || cal_2 > 100) {
                    System.out.print("\033[31mError la calificacion debe estar entre 0 y 100\n");
                    continue;
                }
            } catch (Exception e) {
                System.out.print("\033[31mError debes ingresar un numero valido\n");
                continue;
            }
            try {
                System.out.print("\033[33mIntroduce la calificacion 3: ");
                cal_3 = Double.parseDouble(scanner.nextLine());
                if (cal_3 < 0 || cal_3 > 100) {
                    System.out.print("\033[31mError la calificacion debe estar entre 0 y 100\n");
                    continue;
                }
            } catch (Exception e) {
                System.out.print("\033[31mError debes ingresar un numero valido\n");
                continue;
            }
            if (cal_1 < 60 || cal_2 < 60 || cal_3 < 60) {
                System.out.printf("\033[32mEstudiante: %s, Calificacion final: NA (No Acreditado)\n", nombre);
            } else {
                double promedio = (cal_1 + cal_2 + cal_3) / 3;
                System.out.printf("\033[32mEstudiante: %s, Calificacion final: %.2f\n", nombre, promedio);
            }
            System.out.print("\033[34mDeseas registrar otro estudiante? S/N: ");
            String respuesta = scanner.nextLine();
            if (respuesta.equalsIgnoreCase("N")) break;
        }
        scanner.close();
    }
}
