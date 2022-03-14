const nome = document.querySelector('#nome').textContent;
const getNome = () => `Sr. ${nome}`;
const sobrenome = document.querySelector('#sobrenome').textContent;
const nomeCompleto = nome + " " + "\n" + sobrenome;
const nomeCompletoTS = `${getNome()} ${sobrenome}`;

console.log('Nome: ', nome);
console.log('Sobrenome: ', sobrenome);
console.log('Nome completo: ', nomeCompleto);
console.log('Nome completo com Template String: ', nomeCompletoTS);

document.querySelector('#conteudo').textContent = nomeCompletoTS;