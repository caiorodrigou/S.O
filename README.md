# Interpretador de Linha de Comando (Shell)

Trabalho individual desenvolvido para a disciplina de Sistemas Operacionais. O objetivo do programa e simular uma shell Unix simples em C++ que recebe entradas do usuario e executa comandos internos.

## Comandos Implementados

- exit [n]: Finaliza a shell com o codigo de saida informado ou 0 por padrao.
- pwd: Exibe o caminho do diretorio atual de trabalho.
- cd [dir]: Muda para o diretorio informado. Se nenhum caminho for passado, vai para o diretorio HOME.
- history: Mostra os ultimos 10 comandos digitados do mais recente ao mais antigo.
- history -c: Limpa todo o historico de comandos salvos.

## Como Compilar e Executar

No terminal Linux:

1. Compilacao:
g++ Shell.cpp -o shell

2. Execucao:
./shell

