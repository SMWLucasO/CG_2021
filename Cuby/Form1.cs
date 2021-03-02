using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using Cuby.Animation;
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
        
        private IDictionary<char, ICommand> CharacterizedCommands { get; set; } 
        private IDictionary<Keys, ICommand> NonCharacterizedCommands { get; set; } 
        
        public Form1()
        {
            InitializeComponent();

            ((Control) this).Width = Width;
            ((Control) this).Height = Height;
            this.DoubleBuffered = true;

            // register all the commands
            CharacterizedCommands = CommandRegister.FetchCharacterizedCommands();
            NonCharacterizedCommands = CommandRegister.FetchNonCharacterizedCommands();

            this.Camera = new Camera();

            AnimationManager.Instance.Form = this;
            
            // register the axes
            Axes = new List<Axis>()
            {
                new AxisX(40),
                new AxisY(40),
                new AxisZ(40)
            };

            this.Cube = new Cube(Color.Purple);

        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            
            foreach (var axis in Axes)
            {
                axis.Draw(
                    e.Graphics,
                    TransformationUtil.ViewpointTransformation(axis,
                        TransformationUtil.ApplyEffects(axis, axis.VectorBuffer), this.Camera, Width, Height)
                );
            }

            Cube.Draw(
                e.Graphics,
                TransformationUtil.ViewpointTransformation(Cube,
                    TransformationUtil.ApplyEffects(Cube, Cube.VectorBuffer), this.Camera, Width, Height)
            );
        }

        private void Form1_OnCharacterizedKeyDown(object sender, KeyPressEventArgs e)
        {
            // convert key to lowercase single-character string.
            if (CharacterizedCommands.TryGetValue(e.KeyChar, out ICommand command))
                command.Execute(Cube, this.Camera);
            
            if (e.KeyChar == (char)Keys.Escape)
                Application.Exit();
            
            this.Refresh();
            
        }

        private void Form1_OnNonCharacterizedKeyDown(object sender, KeyEventArgs e)
        {
            if (NonCharacterizedCommands.TryGetValue(e.KeyCode, out ICommand command))
                command.Execute(Cube, this.Camera);
            
            this.Refresh();
        }
    }
}
