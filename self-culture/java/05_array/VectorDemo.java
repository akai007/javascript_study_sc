import java.util.Vector;

public class VectorDemo {
  
  public static void main(String[] args) {
    Vector<String> arr = new Vector<String>(10);
    System.out.println(arr.size());
    arr.addElement("Akai");
    System.out.println(arr.size());
    arr.addElement("Akai");
    System.out.println(arr.size());

    arr.insertElementAt("Leo", 1);
    System.out.println(arr.toString());

    arr.setElementAt("Meng", 1);
    System.out.println(arr.toString());

    System.out.println(arr.contains("LIAOKAI"));
    System.out.println(arr.contains("Akai"));
    System.out.println(arr.indexOf("Akai"));
    System.out.println(arr.lastIndexOf("Akai"));
    arr.addElement("Akai");
    arr.addElement("Akai");
    arr.addElement("Akai");
    arr.addElement("Akai");
    arr.addElement("Akai");
    arr.addElement("Akai");
    arr.addElement("Akai");
    arr.addElement("Akai");
    arr.addElement("Akai");
    arr.addElement("Akai");
    System.out.println(arr.capacity()); // 装满时默认成倍增长


  }
}
