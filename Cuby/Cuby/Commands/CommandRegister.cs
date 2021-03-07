using System.Windows.Forms;
using System.Collections.Generic;
using Cuby.Commands.Animation;
using Cuby.Commands.CameraMovement;
using Cuby.Commands.Movement.X;
using Cuby.Commands.Movement.Y;
using Cuby.Commands.Movement.Z;
using Cuby.Commands.Placement;
using Cuby.Commands.Reset;
using Cuby.Commands.Rotation.X;
using Cuby.Commands.Rotation.Y;
using Cuby.Commands.Rotation.Z;
using Cuby.Commands.Scaling;

namespace Cuby.Commands
{
    public static class CommandRegister
    {
        
        public static Form1 Form { get; set; }
        
        /// <summary>
        /// The command registry.
        /// </summary>
        /// <returns>All registered commands</returns>
        public static IDictionary<char, ICommand> FetchCharacterizedCommands() => new Dictionary<char, ICommand>()
        {
            { 's', new ScaleCubeUpCommand() },
            { 'S', new ScaleCubeDownCommand() },
            { (char)Keys.PageUp, new DecreaseZCommand() },
            { (char)Keys.PageDown, new IncreaseZCommand() },
            { 'x', new RotateXAxisPositivelyCommand() },
            { 'X', new RotateXAxisNegativelyCommand() },
            { 'y', new RotateYAxisPositivelyCommand() },
            { 'Y', new RotateYAxisNegativelyCommand() },
            { 'z', new RotateZAxisPositivelyCommand() },
            { 'Z', new RotateZAxisNegativelyCommand() },
            { 'A', new StartAnimationCommand() },
            { 'C', new ResetVariablesCommand() },
            { 'r', new DecreaseRCommand() },
            { 'R', new IncreaseRCommand() },
            { 'd', new DecreaseDCommand() },
            { 'D', new IncreaseDCommand() },
            { 't', new DecreaseThetaCommand() },
            { 'T', new IncreaseThetaCommand() },
            { 'p', new DecreasePhiCommand() },
            { 'P', new IncreasePhiCommand() },
        };

        public static IDictionary<Keys, ICommand> FetchNonCharacterizedCommands() => new Dictionary<Keys, ICommand>()
        {
            { Keys.Up, new IncreaseYCommand() },
            { Keys.Down, new DecreaseYCommand() },
            { Keys.Right, new IncreaseXCommand() },
            { Keys.Left, new DecreaseXCommand() },
            { Keys.Space, new PlaceCubeCommand() }
        };
    }
}