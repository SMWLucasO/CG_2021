using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace Cuby
{
    public static class Legenda
    {
        private static IList<WatchedObject> _watching = new List<WatchedObject>();
        
        public static void WatchObject(object obj, IList<(string, string)> members)
        {
            _watching.Add(new WatchedObject()
            {
                Object = obj,
                Properties = members.Select(m => new WatchedProperty
                {
                    Name = m.Item1,
                    Description = m.Item2
                }).ToList()
            });
        }

        public static void Render(Graphics graphics)
        {
            var x = 0;
            var y = 0;
            Font font = new Font("Arial", 12);
            foreach (var watching in _watching)
            {
                var width = graphics.MeasureString(watching.LongestName, font).Width;
                foreach (var param in watching.Properties)
                {
                    var val = watching.Object.GetType().GetProperty(param.Name)?.GetValue(watching.Object) ?? "";

                    if (val is float f)
                        val = Math.Round(f, 3, MidpointRounding.ToEven);

                    if (val is double d)
                        val = Math.Round(d, 3, MidpointRounding.ToEven);
                    
                    graphics.DrawString($"{param.Name}:", font, new SolidBrush(Color.Black), new PointF(x, y));
                    graphics.DrawString($"{val}", font, new SolidBrush(Color.Black), new PointF(x + width + 20, y));
                    graphics.DrawString($"{param.Description}", font, new SolidBrush(Color.Black), new PointF(x + width + 70, y));
                    y += 20;
                }
                
                y += 20;
            }
        }
    }
}