using System.Collections.Generic;
using System.Windows.Forms;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Rotation.Y
{
    public class RotateYAxisPositivelyCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
        {
            cube.RotationY += 1;
            foreach (var axis in axes)
            {
                axis.RotationY += 1;
            }
        }
    }
}