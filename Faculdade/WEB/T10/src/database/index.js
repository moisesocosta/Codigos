import Sequeliz from "sequelize"
import config from "../config/database"
import Empresa from "../app/models/Empresa"
import sequelize from "sequelize"

const models = [Empresa]

class Database{
    constructor(){
        this.connection = new Sequelize(config)

        this.init()
    }

    init(){
        models.forEach(model => model.init(this.connection))
    }
}

export default new Database()