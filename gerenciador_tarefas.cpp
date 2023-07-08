#include <iostream>
#include <string>
#include <list>

using namespace std;

//criação da classe Tarefa abaixo, para podermos armazenar as tarefas em uma lista posteriormente

class Tarefa {

public:
	string nome;
    int indice;
    bool concluida;
    //Criação do metodo adicionar abaixo, para podermos adicionar tarefas na lista.
    void Adicionar(string nome, int indice) {
        this->nome = nome;
        this->indice = indice;
        this->concluida = false;
    }
};
//Função abaixo criada para exibir as tarefas. Recebe como parametro o endereço de uma lista, para evitar que sejam feitas cópias desnecessárias. Constante pois
//Essa função não altera a lista
void ExibirListaTarefas(const list<Tarefa>& listaTarefas) {
    list<Tarefa>::const_iterator it;//iterator para manipular a lista, pode-se interpretar como um ponteiro
    for (it = listaTarefas.begin(); it != listaTarefas.end(); ++it) {
        const Tarefa& tarefa = *it;
        cout << "Nome: " << tarefa.nome << ", Indice: " << tarefa.indice << endl;
    }
}
//Função abaixo criada para exibir as pendencias. Recebe como parametro o endereço de uma lista, para evitar que sejam feitas cópias desnecessárias.
//Constante pois essa função não altera a lista
void ExibirPendencias(const list<Tarefa>& listaTarefas){
	list<Tarefa>::const_iterator it;
    for (it = listaTarefas.begin(); it != listaTarefas.end(); ++it) {
        const Tarefa& tarefa = *it;
        if(tarefa.concluida == false){
        	cout << "Nome: " << tarefa.nome << ", Indice: " << tarefa.indice << endl;
    	}
    }
}
//Função abaixo marca uma tarefa como concluida, recebe o endereço de uma lista para evitar cópias desnecessárias. Recebe também o indice digitado pelo usuario
//Para poder buscar a tarefa em questão. O endereço aqui não é constante pois a lista será alterada.
void Concluir(list<Tarefa>& listaTarefas, int indice){
	bool encontrou = false;//Valor booleano para poder checar se o indice digitado é válido
	//No for abaixo, o iterator é colocado dentro da lista, pois é iniciado com o valor inicial da mesma. A cada iteração, ele passa para o próximo item.
	for (list<Tarefa>::iterator it = listaTarefas.begin(); it != listaTarefas.end(); ++it) {
		const Tarefa tarefa = *it;//Aqui é criado um objeto tarefa para poder exibir o nome da tarefa concluida posteriormente
		//no if abaixo, o operador "->" é utilizado para checar o valor para qual o ponteiro it está apontando e checar se confere com o digitado pelo usuario.
		if(it->indice == indice){
			it->concluida = true;//Aqui o operador "->" é utilizado para alterar um valor para qual o ponteiro está apontando, que pertence a lista de tarefas.
			cout << "Parabens por ter concluido a tarefa " << tarefa.nome << endl;
			encontrou = true;
			break;
		}	
	}
	if(encontrou == false){
	cout << "Indice invalido." << endl;
	}
}

void ApagarTarefa(list<Tarefa>& listaTarefas, int indice){
	bool encontrou = false;
	for (list<Tarefa>::iterator it = listaTarefas.begin(); it != listaTarefas.end(); ++it) {
		if(it->indice == indice){
			listaTarefas.erase(it);
			encontrou = true;
			break;
		}
	}
	if(encontrou == false){
		cout << "Indice invalido" << endl;
	}
}

void limparTela(){
	system("cls");
}



int main(){
	int opcao;//Variavel para guardar opção escolhida pelo usuario
	int indice;//Variavel para percorrer a lista e localizar as tarefas
	string nome;
	Tarefa tarefa;//Criação do objeto tarefa
	list<Tarefa> listaTarefas;//Lista de tarefas
	do{
		cout << "----------MENU-----------" << endl;
		cout << "1 -> Adicionar tarefa" << endl << "2 -> Marcar tarefa como concluida" << endl;
		cout << "3 -> Exibir pendencias" << endl << "4 -> Remover tarefa da lista" << endl;
		cout << "0 -> Sair do programa" << endl;
		cin >> opcao;
		limparTela();
		switch(opcao){
			case 1:
				cout << "Digite o nome e o indice da tarefa que deseja adicionar: ";
				cin >> nome >> indice;//usuario digita o nome e o indice da tarefa a ser adicionada, por padrão é adicionada como não concluida
				tarefa.Adicionar(nome, indice);//adiciona a tarefa no objeto criado anteriormente, por meio de um metódo criado na classe Tarefa
				listaTarefas.push_back(tarefa);//Adiciona a tarefa que está presente no objeto na lista
				cout << "Tarefa adicionada";
				break;
			case 2:
				cout << "Quais dessas tarefas voce concluiu? Digite o indice" << endl;
				ExibirListaTarefas(listaTarefas);//Função que exibe a lista de tarefas para o usuario, a fim de facilitar a interação com o programa
				cout << endl;
				cin >> indice;
				Concluir(listaTarefas, indice);//Função que troca o status da tarefa para concluida, alterando o valor booleano.
				break;
			case 3:
				ExibirPendencias(listaTarefas);//Função que exibe apenas as tarefas não concluidas
				break;
				
			case 4:
				cout << "Qual tarefa deseja remover? Digite o indice" << endl;
				ExibirListaTarefas(listaTarefas);
				cin >> indice;
				ApagarTarefa(listaTarefas, indice);//Função que remove uma tarefa da lista
				
				break;
			
			case 0:
				cout << "Fechando programa";
				
				return 0;//Return 0 para fechar o programa assim que o usuario digitar a opção 0.
				
			default://default para tratar possíveis opções invalidas digitadas
				cout << "Opcao invalida, por favor selecione uma opcao disponivel no menu." << endl;
		}
	}while(opcao != 0);

	return 0;
}

