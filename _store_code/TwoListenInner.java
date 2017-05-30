import java.awt.*;
import java.awt.event.*;

public class TwoListenInner{
    private Frame f;
    private TextField tf;

    public static void main( String ars[])
    {
        TwoListenInner that= new TwoListenInner();
        that.go();
    }
    public void go()
    {
        f = new Frame("Two Listeners example");
        f.add("North",new Label("Click"));
        tf=new TextField(30);
        f.add("South",tf);
        f.addMouseMotionListener(new MouseMotionHandler());
        f.addMouseListener(new MouseEventHandler());
        f.setSize(300,200);
        f.setVisible(true);
    }

    public class MouseMotionHandler extends MouseMotionAdapter
    {
        public void mouseDragged(MouseEvent e)
        {
            String s="Mousedragging: X="+e.getX()+"Y="+e.getY();
            tf.setText(s);
        }
    }

    public class MouseEventHandler extends MouseAdapter
    {
        public void mouseEntered(MouseEvent e)
        {
            String s ="the mouse entered";
            tf.setText(s);
        }
        public void mouseExited(MouseEvent e)
        {
            String s="the mouse left";
            tf.setText(s);
        }
    }
}
