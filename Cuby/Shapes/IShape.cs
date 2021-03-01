using System.Drawing;

namespace Cuby.Shapes
{
    public interface IShape
    {
        
        /// <summary>
        /// The shape's color.
        /// </summary>
        public Color Color { get; set; }

        public void ResetTransformations();

    }
}