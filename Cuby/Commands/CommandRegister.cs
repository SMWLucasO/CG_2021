using System.Windows.Forms;
using System.Collections.Generic;
using Cuby.Commands.Movement.XY;
using Cuby.Commands.Movement.Z;
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
        public static IDictionary<char, ICommand> FetchCommands() => new Dictionary<char, ICommand>()
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
            { (char)Keys.LButton, new IncreaseXYCommand() },
            { (char)Keys.RButton, new DecreaseXYCommand() },
        };
    }
}