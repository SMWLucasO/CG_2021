using System.Collections.Generic;
using System.Drawing;
using Cuby.Utils;

namespace Cuby.Axes
{
    public class AxisX : Axis
    {
        
        public AxisX(int size=100) : base(size)
        {
            VectorBuffer.Add(new Vector(0, 0, 0));
            VectorBuffer.Add(new Vector(size, 0, 0));
        }

        public override void Draw(Graphics g, List<Vector> vectorBuffer)
        {
            Pen pen = new Pen(Color.Red, 2f);
            g.DrawLine(pen, vectorBuffer[0].x, vectorBuffer[0].y, vectorBuffer[1].x, vectorBuffer[1].y);
            Font font = new Font("Arial", 10);
            PointF p = new PointF(vectorBuffer[1].x, vectorBuffer[1].y);
            g.DrawString("x", font, Brushes.Red, p);
        }
    }
}
