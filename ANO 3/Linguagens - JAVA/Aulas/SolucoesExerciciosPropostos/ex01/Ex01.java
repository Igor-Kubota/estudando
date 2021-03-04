import java.util.Scanner;

public class Ex01{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Informe seu nome completo:");
        String nome = scanner.nextLine();
        System.out.println("Informe seu R.A.:");
        String ra = scanner.nextLine();
        System.out.println("Informe seu telefone:");
        String telefone = scanner.nextLine();
        System.out.println("Informe seu email:");
        String email = scanner.nextLine();
        System.out.println("Informe sua idade:");
        int idade = Integer.parseInt(scanner.nextLine());
        String saida = String.format("{nome:%s,\nr.a.:%s,\ntelefone:%s,\nemail:%s,\nidade:%d}",
        nome,ra,telefone,email,idade);
        System.out.println(saida);
        scanner.close();    
    }
}