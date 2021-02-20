using System.Collections.Generic;
using System.Drawing;
using Cuby.Utils;

namespace Cuby.Shapes
{
    public class Square
    {
        Color color;
        private int size;
        private float weight;

        public List<Vector> vb;

        public Square(Color color, int size = 100, float weight = 3)
        {
            this.color = color;
            this.size = size;
            this.weight = weight;

            vb = new List<Vector>();
            vb.Add(new Vector(-size, -size, 0));
            vb.Add(new Vector(size, -size, 0));
            vb.Add(new Vector(size, size, 0));
            vb.Add(new Vector(-size, size, 0));
        }

        public void Draw(Graphics g, List<Vector> vb)
        {
            Pen pen = new Pen(color, weight);
            g.DrawLine(pen, vb[0].X, vb[0].Y, vb[1].X, vb[1].Y);
            g.DrawLine(pen, vb[1].X, vb[1].Y, vb[2].X, vb[2].Y);
            g.DrawLine(pen, vb[2].X, vb[2].Y, vb[3].X, vb[3].Y);
            g.DrawLine(pen, vb[3].X, vb[3].Y, vb[0].X, vb[0].Y);
        }
    }
}
