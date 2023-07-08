#include <iostream>
#include <string>
#include <list>

using namespace std;

//cria��o da classe Tarefa abaixo, para podermos armazenar as tarefas em uma lista posteriormente

class Tarefa {

public:
	string nome;
    int indice;
    bool concluida;
    //Cria��o do metodo adicionar abaixo, para podermos adicionar tarefas na lista.
    void Adicionar(string nome, int indice) {
        this->nome = nome;
        this->indice = indice;
        this->concluida = false;
    }
};
//Fun��o abaixo criada para exibir as tarefas. Recebe como parametro o endere�o de uma lista, para evitar que sejam feitas c�pias desnecess�rias. Constante pois
//Essa fun��o n�o altera a lista
void ExibirListaTarefas(const list<Tarefa>& listaTarefas) {
    list<Tarefa>::const_iterator it;//iterator para manipular a lista, pode-se interpretar como um ponteiro
    for (it = listaTarefas.begin(); it != listaTarefas.end(); ++it) {
        const Tarefa& tarefa = *it;
        cout << "Nome: " << tarefa.nome << ", Indice: " << tarefa.indice << endl;
    }
}
//Fun��o abaixo criada para exibir as pendencias. Recebe como parametro o endere�o de uma lista, para evitar que sejam feitas c�pias desnecess�rias.
//Constante pois essa fun��o n�o altera a lista
void ExibirPendencias(const list<Tarefa>& listaTarefas){
	list<Tarefa>::const_iterator it;
    for (it = listaTarefas.begin(); it != listaTarefas.end(); ++it) {
        const Tarefa& tarefa = *it;
        if(tarefa.concluida == false){
        	cout << "Nome: " << tarefa.nome << ", Indice: " << tarefa.indice << endl;
    	}
    }
}
//Fun��o abaixo marca uma tarefa como concluida, recebe o endere�o de uma lista para evitar c�pias desnecess�rias. Recebe tamb�m o indice digitado pelo usuario
//Para poder buscar a tarefa em quest�o. O endere�o aqui n�o � constante pois a lista ser� alterada.
void Concluir(list<Tarefa>& listaTarefas, int indice){
	bool encontrou = false;//Valor booleano para poder checar se o indice digitado � v�lido
	//No for abaixo, o iterator � colocado dentro da lista, pois � iniciado com o valor inicial da mesma. A cada itera��o, ele passa para o pr�ximo item.
	for (list<Tarefa>::iterator it = listaTarefas.begin(); it != listaTarefas.end(); ++it) {
		const Tarefa tarefa = *it;//Aqui � criado um objeto tarefa para poder exibir o nome da tarefa concluida posteriormente
		//no if abaixo, o operador "->" � utilizado para checar o valor para qual o ponteiro it est� apontando e checar se confere com o digitado pelo usuario.
		if(it->indice == indice){
			it->concluida = true;//Aqui o operador "->" � utilizado para alterar um valor para qual o ponteiro est� apontando, que pertence a lista de tarefas.
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
	int opcao;//Variavel para guardar op��o escolhida pelo usuario
	int indice;//Variavel para percorrer a lista e localizar as tarefas
	string nome;
	Tarefa tarefa;//Cria��o do objeto tarefa
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
				cin >> nome >> indice;//usuario digita o nome e o indice da tarefa a ser adicionada, por padr�o � adicionada como n�o concluida
				tarefa.Adicionar(nome, indice);//adiciona a tarefa no objeto criado anteriormente, por meio de um met�do criado na classe Tarefa
				listaTarefas.push_back(tarefa);//Adiciona a tarefa que est� presente no objeto na lista
				cout << "Tarefa adicionada";
				break;
			case 2:
				cout << "Quais dessas tarefas voce concluiu? Digite o indice" << endl;
				ExibirListaTarefas(listaTarefas);//Fun��o que exibe a lista de tarefas para o usuario, a fim de facilitar a intera��o com o programa
				cout << endl;
				cin >> indice;
				Concluir(listaTarefas, indice);//Fun��o que troca o status da tarefa para concluida, alterando o valor booleano.
				break;
			case 3:
				ExibirPendencias(listaTarefas);//Fun��o que exibe apenas as tarefas n�o concluidas
				break;
				
			case 4:
				cout << "Qual tarefa deseja remover? Digite o indice" << endl;
				ExibirListaTarefas(listaTarefas);
				cin >> indice;
				ApagarTarefa(listaTarefas, indice);//Fun��o que remove uma tarefa da lista
				
				break;
			
			case 0:
				cout << "Fechando programa";
				
				return 0;//Return 0 para fechar o programa assim que o usuario digitar a op��o 0.
				
			default://default para tratar poss�veis op��es invalidas digitadas
				cout << "Opcao invalida, por favor selecione uma opcao disponivel no menu." << endl;
		}
	}while(opcao != 0);

	return 0;
}

