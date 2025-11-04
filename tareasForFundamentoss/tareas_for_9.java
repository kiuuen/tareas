//9. Encuentre la serie geométrica para 1/50
//Serie geométrica = 1/1 +1/2 +1/4 + 1/6 +1/8 + 1/10 +1/12 +......... 
//Imprima el resultado de la sumatoria.
//Σ = 2.90797909

public class tareas_for_9 {
    public static void main(String[] args) {
        System.out.printf("Serie geometrica = 1/1");
        double sumatoria = 1/1;
        for (double n = 2;
        n<=50;
        n++) {
            System.out.printf(" + 1/%.0f",n);
            sumatoria += (1/n); // empieza en 1 (1/1) pq sumatoria vale 1 y de ahi sigue 1/2+1/3... es acumulativa
            n++; // para q vaya de 2 en 2 apartir del 2
        }
        System.out.println("\nSigma = " + sumatoria);
        // Sigma = 2.907979088876753
    }

}
