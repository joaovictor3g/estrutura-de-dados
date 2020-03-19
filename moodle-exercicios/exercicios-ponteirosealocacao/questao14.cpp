#include <iostream>

using namespace std;

struct Produto{
    int id_produto;
    char nome[50];
    int estoque;
    double preco;

};

Produto *preencher(Produto *prod, int qtd_prod) {
    for(int i = 0; i < qtd_prod; i++) {
        system("clear");

        cout << "Digite o Id do " << i+1<< "° produto: " << endl;
        cin >> prod[i].id_produto;
        
        cout << "Digite o nome do " << i+1 << "° produto: " << endl;
        cin.ignore();
        cin.get(prod[i].nome, 50);
        
        cout << "Digite a quantidade em estoque: " << endl;
        cin >> prod[i].estoque;

        cout << "Digite o preço deste produto: " << endl;
        cin >> prod[i].preco;
    
    }

    return prod;
}

void maior_preco(Produto *prod, int qtd_prod) {
    double bigger_price = prod[0].preco;
    
    for(int i = 0; i < qtd_prod; i++) {
        if(bigger_price <= prod[i].preco) {
            bigger_price = prod[i].preco;
        }
    }
    
    cout << "\nProduto com maior preço: " << endl;
    for(int i = 0; i < qtd_prod; i++) {
        if(bigger_price == prod[i].preco) {
            cout << "ID do produto: " << prod[i].id_produto << endl;
            cout << "Nome do produto: " << prod[i].nome << endl;
            cout << "Quantidade em estoque: " << prod[i].estoque << endl;
            cout << "Preço: " << prod[i].preco << endl;

        }
    }

}

void mais_em_estoque(Produto *prod, int qtd_prod) {
    int qtd_estoque = prod[0].estoque;

    for(int i = 0; i < qtd_prod; i++) {
        if(qtd_estoque <= prod[i].estoque) {
            qtd_estoque = prod[i].estoque;
        }
    }
    
    cout << "\nProduto com maior quantidade em estoque: " << endl;
    for(int i = 0; i < qtd_prod; i++) {
        if(qtd_estoque == prod[i].estoque) {
            cout << "ID do produto: " << prod[i].id_produto << endl;
            cout << "Nome do produto: " << prod[i].nome << endl;
            cout << "Quantidade em estoque: " << prod[i].estoque << endl;
            cout << "Preço: " << prod[i].preco << endl;

        }
    }    
}

int main() {
    int qtd_produtos = 0;
    cin >> qtd_produtos;

    Produto *produtos = new (nothrow) Produto[qtd_produtos];

    if(produtos == nullptr) {
        cout << "Alocação mal-sucedida" << endl;
        exit(1);
    }
    produtos = preencher(produtos, qtd_produtos);

    maior_preco(produtos, qtd_produtos);
    mais_em_estoque(produtos, qtd_produtos);

    delete[] produtos;
    return 0;
}