using System.Collections.Generic;
using System.Windows.Forms;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Movement.XY
{
    public class IncreaseXYCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
        {
            cube.TranslationX -= 0.1f;
            cube.TranslationY += 0.1f;
        }
    }
}