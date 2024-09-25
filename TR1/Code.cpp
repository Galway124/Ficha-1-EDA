#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <cmath>
int main()
{
	//setlocale(LC_ALL, "");
	FILE* pfile; // Apontador para uma estrutura de um ficheiro
	char nome_ficheiro[] = { "dados.txt" }; // String com o nome do ficheiro
	float* valores; // Apontador para o array din�mico, que guarda os valores
	// lidos do ficheiro
	int nclasses, nlinhas;
	// n� de classes e tamanho da amostra
	int i;
	float menor = 100000;
	float max = 0;
	float soma = 0;
	///////////////////////////////////////////////////////////
	// Leitura dos dados do ficheiro para o array valores
	//
	pfile = fopen(nome_ficheiro, "r"); // Abertura do ficheiro em modo de leitura
	if (pfile == NULL) { // Erro na abertura do ficheiro, termina o programa
		printf("Erro na abertura do ficheiro: %s\n", nome_ficheiro);
		return 1;
	}
	// Leitura da 1� linha com o n�mero de classes do histograma
	fscanf(pfile, "%d", &nclasses);
	// Leitura da 2� linha com o n�mero de elementos da amostra
	fscanf(pfile, "%d", &nlinhas);
	valores = new float[nlinhas]; // cria��o do array din�mico
	if (valores == NULL) { // erro na aloca��o de mem�ria
		printf("Erro na aloca��o de mem�ria\n");
		return 1; // termina o programa
	}
	// Leitura dos elementos da amostra
	for (i = 0; i < nlinhas; i++) {
		fscanf(pfile, "%f,", &valores[i]);
		if (valores[i] <= menor) {
			menor = valores[i];
			//printf("%d", menor);
		}
		if (valores[i] >= max) {
			max = valores[i];
			//printf("%d", menor);
		}
		
		soma += valores[i];
		

	}
	float med = soma / nlinhas;
	//float desv1 = 0;
	/*for (i = 0; i < nlinhas; i++) {
		desv1 += pow(valores[i] - med, 2);
	printf("\n%f", desv);	
	}
	float desv = sqrt((1 / nlinhas));
	printf("%f", menor);
	printf("\n%f", max);
	printf("\n%f", soma);
	printf("\n%f", med);
	printf("classes= %d\nlinhas=%d\n", nclasses, nlinhas);
		printf("%f\n", valores[i]);

	
	*/
	setlocale(LC_ALL, "");
	float intri = max / nclasses;
	float intrf = 0;
	int frqabs = 0;
	float freqabsp = 0;
	printf("Valor\t\t\tFreq.Absoluta\t\t\tFreq.Relativa\t\t\tRepresenta��o Gr�fica\n");
	for (i = 0; i < nclasses; i++) {
		printf("%.1f a ", intrf);
		float intrvinf = intrf;
		intrf += intri;
		printf("%.1f\t", intrf);
		for (int j = 0; j < nlinhas; j++) {
			if (valores[j] <= intrf && valores[j] >= intrvinf) {
				frqabs += 1;
			}
			
			
		}
		printf("\t\t%d\t", frqabs);
		freqabsp = (frqabs * 100) / nlinhas;
		printf("\t\t  %.1f%%", freqabsp);
		//printf("%\n");
		printf("\t\t\t\t\t");
		for (int k = 1; k <= frqabs; k++) {
			printf("*");
		}
		printf("\n");
		frqabs = 0;
		freqabsp = 0;


	}
	float desvs = 0;

	for (int i = 0; i < nlinhas; i++) {
		//printf("\n%f", desvs);
		//desvs += (valores[i] - med) * (valores[i] - med);
		desvs += pow((valores[i] - med), 2);

	}
	float desvp = 0;
	desvp = sqrt(desvs/nlinhas);
	printf("M�dia da Amostra: %.2f", med);
	printf("\nDesvio padr�o da Amostra: %.2f", desvp);

	
	fclose(pfile); // fecho do ficheiro
	///////////////////////////////////////////////////////////
	// C O M P L E T A R
	delete[] valores; // liberta��o da mem�ria ocupada pelo array din�mico
	return 0;
}