import java.util.Scanner;

public class Ex05{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double [] valores = new double[3];
        int posicao;
        valores[0] = 0;
        valores[1] = 1;
        valores[2] = 1;
        System.out.println("Informe uma posição:");
        posicao = scanner.nextInt();
        for(int i = 2; i < posicao; i++){
            valores[0] = valores[1];
            valores[1] = valores[2];
            valores[2] = valores[0] + valores[1];
        }
        if(posicao < 3)
            System.out.println("Valor:" + valores[posicao]);
        else
            System.out.println("Valor:" + valores[2]);

    }
}