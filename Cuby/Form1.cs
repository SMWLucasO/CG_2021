using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using Cuby.Axis;
using Cuby.Shapes;
using Cuby.Utils;

namespace Cuby
{
    public partial class Form1 : Form
    {
        // Axes
        AxisX x_axis;
        AxisY y_axis;

        // Objects
        Square square, square2, square3, square4;

        // Window dimensions
        const int WIDTH = 800;
        const int HEIGHT = 600;

        public Form1()
        {
            InitializeComponent();

            this.Width = WIDTH;
            this.Height = HEIGHT;
            this.DoubleBuffered = true;

            Vector v1 = new Vector();
            Console.WriteLine(v1);
            Vector v2 = new Vector(1, 2, 0);
            Console.WriteLine(v2);
            Vector v3 = new Vector(2, 6, 0);
            Console.WriteLine(v3);
            Vector v4 = v2 + v3;
            Console.WriteLine(v4); // 3, 8

            Matrix m1 = new Matrix();
            Console.WriteLine(m1); // 1, 0, 0, 1
            Matrix m2 = new Matrix(
                2, 4, 0,
                -1, 3, 0,
                0, 0, 0);
            Console.WriteLine(m2);
            Console.WriteLine(m1 + m2); // 3, 4, -1, 4
            Console.WriteLine(m1 - m2); // -1, -4, 1, -2
            Console.WriteLine(m2 * m2); // 0, 20, -5, 5

            Console.WriteLine(m2 * v3); // 28, 16

            // Define axes
            x_axis = new AxisX(200);
            y_axis = new AxisY(200);

            // Create object
            square = new Square(Color.Purple,100);
            
            square2 = new Square(Color.Cyan, 150);
            for (int i = 0; i < square2.vb.Count; i++)
            {
                square2.vb[i] = Matrix.ScaleMatrix(1.5f) * square2.vb[i];
            }
            
            
            square3 = new Square(Color.Orange, 100);
            for (int i = 0; i < square3.vb.Count; i++)
            {
                square3.vb[i] = Matrix.RotateMatrixZ(20) * square3.vb[i];
            }
            
            square4 = new Square(Color.DarkBlue, 100);
            for (int i = 0; i < square4.vb.Count; i++)
            {
                square4.vb[i] = (Matrix.TranslateMatrix(new Vector(75, -25, 0)) * square4.vb[i]);
            }

        }

        protected override void OnPaint(PaintEventArgs e)
        {
            List<Vector> vb;
            base.OnPaint(e);

            vb = ViewpointTransformation(x_axis.vb);
            // Draw axes
            x_axis.Draw(e.Graphics, vb);

            vb = ViewpointTransformation(y_axis.vb);
            
            y_axis.Draw(e.Graphics, vb);

            vb = ViewpointTransformation(square.vb);
            // Draw square
            square.Draw(e.Graphics, vb);

            vb = ViewpointTransformation(square2.vb);
            
            square2.Draw(e.Graphics, vb);
            
            vb = ViewpointTransformation(square3.vb);
            square3.Draw(e.Graphics, vb);
            
            vb = ViewpointTransformation(square4.vb);
            square4.Draw(e.Graphics, vb);

        }

        public static List<Vector> ViewpointTransformation(List<Vector> vb)
        {
            List<Vector> result = new List<Vector>();
            float dx = WIDTH / 2;
            float dy = HEIGHT / 2;

            foreach (var vector in vb)
            {
                Vector v2 = new Vector(vector.x + dx, dy - vector.y, 0);
                result.Add(v2);
            }

            return result;
        }
        
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Escape)
                Application.Exit();
        }
    }
}
