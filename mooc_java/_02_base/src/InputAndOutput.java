import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class InputAndOutput {
    public static void scanner() {
        System.out.print("请输入一个整数：");
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        System.out.printf("%d 的平方等于 %d", a, a*a);
    }

    public static void inout() {
        char c = ' ';
        System.out.print("Please input a char: ");
        try {
            c = (char) System.in.read();
        }catch (IOException e){}

        System.out.println("You have entered: " + c);
    }

    public static void bufferInOut() {
        System.out.print("Please input a line: ");
        String s = "";
        try {
            BufferedReader in = new BufferedReader((
                    new InputStreamReader(System.in)
            ));
            s = in.readLine();
        }catch (IOException e) {}

        System.out.println("You input a line:");
        System.out.println("" + s);
    }



}
