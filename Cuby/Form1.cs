using System.Collections.Generic;
using System.Drawing;
using System.Linq;
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

        private IDictionary<Keys, ICommand> Commands { get; set; } 
        
        public Form1()
        {
            InitializeComponent();

            ((Control) this).Width = Width;
            ((Control) this).Height = Height;
            this.DoubleBuffered = true;

            Commands = new Dictionary<Keys, ICommand>();
            
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
                    TransformationUtil.ViewpointTransformation(axis.VectorBuffer, Width, Height)
                );
            }
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            // convert key to lowercase single-character string.
            Commands[e.KeyCode].Execute(Cube, Axes);
            if (e.KeyCode == Keys.Escape)
                Application.Exit();
        }
    }
}
