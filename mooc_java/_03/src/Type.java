import java.lang.reflect.Field;
import java.sql.Array;

public class Type {
    // base type
    byte bMax = Byte.MAX_VALUE;
    short sMax = Short.MAX_VALUE;
    int iMax = Integer.MAX_VALUE;
    long lMax = Long.MAX_VALUE;

    float fMax = Float.MAX_VALUE;
    double dMax = Double.MAX_VALUE;

    char cMax = Character.MAX_VALUE;
    boolean b = true;

    Object o = new Object();
    int[] ints = { 3, 4, 5 };
    double[] doubles = { 2.2, 4 };
    Integer [] integers = new Integer[4];

    public static void displayBaseType() {
        Field[] fields = Type.class.getDeclaredFields();
        try {
            for (int i = 0; i < fields.length; i++) {
                Field f = fields[i];
                System.out.println(f.getName() + '\t' + f.getType() + '\t' + f.get(new Type()));
            }
        } catch (Exception e) {}
    }

}
