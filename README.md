# Relatorio atv9
### Ariel T Leventhal

## Introdução
Nesse relatorio iremos analisar duas heuristicas para resolver o problema da mochila binaria. 
A primeira heuristica é de mais caro primeiro, onde ordenamos os itens por valor e tentamos colocar os mais caros primeiro.
A segunda heuristica é de mais leve primeiro, onde ordenamos os itens por peso e tentamos colocar os mais leves primeiro.

## Entrada onde a heuristica de mais leve primeiro é melhor
```
10 600
300 200
300 200
10  50
10 50
10 50
2 100
4 100
50 100
4 100
10 100
```

Nessa entrada, a heuristica de mais caro primeiro começa pegando os doins itens de 400 de valor e 300 de peso. Isso faz com que não seja possivel pegar mais nenhum item, pois o peso total ja chegou a 600.
Em contrapartida, a heuristica de mais leve primeiro pega itens mais leves que podem ter menor valor mas a razão valor/peso é maior. Assim, ela consegue pegar mais itens e o valor total é maior.

## Entrada onde a heuristica de mais caro primeiro é melhor
```
5 10
9 100
8 90
7 80
2 5
1 1
```

Nessa entrada, a heuristica de mais caro primeiro pega os itens de maior valor e peso, e consegue pegar apenas um item. A heuristica de mais leve primeiro pega os itens mais leves e consegue pegar 3 itens, o que resulta em um valor total menor.

## Conclusão

A heuristica de mais caro primeiro é melhor quando os itens tem valores muito altos e pesos baixos, pois ela consegue pegar os itens de maior valor. A heuristica de mais leve primeiro é melhor quando os itens tem valores baixos e pesos altos, pois ela consegue pegar mais itens. 
Alem disso a heuristica de mais caro primeiro é ruim quando o peso dos itens caros sao altos em relação ao peso total da mochila, pois ela não consegue pegar muitos itens.


## Complexidade de tempo
A complexidade de tempo de ambas as heuristicas é O(nlogn) pois a ordenação dos itens é feita em O(nlogn) e a inserção dos itens na mochila é feita em O(n).


## Elas conseguem resolver o problema da mochila binaria de forma otima?
Ambas podem apenas em casos especificos resolver o problema de maneira otima. Mas como regra elas não conseguem. 