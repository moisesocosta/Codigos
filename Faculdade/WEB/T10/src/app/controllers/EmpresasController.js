let empresas = [
    {id: 1, name: "Facebook", site: "http://facebook.com"},
    {id: 2, name: "Google", site: "http://google.com"},
    {id: 3, name: "Hostgator", site: "http://hostgator.com"}
]

class EmpresasController{
    //Listar
    index(req, res){
        res.json(empresas);
    }

    //Recupera uma empresa
    show(req, res){
        const id = parseInt(req.params.id);
        const empresa = empresas.find(items => items.id === id);
        const status = empresa ? 200:404;
        return res.status(status).json(empresa);
    }

    //Cria uma empresa
    create(req, res){
        const {name, site} = req.body;
        const id = empresas[empresas.lenght - 1].id + 1;
        const novaEmpresa = {id, name, site};
        empresas.push(novaEmpresa);
        return res.status(201).json(novaEmpresa);
    }

    //Atualiza uma empresa
    update(req, res){
        const {name, site} = req.body;
        const id = parseInt(req.params.id);
        const index = empresas.findIndex(item => item.id === id);
        const status = index >= 0 ? 200:400;
        if(index >= 0){
            empresas[index] = {id:parseInt(id), name, site};
        }
        return res.status(status).json(empresas[index]);
    }

    //Excluir uma empresa
    destroy(req, res){
        const id = parseInt(req.params.id);
        const index = empresas.findIndex(item => item.id === id);
        const status = index >= 0 ? 200:404;
        if(index >= 0){
            empresas.splice(index, 1);
        }
        return res.status(status).json();
    }
}

export default new EmpresasController();