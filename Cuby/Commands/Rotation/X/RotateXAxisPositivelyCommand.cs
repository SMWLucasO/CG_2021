﻿using System.Collections.Generic;
using System.Windows.Forms;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands.Rotation.X
{
    public class RotateXAxisPositivelyCommand : ICommand
    {
        public void Execute(Cube cube, Camera camera)
            => cube.RotationX += 1;
            
        
    }
}