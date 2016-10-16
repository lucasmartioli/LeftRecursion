# PredictionTable
Gera a tabela preditiva para um parser preditivo, dado uma gramática

# Compilação

**Para compilar no linux Ubunto 16 LTS:**

Na pasta **PredictionTable** executar comando **cmake .**
Também na pasta executar o comando **make**

Para testar executar **./PredictionTable <nome_do_arquivo_de_entrada>**

**Para compilar no Windows:**

# Detalhes de implementação

Para as gramaticas utilizadas, o caracter que representa o **vazio** na gramatica, o **ε (epsolon)**, foi selecionado o caracter **"*"**.

struct **GramaticalRule**
{

    struct GramaticalRule *next;
    char *rule;
    char key;
      
}

S-aSb
S-ab

struct **GramaticalRule** gramatica;

char *rule1 = "aSb";


gramatica.key = 'S';
gramatica.rule = rule1;
gramatica.next = NULL;

struct **GramaticalRule** novaRegra;

char *rule2 = "ab" ;

novaRegra.key = 'S';
novaRegra.rule = rule2;
novaRegra.next = NULL;

gramatica.next = *novaRegra;


struct **AlgorithmsResult**
{

    struct AlgorithmsResult *next;
    char *first;
    char *follow;
    char key;
	
}
