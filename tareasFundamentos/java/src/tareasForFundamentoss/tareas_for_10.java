// 10. Encuentre la serie alternada para 1/50
//Serie alternada = 1 – 1/2 + 1/3 – 1/4 + 1/5 – 1/6 + 1/7 – 1/8 +......................
//Imprima el resultado de la sumatoria
public class tareas_for_10 { // recicle la tarea 9
    public static void main(String[] args) {
        System.out.printf("Serie geometrica = 1/1");
        double sumatoria = 1/1;
        for (double n = 2;
        n<=50;
        n++) {
            double signo = Math.pow(-1,n); // lo hice en una tarea anterior es para intercalar signos +-+-
            System.out.printf(" + (%.0f/%.0f)",-signo, n); //-signo pq empieza en 2 y no en 1
            sumatoria += signo*(1/n); // empieza en 1 (1/1) pq sumatoria vale 1 y de ahi sigue 1/2+1/3... es acumulativa
        }
        System.out.println("\nSigma = " + sumatoria);
        // Sigma = 1.3167528394240826
    }

}

