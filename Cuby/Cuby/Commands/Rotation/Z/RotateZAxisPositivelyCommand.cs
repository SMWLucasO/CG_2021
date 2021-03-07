using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Rotation.Z
{
    public class RotateZAxisPositivelyCommand : ICommand
    {
        public void Execute(Cube cube, Camera camera)
            => cube.RotationZ += 1;
        
    }
}