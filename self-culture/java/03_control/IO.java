import java.util.Scanner;

public class IO {
  String testString;
  public static void main(String [] args) {
    // echo();
    // computeBMI();
    test();
  }

  public static void test() {

    IO io = new IO();
    System.out.println(io.testString);
  }

  public static void echo() {
    String message;
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter anything you want: ");
    message = scan.nextLine();
    System.out.println(message);

    scan.close();
  }

  public static void computeBMI() {
    int age;
    double height;
    double weight;

    Scanner scan = new Scanner(System.in);
    System.out.print("How old are you?   : ");
    age = scan.nextInt();

    System.out.print("How tall are you? (e: 1.80)  : ");
    height = scan.nextDouble();

    System.out.print("What your weight? (e: 66.6)   : ");
    weight = scan.nextDouble();

    double bmi = weight/(height*height);
    System.out.println("BMI :" + bmi);

    scan.close();
  }
}
