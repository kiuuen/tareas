// 3. Sumatoria encontrar la sumatoria de una serie de números, el límite se le solicita al 
//usuario. (Puede usar la fórmula de Gauss).
//Escriba el número para sumatoria: 8 
//Σ= 1 + 2 + 3 +4 +5 + 6 + 7 +8
//Resultado: 36
//Escriba el número para sumatoria: 100
//Σ= 1 + 2 + 3 +4 +5 + 6 + 7 + 8 +9 + 10 + 11 +12 + …. + 100
//Resultado: 505
import java.util.Scanner; // USO SCANNER PORQ NO ME EJECUTA CON CONSOLE
public class tareas_for_3 {
    public static void main(String[] args) {
        Scanner Sc = new Scanner(System.in); 
        System.out.print("Ecriba el numero para sumatoria: " +
        "Σ = ");
        int limiteSumatoria = Sc.nextInt();  
        int resultado = 0;
        System.out.printf("Sumatoria = 1");
        // Este ejercicio es curioso, una sumatoria en programacion no es mas que un for!
        for (int n = 2;
        n <= limiteSumatoria;
        n++) { // esto es como una Σ con limite n que en este caso es lo que ponga en input
            System.out.printf(" + "+n);
            resultado = (limiteSumatoria*(limiteSumatoria+1))/2; // formula
        }
        System.out.println("\nResultado = "+ resultado);
        Sc.close();
    }
}
