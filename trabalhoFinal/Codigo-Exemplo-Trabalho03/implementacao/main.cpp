#include <iostream>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include "vetorOrdenado.h"
#define TAM 10

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
	// const int sizes[] = {100, 200, 300, 400, 500, 600, 700, 800};
    int total_sizes = sizeof(sizes)/sizeof(sizes[0]);    


    // Etapa 1: Gerar arquivos contendo números aleatórios
	gera_dados(total_sizes, sizes);
    // ------------------------------------------------------------
	// Etapa 2 - Execução do CocktailSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	// std::ofstream ofs("resultados/resultadoInsertionSort.txt", std::ofstream::out);
    // for(int iteracao = 0; iteracao < total_sizes; iteracao++) {
		
	// 	long double duracao_media_bubble = 0.0;
	// 	int tamanho_vetor = sizes[iteracao]; // pega o tamanho do vetor para esta iteracao
	// 	int vet[tamanho_vetor]; // cria vetor a ser ordenado
		
	// 	// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
	// 	// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
	// 	// Chamar o bubble sort para ordena-los e, entao, calcular o tempo medio de 
	// 	// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
	// 	for(int semente = 0; semente < 5; semente++) {	
	// 		string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
	// 		ler_dados(tamanho_vetor, vet, nome_arquivo.c_str());
			
	// 		// BubbleSort ------------------------------------------------------
	// 		// obtendo o tempo inicial
	// 		auto ini = std::chrono::high_resolution_clock::now();
	// 	    iteractive_insertion_sort(vet, tamanho_vetor); // ordena o vetor usando o bubbleSort
	// 		// print(vet, TAM, "iterativamente", "recursivamente");		
	// 		// obtendo o tempo final
	// 		auto fim = std::chrono::high_resolution_clock::now();
		
	// 		// obtendo a duração total da ordenação
	// 		auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
	// 		duracao_media_bubble += duracao_bubble;
			
	// 	}
		
	// 	duracao_media_bubble = duracao_media_bubble / 5.0;
	// 	cout << "[Insertion Sort] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
	// 	ofs << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do cocktail
	// }
	
	// ofs.close(); // fecha arquivo de resultados do CockTail Sort
	// ------------------------------------------------------------ 
	
	// ------------------------------------------------------------
	// Selection Sort
	// std::ofstream ofs2("resultados/resultadoSelectionSort.txt", std::ofstream::out);
    // for(int iteracao = 0; iteracao < total_sizes; iteracao++) {
		
	// 	long double duracao_media_bubble = 0.0;
	// 	int tamanho_vetor = sizes[iteracao]; // pega o tamanho do vetor para esta iteracao
	// 	int vet[tamanho_vetor]; // cria vetor a ser ordenado
		

	// 	for(int semente = 0; semente < 5; semente++) {	
	// 		string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
	// 		ler_dados(tamanho_vetor, vet, nome_arquivo.c_str());
			
	// 		auto ini = std::chrono::high_resolution_clock::now();
	// 	    iteractive_selection_sort(vet, tamanho_vetor); // ordena o vetor usando o bubbleSort
			
	// 		auto fim = std::chrono::high_resolution_clock::now();
		
	// 		// obtendo a duração total da ordenação
	// 		auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
	// 		duracao_media_bubble += duracao_bubble;
			
	// 	}
		
	// 	duracao_media_bubble = duracao_media_bubble / 5.0;
	// 	cout << "[Selection Sort] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
	// 	ofs2 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	// }
	
	// ofs2.close(); // fecha arquivo de resultados do CockTail Sort
	int fim = 0;
	while(fim < 1) {
		int* vet = new int[TAM];
		for(int i = 0; i < TAM; i++)
		vet[i] = rand()%100;


		cout << "Vetor original:";
		for(int i = 0; i < TAM; i++)
		cout << vet[i] << " ";
		cout << endl;
		int key = vet[1];
		int current = 1;
		int index = 0;
		int size = TAM;
		iteractive_quick_sort(vet, 0, size);

		print(vet, TAM);
		cout << endl;

		delete[] vet;
		fim++;
	}

	// std::ofstream ofs3("resultados/resultadoInsertionSortRec.txt", std::ofstream::out);
    // for(int iteracao = 0; iteracao < total_sizes; iteracao++) {
		
	// 	long double duracao_media_bubble = 0.0;
	// 	int tamanho_vetor = sizes[iteracao]; // pega o tamanho do vetor para esta iteracao
	// 	int vet[tamanho_vetor]; // cria vetor a ser ordenado
		

	// 	for(int semente = 0; semente < 5; semente++) {	
	// 		string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
	// 		ler_dados(tamanho_vetor, vet, nome_arquivo.c_str());
			
	// 		auto ini = std::chrono::high_resolution_clock::now();
	// 	    recursive_insertion_sort(vet, tamanho_vetor, 0, vet[1], 1); // ordena o vetor usando o bubbleSort
	// 		// insertionSortRecursive(vet, tamanho_vetor);
	// 		auto fim = std::chrono::high_resolution_clock::now();
		
	// 		// obtendo a duração total da ordenação
	// 		auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
	// 		duracao_media_bubble += duracao_bubble;
			
	// 	}
		
	// 	duracao_media_bubble = duracao_media_bubble / 5.0;
	// 	cout << "[Insertion Sort Recursivo] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
	// 	ofs3 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	// }
	
	// ofs3.close(); // fecha arquivo de resultados do CockTail Sort

	// std::ofstream ofs4("resultados/resultadoSelectionSortRec.txt", std::ofstream::out);
    // for(int iteracao = 0; iteracao < total_sizes; iteracao++) {
		
	// 	long double duracao_media_bubble = 0.0;
	// 	int tamanho_vetor = sizes[iteracao]; // pega o tamanho do vetor para esta iteracao
	// 	int vet[tamanho_vetor]; // cria vetor a ser ordenado
		

	// 	for(int semente = 0; semente < 5; semente++) {	
	// 		string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
	// 		ler_dados(tamanho_vetor, vet, nome_arquivo.c_str());
			
	// 		auto ini = std::chrono::high_resolution_clock::now();
	// 	    recursive_selection_sort(vet, tamanho_vetor, 0, vet[0], 0); // ordena o vetor usando o bubbleSort
			
	// 		auto fim = std::chrono::high_resolution_clock::now();
		
	// 		// obtendo a duração total da ordenação
	// 		auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
	// 		duracao_media_bubble += duracao_bubble;
			
	// 	}
		
	// 	duracao_media_bubble = duracao_media_bubble / 5.0;
	// 	cout << "[Selection Sort Recursivo] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
	// 	ofs4 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	// }
	
	// ofs4.close(); // fecha arquivo de resultados do Selection Sort Recursivo
	
	// // Merge Sort Recursivo
	// std::ofstream ofs5("resultados/resultadoMergeSortRec.txt", std::ofstream::out);
    // for(int iteracao = 0; iteracao < total_sizes; iteracao++) {
		
	// 	long double duracao_media_bubble = 0.0;
	// 	int tamanho_vetor = sizes[iteracao]; // pega o tamanho do vetor para esta iteracao
	// 	int vet[tamanho_vetor]; // cria vetor a ser ordenado
		

	// 	for(int semente = 0; semente < 5; semente++) {	
	// 		string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
	// 		ler_dados(tamanho_vetor, vet, nome_arquivo.c_str());
			
	// 		auto ini = std::chrono::high_resolution_clock::now();
	// 	    recursive_merge_sort(vet, 0, tamanho_vetor); // ordena o vetor usando o mergeSort
			
	// 		auto fim = std::chrono::high_resolution_clock::now();
		
	// 		// obtendo a duração total da ordenação
	// 		auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
	// 		duracao_media_bubble += duracao_bubble;
			
	// 	}
		
	// 	duracao_media_bubble = duracao_media_bubble / 5.0;
	// 	cout << "[Merge Sort Recursivo] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
	// 	ofs5 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	// }
	
	// ofs5.close();

	// // // merge Sort iterativo
	// std::ofstream ofs6("resultados/resultadoMergeSortIter.txt", std::ofstream::out);
    // for(int iteracao = 0; iteracao < total_sizes; iteracao++) {
		
	// 	long double duracao_media_bubble = 0.0;
	// 	int tamanho_vetor = sizes[iteracao]; // pega o tamanho do vetor para esta iteracao
	// 	int vet[tamanho_vetor]; // cria vetor a ser ordenado
		

	// 	for(int semente = 0; semente < 5; semente++) {	
	// 		string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
	// 		ler_dados(tamanho_vetor, vet, nome_arquivo.c_str());
			
	// 		auto ini = std::chrono::high_resolution_clock::now();
	// 	    recursive_merge_sort(vet, 0, tamanho_vetor); // ordena o vetor usando o mergeSort
	// 		auto fim = std::chrono::high_resolution_clock::now();
		
	// 		// obtendo a duração total da ordenação
	// 		auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
	// 		duracao_media_bubble += duracao_bubble;
			
	// 	}
		
	// 	duracao_media_bubble = duracao_media_bubble / 5.0;
	// 	cout << "[Merge Sort Iterativo] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
	// 	ofs6 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	// }
	
	// ofs6.close();
}