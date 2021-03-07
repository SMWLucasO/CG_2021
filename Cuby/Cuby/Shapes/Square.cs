using System.Collections.Generic;
using System.Drawing;
using Cuby.Utils;

namespace Cuby.Shapes
{
    public class Square : IShape
    {
        public Color Color { get; set; }
        public int Size { get; set; }
        public float Weight { get; set; }

        public List<Vector> VectorBuffer { get; set; }

        public Square(Color color, int size = 100, float weight = 3)
        {
            this.Color = color;
            this.Size = size;
            this.Weight = weight;

            VectorBuffer = new List<Vector>
            {
                new Vector(-size, -size, 0),
                new Vector(size, -size, 0),
                new Vector(size, size, 0),
                new Vector(-size, size, 0)
            };
        }

        public void Draw(Graphics g, List<Vector> vectorBuffer)
        {
            Pen pen = new Pen(Color, Weight);
            g.DrawLine(pen, vectorBuffer[0].X, vectorBuffer[0].Y, vectorBuffer[1].X, vectorBuffer[1].Y);
            g.DrawLine(pen, vectorBuffer[1].X, vectorBuffer[1].Y, vectorBuffer[2].X, vectorBuffer[2].Y);
            g.DrawLine(pen, vectorBuffer[2].X, vectorBuffer[2].Y, vectorBuffer[3].X, vectorBuffer[3].Y);
            g.DrawLine(pen, vectorBuffer[3].X, vectorBuffer[3].Y, vectorBuffer[0].X, vectorBuffer[0].Y);
        }

        public void ResetTransformations() { }
    }
}
