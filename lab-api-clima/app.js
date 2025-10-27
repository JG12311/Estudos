// 1. Seleção dos elementos HTML
const cidadeInput = document.getElementById('cidadeInput');
const buscarBtn = document.getElementById('buscarBtn');
const limparBtn = document.getElementById('limparBtn');
const resultado = document.getElementById('resultado');

// 2. Evento de clique no botão "Buscar Clima"
buscarBtn.addEventListener('click', buscarClima);

// Permite buscar pressionando Enter
cidadeInput.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
        buscarClima();
    }
});

// 3. Função principal para buscar clima
async function buscarClima() {
    const cidade = cidadeInput.value.trim();

    // Validação se o campo está vazio
    if (!cidade) {
        resultado.innerHTML = '<p class="erro">⚠️ Por favor, digite o nome de uma cidade.</p>';
        return;
    }

    // Mostrar mensagem de carregamento
    resultado.innerHTML = '<p class="loading">🔄 Buscando informações...</p>';

    try {
        // Primeira requisição: buscar latitude e longitude da cidade
        const geoURL = `https://geocoding-api.open-meteo.com/v1/search?name=${encodeURIComponent(cidade)}&count=1&language=pt&format=json`;
        
        const geoResponse = await fetch(geoURL);
        const geoData = await geoResponse.json();

        // Console para debug - ver o retorno da API
        console.log('Dados de geolocalização:', geoData);

        // Verificar se a cidade foi encontrada
        if (!geoData.results || geoData.results.length === 0) {
            resultado.innerHTML = '<p class="erro">❌ Cidade não encontrada. Tente novamente com outro nome.</p>';
            return;
        }

        // Extrair dados da primeira cidade encontrada
        const { latitude, longitude, name, country } = geoData.results[0];

        // Segunda requisição: buscar o clima atual com base nas coordenadas
        const weatherURL = `https://api.open-meteo.com/v1/forecast?latitude=${latitude}&longitude=${longitude}&current_weather=true&timezone=America/Sao_Paulo`;
        
        const weatherResponse = await fetch(weatherURL);
        const weatherData = await weatherResponse.json();

        // Console para debug - ver o retorno da API
        console.log('Dados de clima:', weatherData);

        // Verificar se há dados de clima
        if (!weatherData.current_weather) {
            resultado.innerHTML = '<p class="erro">❌ Não foi possível obter os dados do clima.</p>';
            return;
        }

        // 4. Tratar o retorno (JSON) e exibir os dados
        const temperatura = weatherData.current_weather.temperature;
        const vento = weatherData.current_weather.windspeed;

        exibirResultado(name, country, temperatura, vento);

    } catch (error) {
        // 5. Tratar erros
        console.error('Erro ao buscar dados:', error);
        resultado.innerHTML = '<p class="erro">❌ Erro ao buscar dados. Verifique sua conexão com a internet.</p>';
    }
}

// Função para exibir o resultado formatado
function exibirResultado(cidade, pais, temperatura, vento) {
    // Desafio 1: Determinar o ícone baseado na temperatura
    let icone = '🌡️';
    if (temperatura < 0) {
        icone = '❄️';
    } else if (temperatura < 10) {
        icone = '🥶';
    } else if (temperatura < 20) {
        icone = '😊';
    } else if (temperatura < 30) {
        icone = '☀️';
    } else {
        icone = '🔥';
    }

    // Desafio 2: Determinar a classe CSS baseada na temperatura
    let classeTemperatura = 'ameno';
    if (temperatura < 5) {
        classeTemperatura = 'muito-frio';
    } else if (temperatura < 15) {
        classeTemperatura = 'frio';
    } else if (temperatura < 25) {
        classeTemperatura = 'ameno';
    } else if (temperatura < 32) {
        classeTemperatura = 'quente';
    } else {
        classeTemperatura = 'muito-quente';
    }

    // Desafio 3: Mensagem personalizada baseada no horário
    const hora = new Date().getHours();
    let saudacao = 'Olá';
    if (hora >= 5 && hora < 12) {
        saudacao = 'Bom dia';
    } else if (hora >= 12 && hora < 18) {
        saudacao = 'Boa tarde';
    } else {
        saudacao = 'Boa noite';
    }

    // Montar o HTML do resultado
    resultado.innerHTML = `
        <div class="clima-info ${classeTemperatura}">
            <div class="cidade-nome">${cidade}, ${pais}</div>
            <div class="icone-clima">${icone}</div>
            <div class="temperatura">${temperatura}°C</div>
            <div class="detalhes">
                <div class="detalhe-item">
                    <span class="detalhe-label">Vento</span>
                    <strong>💨 ${vento} km/h</strong>
                </div>
            </div>
            <div class="mensagem-personalizada">
                ${saudacao}! Em ${cidade}, faz ${temperatura}°C neste momento.
            </div>
        </div>
    `;
}

// 6. Evento do botão "Limpar"
limparBtn.addEventListener('click', () => {
    cidadeInput.value = '';
    resultado.innerHTML = '';
    cidadeInput.focus();
});

// Focar no campo de entrada ao carregar a página
cidadeInput.focus();