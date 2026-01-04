#include <stdio.h>
#include <string.h>

#define LINHASG 10
#define COLUNASG 10

#define LINHASM 3
#define COLUNASM 5

int main() {
    int k = 2;
    int index;
    char buffer[10];
    char *mar[LINHASG][COLUNASG] = {{"A1","B","C","D","E","F","G","H","I","J"}};
    char *cone[3][5];
    char *cruz[3][5];
    char *octaedro[3][5];

    //coloca os numeros de 2 a 10 na primeira coluna referente a cada linha
    for (int i = 1; i < LINHASG; i++){
        index = i + 1;
        sprintf(buffer, "%d", index);
        mar[i][0] = strdup(buffer);
    }

    // coloca "O" onde não tem navio
    for (int i = 0; i < LINHASG; i++) {
        for (int j = 0; j < COLUNASG; j++) {
            if (mar[i][j] == NULL) {
                mar[i][j] = "O";
            }
        }
    }

    /*
    //posicionando navio horinzontal 01
    for (int i = 3; i < 4; i++){
        for (int j = 4; j < 7; j++) {
            mar[i][j] = "#";
        }
    }
    
    //posicionando navio vertical 01
    for (int j = 8; j < 9; j++){
        for (int i = 7; i > 4; i--){
            mar[i][j] = "#";
        }  
    }

    //posionando navio diagonal 01
    for (int i = 5, j = 1; i < 7 || j < 4; i++, j++){
        mar[i][j] = "#";
    }

    //posionando navio diagonal 02
    for (int i = 9, j = 4; i > 7 || j < 7; i--, j++){
        mar[i][j] = "#";
    }
    */

    //Habilidade Cone
    for (int j = 0; j < COLUNASM; j++){
        for (int i = 0; i < LINHASM; i++){
            if ((i + j) >= 2 && (j - i) < 3) {
                cone[i][j] = "#"; 
            } else {
                cone[i][j] = "0";
            }
        }
    }
    
    //Habilidade Cruz
    for (int i = 0; i < LINHASM; i++){
        for (int j = 0; j < COLUNASM; j++){
            if ((i > 0 && i < 2)){
                cruz[i][j] = "#"; 
            } else if (j == 2 && (i + j) % 2 == 0) {
                cruz[i][j] = "#";
            } else {
                cruz[i][j] = "0"; 
            }
        }
    }

    //Habilidade Octaedro
    for (int i = 0; i < LINHASM; i++){
        for (int j = 0; j < COLUNASM; j++){
            if ((i > 0 && i < 2 && j != 0 && j != 4)){
                octaedro[i][j] = "#"; 
            } else if (j == 2 && (i + j) % 2 == 0) {
                octaedro[i][j] = "#";
            } else {
                octaedro[i][j] = "0"; 
            }
        }
    }

    //Inserindo Habilidades
    for (int i = 0; i < LINHASM; i++){
        for (int j = 0; j < COLUNASM; j++){
            mar[2 + i][2 + j] = cone[i][j];
            mar[6 + i][1 + j] = cruz[i][j];
            //mar[6 + i][1 + j] = octaedro[i][j];
        }
    }
    
    
    
    
    // exibição da tabela
    for (int i = 0; i < LINHASG; i++) {
        for (int j = 0; j < COLUNASG; j++) {
            printf(" %s ", mar[i][j]);
        }
        printf("\n");
    }

    return 0;
}
