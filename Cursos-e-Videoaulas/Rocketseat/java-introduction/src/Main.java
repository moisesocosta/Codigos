import java.util.ArrayList;

public class Main {

    public String name;

    static String nomeDoVideo = "começando do zero em java";

    protected int salary;

    public static void main(String[] args) {
        Ser meuSerAnimal = new Cachorro( "Willy", 5, "Moisés");
        Ser meuSerHumano = new Pessoa( "Moisés", 22, "Oliveira");
        meuSerAnimal.setNome("Moisés");
        System.out.println(meuSerAnimal.saudacao());
        System.out.println(meuSerHumano.saudacao());
        System.out.println(nomeDoVideo);
    }

    private void atualizaSalario(){
        this.salary = 4000;
    }

    public int getSalary(){
        this.atualizaSalario();
        return this.salary;
    } 
}