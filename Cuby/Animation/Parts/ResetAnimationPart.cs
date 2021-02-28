using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Animation.Parts
{
    public class ResetAnimationPart : IAnimationPart
    {
        public Cube Cube { get; set; }
        public Camera Camera { get; set; }
        public List<Axis> Axes { get; set; }
        public void Execute()
        {
            if (Camera.Theta == Camera.ThetaDefault && Camera.Phi == Camera.PhiDefault)
                AnimationManager.Instance.Next();

            if (Camera.Theta != Camera.ThetaDefault)
                Camera.Theta += 1;

            if (Camera.Phi != Camera.PhiDefault)
                Camera.Phi -= 1;

        }
    }
}