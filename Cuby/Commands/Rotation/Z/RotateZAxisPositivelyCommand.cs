using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Rotation.Z
{
    public class RotateZAxisPositivelyCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
        {
            cube.RotationZ += 1;
            foreach (var axis in axes)
            {
                axis.RotationZ += 1;
            }
        }
    }
}