using System;
using System.Drawing;
using System.Windows.Forms;
using Cuby.Shapes;

namespace Cuby.Commands.Placement
{
    public class PlaceCubeCommand : ICommand
    {
        public void Execute(Cube cube, Camera camera)
        {
            Form1 f = CommandRegister.Form;
            if (f == null) return;
            
            if (f.Cube != null)
                f.PlacedCubes.Add(f.Cube);

            Random random = new Random();

            f.Cube = new Cube(Color.FromArgb(random.Next(0, 256), random.Next(0, 256), random.Next(0, 256)));

        }
    }
}