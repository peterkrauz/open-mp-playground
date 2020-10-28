# OpenMP Prime Finder

### Sobre
O arquivo [open_mp_prime_finder](open_mp_prime_finder.c) contém a solução do problema proposto pelo professor utilizando as primitivas do [OpenMP](https://www.openmp.org/). Neste contexto, substitui-se as threads POSIX pela integração com as do OpenMP.

### Execução
obs.: Foi necessário instalar a versão 7 do GCC para conseguir usufruir do argumento `-fopenmp`.

Em um terminal qualquer, digite o seguinte trecho para compilar o programa:
```
$ gcc-7 -fopenmp open_mp_prime_finder.c -o <nome_do_output>
```
Para rodá-lo com entradas específicas, digite:
```
$ ./<nome_do_output> 500 10
```
Onde o primeiro argumento (`500`) é a quantia de números a serem percorridos, e o segunto argumento (`10`) a quantia de threads que fará a busca.
