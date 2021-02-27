using System.Collections.Generic;
using Cuby.Animation;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Reset
{
    public class ResetVariablesCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
        {
            AnimationManager.Instance.End();
            
            cube.ResetTransformations();
            camera.ResetTransformations();
            
            foreach (var axis in axes)
                axis.ResetTransformations();
        }
    }
}