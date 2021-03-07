using Cuby.Shapes;

namespace Cuby.Commands.CameraMovement
{
    public class IncreaseRCommand: ICommand
    {
        public void Execute(Cube cube, Camera camera) => camera.R += 1;
    }
}