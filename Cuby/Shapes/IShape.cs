using System.Collections.Generic;
using System.Drawing;
using Cuby.Utils;

namespace Cuby.Shapes
{
    public interface IShape
    {
        
        /// <summary>
        /// The shape's color.
        /// </summary>
        public Color Color { get; set; }
        
        public List<Vector> VectorBuffer { get; set; }

    }
}