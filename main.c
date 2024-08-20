#include <stdio.h>

float calcularPGCF(float CT, float DCP) {
    return (((CT / 0.7067) - DCP) / 0.9156) - DCP;
}

int main() {
    char opcaoCh;

    do {
        int numGatos;

        do {
            printf("Digite o número de gatos (deve ser maior que zero): ");
            scanf("%d", &numGatos);
        } while (numGatos <= 0);

        int abaixoDoPeso = 0, pesoIdeal = 0, acimaDoPeso = 0;
        float somaPGCF_abaixoDoPeso = 0, somaPGCF_pesoIdeal = 0, somaPGCF_acimaDoPeso = 0;

        for (int i = 1; i <= numGatos; i++) {
            float CT, DCP;

            do {
                printf("\nGato %d:\n", i);
                printf("Digite a Circunferência Torácica em (cm): ");
                scanf("%f", &CT);
                printf("Digite a Distância entre o Calcâneo e a Patela em (cm): ");
                scanf("%f", &DCP);
            } while (CT <= 0 || DCP <= 0);

            float PGCF = calcularPGCF(CT, DCP);

            if (PGCF < 20) {
                abaixoDoPeso++;
                somaPGCF_abaixoDoPeso += PGCF;
            } else if (PGCF >= 20 && PGCF < 27) {
                pesoIdeal++;
                somaPGCF_pesoIdeal += PGCF;
            } else {
                acimaDoPeso++;
                somaPGCF_acimaDoPeso += PGCF;
            }

            printf("PGCF: %.2f\n", PGCF);
            if (PGCF < 20) {
                printf("O gato está abaixo do peso\n");
            } else if (PGCF >= 20 && PGCF < 27) {
                printf("O gato está no peso ideal\n");
            } else {
                printf("O gato está acima do peso\n");
            }
        }

        printf("\nResultados:\n");

        if (abaixoDoPeso > 0) {
            float mediaPGCF_abaixoDoPeso = somaPGCF_abaixoDoPeso / abaixoDoPeso;
            printf("Abaixo do Peso: %d animais, PGCF médio: %.2f\n", abaixoDoPeso, mediaPGCF_abaixoDoPeso);
        }

        if (pesoIdeal > 0) {
            float mediaPGCF_pesoIdeal = somaPGCF_pesoIdeal / pesoIdeal;
            printf("Peso Ideal: %d animais, PGCF médio: %.2f\n", pesoIdeal, mediaPGCF_pesoIdeal);
        }

        if (acimaDoPeso > 0) {
            float mediaPGCF_acimaDoPeso = somaPGCF_acimaDoPeso / acimaDoPeso;
            printf("Acima do Peso: %d animais, PGCF médio: %.2f\n", acimaDoPeso, mediaPGCF_acimaDoPeso);
        }
        getchar();
        printf("\nPressione a tecla ENTER para repetir o programa ou qualquer outra tecla para sair.\n");
        opcaoCh = getchar();

    } while (opcaoCh == '\n');
}