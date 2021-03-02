using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Movement.Y
{
    public class IncreaseYCommand : ICommand
    {
        public void Execute(Cube cube, Camera camera)
            => cube.TranslationY += 0.1f;
    }
}