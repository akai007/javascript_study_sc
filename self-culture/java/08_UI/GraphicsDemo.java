import java.awt.Color;
import java.awt.Graphics;

import javax.swing.*;

public class GraphicsDemo {
  public static void main(String[] args) {
    JFrame frame = new JFrame("Graphics");
    frame.setSize(400,400);
    frame.setContentPane(new MyPanel());
    frame.setVisible(true);
  }
}

class MyPanel extends JPanel{
  public void paintComponent(Graphics g) {
    g.setColor(Color.green);
    g.drawOval(200, 200, 100, 100);
    
  }
}
