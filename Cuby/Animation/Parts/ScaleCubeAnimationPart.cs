using System;
using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Animation.Parts
{
    public class ScaleCubeAnimationPart : IAnimationPart
    {
        public Cube Cube { get; set; }
        public Camera Camera { get; set; }
        public List<Axis> Axes { get; set; }

        private float _increment = 0.01f;
        
        public void Execute()
        {

            Cube.Scale += _increment;
            Camera.Theta -= 1;

            if (_increment >= 1.5f && _increment >= 0)
                _increment = -_increment;

            if (Math.Abs(Cube.Scale - 1) <= 0.0001 && _increment < 0)
                AnimationManager.Instance.Next();

        }
    }
}