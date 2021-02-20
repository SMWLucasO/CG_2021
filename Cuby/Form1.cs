using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using Cuby.Axes;
using Cuby.Commands;
using Cuby.Shapes;
using Cuby.Utils;

namespace Cuby
{
    public partial class Form1 : Form
    {
        // The axes 
        private List<Axis> Axes { get; set; }
        
        // Window dimensions
        private const int Width = 800;
        private const int Height = 600;
        
        // our cube
        public Cube Cube { get; set; }

        public Camera Camera { get; set; }
        
        private IDictionary<char, ICommand> Commands { get; set; } 
        
        public Form1()
        {
            InitializeComponent();

            ((Control) this).Width = Width;
            ((Control) this).Height = Height;
            this.DoubleBuffered = true;

            // register all the commands
            Commands = CommandRegister.FetchCommands();

            this.Camera = new Camera();
            
            // register the axes
            Axes = new List<Axis>()
            {
                new AxisX(),
                new AxisY(),
                new AxisZ()
            };

            this.Cube = new Cube(Color.Gold);

        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            
            foreach (var axis in Axes)
            {
                axis.Draw(
                    e.Graphics,
                    TransformationUtil.ViewpointTransformation(axis.VectorBuffer, this.Camera, Width, Height)
                );
            }

            Cube.Draw(
                e.Graphics,
                TransformationUtil.ViewpointTransformation(
                    TransformationUtil.ApplyEffects(Cube.CubeInfo, Cube.Vertexbuffer), this.Camera, Width, Height)
            );
        }

        private void Form1_KeyDown(object sender, KeyPressEventArgs e)
        {
            // convert key to lowercase single-character string.
            if (Commands.TryGetValue(e.KeyChar, out ICommand command))
                command.Execute(Cube, Axes, this.Camera);
            
            if (e.KeyChar == (char)Keys.Escape)
                Application.Exit();
        }
    }
}
