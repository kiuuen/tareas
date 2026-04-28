/*
 * EJERCICIO 20B: Subir escaleras (Estilo LeetCode #70)
 * 
 * TAREA:
 * Tienes N escalones. En cada paso puedes subir 1 o 2 escalones.
 * ¿De cuántas formas distintas puedes llegar al tope?
 * 
 * EJEMPLOS:
 * n=1  → 1 forma
 * n=2  → 2 formas
 * n=3  → 3 formas
 * n=5  → 8 formas
 * n=10 → 89 formas
 * 
 * BONUS: ¿Y si pudieras subir 1, 2 o 3 escalones?
 */

// Tu código aquí

#include <iostream>
#include <vector>
#include <algorithm>

int steps(int N) { // so its just fibonacci cause ask for 1-2 steps
    std::vector<int> dp(N+1);
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2]; // + dp[i-3] with 3 steps
    }
    return dp[N];

}
int main() {
    int number = 10;
    std::cout << "steps required for " << number << " steps: " << steps(number) << std::endl;
    return 0;
}