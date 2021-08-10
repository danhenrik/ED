// Esse código assume repetição de mesmos valores. O novo entra depois do valor que já está na lista caso isso aconteça.
void ListaEncadeada::InsereOrdenado(TipoItem item)
{
  TipoCelula *cel, *aux, *nova;
  nova = new TipoCelula();
  nova->item = item;
  // Começa do primeiro em vez do primeiro->prox devido a lógica utilizada que checa o proximo do atual em vez do atual
  // adotando a abordagem de estar sempre um passo atrás.
  cel = primeiro;
  // Apenas pra evitar ficar chamando em cada iteração o método.
  int c = item.GetChave();
  // Só pra não deixar um while infinito caso por algum motivo dê algo errado dentro do loop.
  for (int i = 0; i < tamanho; i++)
  {
    // Se a próxima célula tiver uma chave maior que a chave a ser inserida, insira a célula antes dela.
    if (cel->prox->item.GetChave() > c)
    {
      aux = cel->prox;
      cel->prox = nova;
      nova->prox = aux;
      tamanho++;
      break;
    }
    // Checa se o próximo elemento é o último, não sei se  uma comparação direta (cel->prox == ultimo) funcionaria.
    if (cel->prox->prox == NULL)
    {
      ultimo->prox = nova;
      nova = ultimo;
      tamanho++;
      break;
    }
    cel = cel->prox;
  }
}