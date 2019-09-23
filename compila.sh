#!/bin/bash
cd servidor/
rm *.o
gcc -c servidor.c lucasCosta_*
gcc -o prgmServidor *.o
cd ../cliente/
rm *.o
gcc -c cliente.c lucasCosta_*
gcc -o prgmCliente *.o