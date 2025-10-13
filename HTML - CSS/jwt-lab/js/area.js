(function() {
  const TOKEN_KEY = 'jwt_token';
  const token = localStorage.getItem(TOKEN_KEY);

  if (!token) {
    // Sem token: bloqueia acesso
    alert('Acesso negado: faça login.');
    window.location.replace('index.html');
    return;
  }

  // Preenche textarea com o token
  const tokenBox = document.getElementById('tokenBox');
  tokenBox.value = token;

  // Decodifica payload do JWT para exibir nome
  function decodeBase64Url(str) {
    // Ajusta base64url para base64 comum
    const pad = str.length % 4 === 2 ? '==' : (str.length % 4 === 3 ? '=' : (str.length % 4 === 1 ? '===' : ''));
    const base64 = str.replace(/-/g, '+').replace(/_/g, '/') + pad;
    try {
      return atob(base64);
    } catch (e) {
      return null;
    }
  }

  function parseJwtPayload(jwt) {
    const parts = jwt.split('.');
    if (parts.length !== 3) return null;
    const payloadJson = decodeBase64Url(parts[1]);
    if (!payloadJson) return null;
    try {
      return JSON.parse(payloadJson);
    } catch (e) {
      return null;
    }
  }

  const payload = parseJwtPayload(token);
  const usernameEl = document.getElementById('username');
  if (payload && payload.name) {
    usernameEl.textContent = payload.name;
  } else {
    usernameEl.textContent = 'Usuário autenticado';
  }

  // Logout
  document.getElementById('logout').addEventListener('click', function() {
    localStorage.removeItem(TOKEN_KEY);
    window.location.replace('index.html');
  });

  // Copiar token
  document.getElementById('copyToken').addEventListener('click', async function() {
    try {
      await navigator.clipboard.writeText(tokenBox.value.trim());
      alert('Token copiado!');
    } catch (e) {
      // Fallback
      tokenBox.select();
      document.execCommand('copy');
      alert('Token copiado.');
    }
  });

  // Abrir jwt.io e instruções rápidas
  document.getElementById('openJwtIo').addEventListener('click', async function() {
    try {
      await navigator.clipboard.writeText(tokenBox.value.trim());
    } catch (e) {
      // ignore copy failure here; user can still copy manual
    }
    window.open('https://jwt.io', '_blank');
    alert('O token foi copiado. No jwt.io: cole à esquerda e, em JWT Signature Verification, digite: my-secret-key');
  });

  // Se o usuário clicar no link "jwt.io", também copiamos o mesmo token antes
  const jwtIoLink = document.getElementById('jwtIoLink');
  if (jwtIoLink) {
    jwtIoLink.addEventListener('click', async function() {
      try {
        await navigator.clipboard.writeText(tokenBox.value.trim());
      } catch (e) {
        // ignorar; usuário pode copiar manualmente
      }
    });
  }
})();


