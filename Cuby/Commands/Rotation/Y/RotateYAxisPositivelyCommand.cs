using System.Collections.Generic;
using System.Windows.Forms;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Rotation.Y
{
    public class RotateYAxisPositivelyCommand : ICommand
    {
        public void Execute(Cube cube, Camera camera)
            => cube.RotationY += 1;
        
    }
}