using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Animation
{
    public interface IAnimationPart
    {

        public Cube Cube { get; set; }
        
        public Camera Camera { get; set; }

        public void Execute();

    }
}