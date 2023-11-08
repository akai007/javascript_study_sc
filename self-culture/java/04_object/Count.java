import java.util.Hashtable;
import java.util.Map;

public class Count extends CounteHelper {

  public static void main(String[] args) {
    new Count();
    new Count();
    new Count();
    new Count();
    new Count();
    System.out.println(Count.getCount());
  }
}

class CounteHelper {
  Counter c = new Counter(Thread.currentThread().getStackTrace()[2].getClassName());

  public static int getCount() {
    System.out.println(Thread.currentThread().getStackTrace()[2].getClassName());
    return Counter.getCount(Thread.currentThread().getStackTrace()[2].getClassName());
  }
}


class Counter {
  static Map<String, Integer> counts = new Hashtable<String, Integer>();

  public Counter(String className) {
    this.setCounts(className);
  }

  public void setCounts(String className) {
    if ( counts.containsKey(className) ) {
      counts.put(className, ((Integer)counts.get(className)) + 1);
    } else {
      counts.put(className, 1);
    }
  }

  public static int getCount(String className) {
    return (Integer)counts.get(className);
  }
}
