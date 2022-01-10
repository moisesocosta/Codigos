import Sequelize, {Model} from 'sequelize'

class Empresa extends Model{
    static init(sequelize){
        super.init(
            {
                name: Sequelize.STRING,
                site: Sequelize.STRING,
                status: Sequelize.ENUM("ACTIVE","ARCHIVED")
            },
            {
                sequelize,  
            }
        )
    }
}

export default Empresa