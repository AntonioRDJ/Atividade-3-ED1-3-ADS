#include <iostream>
#include <string.h>

using namespace std;

class Data
{
	private:
		int dia;
		int mes;
		int ano;
		int idade2;
		
	public:
		Data(int dia, int mes, int ano)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		
		Data()
		{
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
		
		void setDia(int dia)
		{
			this->dia = dia;
		}
		
		void setMes(int mes)
		{
			this->mes = mes;
		}

		void setAno(int ano)
		{
			this->ano = ano;
		}
		
		int getDia()
		{
			return this->dia;
		}
		
		int getMes()
		{
			return this->mes;
		}

		int getAno()
		{
			return this->ano;
		}
		
		string getData()
        {
 	        return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
        }
        
        int getIdade() {
        	int dia = 18, mes = 05, ano = 2021, idade = ano - this->ano;
			if(this->mes > mes) {
				idade--;
			}else if(this->mes == mes && this-> dia > dia) {
				idade--;
			}
			return idade;
		}
};

class Contato
{
private:
		string email;
		string nome;
		string telefone;
		Data *dtnasc;
		
public:
		Contato(string email, string nome, string telefone, Data *dtnasc)
		{
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;
			this->dtnasc = dtnasc;
		}
		Contato()
		{
			this->email = "";
			this->nome = "";
			this->telefone = "";
			this->dtnasc = new Data();
		}
		void setEmail(string email)
		{
			this->email = email;
		}
		void setNome(string nome)
		{
			this->nome = nome;
		}
		void setTelefone(string telefone)
		{
			this->telefone = telefone;
		}
		void setDtnasc(Data *dtnasc)
		{
			this->dtnasc = dtnasc;
		}
		
		string getEmail()
		{
			return this->email;
		}
		string getNome()
		{
			return this->nome;
		}
		string getTelefone()
		{
			return this->telefone;
		}
		Data *getDtnasc() {
			return this->dtnasc;
		}
		
		string getDados()
        {
        	int getIdade = this->dtnasc->getIdade();
 	        return "- Email: " + this->email + "\n" + "- Nome: " + this->nome + "\n" + "- Telefone: " + this->telefone + "\n" + "- Idade: " + std::to_string(getIdade);
        }		
};

int main(int argc, char** argv)
{
	string email, nome, telefone;
	int dia, mes, ano;
	
	Contato *cont[5];
	
	for(int i=0; i<5; i++)
	{
	cout << (i+1) <<" Contato" << endl; 
	cout << "Digite o seu e-mail:" << endl;
	cin >> email;
	
	cout << "Digite o seu nome:" << endl;
	cin >> nome;
	
	cout << "Digite o seu telefone:" << endl;
	cin >> telefone;
	
	cout << "Digite o dia do seu aniversario:" << endl;
	cin >> dia;
	cout << "Digite o mes do seu aniversario:" << endl;
	cin >> mes;
	cout << "Digite o ano do seu aniversario:" << endl;
	cin >> ano;
	cout << endl;
	
	cont[i] = new Contato(email, nome, telefone, new Data(dia, mes, ano));
	}

	system("cls");
	for(int i=0; i<5; i++)
	{
	cout << (i+1) <<" Contato" << endl;
	cout << cont[i]->getDados() << endl;
	cout << "---------------------";
	cout << endl;
	}
	
	return 0;
}

/*
Com a finalidade de registro de frequência associada à aula de 04/05/2021, desenvolva um programa 
que permita a digitação (e posterior exibição), dos dados relativos à classe "Contato" abaixo 
descrita:

---------------------
| Data              |
|-------------------|
| - dia: int        |
| - mes: int        |
| - ano: int        |
---------------------
-----------------------

| Contato             |
|---------------------|
| - email: string     |
| - nome: string      |
| - telefone: string  |
| - dtnasc: Data      |
|---------------------|
| + idade(): int      |
-----------------------
Implementar construtores, getter's e setter's.

OBSERVAÇÕES:

Utilizar a classe Data implementada durante os exemplos da aula;
Utilizar o ano de 2021 para o cálculo da idade ou buscar alternativa para pegar, de forma automática, 
o ano do sistema operacional.
Implementar uma solução que permita cadastrar e exibir uma estrutura com 5 contatos 
(ao exibir, informar nome, e-mail, telefone e idade).
*/

