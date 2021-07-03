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
 
  int lados;
  cout << "informe os lados" << endl;
  cin >> lados;
  
  tNo*no;
  no=criaNo(info);
  if (listaVazia(pLista))
  {
    pLista -> primeiro=no;
  }
  else 
  {
    pLista ->ultimo -> proximo=no;
  }
  pLista-> ultimo=no;
  pLista -> marcador=no;
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


  cout << " o tamanho da lista e" << idades -> tamanho << endl;

int tri;
cout << "Por favor informe quantos triagulos deseja adicionar" << endl;
cin >> tri;
  for (int i=0; i<tri; i++)
  {

  int lado1,lado2,lado3;

  incluirNoFim (idades, lado1);
  cout << " o tamanho da lista e: " << idades -> tamanho << endl;
  incluirNoFim (idades, lado2);
  cout << " o tamanho da lista e: " << idades -> tamanho 
  << endl;
  incluirNoFim (idades,lado3);
  cout << " o tamanho da lista e: " << idades -> tamanho << endl;

  }

}