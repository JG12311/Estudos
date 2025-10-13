(function() {
  const form = document.getElementById('login-form');
  const errorEl = document.getElementById('error');

  // Token fixo 
  const FIXED_TOKEN = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6MTIzLCJuYW1lIjoiRW5nLiBDb21wdXRhXHUwMGU3XHUwMGUzbyIsInJvbGUiOiJKV1QiLCJpYXQiOjE3NTk5ODEzMTcsImV4cCI6MTc1OTk4NDkxN30.b1KfcSFInRwYnvRA0Ae5jYuL59KZmCsufPgISNGq0X0';
  const TOKEN_KEY = 'jwt_token';

  form.addEventListener('submit', function(ev) {
    ev.preventDefault();
    errorEl.hidden = true;
    const email = document.getElementById('email').value.trim();
    const password = document.getElementById('password').value.trim();

    if (!email || !password) {
      errorEl.textContent = 'Preencha e-mail e senha.';
      errorEl.hidden = false;
      return;
    }

    // Salva o token fixo e redireciona
    try {
      localStorage.setItem(TOKEN_KEY, FIXED_TOKEN);
    } catch (e) {
      errorEl.textContent = 'Não foi possível salvar o token.';
      errorEl.hidden = false;
      return;
    }

    window.location.href = 'area.html';
  });
})();


