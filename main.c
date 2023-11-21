#include <stdio.h>

void exibiirTabuleiro(int layoutVelha[3][3]){
    printf(" 1 2 3\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; ++j) {
            if (layoutVelha[i][j] == 0){
                printf("- ");
            } else if (layoutVelha[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    int restartgame;
    do {
        int layoutVelha[3][3] = {
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}
        };

        int playerNow = 1;


        do {
            exibiirTabuleiro(layoutVelha);

            int row, column;

            do {
                printf("Jogador %d, Informe a linha que deseja jogar : \n", playerNow);
                scanf("%d", &row);

                printf("Jogador %d, Informe a coluna que deseja jogar : \n", playerNow);
                scanf("%d", &column);
            } while (row < 1 || row > 3 || column < 1 || column > 3 || layoutVelha[row - 1][column - 1] != 0);

            layoutVelha[row - 1][column - 1] = playerNow;

            // Linhas e colunas
            for (int i = 0; i < 3; ++i) {
                if (layoutVelha[i][0] == playerNow && layoutVelha[i][1] == playerNow && layoutVelha[i][2] == playerNow){
                    exibiirTabuleiro(layoutVelha);
                    printf("Jogador %d venceu!\n", playerNow);
                    return 0;
                }

                if (layoutVelha[0][i] == playerNow && layoutVelha[1][i] == playerNow && layoutVelha[2][i] == playerNow) {
                    exibiirTabuleiro(layoutVelha);
                    printf("Jogador %d venceu!\n", playerNow);
                    return 0;
                }
            }

            if (layoutVelha[0][0] == playerNow && layoutVelha[1][1] == playerNow && layoutVelha[2][2] == playerNow) {
                exibiirTabuleiro(layoutVelha);
                printf("Jogador %d venceu!\n", playerNow);
                return 0;
            }
            if (layoutVelha[0][2] == playerNow && layoutVelha[1][1] == playerNow && layoutVelha[2][0] == playerNow) {
                exibiirTabuleiro(layoutVelha);
                printf("Jogador %d venceu!\n", playerNow);
                return 0;
            }

            int empate = 1;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (layoutVelha[i][j] == 0){
                        empate = 0;
                    }
                }
            }

            if (empate){
                exibiirTabuleiro(layoutVelha);
                printf("O jogo terminou em empate.\n");
                return 0;
            }

            playerNow = (playerNow == 1) ? 2 : 1; // Isso equivalente a isso :

            /*
             *
             * if (playerNow == 1) {
                    playerNow = 2;
                } else {
                    playerNow = 1;
                 }
             *
             *
             *
             * */

        } while (1);

        char restart;
        printf("Deseja jogar novamente? (S/N): ");
        scanf(" %c", &restart);

        if (restart == 'S' || restart == 's') {
            restartgame = 1;
        } else {
            restartgame = 0;
            printf("Saindo...\n");
        }


    } while (restartgame);

    return 0;
}
