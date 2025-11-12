//4. Sumatoria de 1/1 + 1⁄2 + 1/3 + 1⁄4 + 1/5 +1/6 +1/7 +...+ 1/50.
//Σ= Calcular el resultado.
//Σ= ?
public class tareas_for_4 {
    public static void main(String[] args) {
    System.out.print("Sigma = Calcular resultado\nSigma = 1/1"); // no me detecta Σ 
    double resultado = 1.0;
    for (int n = 2;
    n<=50;
    n++) {
        System.out.printf(" + 1/"+n);
        resultado += 1.0 / n; // eñ += acumula todos los resultados los va sumando 
    }
    System.out.println("\nResultado = "+resultado+1); // + 1 porq ue n = 2 es solo por que luego al final imprime 1/50 + por eso corregi
    } // lanza Resultado = 4.4992053383294231

}
