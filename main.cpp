#include <stdio.h>
#include <string.h>

#define MAX_MOVES 32

using namespace std;

int moves[10][3] = {
    {4, 6, -1},     // desde 0
    {6, 8, -1},     // desde 1
    {7, 9, -1},     // desde 2
    {4, 8, -1},     // desde 3
    {3, 9, 0},      // desde 4
    {-1, -1, -1},   // desde 5
    {1, 7, 0},      // desde 6
    {2, 6, -1},     // desde 7
    {1, 3, -1},     // desde 8
    {2, 4, -1}      // desde 9
};

long long memo[10][MAX_MOVES + 1];

long long countPaths(int start, int movesLeft)
{
    if (movesLeft == 0) return 1;
    if (memo[start][movesLeft] != -1) return memo[start][movesLeft];

    long long totalPaths = 0;
    for (int i = 0; i < 3; i++)
    {
        if (moves[start][i] != -1)
        {
            totalPaths += countPaths(moves[start][i], movesLeft - 1);
        }
    }
    memo[start][movesLeft] = totalPaths;
    return totalPaths;
}

int main()
{
    memset(memo, -1, sizeof(memo));

    int steps[] = {1, 2, 3, 5, 8, 10, 15, 18, 21, 23, 32};
    int numSteps = sizeof(steps) / sizeof(steps[0]);

    printf("| N  pasos | Simulacion        |\n");
    printf("|----------|-------------------|\n");
    for (int i = 0; i < numSteps; i++)
    {
        long long totalPaths = 0;

        for (int start = 0; start <= 9; start++)
        {
            totalPaths += countPaths(start, steps[i]);
        }
        printf("| %2d       | %lld             |\n", steps[i], totalPaths);
    }

    return 0;
}