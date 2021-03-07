using Cuby.Shapes;

namespace Cuby.Commands.CameraMovement
{
    public class IncreaseThetaCommand: ICommand
    {
        public void Execute(Cube cube, Camera camera) => camera.Theta += 1;
    }
}