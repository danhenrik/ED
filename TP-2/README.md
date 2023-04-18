## TP2 ED - 2021/1

#### Feito em cima do WSL do windows, usando o modo WSL do VSCode tanto na compilação quanto no debug.

Resultado final compilado em ./bin/run.exe

Comandos para compilação em exe no mesmo path:

```sh
g++ -std=c++11 -g -Wall -c src/Heapsort.cc -o obj/Heapsort.o -I./include/
g++ -std=c++11 -g -Wall -c src/Consciencia.cc -o obj/Consciencia.o -I./include/
g++ -std=c++11 -g -Wall -c src/Radixsort.cc -o obj/Radixsort.o -I./include/
g++ -std=c++11 -g -Wall -c src/Quicksort.cc -o obj/Quicksort.o -I./include/
g++ -std=c++11 -g -Wall -c src/Main.cc -o obj/Main.o -I./include/
g++ -std=c++11 -g -Wall -c src/Mergesort.cc -o obj/Mergesort.o -I./include/
g++ -std=c++11 -g -Wall -o ./bin/run.exe  ./obj/Heapsort.o  ./obj/Consciencia.o  ./obj/Radixsort.o  ./obj/Quicksort.o  ./obj/Main.o  ./obj/Mergesort.o
```
