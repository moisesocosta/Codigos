const restify = require('restify')

const server = restify.createServer()

server.get('/', (req, res) => {
    res.send('Ae! Servidor criado veio com resposta para o path')
})

server.listen(8081, () => {
    console.log('Servidor de pé em http://localhost:8081')
    console.log('Pra derrubar o servidor: crtl + c')
})