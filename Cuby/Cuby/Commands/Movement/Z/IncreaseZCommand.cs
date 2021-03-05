using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Movement.Z
{
    public class IncreaseZCommand : ICommand
    {
        public void Execute(Cube cube, Camera camera) 
            => cube.TranslationZ += 0.1f;
    }
}