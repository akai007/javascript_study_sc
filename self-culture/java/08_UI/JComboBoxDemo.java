import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.border.Border;

public class JComboBoxDemo {
  JFrame frame = new JFrame("ComboBoxDemo");

  public void go() {
    String[] itemList = {"One", "Two", "Three", "Four", "Five"};
    JComboBox jcb = new JComboBox(itemList);
    
    JPanel p1 = new JPanel();
    Container contentPane = frame.getContentPane();

    p1.add(jcb);
    jcb.addItem("Six Six Six");
    jcb.removeItem("One");
    
    jcb.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        if (e.getSource() == jcb) {
          jcb.insertItemAt((String)jcb.getSelectedItem(), 0);
        }
      }
    });

    contentPane.setLayout(new FlowLayout(0, 0, 0));
    contentPane.add(p1);

    frame.pack();
    frame.setVisible(true);
    frame.setLocation(600, 800);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }

  public static void main(String[] args) {
    JComboBoxDemo demo = new JComboBoxDemo();
    demo.go();
  }
}
