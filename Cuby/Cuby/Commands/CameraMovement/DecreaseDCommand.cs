using Cuby.Shapes;

namespace Cuby.Commands.CameraMovement
{
    public class DecreaseDCommand: ICommand
    {
        public void Execute(Cube cube, Camera camera) => camera.D -= 4;
    }
}