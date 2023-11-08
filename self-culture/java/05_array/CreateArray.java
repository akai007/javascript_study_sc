public class CreateArray {
  public static void main(String[] args) {
    // 静态初始化
    int [] intArr = {1, 2, 3, 4};
    double [] heights = {1.7, 2.4, 4.5, 6,6};
    char vowels [] = {'a', 'b', 'c', 'd'};

    // 动态树池话
    String names[] = new String[4];
    names[0] = "XinXin"; names[1] = "akai"; names[2] = "Leo"; names[3] = "Meng";
    
    for (int i = 0; i < names.length; i++ ) {
      System.out.print(names[i] + "\t");
    }
  }
}
