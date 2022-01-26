#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dificuldade;
	int valor1;
	int valor2;
	int operacao;
	int resultado;
} Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int pontos = 0;

int main(){
	srand(time(NULL));

	jogar();

	return 0;
}

void mostrarInfo(Calcular calc){
	char op[25];

	if(calc.operacao == 0){
		sprintf(op,"Somar");
	}else if(calc.operacao == 1){
		sprintf(op,"Diminuir");
	}else if(calc.operacao == 2){
		sprintf(op,"Multiplicar");
	}else{
		sprintf(op,"Operação desconhecida!");
	}
	printf("Valor 1: %d\n",calc.valor1);
	printf("Valor 2: %d\n",calc.valor2);
	printf("Dificuldade: %d\n",calc.dificuldade);
	printf("Operacao: %s\n",calc.operacao,op);
}

int somar(int resposta, Calcular calc){
	int resultado = calc.valor1 + calc.valor2;
	calc.resultado = resultado;
	int certo = 0;

	if(resposta == calc.resultado){
		printf("Resposta Correta!\n");
		certo = 1;
	}else{
		printf("Resposta Errada!\n");
	}

	printf("%d + %d = %d\n", calc.valor1, calc.valor2,calc.resultado);

	return certo;
}

int diminuir(int resposta, Calcular calc){
	int resultado = calc.valor1 - calc.valor2;
	calc.resultado = resultado;
	int certo = 0;

	if(resposta == calc.resultado){
		printf("Resposta Correta!\n");
		certo = 1;
	}else{
		printf("Resposta Errada!\n");
	}

	printf("%d - %d = %d\n", calc.valor1, calc.valor2,calc.resultado);

	return certo;
}

int multiplicar(int resposta, Calcular calc){
        int resultado = calc.valor1 * calc.valor2;
        calc.resultado = resultado;
        int certo = 0;

        if(resposta == calc.resultado){
                printf("Resposta Correta!\n");
                certo = 1;
        }else{
                printf("Resposta Errada!\n");
        }

        printf("%d * %d = %d\n", calc.valor1, calc.valor2,calc.resultado);

        return certo;
}

void jogar(){
	Calcular calc;
	int dificuldade;
	printf("[1][2][3][4]\n");
	printf("Informe o nível de dificuldade desejado:");
	scanf("%d", &dificuldade);
	calc.dificuldade = dificuldade;
	calc.operacao = rand() % 3;

	if(calc.dificuldade == 1){
		calc.valor1 = rand() % 11;
		calc.valor2 = rand() % 11;
	}else if(calc.dificuldade == 2){
		calc.valor1 = rand() % 101;
		calc.valor2 = rand() % 101;
	}else if(calc.dificuldade == 3){
		calc.valor1 = rand() % 1001;
		calc.valor2 = rand() % 1001;
	}else if(calc.dificuldade == 4){
		calc.valor1 = rand() % 10001;
		calc.valor2 = rand() % 10001;
	}else{
		calc.valor1 = rand() % 100001;
		calc.valor2 = rand() % 100001;
	}

	int resposta;
	if(calc.operacao == 0){
		printf("%d + %d\n", calc.valor1, calc.valor2);
		printf("Informe o resultado da operação acima:");
		scanf("%d", &resposta);
		if(somar(resposta,calc)){
			pontos += 1;
			printf("Pontuação:[%d]\n", pontos);
		}
	}else if(calc.operacao == 1){
		printf("%d - %d\n", calc.valor1, calc.valor2);
                printf("Informe o resultado da operação acima:");
                scanf("%d", &resposta);
                if(diminuir(resposta,calc)){ 
                        pontos += 1;
                        printf("Pontuação:[%d]\n", pontos);
                }
        }else if(calc.operacao == 2){
                printf("%d * %d\n", calc.valor1, calc.valor2);
                printf("Informe o resultado da operação acima:");
                scanf("%d", &resposta);
                if(multiplicar(resposta,calc)){ 
                        pontos += 1;
                        printf("Pontuação:[%d]\n", pontos);
                }
        }else{
		printf("A operação [%d] não é reconhecida.\n", calc.operacao);
	}
	int continuar;
	printf("Deseja continuar jogando? [1 - Sim ; 2 - Não]:");
	scanf("%d",&continuar);
	if(continuar == 1){
		jogar();
	}else{
		printf("Você finalizou com [%d] pontos.\n", pontos);
		printf("Até a proxima!\n");
	}
}