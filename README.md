# Computação Gráfica
### O ARQUIVO PRINCIPAL É O TESTE
Este projeto demonstra a criação de gráficos 2D utilizando a biblioteca **OpenGL** com a **FreeGLUT**, permitindo interação através do teclado e do mouse.

## Dependências

Para compilar e executar este projeto, você precisa das seguintes dependências:

- **FreeGLUT**: Biblioteca para criação de janelas e gerenciamento de eventos com OpenGL.

# Instalação do FreeGLUT:

#### No Ubuntu/Debian:
```bash
    sudo apt-get install freeglut3 freeglut3-dev
```

## No Windows:
Baixe o FreeGLUT do site oficial
Adicione os arquivos .dll e as bibliotecas ao seu diretório de trabalho.
Compilação e Execução

## Compilação:
Para compilar o código, use o seguinte comando:

```bash
g++ nome_do_arquivo.cpp -o nome_do_projeto -lglut -lGL -lGLU
```

- **nome_do_arquivo.cpp** é o arquivo de código fonte.
- **nome_do_projeto** é o nome do executável gerado.
## Execução:
Após a compilação, execute o projeto com o comando:

```bash
./nome_do_projeto
```
## Funcionalidades
1. **Escolha de Cor** (A cor padrão é Branca):
Pressione r ou R para selecionar Vermelho.
Pressione g ou G para selecionar Verde.
Pressione b ou B para selecionar Azul.
2. **Menu de Interação** (Botão Direito do Mouse):
Ao clicar com o botão direito do mouse, um menu será exibido com as seguintes opções:

**Pontos**: Clique em qualquer lugar da tela para desenhar pontos na posição do clique.
**Linha**: Clique com o botão esquerdo para selecionar dois pontos que formarão uma linha entre eles.
**Retângulo**: Clique com o botão esquerdo para selecionar dois pontos que formarão um retângulo entre eles.

## Exemplos de Uso
1. Compile e execute o programa.
2. Clique com o botão direito para abrir o menu de interações.
3. Escolha a opção Pontos, Linha ou Retângulo.
4. Selecione as posições na tela para desenhar as formas desejadas.
5. Use o teclado para alternar entre as cores disponíveis.