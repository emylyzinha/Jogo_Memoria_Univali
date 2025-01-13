# Jogo da Memória 

### **Funcionalidades**
- **Tabuleiros Dinâmicos:** Geração aleatória de diferentes variações do tabuleiro inicial:
  - Tabuleiro original.
  - Transposição da matriz.
  - Inversão de linhas.
  - Inversão de colunas.
- **Jogadas Interativas:** O jogador seleciona duas cartas por rodada, tentando encontrar pares.
- **Validação de Entradas:** Evita jogadas inválidas ou repetidas.
- **Matriz de Gabarito e Jogo:** Exibe o progresso e mantém ocultos os valores não encontrados.
- **Verificação de Vitória/Derrota:** Ganha ao encontrar todos os pares em até 24 jogadas.
- **Mensagens de Feedback:** Informa ao jogador se acertou ou errou na jogada.

---

### **Tecnologias Utilizadas**
- **C++:** Linguagem base para lógica e interação com o usuário.
- **Bibliotecas:**  
  - `iostream`: Entrada e saída de dados.  
  - `time.h`: Geração de números aleatórios.  
  - `cstdlib`: Uso de comandos como `system("cls")` para limpar o terminal.  
  - `locale.h`: Suporte à acentuação e caracteres especiais.  

---

### **Objetivo**
Este projeto visa:
- Praticar manipulação de matrizes e operações com números aleatórios.
- Implementar estruturas de controle e validação de entradas.
- Criar uma experiência interativa em C++ para aprender lógica de programação de forma lúdica.

---

### **Como Jogar**
1. O jogo apresenta um tabuleiro de 4x4 oculto.
2. Escolha as coordenadas (linha e coluna) de duas cartas por jogada.
3. Tente encontrar os pares correspondentes.
4. O jogo termina quando todos os pares são encontrados ou quando o limite de 24 jogadas é atingido.
