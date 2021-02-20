using System.Collections.Generic;
using System.Linq;

namespace Cuby.Utils
{
    public static class TransformationUtil
    {
        
        /// <summary>
        /// Apply a viewpoint transformation to the input vectors.
        /// </summary>
        /// <param name="vectorBuffer">The vectors to transform.</param>
        /// <param name="width">The width of the screen.</param>
        /// <param name="height">The height of the screen.</param>
        /// <returns></returns>
        public static List<Vector> ViewpointTransformation(IEnumerable<Vector> vectorBuffer, int width, int height)
        {
            float dx = width / 2;
            float dy = height / 2;

            return vectorBuffer.Select(vector =>
                new Vector(vector.x + dx, dy - vector.y, 0)
            ).ToList();
        }
        
    }
}