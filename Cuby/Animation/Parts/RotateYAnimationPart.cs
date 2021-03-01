using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Animation.Parts
{
    public class RotateYAnimationPart : IAnimationPart
    {
        public Cube Cube { get; set; }
        public Camera Camera { get; set; }
        public List<Axis> Axes { get; set; }
        
        private int _increment = 1;
        private bool _switchedBack = false;
        
        public void Execute()
        {
            if (_switchedBack && Cube.RotationY == 0)
            {
                _increment = -_increment; // reset incrementor
                _switchedBack = false; // reset bool
                AnimationManager.Instance.Next();
                return;
            }

            Cube.RotationY += _increment;
            Camera.Phi += 1;
            
            foreach (var axis in Axes)
            {
                axis.RotationY += _increment;
            }
            
            if (Cube.RotationY == 45)
            {
                _switchedBack = true;
                _increment = -_increment;
            }
        }
    }
}