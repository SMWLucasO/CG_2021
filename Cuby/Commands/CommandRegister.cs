using System.Windows.Forms;
using System.Collections.Generic;
using Cuby.Commands.Animation;
using Cuby.Commands.Movement.X;
using Cuby.Commands.Movement.Y;
using Cuby.Commands.Movement.Z;
using Cuby.Commands.Reset;
using Cuby.Commands.Rotation.X;
using Cuby.Commands.Rotation.Y;
using Cuby.Commands.Rotation.Z;
using Cuby.Commands.Scaling;

namespace Cuby.Commands
{
    public static class CommandRegister
    {
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
        };

        public static IDictionary<Keys, ICommand> FetchNonCharacterizedCommands() => new Dictionary<Keys, ICommand>()
        {
            { Keys.Up, new IncreaseYCommand() },
            { Keys.Down, new DecreaseYCommand() },
            { Keys.Right, new IncreaseXCommand() },
            { Keys.Left, new DecreaseXCommand() },
        };
    }
}