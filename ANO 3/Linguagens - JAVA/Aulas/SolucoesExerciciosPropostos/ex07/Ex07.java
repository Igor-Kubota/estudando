import java.util.Scanner;

public class Ex07{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String valor;
        int soma = 0;
        System.out.println("Informe um valor inteiro:");
        valor = scanner.nextLine();
        for(int i = 0; i < valor.length(); i++)
            soma += Integer.parseInt(""+valor.charAt(i));
        System.out.println("Somatória:" + soma);
    }
}