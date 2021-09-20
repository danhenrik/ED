#include "Node.h"

class ArvoreBinaria
{
public:
  /* Constrói uma árvore binária vazia (apenas o nó root como NULL). */
  ArvoreBinaria();
  /* Chama o método limpa que exclui todos os nós da árvore. */
  ~ArvoreBinaria();

  /* Insere um novo nó criado a partir das duas strings passadas. */
  void Insere(string nome, string dado);
  /* Pesquisa um nó com nome (chave) igual a string passada e imprime
  respectivamente o nome e a soma dos binários convertidos para decimais
  e o remove da árvore. */
  void Pesquisa(string nome);
  /* Remove um nó da árvore já reorganizando a árvore de acordo. */
  void Remove(string nome);
  /* Dependendo do número passado faz um dos 3 caminhamentos implementados:
   1 - Caminhamento pré-ordem
   2 - Caminhamento central
   3 - Caminhamento pós-ordem
   Todos esses caminhamentos imprimem as chaves dos nós (nomes). */
  void Caminha(int tipo);
  /* Limpar a árvore deixando apenas o nó root inicializado como NULL (árvore zerada). */
  void Limpa();

private:
  /* Método usado pela função 'Insere' para inserir novos nós. */
  void InsereRecursivo(Node *&n, string nome, string dado);
  /* Método usado pela função 'Pesquisa' que retorna o nó desejado. */
  Node *PesquisaRecursivo(Node *n, string nome);
  /* Método usado pela função 'Remove' que remove o nó com a chave(nome) passada. */
  void RemoveRecursivo(Node *&n, string nome);
  /* Método usado pela função 'RemoveRecursivo' que acha o antecessor do 
  nó a ser excluido e faz essa substituição. */
  void Antecessor(Node *n, Node *&r);
  /* Método usado pela função 'Limpa' que exclui todos os nós da árvore. */
  void ApagaRecursivo(Node *n);
  /* Caminhamento pré-ordem com a impressão das chaves (nome). */
  void PreOrdem(Node *n);
  /* Caminhamento central com a impressão das chaves (nome). */
  void InOrdem(Node *n);
  /* Caminhamento pós-ordem com a impressão das chaves (nome). */
  void PosOrdem(Node *n);

  Node *root;
};