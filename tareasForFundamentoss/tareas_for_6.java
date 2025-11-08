// 6. Calcule el valor de π a partir de la siguiente serie infinita (serie Gregory-Leibniz): 
//π = 4/1 -4 /3 + 4/5 -4/7 + 4/9 – 4/11 +............ 
//Para 20 iteraciones e imprimir el resultado

public class tareas_for_6 {
    public static void main(String[] args) {
        System.out.println("La suma es:");
        double resultado = 0;
        for (int n = 1;
        n <= 100000;
        n++) {
            double signo = Math.pow(-1,n/2);// elevo -1 a la n/2, eso para tener signos + - + - intercalados, y n/2 para deshacer lo que hago despues que es ir de 2 en 2, ahora voy de 1 en 1
            System.out.printf(" + (%.0f/%.0f)", (signo*4), (double)n); // paso n a double para poder usar el %.0f en los dos
            resultado += (signo*4)/n;
            n = n+1; // n va de 2 en 2
        }
        System.out.println("\nPi = "+resultado);
        // para 20 iteraciones da 3.0418396189294032
        // para 10,000 iteraciones da 3.141392653591791
        // para 100,000 iteraciones da 3.1415726535897814
    }
}
