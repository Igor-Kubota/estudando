import java.util.Scanner;

public class Ex06{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int valorInicial, valorFinal, somatoria, produto;
        System.out.println("Informe o valor inicial e final:");
        valorInicial = scanner.nextInt();
        valorFinal = scanner.nextInt();
        produto = 1;
        somatoria = 0;
        for(int i = valorInicial; i <= valorFinal; i++){
            somatoria += i;
            produto *= i;
        }
        System.out.println("Soma:" + somatoria);
        System.out.println("Produto:" + produto);
    }
}