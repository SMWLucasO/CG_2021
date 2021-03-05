using System.Collections.Generic;
using System.Drawing;

namespace Cuby
{
    public static class Legenda
    {
        private static IDictionary<object, IList<(string,string)>> _watching = new Dictionary<object, IList<(string,string)>>();
        
        public static void WatchObject(object obj, IList<(string, string)> members)
        {
            _watching.Add(obj, members);
        }

        public static void Render(Graphics graphics)
        {
            var x = 0;
            var y = 0;
            Font font = new Font("Arial", 12);
            foreach (var watching in _watching)
            {
                foreach (var param in watching.Value)
                {
                    var val = watching.Key.GetType().GetProperty(param.Item1)?.GetValue(watching.Key) ?? "";
                    graphics.DrawString($"{param.Item1}:", font, new SolidBrush(Color.Black), new PointF(x, y));
                    graphics.DrawString($"{val}", font, new SolidBrush(Color.Black), new PointF(x + 130, y));
                    graphics.DrawString($"{param.Item2}", font, new SolidBrush(Color.Black), new PointF(x + 200, y));
                    y += 20;
                }
                
                y += 20;
            }
        }
    }
}