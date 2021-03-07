using System.Collections.Generic;
using System.Windows.Forms;
using Cuby.Axes;
using Cuby.Shapes;

namespace Cuby.Commands
{
    public interface ICommand
    {
        void Execute(Cube cube, Camera camera);
        
    }
}