#include <bits/stdc++.h>

using namespace std;

struct VetorDinamico{
    int *v, tamanho, capacidade;

    VetorDinamico(){
        tamanho=0, capacidade=1;

        v=(int*)malloc(sizeof(int)*capacidade);
        
    }

    void aumentar(){
        capacidade*=2;

        int *temp=(int*)malloc(sizeof(int)*capacidade);

        for(int i=0; i<tamanho; i++){
            temp[i]=v[i];
        }

        free(v);
        v=temp;
    }

    void inserir(int x){
        if(tamanho==capacidade){
            aumentar();
        }

        v[tamanho++]=x;
    }
};

struct node{
    int val;
    node* next;

    node(int valor){
        val=valor;
        next=NULL;
    }
};

void inserir(int vertice, int valor, node** vizinhos){
    node* novo = new node(valor);

    if(vizinhos[vertice]==NULL){
        vizinhos[vertice]=novo;
    }else{
        node* head = vizinhos[vertice];

        while(head->next != NULL){
            head = head->next;
        }

        head->next = novo;
    }
}

VetorDinamico getNumbers(string &s){
    VetorDinamico nums;
    string linha="";

    for(int i=0; i<s.size(); i++){
        if(s[i]-'0'>=0 && s[i]-'0'<=9){
            linha+=s[i];
        }else{
            nums.inserir(stoi(linha));
            linha="";
        }
    }

    if(!linha.empty()) nums.inserir(stoi(linha));

    return nums;
}

void TopoSort(int n, int grau[], node** vizinhos){
    VetorDinamico fila, resp;

    for(int i=1; i<=n; i++){
        if(!grau[i]){
            fila.inserir(i);
        }
    }

    int pos=0;
    while(pos<fila.tamanho){
        int vertice=fila.v[pos++];
        
        resp.inserir(vertice);

        node* head = vizinhos[vertice];

        while(head!=NULL){
            int viz = head->val;
            
            grau[viz]--;
            
            if(!grau[viz]){
                fila.inserir(viz);
            }

            head = head->next;
        }
    }

    for(int i=0; i<resp.tamanho; i++){
        cout << resp.v[i] << " ";
    }
    cout << endl;
}

int main(){
    int n, m;
    
    cin >> n >> m;
    getchar();

    int grau[n+1];

    for(int i=1; i<=n; i++){
        grau[i]=0;
    }

    node* vizinhos[n+1];

    for(int i=1; i<=n; i++){
        vizinhos[i]=NULL;
    }

    for(int i=1; i<=n; i++){
        string x;
        getline(cin, x);

        if(x.empty()) continue;

        VetorDinamico viz_atual = getNumbers(x);

        for(int j=0; j<viz_atual.tamanho; j++){
            inserir(i, viz_atual.v[j], vizinhos);
            grau[viz_atual.v[j]]++;
        }
    }

    TopoSort(n, grau, vizinhos);

    return 0;
}
