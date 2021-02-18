using System.Collections.Generic;
using System.Drawing;

namespace MatrixTransformations
{
    public class AxisX
    {
        private int size;

        public List<Vector> vb;

        public AxisX(int size=100)
        {
            this.size = size;

            vb = new List<Vector>();
            vb.Add(new Vector(0, 0));
            vb.Add(new Vector(size, 0));
        }

        public void Draw(Graphics g, List<Vector> vb)
        {
            Pen pen = new Pen(Color.Red, 2f);
            g.DrawLine(pen, vb[0].x, vb[0].y, vb[1].x, vb[1].y);
            Font font = new Font("Arial", 10);
            PointF p = new PointF(vb[1].x, vb[1].y);
            g.DrawString("x", font, Brushes.Red, p);
        }
    }
}
