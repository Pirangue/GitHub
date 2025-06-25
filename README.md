# Algoritmo Genético para Solução de Labirintos

Este projeto implementa um algoritmo genético em linguagem C que encontra um caminho ideal em um labirinto. Cada indivíduo da população carrega um genoma com movimentos, e a simulação evolui por seleção, crossover e mutação. O sistema é configurado por arquivos `.ini` e gera logs por geração em `.csv`.

---

## Estrutura do Projeto

.
├── Config
│   ├── config.c
│   ├── config.h
├── Graficos
│   ├── Grafico - Log.xlsx
│   ├── Grafico - log2.xlsx
├── Labirinto
│   ├── labirinto.c
│   ├── labirinto.h
├── Log
│   ├── log.c
│   ├── log.csv
│   ├── log.h
│   ├── log2.csv
├── Povo
│   ├── individuo.c
│   ├── individuo.h
│   ├── populacao.c
│   ├── populacao.h
├── config.ini
├── config2.ini
├── labirinto.exe
├── Main.c
├── mapa.txt
├── mapa2.txt

---

## Mapa do Labirinto (.txt)

Exemplo de mapa:

################
#S       #     #
#  ### #   ##  #
#      #  ###  #
# ## #### #    #
#      #   #####
# ### ## ###   #
# #          # #
# ### ###### # #
#     #       E#
################

'S' é o ponto de partida e 'E' é o objetivo. '#' representa paredes.

---

## Arquivo de Configuração (.ini)

Exemplo de configuração (config.ini):

tamanho_populacao = 100
taxa_mutacao = 0.02
max_geracoes = 1000
versao_geracao = inteligante
arquivo_labirinto = mapa2.txt
arquivo_saida_log = Log/log3.csv


Parâmetros:
- tamanho_populacao: tamanho da população
- max_geracoes: número máximo de gerações
- taxa_mutacao: chance de mutação (0 a 1)
- versao_geracao: aleatorio ou inteligente
- arquivo_labirinto: nome do arquivo que armazeno o labirinto
- arquivo_saida_log: nome do arquivo de log gerado

---

## Como Compilar e Executar

1. Compile usando gcc:

gcc Config/config.c Labirinto/labirinto.c Log/log.c Povo/individuo.c Povo/populacao.c MAin.c -o labirinto -lm

2. Execute o programa passando o arquivo de configuração:

./labirinto.exe config.ini
   ou
./labirinto.exe config2.ini

---

## Estrutura do Log CSV

O log é gerado no formato:

1, 850, DDRRUULDRD
2, 905, DDRRRULDDD
3, 990, DDRRRRRUUU

Formato:
geracao, fitness, movimentos

---

## Análise de Resultados

1. Abra o arquivo .csv no Excel ou Google Sheets.
2. Caso os dados estejam em uma única coluna, use "Texto para Colunas" e separe por vírgulas.
3. Crie um gráfico de linha ou dispersão:
   - Eixo X: geração
   - Eixo Y: fitness

Você pode comparar experimentos alterando o modo (aleatorio/inteligente) e visualizando a evolução.

---

## Geração de Indivíduos

O sistema suporta duas estratégias:

- Aleatoria: gera movimentos aleatórios livremente
- Inteligente: gera movimentos evitando paredes e com lógica de movimentação (experimental)

---

## Requisitos Atendidos

- Leitura de mapa externo
- Leitura de parâmetros via arquivo .ini
- Registro de log CSV com fitness e genoma
- Suporte a duas estratégias de geração
- Modularização do código com TADs
- Uso de lista encadeada dinamica para população

---

## Observações

- O projeto deve ser compilado com suporte à biblioteca math (-lm)
- O arquivo .ini deve estar na raiz ou o caminho ajustado
- O código é acadêmico, mas pode ser expandido para robótica, IA, jogos etc.

---

## Autor

Cauê Piragé  
Trabalho acadêmico — Algoritmos Genéticos em C
