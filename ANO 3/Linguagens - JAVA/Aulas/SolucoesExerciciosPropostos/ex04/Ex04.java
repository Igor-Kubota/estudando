import java.util.Scanner;

public class Ex04{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String frase1, fraseTeste;
        System.out.println("Informe uma frase:");
        frase1 = scanner.nextLine();
        fraseTeste = frase1.trim().replace(" ", ""); //https://www.geeksforgeeks.org/java-string-trim-method-example/ e https://www.javatpoint.com/java-string-replace
        boolean igual = true;
        for(int i = 0; i < fraseTeste.length(); i++){
            igual = fraseTeste.charAt(i) == fraseTeste.charAt(fraseTeste.length()-i-1);
            if(!igual)
                break;
        }
        if(igual)
            System.out.println("A frase: "+frase1+" é um Palindromo!");
        else
            System.out.println("A frase: "+frase1+" não é um Palindromo!");
    }
}