using System.Collections.Generic;
using System.Drawing;
using Cuby.Shapes;
using Cuby.Utils;

namespace Cuby.Axes
{
    public abstract class Axis : IShape
    {
        
        public Color Color { get; set; }

        public int Size { get; set; }

        public List<Vector> VectorBuffer { get; set; }
        
        public Axis(int size)
        {
            this.Size = size;
            this.VectorBuffer = new List<Vector>();
        }

        public abstract void Draw(Graphics g, List<Vector> vectorBuffer);

    }
}