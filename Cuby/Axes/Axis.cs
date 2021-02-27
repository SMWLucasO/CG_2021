using System.Collections.Generic;
using System.Drawing;
using Cuby.Shapes;
using Cuby.Shapes.Information;
using Cuby.Utils;

namespace Cuby.Axes
{
    public abstract class Axis : IShape, IRotatable
    {
        
        public Color Color { get; set; }

        public int RotationX { get; set; }
        public int RotationY { get; set; }
        public int RotationZ { get; set; }
        
        public int Size { get; set; }

        public List<Vector> VectorBuffer; 
        
        public Axis(int size)
        {
            this.Size = size;
            this.VectorBuffer = new List<Vector>();
        }

        public abstract void Draw(Graphics g, List<Vector> vectorBuffer);
        
        /// <summary>
        /// Reset applied transformations.
        /// </summary>
        public void ResetTransformations()
        {
            RotationX = 0;
            RotationY = 0;
            RotationZ = 0;
        }
        
    }
}