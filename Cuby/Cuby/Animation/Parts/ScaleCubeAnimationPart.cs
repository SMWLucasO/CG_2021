﻿using System;
using System.Collections.Generic;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Animation.Parts
{
    public class ScaleCubeAnimationPart : IAnimationPart
    {
        public Cube Cube { get; set; }
        public Camera Camera { get; set; }

        private float _increment = 0.01f;
        private bool _switchedBack = false;
        
        public void Execute()
        {

            Cube.Scale += _increment;
            Camera.Theta -= 1;

            if (Cube.Scale >= 1.5f && !_switchedBack)
            {
                _switchedBack = true;
                _increment = -_increment;
            }

            if (Math.Abs(Cube.Scale - 1) < 0.001 && _switchedBack)
            {
                Cube.Scale = 1f;
                _increment = -_increment; // reset increment.
                _switchedBack = false;
                AnimationManager.Instance.Next();
            }

        }
    }
}