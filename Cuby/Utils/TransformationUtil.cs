using System;
using System.Collections.Generic;
using System.Linq;
using Cuby.Shapes.Information;

namespace Cuby.Utils
{
    public static class TransformationUtil
    {
        /// <summary>
        /// Apply a viewpoint transformation to the input vectors.
        /// </summary>
        /// <param name="vectorBuffer">The vectors to transform.</param>
        /// <param name="camera">The camera from which we look</param>
        /// <param name="width">The width of the screen.</param>
        /// <param name="height">The height of the screen.</param>
        /// <returns></returns>
        public static List<Vector> ViewpointTransformation(IEnumerable<Vector> vectorBuffer, Camera camera, int width, int height)
        {
            List<Vector> vb = new List<Vector>();
            Matrix viewTransform = Matrix.ViewTransformationMatrix(camera);
            
            float dx = width / 2;
            float dy = height / 2;

            foreach (var vector in vectorBuffer)
            {
                Vector nVec = new Vector(vector.x, vector.y, vector.z) { w = vector.w };

                nVec = viewTransform * nVec;
                
                if (vector.z != 0)
                {
                    Matrix projMat = Matrix.ProjectionMatrix(camera, nVec);
                    nVec = projMat * nVec;
                }
                
                vb.Add(new Vector(nVec.x + dx, dy - nVec.y, 0));
            }


            return vb;
        }

        public static IEnumerable<Vector> ApplyEffects(ShapeInfo info, List<Vector> vectorBuffer)
        {
            List<Vector> transformedVectors = new List<Vector>();

            foreach (var vector in vectorBuffer)
            {
                Vector nVec = new Vector(vector.x, vector.y, vector.z) { w = vector.w };

                // Leftmost: translations
                // Then: rotations
                // then scale
                // T * R * S
                nVec = Matrix.TranslateMatrix(new Vector(info.TranslationX, info.TranslationY, info.TranslationZ)) *
                       (Matrix.RotateMatrixX(info.RotationX) * Matrix.RotateMatrixY(info.RotationY) * Matrix.RotateMatrixZ(info.RotationZ)) * 
                       Matrix.ScaleMatrix(info.Scale) * nVec;

                
                transformedVectors.Add(nVec);
            }

            return transformedVectors;
        }
    }
}