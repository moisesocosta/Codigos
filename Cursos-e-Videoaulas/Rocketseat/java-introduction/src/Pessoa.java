public class Pessoa extends Ser{

  String sobrenome;

  public Pessoa(String nome, int idade, String sobrenome){
    super(nome, idade);
    this.sobrenome = sobrenome;
  }
  void criaApp(){
    Main meuApp = new Main();
    System.out.println(meuApp.name);
    System.out.println(meuApp.salary);
    this.idade = 22;
  }

  @Override
  public String saudacao(){
    return "Olá, seu nome é " + this.nome;
  }
}