
class LeftHand extends Thread {
  public void run() {
    for (int i = 0; i < 10; i++) {
      System.out.println("LeftHand run" + (i+1) + "time(s)");
      try {
        sleep(1000);
      } catch (Exception e) {
        // TODO: handle exception
      }
    }
  }
}
class RightHand extends Thread {
  public void run() {
    for (int i = 0; i < 10; i++) {
      System.out.println("RightHand run" + (i+1) + "time(s)");
      try {
        sleep(1000);
      } catch (Exception e) {
        // TODO: handle exception
      }
    }
  }
}

class FootThread implements Runnable {
  private int i = 0;
  public void run() {
    for (; i < 20; i++) {
      System.out.println(Thread.currentThread().getName() + "Foot run" + (i+1) + "time(s)");
      try {
        Thread.sleep(1000);
      } catch (Exception e) {
        // TODO: handle exception
      }
    }
  }
}

public class ThreadTest {
  public static void main(String[] args) {
    LeftHand leftHand = new LeftHand();
    RightHand rightHand = new RightHand();
    leftHand.start();
    rightHand.start();

    FootThread footThread = new FootThread();
    Thread leftFoot = new Thread(footThread, "left");
    Thread rightFoot = new Thread(footThread, "right");
    leftFoot.start();
    rightFoot.start();
  }
}
