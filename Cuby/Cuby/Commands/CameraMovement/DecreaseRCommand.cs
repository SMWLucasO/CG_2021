using Cuby.Shapes;

namespace Cuby.Commands.CameraMovement
{
    public class DecreaseRCommand: ICommand
    {
        public void Execute(Cube cube, Camera camera) => camera.R -= 1;
    }
}