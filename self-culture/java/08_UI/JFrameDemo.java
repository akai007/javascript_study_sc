import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JFrameDemo implements ActionListener{
  JFrame frame;
  JTextField num1, num2, resultText;
  JButton bAdd;

  public void go() {
    frame = new JFrame("JFrameDemo");

    JPanel contentPanel = new JPanel();

    bAdd = new JButton("=");
    num1 = new JTextField("num1");
    num2 = new JTextField("num2");
    resultText = new JTextField("结果");

    contentPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
    contentPanel.add(num1);
    contentPanel.add(new JLabel("+"));
    contentPanel.add(num2);
    contentPanel.add(bAdd, BorderLayout.CENTER);
    contentPanel.add(resultText);
    bAdd.addActionListener(this);

    frame.setContentPane(contentPanel);
    frame.pack();
    frame.setVisible(true);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == bAdd) {
      Integer res = Integer.valueOf(num1.getText()) + Integer.valueOf(num2.getText());
      resultText.setText(res+"");
    }
  }

  public static void main(String[] args) {
    new JFrameDemo().go();
  }
}
