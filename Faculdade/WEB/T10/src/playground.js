import "./database"
import Empresa from "./app/models/Empresa"

class Playground{
    static async play(){
        try{
            const empresa = await Empresa.findByPk(5)
            
            empresa.destroy()
        }catch(e){
            console.log("Erro" + e)
        }

    }
}

Playground.play()