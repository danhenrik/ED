## TP1 ED - 2021/1

#### Feito em cima do WSL do windows, usando o modo WSL do VSCode tanto na compilação quanto no debug.

Resultado final compilado em bin/run.out

Comandos para compilação em exe no mesmo path:

```sh
g++ -std=c++11 -g -Wall -c src/Item.cc -o obj/Item.o -I./include/
g++ -std=c++11 -g -Wall -c src/FilaEncadeada.cc -o obj/FilaEncadeada.o -I./nclude/
g++ -std=c++11 -g -Wall -c src/Celula.cc -o obj/Celula.o -I./include/
g++ -std=c++11 -g -Wall -c src/Main.cc -o obj/Main.o -I./include/
g++ -std=c++11 -g -Wall -o ./bin/run.exe  ./obj/Item.o  ./obj/FilaEncadeada.o  ./obj/Celula.o  ./obj/Main.o
```
