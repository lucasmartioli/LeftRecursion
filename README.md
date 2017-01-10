# LeftRecursion
Retira a recursão a esquerda, dado uma gramática.

# Compilação

**Para compilar no Linux:**

Na pasta onde se encontram os arquivos fontes executar comando **"cmake ."**
Também na pasta executar o comando **"make"**

Para testar executar **"./LeftRecursion <nome_do_arquivo_de_entrada> [nome_do_arquivo_de_saida]"**

# Detalhes de execução

Para as gramaticas utilizadas, **NENHUM simbolo deve ter mais de um caracter**

Para as gramaticas utilizadas, o caracter que representa o **vazio** na gramatica, o **ε (epsolon)**, foi selecionado o caracter **e**.

**GRAMATICA DE TESTE**

A gramática de teste é a que aparece no arquivo gramtica.txt.

```
A-Ab|b|C
C-CvvW|Cjj|n
```

**SAIDA**

```
E-bE
E-e
A-bE
A-CE
H-vvWH
H-e
H-jjH
C-nH
```