using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Rotation.Y
{
    public class RotateYAxisNegativelyCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
            => cube.RotationY -= 1;
        
    }
}