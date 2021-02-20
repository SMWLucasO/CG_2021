using System.Collections.Generic;
using System.Drawing;
using Cuby.Utils;

namespace Cuby.Axes
{
    public abstract class Axis
    {
        // TODO: Implement super class for axis
        public int Size { get; set; }

        public List<Vector> VectorBuffer; 
        
        public Axis(int size)
        {
            this.Size = size;
            this.VectorBuffer = new List<Vector>();
        }

        public abstract void Draw(Graphics g, List<Vector> vectorBuffer);

    }
}