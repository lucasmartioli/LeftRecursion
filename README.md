# PredictionTable
Gera a tabela preditiva para um parser preditivo, dado uma gramática

struct **GramaticalRule**
{
  struct GramaticalRule *next;
  char *rule;
  char key;
}

S-aSb
S-ab

struct **GramaticalRule** gramatica;

char *rule1 = "aSb" ;

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
