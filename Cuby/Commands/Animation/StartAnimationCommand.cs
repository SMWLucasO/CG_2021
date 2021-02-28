﻿using System.Collections.Generic;
using Cuby.Animation;
using Cuby.Animation.Parts;
using Cuby.Axes;
using Cuby.Commands.Reset;
using Cuby.Shapes;

namespace Cuby.Commands.Animation
{
    public class StartAnimationCommand : ICommand
    {
        public void Execute(Cube cube, List<Axis> axes, Camera camera)
        {
            if (AnimationManager.Instance.AnimationHasStarted)
                return;

            // Reset the  variables before starting the animation.
            new ResetVariablesCommand().Execute(cube, axes, camera);
            
            // Start the animation.
            AnimationManager.Instance.AnimationHasStarted = true;
            AnimationManager.Instance.AnimationParts = GetAnimation(cube, camera, axes);
            AnimationManager.Instance.Start();
        }

        private List<IAnimationPart> GetAnimation(Cube cube, Camera camera, List<Axis> axes)
        {
            return new List<IAnimationPart>()
            {
                new ScaleCubeAnimationPart() {Cube = cube, Camera = camera, Axes = axes },
                new RotateXAnimationPart() {Cube = cube, Camera = camera, Axes = axes },
                new RotateYAnimationPart() {Cube = cube, Camera = camera, Axes = axes },
                new ResetAnimationPart() {Cube = cube, Camera = camera, Axes = axes }
            };
        }
        
    }
}