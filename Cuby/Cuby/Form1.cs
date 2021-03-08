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

        public List<Cube> PlacedCubes { get; set; } = new List<Cube>();
        
        // our cube
        private Cube _cube;

        public Cube Cube
        {
            get => _cube;
            set
            {
                var prev = _cube;
                _cube = value;
                
                Legenda.ReplaceObject(_cube, prev);
            }
        }

        public Camera Camera { get; set; }
        
        private IDictionary<char, ICommand> CharacterizedCommands { get; set; } 
        private IDictionary<Keys, ICommand> NonCharacterizedCommands { get; set; }
        
        public Form1()
        {
            InitializeComponent();

            ((Control) this).Width = Width;
            ((Control) this).Height = Height;
            this.DoubleBuffered = true;

            CommandRegister.Form = this;
            
            // register all the commands
            CharacterizedCommands = CommandRegister.FetchCharacterizedCommands();
            NonCharacterizedCommands = CommandRegister.FetchNonCharacterizedCommands();

            this.Camera = new Camera();

            AnimationManager.Instance.Form = this;
            
            // register the axes
            Axes = new List<Axis>()
            {
                new AxisX(1),
                new AxisY(1),
                new AxisZ(1)
            };

            this.Cube = new Cube(Color.Purple);
            
            Legenda.WatchObject(Cube, new List<(string, string)>
            {
                (nameof(Cube.Scale), "S/s"),
                (nameof(Cube.TranslationX), "Left/Right"),
                (nameof(Cube.TranslationY), "Up/Down"),
                (nameof(Cube.TranslationZ), "PgDn/PgUp"),
                (nameof(Cube.RotationX), "X/x"),
                (nameof(Cube.RotationY), "Y/y"),
                (nameof(Cube.RotationZ), "Z/z"),
            });
            Legenda.WatchObject(Camera, new List<(string, string)>
            {
                (nameof(Camera.R), "R/r"),
                (nameof(Camera.D), "D/d"),
                (nameof(Camera.Theta), "T/t"),
                (nameof(Camera.Phi), "P/p"),
            });
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);
            
            foreach (var axis in Axes)
            {
                axis.Draw(
                    e.Graphics,
                    TransformationUtil.ViewpointTransformation(
                        TransformationUtil.ApplyEffects(axis, axis.VectorBuffer), this.Camera, Width, Height)
                );
            }


            foreach (Cube cube in PlacedCubes)
            {
                cube.Draw(
                    e.Graphics,
                    TransformationUtil.ViewpointTransformation(
                        TransformationUtil.ApplyEffects(cube, cube.VectorBuffer), this.Camera, Width, Height)
                );
            }
            
            Cube.Draw(
                e.Graphics,
                TransformationUtil.ViewpointTransformation(
                    TransformationUtil.ApplyEffects(Cube, Cube.VectorBuffer), this.Camera, Width, Height)
            );
            
            Legenda.Render(e.Graphics);
        }

        private void Form1_OnCharacterizedKeyDown(object sender, KeyPressEventArgs e)
        {
            // convert key to lowercase single-character string.
            if (CharacterizedCommands.TryGetValue(e.KeyChar, out ICommand command))
            {
                command.Execute(Cube, this.Camera);
                this.Refresh();
            }
            
            if (e.KeyChar == (char)Keys.Escape)
                Application.Exit();
        }

        private void Form1_OnNonCharacterizedKeyDown(object sender, KeyEventArgs e)
        {
            if (!NonCharacterizedCommands.TryGetValue(e.KeyCode, out ICommand command)) return;
            command.Execute(Cube, this.Camera);
            this.Refresh();
        }
    }
}
