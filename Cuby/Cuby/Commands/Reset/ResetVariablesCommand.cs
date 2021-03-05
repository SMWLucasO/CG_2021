using System.Collections.Generic;
using Cuby.Animation;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Reset
{
    public class ResetVariablesCommand : ICommand
    {
        public void Execute(Cube cube, Camera camera)
        {
            AnimationManager.Instance.End();
            
            cube.ResetTransformations();
            camera.ResetTransformations();
            
        }
    }
}