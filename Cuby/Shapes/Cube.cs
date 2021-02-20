using System.Collections.Generic;
using System.Drawing;
using Cuby.Shapes.Information;
using Cuby.Utils;

namespace Cuby.Shapes
{
    public class Cube
    {

        //          7----------4
        //         /|         /|
        //        / |        / |                y
        //       /  6-------/--5                |
        //      3----------0  /                 ----x
        //      | /        | /                 /
        //      |/         |/                  z
        //      2----------1
        public List<Vector> Vertexbuffer { get; set; } = new List<Vector>
        {
            new Vector( 1.0f,  1.0f, 1.0f),     //0
            new Vector( 1.0f, -1.0f, 1.0f),     //1
            new Vector(-1.0f, -1.0f, 1.0f),     //2
            new Vector(-1.0f,  1.0f, 1.0f),     //3

            new Vector( 1.0f,  1.0f, -1.0f),    //4
            new Vector( 1.0f, -1.0f, -1.0f),    //5
            new Vector(-1.0f, -1.0f, -1.0f),    //6
            new Vector(-1.0f,  1.0f, -1.0f),    //7

            new Vector( 1.2f,  1.2f, 1.2f),     //0
            new Vector( 1.2f, -1.2f, 1.2f),     //1
            new Vector(-1.2f, -1.2f, 1.2f),     //2
            new Vector(-1.2f,  1.2f, 1.2f),     //3

            new Vector( 1.2f,  1.2f, -1.2f),    //4
            new Vector( 1.2f, -1.2f, -1.2f),    //5
            new Vector(-1.2f, -1.2f, -1.2f),    //6
            new Vector(-1.2f,  1.2f, -1.2f)     //7
        };

        public Color Color { get; set; }
        
        public ShapeInfo CubeInfo { get; set; }

        public Cube(Color c)
        {
            Color = c;
            CubeInfo = new ShapeInfo();
        }

        public void Draw(Graphics g, List<Vector> vb)
        {
            Pen pen = new Pen(Color, 2f);
            g.DrawLine(pen, vb[0].x, vb[0].y, vb[1].x, vb[1].y);    //0 -> 1
            g.DrawLine(pen, vb[1].x, vb[1].y, vb[2].x, vb[2].y);    //1 -> 2
            g.DrawLine(pen, vb[2].x, vb[2].y, vb[3].x, vb[3].y);    //2 -> 3
            g.DrawLine(pen, vb[3].x, vb[3].y, vb[0].x, vb[0].y);    //3 -> 0

            g.DrawLine(pen, vb[4].x, vb[4].y, vb[5].x, vb[5].y);    //4 -> 5
            g.DrawLine(pen, vb[5].x, vb[5].y, vb[6].x, vb[6].y);    //5 -> 6
            g.DrawLine(pen, vb[6].x, vb[6].y, vb[7].x, vb[7].y);    //6 -> 7
            g.DrawLine(pen, vb[7].x, vb[7].y, vb[4].x, vb[4].y);    //7 -> 4

            //pen.DashStyle = DashStyle.DashDot;
            g.DrawLine(pen, vb[0].x, vb[0].y, vb[4].x, vb[4].y);    //0 -> 4
            g.DrawLine(pen, vb[1].x, vb[1].y, vb[5].x, vb[5].y);    //1 -> 5
            g.DrawLine(pen, vb[2].x, vb[2].y, vb[6].x, vb[6].y);    //2 -> 6
            g.DrawLine(pen, vb[3].x, vb[3].y, vb[7].x, vb[7].y);    //3 -> 7

            Font font = new Font("Arial", 12, FontStyle.Bold);
            for (int i = 0; i < 8; i++)
            {
                PointF p = new PointF(vb[i + 8].x, vb[i + 8].y);
                g.DrawString(i.ToString(), font, Brushes.Black, p);
            }
        }
    }   
}
