# PredictionTable
Gera a tabela preditiva para um parser preditivo, dado uma gramática

# Compilação

**Para compilar no linux Ubunto 16 LTS:**

Na pasta **PredictionTable** executar comando **"cmake ."**
Também na pasta executar o comando **"make"**

Para testar executar **"./PredictionTable nome_do_arquivo_de_entrada"**

# Detalhes de execução

Para as gramaticas utilizadas, **NENHUM simbolo deve ter mais de um caracter**

Para as gramaticas utilizadas, o caracter que representa o **vazio** na gramatica, o **ε (epsolon)**, foi selecionado o caracter **e**.

Como resultado do algoritmo temos os arquivos: **first.txt** **follow.txt** e **tabela.csv**.

**GRAMATICA DE TESTE**

```
S-TW
W-+TW|e
T-FX
X-*FX|
X-e
F-(S)|i
```


**SAIDAS**

**FIRST**

```
Conjunto: S = {(i}
Conjunto: W = {+e}
Conjunto: T = {(i}
Conjunto: X = {*e}
Conjunto: F = {(i}
```

**FOLLOW**

```
Conjunto: S = {$)}
Conjunto: W = {$)}
Conjunto: T = {+$)}
Conjunto: X = {+$)}
Conjunto: F = {*+$)}
```

**TABELA**

```
	$	+	*	(	)	i
S	ERRO	ERRO	ERRO	S-TW	ERRO	S-TW
T	ERRO	ERRO	ERRO	T-FX	ERRO	T-FX
W	W-e	W-+TW	ERRO	ERRO	W-e	ERRO
F	ERRO	ERRO	ERRO	F-(S)	ERRO	F-i
X	X-e	X-e	X-*FX	ERRO	X-e	ERRO
```




# Detalhes de implementação

```
struct GrammarRule
   {
   
       struct GramaticalRule *next;
       char *rule;
       char key;
         
   }
```

S-aSb
S-ab

```
GrammarRule *gramatica;

char *rule1 = "aSb";

gramatica.key = 'S';
gramatica.rule = rule1;
gramatica.next = NULL;

GrammarRule *novaRegra;

char *rule2 = "ab" ;

novaRegra.key = 'S';
novaRegra.rule = rule2;
novaRegra.next = NULL;

gramatica.next = *novaRegra;
```



