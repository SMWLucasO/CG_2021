using System.Collections.Generic;
using System.Windows.Forms;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Scaling
{
    public class ScaleCubeDownCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
            => cube.Scale -= 0.1f;
    }
}