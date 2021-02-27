using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Animation.Parts
{
    public class RotateYAnimationPart : IAnimationPart
    {
        public Cube Cube { get; set; }
        public Camera Camera { get; set; }
        public List<Axis> Axes { get; set; }
        public void Execute()
        {
            throw new System.NotImplementedException();
        }
    }
}