using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Rotation.Y
{
    public class RotateYAxisNegativelyCommand : ICommand
    {
        public void Execute(Cube cube, Camera camera)
            => cube.RotationY -= 1;
        
    }
}