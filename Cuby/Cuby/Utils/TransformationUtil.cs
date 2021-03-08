using System.Collections.Generic;
using System.Linq;
using Cuby.Shapes;
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
                Vector nVec = new Vector(vector.X, vector.Y, vector.Z) { W = vector.W };

                nVec = viewTransform * nVec;
                
                Matrix projMat = Matrix.ProjectionMatrix(camera, nVec);
                
                nVec = projMat * nVec;
                
                vb.Add(new Vector(nVec.X + dx, dy - nVec.Y, nVec.Z) { W = nVec.W});
            }


            return vb;
        }

        /// <summary>
        /// Apply rotation, translation and rotation effects from the shape, on the shape.
        /// </summary>
        /// <param name="shape">The shape containing the transformation data.</param>
        /// <param name="vectorBuffer">The vectors being updated.</param>
        /// <returns></returns>
        public static IEnumerable<Vector> ApplyEffects(IShape shape, List<Vector> vectorBuffer)
        {
            List<Vector> transformedVectors = new List<Vector>();

            foreach (var vector in vectorBuffer)
            {
                Matrix resultMatrix = null;
                Vector nVec = new Vector(vector.X, vector.Y, vector.Z) { W = vector.W };

                
                // apply scaling if possible
                if (shape is IScalable scalable) resultMatrix = Matrix.ScaleMatrix(scalable.Scale);
                
                // apply rotation if possible
                if (shape is IRotatable rotatable)
                {
                    if (resultMatrix == null)
                        resultMatrix = (Matrix.RotateMatrixX(rotatable.RotationX) *
                                        Matrix.RotateMatrixY(rotatable.RotationY) *
                                        Matrix.RotateMatrixZ(rotatable.RotationZ));
                    else
                        resultMatrix =
                            (Matrix.RotateMatrixX(rotatable.RotationX) *
                            Matrix.RotateMatrixY(rotatable.RotationY) *
                            Matrix.RotateMatrixZ(rotatable.RotationZ)) * resultMatrix;
                }

                // apply translation if possible
                if (shape is ITranslatable translatable)
                {
                    if (resultMatrix == null)
                        resultMatrix =
                            Matrix.TranslateMatrix(
                                new Vector(translatable.TranslationX, translatable.TranslationY,
                                    translatable.TranslationZ)
                            );
                    else
                        resultMatrix = Matrix.TranslateMatrix(
                            new Vector(translatable.TranslationX, translatable.TranslationY, translatable.TranslationZ)
                        ) * resultMatrix;
                }

                // generate the resulting vector of applying the transformations, if there are any transformations.
                if (resultMatrix != null)
                    nVec = resultMatrix * nVec;
                
                transformedVectors.Add(nVec);
            }

            return transformedVectors;
        }
    }
}