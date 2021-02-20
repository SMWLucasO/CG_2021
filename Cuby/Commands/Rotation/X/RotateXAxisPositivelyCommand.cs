using System.Collections.Generic;
using System.Windows.Forms;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Rotation.X
{
    public class RotateXAxisPositivelyCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
        {
            cube.RotationX += 1;
            foreach (var axis in axes)
            {
                axis.RotationX += 1;
            }
        }
    }
}