using Cuby.Shapes;

namespace Cuby.Commands.CameraMovement
{
    public class DecreaseThetaCommand: ICommand
    {
        public void Execute(Cube cube, Camera camera) => camera.Theta -= 1;
    }
}