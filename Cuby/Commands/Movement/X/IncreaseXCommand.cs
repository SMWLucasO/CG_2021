using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Movement.X
{
    public class IncreaseXCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
            => cube.TranslationX += 0.1f;
    }
}