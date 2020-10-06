#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include "vetorOrdenado.h"

using namespace std;

void gera_dados(int num_iteracoes, const int vetor_tam[]) {
	for(int iteracao = 0; iteracao < num_iteracoes; iteracao++) {
		for(int semente = 0; semente < 5; semente++) {	
			std::string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[iteracao];
			for(int i = 0; i < tamanho_vetor; i++) {
				r = rand(); // gera numero aleatorio
				fout.write((char*)&r, sizeof(r));
			}
			fout.close();
		}
	}
}

/*
 * Recebe um vetor de inteiros A[0..n-1] como argumento e o preenche
 * com os n inteiros contidos no arquivo binario de mesmo nome que a 
 * string nomeArquivo
 */
void ler_dados(int n, int A[], const char *nomeArquivo) {	
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++) {
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor
	}
	fin.close(); // fecha o arquivo de leitura
}

int main() {
    srand(time(NULL));

    const int sizes[] = {500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000};
    int total_sizes = sizeof(sizes)/sizeof(sizes[0]);    


    // Etapa 1: Gerar arquivos contendo números aleatórios
	gera_dados(total_sizes, sizes);
    // ------------------------------------------------------------
	// Etapa 2 - Execução do CocktailSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs("resultados/resultadoInsertionSort.txt", std::ofstream::out);
    for(int iteracao = 0; iteracao < total_sizes; iteracao++) {
		
		long double duracao_media_bubble = 0.0;
		int tamanho_vetor = sizes[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vet[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o bubble sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) {	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vet, nome_arquivo.c_str());
			
			// BubbleSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		    iteractive_insertion_sort(vet, tamanho_vetor); // ordena o vetor usando o bubbleSort
			// print(vet, TAM, "iterativamente", "recursivamente");		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_bubble += duracao_bubble;
			
		}
		
		duracao_media_bubble = duracao_media_bubble / 5.0;
		cout << "[Insertion Sort] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
		ofs << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do cocktail
	}
	
	ofs.close(); // fecha arquivo de resultados do CockTail Sort
	// ------------------------------------------------------------ 
	
	// ------------------------------------------------------------
	// Bubble Sort Recursivo
	// std::ofstream ofs2("resultados/resultadoBubbleSortRecursivo.txt", std::ofstream::out);
    // for(int iteracao = 0; iteracao < 4; iteracao++) {
		
	// 	long double duracao_media_bubble = 0.0;
	// 	int tamanho_vetor = sizes[iteracao]; // pega o tamanho do vetor para esta iteracao
	// 	int vet[tamanho_vetor]; // cria vetor a ser ordenado
		

	// 	for(int semente = 0; semente < 5; semente++) {	
	// 		string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
	// 		ler_dados(tamanho_vetor, vet, nome_arquivo.c_str());
			
	// 		auto ini = std::chrono::high_resolution_clock::now();
	// 	    recursive_bubble_sort(vet, tamanho_vetor, tamanho_vetor); // ordena o vetor usando o bubbleSort
			
	// 		auto fim = std::chrono::high_resolution_clock::now();
		
	// 		// obtendo a duração total da ordenação
	// 		auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
	// 		duracao_media_bubble += duracao_bubble;
			
	// 	}
		
	// 	duracao_media_bubble = duracao_media_bubble / 5.0;
	// 	cout << "[BubbleSort Recursivo] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
	// 	ofs2 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	// }
	
	// ofs2.close(); // fecha arquivo de resultados do CockTail Sort

}