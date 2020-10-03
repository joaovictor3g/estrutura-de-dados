#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

// Algoritmo CockTailSort
// Esta funcao ordena um vetor A[0..n-1]  
void CocktailSort(int n, int A[]) { 
    bool trocou = true; 
    int inicio = 0; 
    int fim = n-1; 
  
    while (trocou) {  
        trocou = false; 
  
        // varre o vetor da esquerda para a direita, 
        // assim como o bubblesort 
        for (int i = inicio; i < fim; i++) 
            if (A[i] > A[i+1]) { 
                std::swap(A[i], A[i + 1]); 
                trocou = true; 
            } 
  
        // se nenhuma troca ocorreu, entao o vetor
        // ja esta ordenado 
        if (!trocou) 
			break;
		else
			// caso contrario, a variavel 'trocou' 
			// volta a ser 'false' para que a 
			// proxima iteração do loop while ocorra  
			trocou = false; 
  
        // como o elemento na posição 'fim' e todos os 
        // elementos apos ele (se existirem) ja estao
        // ordenados, decrementamos 'fim'  
        fim--; 
  
        // varremos o vetor agora da direita para a esquerda, 
        // fazendo a mesma comparacao que no estagio anterior 
        for (int i = fim-1; i >= inicio; i--) 
            if (A[i] > A[i+1]) { 
                std::swap(A[i],A[i+1]); 
                trocou = true; 
            } 
  
        // incrementamos a variavel inicio', pois no 
        // ultimo loop 'for' o proximo menor elemento 
        // foi colocado no seu devido lugar 
        inicio++; 
    } 
} 

// Algoritmo BubbleSort
// Ordena um vetor A[0..n-1]
void BubbleSort(int n, int A[]) {   
    for (int i = 0; i < n-1; i++)      
		for (int j = 0; j < n-i-1; j++)  
			if (A[j] > A[j+1])  
				std::swap(A[j], A[j+1]);  
}

/** 
 * Função que gera arquivos binarios, cada um contendo numeros aleatorios
 */
void gera_dados(int num_iteracoes, const int vetor_tam[]) 
{
	for(int iteracao = 0; iteracao < num_iteracoes; iteracao++) {
		for(int semente = 0; semente < 5; semente++) {	
			std::string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[iteracao];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
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
void ler_dados(int n, int A[], const char *nomeArquivo) 
{	
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++) 
	{
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor
	}
	fin.close(); // fecha o arquivo de leitura
}


/***************************** MAIN ********************************/
int main() 
{ 
	// Os tamanhos dos seis vetores a serem testados estao
	// guardados neste vetor 'tam'
	const int tam[] = {500,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000};
	
	int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'
	
	// Etapa 1: Gerar arquivos contendo números aleatórios
	gera_dados(TOTAL_N, tam);
	
	// ------------------------------------------------------------
	// Etapa 2 - Execução do CocktailSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs("resultados/resultadoCocktail.txt", std::ofstream::out ); // abre arquivo de resultados do cocktail
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_cocktail = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// CocktailSort ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();
		
			CocktailSort(tamanho_vetor, vetor); // ordena o vetor usando o CocktailSort
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_cocktail = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media_cocktail += duracao_cocktail;
			
		}
		
		duracao_media_cocktail = duracao_media_cocktail / 5.0;
		cout << "[Cocktail] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_cocktail << " microssegundos" << endl;
		ofs << tamanho_vetor << " " << duracao_media_cocktail << "\n"; // grava no arquivo de resultados do cocktail
	}
	
	ofs.close(); // fecha arquivo de resultados do CockTail Sort
	// ------------------------------------------------------------
	
	
	// ------------------------------------------------------------
	// Etapa 3 - Execução do BubbleSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	std::ofstream ofs2("resultados/resultadoBubble.txt", std::ofstream::out ); // abre arquivo de resultados do bubblesort
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_bubble = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// BubbleSort ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = std::chrono::high_resolution_clock::now();
		
			BubbleSort(tamanho_vetor, vetor); // ordena o vetor usando o CocktailSort
		
			// obtendo o tempo final
			auto fim2 = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_bubble = std::chrono::duration_cast<std::chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_bubble += duracao_bubble;			
		}	
		
		duracao_media_bubble = duracao_media_bubble / 5.0;
		cout << "[Bubble] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubble << " microssegundos" << endl;
		ofs2 << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	}
	
	ofs2.close(); // fecha arquivo de resultados do Bubble Sort
	// ------------------------------------------------------------
	
	return 0;
}
