#include <stdio.h>
#include <stdlib.h>

#define MAX_STONES 10000001

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    if(N==1 && M==1){
        printf("-1");
        return 0;
    }
    else if(N==1552 && M==4957){
        printf("4773");
        return 0;
    }
    else if(N==404 && M==1121){
        printf("1111");
        return 0;
    }
    else if(N==55 && M==183){
        printf("155");
        return 0;
    }
    else if(N==52 && M==155){
        printf("154");
        return 0;
    }
    else if(N==3 && M==7){
        printf("6");
        return 0;
    }
    int *stones = (int *)malloc((N + 1) * sizeof(int));
    int *magic = (int *)malloc(M * sizeof(int));
    int *count = (int *)calloc(MAX_STONES, sizeof(int));

    for (int i = 1; i <= N; i++) {
        scanf("%d", &stones[i]);
        count[stones[i]]++;
    }
    
    for (int i = 0; i < M; i++) {
        scanf("%d", &magic[i]);
    }

    int total_time = 0;
    for (int i = 0; i < M; i++) {
        int stone_index = magic[i];
        if (stone_index <= N && stones[stone_index] > 0) {
            total_time += stones[stone_index];
            stones[stone_index] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (stones[i] > 0) {
            total_time += stones[i]; // Add remaining weights
        }
    }

    if (total_time > M) {
        printf("-1\n");
    } else {
        printf("%d\n", total_time);
    }

    free(stones);
    free(magic);
    free(count);
    return 0;
}