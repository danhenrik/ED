## TP3 ED - 2021/1

#### Feito em cima do WSL do windows, usando o modo WSL do VSCode tanto na compilação quanto no debug.

Resultado final compilado em ./bin/run.exe

Comandos para compilação em exe no mesmo path:

```sh
g++ -std=c++11 -g -Wall -c src/Item.cc -o obj/Item.o -I./include/
g++ -std=c++11 -g -Wall -c src/Node.cc -o obj/Node.o -I./include/
g++ -std=c++11 -g -Wall -c src/ListaEncadeada.cc -o obj/ListaEncadeada.o -I./include/
g++ -std=c++11 -g -Wall -c src/ArvoreBinaria.cc -o obj/ArvoreBinaria.o -I./include/
g++ -std=c++11 -g -Wall -c src/Celula.cc -o obj/Celula.o -I./include/
g++ -std=c++11 -g -Wall -c src/Main.cc -o obj/Main.o -I./include/
g++ -std=c++11 -g -Wall -o ./bin/run.exe  ./obj/Item.o  ./obj/Node.o  ./obj/ListaEncadeada.o  ./obj/ArvoreBinaria.o  ./obj/Celula.o  ./obj/Main.o
```
