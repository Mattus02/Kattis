// Problem: https://open.kattis.com/problems/ferryloading4

#include <stdio.h>
#include <stdlib.h>

typedef struct car {
    int size;
    char lr;
} car;

#define LEFT 0
#define RIGHT 1

int main()
{
    int cases, ferry_size, total_cars;

    scanf("%d", &cases);

    char input[100];
    while (cases--)
    {
        scanf("%d %d ", &ferry_size, &total_cars);
        ferry_size *= 100;
        car* cars[2] = {malloc(sizeof(car)*total_cars), malloc(sizeof(car)*total_cars)};
        int counts[2] = {0, 0};

        for (int i = 0; i < total_cars; ++i)
        {
            fgets(input, sizeof(input), stdin);
            car tmp;
            sscanf(input, "%d %c", &tmp.size, &tmp.lr);
            if (tmp.lr == 'l') {
                cars[LEFT][counts[LEFT]++] = tmp;
            } else {
                cars[RIGHT][counts[RIGHT]++] = tmp;
            }
        }

        int trips = 0;
        int accum_size = 0;
        int iters[2] = {0, 0};
        int cur = LEFT;
        
        while (iters[LEFT] < counts[LEFT] || iters[RIGHT] < counts[RIGHT])
        {
            while (iters[cur] < counts[cur] && accum_size + cars[cur][iters[cur]].size <= ferry_size) {
                accum_size += cars[cur][iters[cur]++].size;
            }
            ++trips;
            accum_size = 0;
            cur ^= 1;
        }
        printf("%d\n", trips);
        free(cars[LEFT]);
        free(cars[RIGHT]);
    }
}
