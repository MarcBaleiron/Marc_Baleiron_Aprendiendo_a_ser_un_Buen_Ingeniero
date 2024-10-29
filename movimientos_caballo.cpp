#include "movimientos_caballo.h"

int movimientos[10][3] =
{
    {4, 6, -1},     // 0 puede moverse a 4 y 6
    {6, 8, -1},     // 1 puede moverse a 6 y 8
    {7, 9, -1},     // 2 puede moverse a 7 y 9
    {4, 8, -1},     // 3 puede moverse a 4 y 8
    {3, 9, 0},      // 4 puede moverse a 3, 9 y 0
    {-1, -1, -1},   // 5 no tiene movimientos
    {1, 7, 0},      // 6 puede moverse a 1, 7 y 0
    {2, 6, -1},     // 7 puede moverse a 2 y 6
    {1, 3, -1},     // 8 puede moverse a 1 y 3
    {2, 4, -1}      // 9 puede moverse a 2 y 4
};

int conteo (int n) {
    int dp[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int nuevo_dp[10];

    for (int paso = 0; paso < n; ++paso)
    {
        for (int i = 0; i < 10; ++i) nuevo_dp[i] = 0;

        for (int numero = 0; numero < 10; ++numero)
        {
            for (int j = 0; movimientos[numero][j] != -1; ++j)
            {
                int movimiento = movimientos[numero][j];
                nuevo_dp[movimiento] += dp[numero];
            }
        }

        for (int i = 0; i < 10; ++i) dp[i] = nuevo_dp[i];
    }

    int total = 0;
    for (int i = 0; i < 10; ++i) total += dp[i];

    return total;
}