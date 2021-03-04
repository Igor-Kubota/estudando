import java.util.Scanner;

public class Ex03{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String usuario, senha, usuario_entrada, senha_entrada;
        System.out.println("Informe usuario e senha para cadastro:");
        usuario = scanner.nextLine();
        senha = scanner.nextLine();
        do{
            System.out.println("Informe o usuário para Login:");
            usuario_entrada = scanner.nextLine();
            System.out.println("Informe a senha para Login:");
            senha_entrada = scanner.nextLine();
        } while (!usuario.equalsIgnoreCase(usuario_entrada) || !senha.equalsIgnoreCase(senha_entrada)); //Para saber mais: https://beginnersbook.com/2013/12/java-string-equals-and-equalsignorecase-methods-example/
        System.out.println("Bem Vindo ao Sistema!");
    }
}