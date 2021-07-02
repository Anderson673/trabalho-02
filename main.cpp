#include <iostream>
using namespace std;

struct tNo
{
int info;
tNo*proximo;

};

tNo*criaNo(int item)
{
  tNo*no= new tNo;
  no ->info=item;
  no-> proximo= NULL;
  return no;
}
struct tLista
{
  tNo*primeiro;
  tNo*ultimo;
  tNo*marcador;
  int tamanho;

};

void inicializalista(tLista*pLista)
{
  pLista -> primeiro= NULL;
  pLista -> ultimo= NULL;
  pLista -> marcador= NULL;
  pLista -> tamanho=0;
}
int obterTamanho(tLista*pLista)
{
  return pLista -> tamanho;
}
bool listaVazia (tLista*pLista)
{
  return (pLista->tamanho==0);
}

bool finalLista (tLista*pLista)
{
  return (pLista ->marcador==NULL);
}
void incluirNoFim (tLista*pLista, int info)
{
  
  tNo*no;
  no=criaNo(info);
  if (listaVazia(pLista))
  {
    pLista -> primeiro=no;
  }
  else 
  pLista-> ultimo ->proximo=no;
  pLista ->tamanho ++;

}

void imprimirLista (tLista*pLista)
{
  pLista->marcador = pLista ->primeiro;
  while (!finalLista(pLista))
  {
    int informacao= pLista -> marcador -> info;
    cout << "a informação e: " <<informacao << endl;
    pLista->marcador= pLista->marcador ->proximo;
  }
}
int main() 
{

  tLista* idades = new tLista;
  inicializalista(idades);
  cout << " o tamanho da lista e" << obterTamanho (idades) << endl;
  int idadejoao=10;
  int idadeMaria=20;
  int idadejose=30;

  incluirNoFim (idades, idadejoao);
  incluirNoFim (idades, idadeMaria);
  incluirNoFim (idades, idadejose);
  
  cout << " o tamanho da lista e" << obterTamanho (idades)<< endl;
  cout << "info do ultimo elemento DA LISTA" << idades ->ultimo->info << endl;
  
  imprimirLista(idades);
  incluirNoFim(idades,50);
  cout << "imprimindo apos outra edicao" << endl;
  imprimirLista (idades);


}