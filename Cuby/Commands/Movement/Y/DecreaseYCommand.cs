using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Movement.Y
{
    public class DecreaseYCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
            => cube.TranslationY -= 0.1f;
    }
}