public class PassValueTest {

  private float ptValue;

  public void changeInt (int value) {
    value = 55;
  }

  public void changeStr (String value) {
    value = new String(" different ");
  }

  public void changeObjValue ( PassValueTest ref ) {
    ref.ptValue = 99f;
  }


  public static void main(String[] args) {
    String str;
    int val;
    PassValueTest pt = new PassValueTest();
    val = 11;
    pt.changeInt(val);
    System.out.println("Int value is : " + val);
    str = new String("hello");
    pt.changeStr(str);
    System.out.println("Str value is : " + str);
    pt.ptValue = 101f;
    pt.changeObjValue(pt);
    System.out.println("Current ptValue is : " + pt.ptValue);
  }
  
}
