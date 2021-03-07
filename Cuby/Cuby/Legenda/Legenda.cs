using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace Cuby
{
    public static class Legenda
    {
        private static IList<WatchedObject> _watching = new List<WatchedObject>();
        
        /// <summary>
        /// Watch an object and add given properties to the legenda.
        /// </summary>
        /// <param name="obj">The object to watch</param>
        /// <param name="members">A list of tuples, where a tuple is (PropertyName, Description)</param>
        /// <returns></returns>
        public static void WatchObject(object obj, IList<(string, string)> members)
        {
            _watching.Add(new WatchedObject()
            {
                Object = obj,
                Properties = members.Select(m =>
                {
                    var prop = new WatchedProperty
                    {
                        Name = m.Item1,
                        Description = m.Item2,
                    };

                    prop.InitialValue = GetValue(obj, prop);

                    return prop;
                }).ToList()
            });
        }
        
        /// <summary>
        /// Replace an object that is currently watched.
        /// </summary>
        /// <param name="newObj">The object to watch</param>
        /// <param name="prevObj">The object to repalce</param>
        /// <returns></returns>
        public static void ReplaceObject(object newObj, object prevObj)
        {
            foreach (var watching in _watching)
            {
                if (watching.Object == prevObj)
                    watching.Object = newObj;
            }
        }

        /// <summary>
        /// Get the value of an property.
        /// </summary>
        /// <param name="obj">The object</param>
        /// <param name="property">WatchedProperty to get the value of</param>
        /// <returns></returns>
        private static string GetValue(object obj, WatchedProperty property)
        {
            var val = obj.GetType().GetProperty(property.Name)?.GetValue(obj) ?? "";

            if (val is float f)
                val = Math.Round(f, 3, MidpointRounding.ToEven);

            if (val is double d)
                val = Math.Round(d, 3, MidpointRounding.ToEven);

            return val.ToString();
        }
        
        /// <summary>
        /// Render the legenda
        /// </summary>
        /// <param name="graphics">graphics</param>
        /// <returns></returns>
        public static void Render(Graphics graphics)
        {
            var x = 0;
            var y = 0;
            Font font = new Font("Arial", 12);
            
            foreach (var watching in _watching)
            {
                //get the width of the longest item
                var width = graphics.MeasureString(watching.LongestName, font).Width;
                
                foreach (var param in watching.Properties)
                {
                    var val = GetValue(watching.Object, param);
                    var color = val == param.InitialValue ? Color.Black : Color.DarkOrange;
                    
                    graphics.DrawString($"{param.Name}:", font, new SolidBrush(Color.Black), new PointF(x, y));
                    graphics.DrawString($"{val}", font, new SolidBrush(color), new PointF(x + width + 20, y));
                    graphics.DrawString($"{param.Description}", font, new SolidBrush(Color.Black), new PointF(x + width + 70, y));
                    y += 20;
                }

                y += 20;
            }
            
            graphics.DrawString($"Color Meanings:", font, new SolidBrush(Color.Black), new PointF(x, y));
            graphics.DrawString($"Changed Value", font, new SolidBrush(Color.DarkOrange), new PointF(x, y + 20));
            graphics.DrawString($"Initial Value", font, new SolidBrush(Color.Black), new PointF(x, y + 40));
        }
    }
}