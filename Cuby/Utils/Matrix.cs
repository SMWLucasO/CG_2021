using System;
using System.Text;
using System.Windows.Forms;

namespace Cuby.Utils
{
    public enum Rotation
    {
        X, Y, Z
    }
    
    public class Matrix : IEquatable<Matrix>
    {
        public float[,] InternalMatrix { get; set; } = new float[4, 4];

        public Matrix()
        {
            
        }
        public Matrix(float m11, float m12, float m13,
                      float m21, float m22, float m23,
                      float m31, float m32, float m33)
        {
            
            // our values
            InternalMatrix[0, 0] = m11; InternalMatrix[0, 1] = m12; InternalMatrix[0, 2] = m13;
            InternalMatrix[1, 0] = m21; InternalMatrix[1, 1] = m22; InternalMatrix[1, 2] = m23;
            InternalMatrix[2, 0] = m31; InternalMatrix[2, 1] = m32; InternalMatrix[2, 2] = m33;
            
            
            // around our values.
            InternalMatrix[3, 0] = 0; InternalMatrix[3, 1] = 0; InternalMatrix[3, 2] = 0;
            InternalMatrix[3, 0] = 0; InternalMatrix[3, 1] = 0; InternalMatrix[3, 2] = 0;
            
            InternalMatrix[3, 3] = 1;

        }

        public Matrix(Vector v)
        {
            InternalMatrix[0, 0] = v.x;
            InternalMatrix[1, 0] = v.y;
            InternalMatrix[2, 0] = v.z;
            InternalMatrix[3, 0] = 1;
        }

        public static Matrix operator +(Matrix m1, Matrix m2)
        {
            Matrix result = ZeroMatrix();
            // not allowed
            if (m1.InternalMatrix.GetLength(0) != m1.InternalMatrix.GetLength(1))
                throw new Exception();

            for (int i = 0; i < m1.InternalMatrix.GetLength(0); i++)
                for (int j = 0; j < m1.InternalMatrix.GetLength(1); j++)
                    result.InternalMatrix[i,j] = m1.InternalMatrix[i, j] + m2.InternalMatrix[i, j];

            return result;
        }

        public static Matrix operator -(Matrix m1, Matrix m2)
        {
            Matrix result = ZeroMatrix();
            
            
            if (m1.InternalMatrix.GetLength(0) != m1.InternalMatrix.GetLength(1))
                throw new Exception();

            for (int i = 0; i < m1.InternalMatrix.GetLength(0); i++)
                for (int j = 0; j < m1.InternalMatrix.GetLength(1); j++)
                    result.InternalMatrix[i,j] = m1.InternalMatrix[i, j] - m2.InternalMatrix[i, j];

            return m1;
        }
        public static Matrix operator *(Matrix m1, float f)
        {
            Matrix result = ZeroMatrix();
            
            for (int i = 0; i < m1.InternalMatrix.GetLength(0); i++)
                for (int j = 0; j < m1.InternalMatrix.GetLength(1); j++)
                    result.InternalMatrix[i,j] = m1.InternalMatrix[i, j] * f;


            return result;
        }

        public static Matrix operator *(float f, Matrix m1)
        {
            return m1 * f; // refer to the other operator overloader
        }
        public static Matrix operator *(Matrix m1, Matrix m2)
        {

            Matrix result = ZeroMatrix();

            // loop through columns and rows
            for(int i = 0; i < m1.InternalMatrix.GetLength(0); i++)
            {
                for(int j = 0; j < m1.InternalMatrix.GetLength(1); j++)
                {
                    // multiply each element of the row, by each element of the column and sum this up.
                    for (int k = 0; k < m1.InternalMatrix.GetLength(1); k++)
                        result.InternalMatrix[i, j] += m1.InternalMatrix[i, k] * m2.InternalMatrix[k, j];
                }
            }

            return result;
        }

        public static Vector operator *(Matrix m1, Vector v)
        {
            Vector result = new Vector();
            Matrix tempRes = m1 * new Matrix(v);

            result.x = tempRes.InternalMatrix[0, 0];
            result.y = tempRes.InternalMatrix[1, 0];
            result.z = tempRes.InternalMatrix[2, 0];

            return result;
        }
        

        public static Matrix Identity() =>
            new Matrix(
                1, 0, 0,
                0, 1, 0,
                0, 0, 1
            );

        public static Matrix ZeroMatrix() 
            => new Matrix(0,0,0,0,0,0,0,0,0);

        public static Matrix ScaleMatrix(float s)
        {
            Matrix v = Identity() * s;
            v.InternalMatrix[3, 3] = 1;
            return v;
        }

        public static Matrix TranslateMatrix(Vector v)
        {
            Matrix matrix = Identity();
            matrix.InternalMatrix[0, 3] = v.x;
            matrix.InternalMatrix[1, 3] = v.y;
            matrix.InternalMatrix[2, 3] = v.z;
            return matrix;
        }

        public static Matrix RotateMatrix(Rotation rotation, float degrees)
        {
            return rotation switch
            {
                Rotation.X => RotateMatrixX(degrees),
                Rotation.Y => RotateMatrixY(degrees),
                Rotation.Z => RotateMatrixZ(degrees),
                _ => null
            };
        }
        
        public static Matrix RotateMatrixZ(float degrees)
        {
            float rads = DegreesToRadians(degrees);
            return new Matrix
            (
                (float)Math.Cos(rads), -((float)Math.Sin(rads)), 0,
                (float)Math.Sin(rads), (float)Math.Cos(rads), 0,
                0, 0, 1
            );
        }

        public static Matrix RotateMatrixX(float degrees)
        {
            float rads = DegreesToRadians(degrees);
            return new Matrix
            (
                1, 0, 0,
                0, (float)Math.Cos(rads), -((float)Math.Sin(rads)),
                0, (float)Math.Sin(rads), (float)Math.Cos(rads)
            );
        }

        public static Matrix RotateMatrixY(float degrees)
        {
            float rads = DegreesToRadians(degrees);
            return new Matrix
            (
                (float)Math.Cos(rads), 0, (float)Math.Sin(rads),
                0, 1, 0,
                -((float)Math.Sin(rads)), 0, (float)Math.Cos(rads)
            );
        }
        
        /// <summary>
        /// Generate the view transformation matrix
        /// </summary>
        /// <param name="camera">The camera from which we look</param>
        /// <returns>View transformation matrix</returns>
        public static Matrix ViewTransformationMatrix(Camera camera)
        {
            float thetaRad = DegreesToRadians(camera.Theta);
            float phiRad = DegreesToRadians(camera.Phi);
            
            Matrix viewTransformation = new Matrix(
                (float) -Math.Sin(thetaRad),                               (float) Math.Cos(thetaRad),                           0,
                (float) (-Math.Cos(thetaRad) * Math.Cos(phiRad)),      (float) (-Math.Cos(phiRad) * Math.Sin(thetaRad)), (float) Math.Sin(phiRad),
                (float) (Math.Cos(thetaRad) * Math.Sin(phiRad)),       (float) (Math.Sin(thetaRad) * Math.Sin(phiRad)),  (float) Math.Cos(phiRad)
            ) {InternalMatrix = {[2, 3] = -camera.R, [3, 3] = 1}};
            
            return viewTransformation;
        }

        public static Matrix ProjectionMatrix(Camera camera, Vector vector)
        {
            Matrix projectionMatrix = new Matrix(
            
                 (-camera.D)/vector.z,  0,                    0,
                 0,                    (-camera.D)/vector.z,  0,
                 0,                    0,                    0
            );

            projectionMatrix.InternalMatrix[3, 3] = 0;

            return projectionMatrix;
        }
        
        public override string ToString()
        {
            return $"[{InternalMatrix[0, 0]}, {InternalMatrix[0, 1]}\r\n{InternalMatrix[1, 0]}, {InternalMatrix[1, 1]}]";
        }

        public bool Equals(Matrix other)
        {
            if (other == null) return false;
            
            for (int i = 0; i < this.InternalMatrix.GetLength(0); i++)
            {
                for (int j = 0; j < this.InternalMatrix.GetLength(1); j++)
                {
                    if (this.InternalMatrix[i, j] != other.InternalMatrix[i, j])
                        return false;
                }
            }

            return true;
        } 

        public static float DegreesToRadians(float degrees)
            => (float) ((Math.PI / 180) * degrees);

    }
}
