using Cuby.Shapes;

namespace Cuby.Commands.CameraMovement
{
    public class IncreasePhiCommand: ICommand
    {
        public void Execute(Cube cube, Camera camera) => camera.Phi += 1;
    }
}