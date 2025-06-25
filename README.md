# Calculadora com Notação Polonesa Reversa 
## Ponderada de Computação do Módulo 6 de Engenharia da COmputação
## Kethlen Martins da Silva

## O que a Notação Polonesa Reversa?
A Notação Polonesa Reversa (RPN – Reverse Polish Notation), também chamada de postfix, é uma forma de representar expressões matemáticas em que o operador vem após seus operandos. 

## Como foi implementado o algoritmo?
O algoritmo foi implementado utilizando uma pilha e contou com as definições de tipos e métodos a seguir:

### Tipos
- Pilha
- Operando
- Operador

### Métodos
- InicializarPilha: inicializa a pilha
- QuantidadeElementos: retorna a quantidade de elementos a partir do topo da pilha
- PilhaEstaVazia: retorna quando a pilha está vazia
- EhNumero: verifica se o input é um número ou não
- InserirOperando: adiciona um operando na pilha na última posição
- RemoverOperando: tira o último operando adicionado na lista
- CalcularResultado: calcula o resultado das operações quando encontra um operador

## Considerações
Ao fazer essa ponderada, utilizei a ajuda do chatgpt para encontrar os métodos para input do usuário com espaços em branco na função main() e para terminar a lógica do switch case dentro da função calcularResultado(). Caso algo esteja incoerente nessas etapas do código, eu não codei ele totalmente e planejo melhorar ele em breve por motivos educacionais, mesmo que passe o período da ponderada.
