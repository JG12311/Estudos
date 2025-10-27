# 🌤️ Lab API Clima

Aplicação web para consulta de informações climáticas em tempo real de qualquer cidade do mundo, utilizando a API pública Open-Meteo.

![Status](https://img.shields.io/badge/status-concluído-brightgreen)
![Versão](https://img.shields.io/badge/versão-1.0.0-blue)

---

## 📋 Índice

- [Sobre o Projeto](#sobre-o-projeto)
- [Objetivos de Aprendizado](#objetivos-de-aprendizado)
- [Funcionalidades](#funcionalidades)
- [Tecnologias Utilizadas](#tecnologias-utilizadas)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Como Executar](#como-executar)
- [Como Usar](#como-usar)
- [Conceitos Aplicados](#conceitos-aplicados)
- [Desafios Implementados](#desafios-implementados)
- [API Utilizada](#api-utilizada)
- [Capturas de Tela](#capturas-de-tela)
- [Melhorias Futuras](#melhorias-futuras)
- [Autor](#autor)

---

## 📖 Sobre o Projeto

O **Lab API Clima** é uma aplicação web desenvolvida com o objetivo de demonstrar a comunicação entre sistemas através de APIs REST. O projeto consome dados reais de clima (temperatura e velocidade do vento) da API Open-Meteo, permitindo que o usuário consulte informações meteorológicas de qualquer cidade do mundo.

Este projeto simula o fluxo completo de uma aplicação moderna:

```
Usuário → Front-End (HTML + JS) → API (Open-Meteo) → Resposta JSON → Navegador
```

---

## 🎯 Objetivos de Aprendizado

1. ✅ Compreender o papel de uma API como intermediadora de informações entre sistemas
2. ✅ Utilizar o método `fetch()` para realizar requisições HTTP em JavaScript
3. ✅ Interpretar dados em formato JSON e utilizá-los dinamicamente no navegador
4. ✅ Simular o fluxo real de comunicação cliente-servidor
5. ✅ Aplicar boas práticas de validação, feedback ao usuário e tratamento de erros

---

## ⚡ Funcionalidades

- 🔍 **Busca de cidades**: Pesquise qualquer cidade do mundo
- 🌡️ **Temperatura em tempo real**: Visualize a temperatura atual
- 💨 **Velocidade do vento**: Informação sobre velocidade do vento
- 🎨 **Interface responsiva**: Design adaptável para diferentes dispositivos
- ⏱️ **Feedback de carregamento**: Indicador visual durante a busca
- ❌ **Tratamento de erros**: Mensagens amigáveis para erros e cidade não encontrada
- 🔄 **Função limpar**: Limpe os campos com um clique
- ⌨️ **Atalho de teclado**: Pressione Enter para buscar

---

## 🛠️ Tecnologias Utilizadas

- **HTML5**: Estrutura da página
- **CSS3**: Estilização e design responsivo
- **JavaScript (ES6+)**: Lógica da aplicação
- **Fetch API**: Requisições HTTP
- **Open-Meteo API**: Fonte de dados climáticos

---

## 📁 Estrutura do Projeto

```
lab-api-clima/
│
├── index.html          # Página principal (interface)
├── app.js              # Lógica JavaScript (requisições e exibição)
└── README.md           # Documentação do projeto
```

---

## 🚀 Como Executar

### Pré-requisitos

- Navegador web moderno (Chrome, Firefox, Edge, Safari)
- Conexão com a internet (para acessar a API)

### Passos

1. **Clone ou baixe o projeto**
   ```bash
   git clone [url-do-repositorio]
   ```

2. **Navegue até a pasta do projeto**
   ```bash
   cd lab-api-clima
   ```

3. **Abra o arquivo `index.html` no navegador**
   - Dê um duplo clique no arquivo, ou
   - Arraste o arquivo para o navegador, ou
   - Use a extensão Live Server no VS Code

4. **Pronto!** A aplicação já está funcionando 🎉

---

## 💻 Como Usar

1. **Digite o nome da cidade** no campo de entrada
   - Exemplos: Campinas, São Paulo, Tokyo, Paris, New York

2. **Clique no botão "Buscar Clima"** ou pressione Enter

3. **Visualize os resultados**:
   - Nome da cidade e país
   - Ícone representativo do clima
   - Temperatura atual em °C
   - Velocidade do vento em km/h
   - Mensagem personalizada

4. **Para limpar**, clique no botão "Limpar"

---

## 🧠 Conceitos Aplicados

### 1. Manipulação do DOM
```javascript
const cidadeInput = document.getElementById('cidadeInput');
const resultado = document.getElementById('resultado');
```

### 2. Requisições Assíncronas com Fetch
```javascript
const response = await fetch(url);
const data = await response.json();
```

### 3. Tratamento de Erros
```javascript
try {
    // código da requisição
} catch (error) {
    console.error('Erro:', error);
    // exibir mensagem amigável
}
```

### 4. Validação de Entrada
```javascript
if (!cidade) {
    // mostrar alerta
    return;
}
```

### 5. Programação Assíncrona (async/await)
```javascript
async function buscarClima() {
    // código assíncrono
}
```

---

## 🎨 Desafios Implementados

### Desafio 1: Ícones Dinâmicos
Ícones que mudam baseados na temperatura:
- ❄️ Temperatura < 0°C
- 🥶 Temperatura < 10°C
- 😊 Temperatura < 20°C
- ☀️ Temperatura < 30°C
- 🔥 Temperatura ≥ 30°C

### Desafio 2: Cores de Fundo Dinâmicas
O fundo do resultado muda baseado na temperatura:
- **Muito Frio** (< 5°C): Azul claro
- **Frio** (5-15°C): Azul
- **Ameno** (15-25°C): Amarelo
- **Quente** (25-32°C): Laranja
- **Muito Quente** (> 32°C): Vermelho

### Desafio 3: Mensagem Personalizada
Mensagem que varia conforme o horário:
```
"Bom dia! Em Campinas, faz 27°C neste momento."
"Boa tarde! Em Tokyo, faz 18°C neste momento."
"Boa noite! Em Paris, faz 12°C neste momento."
```

---

## 🌐 API Utilizada

### Open-Meteo API

**API de Geocodificação**
```
https://geocoding-api.open-meteo.com/v1/search
```
- Converte nome da cidade em coordenadas (latitude/longitude)

**API de Clima**
```
https://api.open-meteo.com/v1/forecast
```
- Retorna dados climáticos atuais baseados nas coordenadas

### Vantagens da Open-Meteo:
- ✅ Gratuita
- ✅ Sem necessidade de cadastro
- ✅ Sem chave de API
- ✅ Dados em tempo real
- ✅ Cobertura mundial

---

## 📸 Capturas de Tela

### Tela Inicial
Interface limpa e intuitiva para busca de cidades.

### Buscando Informações
Feedback visual durante o carregamento dos dados.

### Resultado - Clima Quente
Exibição com fundo laranja para temperatura quente (27°C).

### Resultado - Clima Frio
Exibição com fundo azul para temperatura fria (8°C).

### Resultado - Clima Muito Quente
Exibição com fundo vermelho para temperatura muito quente (35°C).

---

## 🐛 Solução de Problemas

### A cidade não é encontrada
- Verifique a ortografia do nome da cidade
- Tente usar o nome em inglês
- Algumas cidades pequenas podem não estar no banco de dados

### Erro de conexão
- Verifique sua conexão com a internet
- Verifique se as URLs da API estão corretas
- Abra o Console do navegador (F12) para ver detalhes do erro

### Dados não aparecem
- Abra o Console (F12) e verifique se há erros
- Confirme que o arquivo `app.js` está na mesma pasta que `index.html`
- Recarregue a página (Ctrl + F5)

---

## 📚 Recursos de Aprendizado

- [Documentação Fetch API](https://developer.mozilla.org/pt-BR/docs/Web/API/Fetch_API)
- [Documentação Open-Meteo](https://open-meteo.com/en/docs)
- [JavaScript Promises e Async/Await](https://developer.mozilla.org/pt-BR/docs/Web/JavaScript/Reference/Statements/async_function)
- [Manipulação do DOM](https://developer.mozilla.org/pt-BR/docs/Web/API/Document_Object_Model)

---

## 👨‍💻 Autor

Desenvolvido por:
João Gabriel Breganon Ferreira RA:25003037
Gabriel Senatori Costa RA:25006213
Guilherme Carvalho Mais RA:25009646

