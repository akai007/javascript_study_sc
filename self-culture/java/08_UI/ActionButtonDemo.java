import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.border.Border;

public class ActionButtonDemo {
  JFrame frame = new JFrame("Two States Button Demo");
  JCheckBox cb1 = new JCheckBox("JCheckbox1");
  JCheckBox cb2 = new JCheckBox("JCheckbox2");
  JCheckBox cb3 = new JCheckBox("JCheckbox3");
  JCheckBox cb4 = new JCheckBox("JCheckbox4");
  JCheckBox cb5 = new JCheckBox("JCheckbox5");
  JCheckBox cb6 = new JCheckBox("JCheckbox6");
  JRadioButton rb1 = new JRadioButton("JRadioButton1");
  JRadioButton rb2 = new JRadioButton("JRadioButton2");
  JRadioButton rb3 = new JRadioButton("JRadioButton3");
  JRadioButton rb4 = new JRadioButton("JRadioButton4");
  JRadioButton rb5 = new JRadioButton("JRadioButton5");
  JRadioButton rb6 = new JRadioButton("JRadioButton6");
  JTextArea ta = new JTextArea();



  
  public void go() {
    
    JPanel p1 = new JPanel();
    // JPanel p2 = new JPanel();
    // JPanel p3 = new JPanel();
    // JPanel p4 = new JPanel();
    // JPanel p5 = new JPanel();
    // JPanel pa = new JPanel();
    // JPanel pb = new JPanel();
    Container contentPane = frame.getContentPane();

    contentPane.setLayout(new FlowLayout(0, 0, 0));
    contentPane.add(p1);

    p1.add(cb1);
    cb1.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        if (e.getSource() == cb1) {
          System.out.println("cb1 clicked " + cb1.isSelected());
        }
      }
    });

    frame.pack();
    frame.setVisible(true);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    
  }

  public static void main(String[] args) {
    ActionButtonDemo demo = new ActionButtonDemo();
    demo.go();
  }
}
