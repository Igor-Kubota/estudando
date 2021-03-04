import java.util.Scanner;

public class Ex02{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String nome1, nome2;
        int idade1, idade2;
        System.out.println("Informe um nome e uma idade:");
        nome1 = scanner.nextLine();
        idade1 = Integer.parseInt(scanner.nextLine());
        System.out.println("Informe outro nome e outra idade:");
        nome2 = scanner.nextLine();
        idade2 = Integer.parseInt(scanner.nextLine());

        if(idade1 > idade2)
            System.out.println(String.format("%s é mais velho que %s por %d anos!", nome1, nome2, (idade1-idade2)));
        else if (idade1 < idade2)
            System.out.println(String.format("%s é mais velho que %s por %d anos!", nome2, nome1, (idade2-idade1)));
        else
            System.out.println(String.format("%s tem a mesma idade que %s!", nome1, nome2, (idade1-idade2)));
    }
}