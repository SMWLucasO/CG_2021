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
        float[,] mat = new float[4, 4];

        public Matrix()
        {
            
        }
        public Matrix(float m11, float m12, float m13,
                      float m21, float m22, float m23,
                      float m31, float m32, float m33)
        {
            
            // our values
            mat[0, 0] = m11; mat[0, 1] = m12; mat[0, 2] = m13;
            mat[1, 0] = m21; mat[1, 1] = m22; mat[1, 2] = m23;
            mat[2, 0] = m31; mat[2, 1] = m32; mat[2, 2] = m33;
            
            
            // around our values.
            mat[3, 0] = 0; mat[3, 1] = 0; mat[3, 2] = 0;
            mat[3, 0] = 0; mat[3, 1] = 0; mat[3, 2] = 0;
            
            mat[3, 3] = 1;

        }

        public Matrix(Vector v)
        {
            mat[0, 0] = v.x;
            mat[1, 0] = v.y;
            mat[2, 0] = v.z;
            mat[3, 0] = 1;
        }

        public static Matrix operator +(Matrix m1, Matrix m2)
        {
            // not allowed
            if (m1.mat.GetLength(0) != m1.mat.GetLength(1))
                throw new Exception();

            for (int i = 0; i < m1.mat.GetLength(0); i++)
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                    m1.mat[i, j] += m2.mat[i, j];

            return m1;
        }

        public static Matrix operator -(Matrix m1, Matrix m2)
        {

            if (m1.mat.GetLength(0) != m1.mat.GetLength(1))
                throw new Exception();

            for (int i = 0; i < m1.mat.GetLength(0); i++)
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                    m1.mat[i, j] -= m2.mat[i, j];

            return m1;
        }
        public static Matrix operator *(Matrix m1, float f)
        {
            for (int i = 0; i < m1.mat.GetLength(0); i++)
                for (int j = 0; j < m1.mat.GetLength(1); j++)
                    m1.mat[i, j] *= f;


            return m1;
        }

        public static Matrix operator *(float f, Matrix m1)
        {
            return m1 * f; // refer to the other operator overloader
        }
        public static Matrix operator *(Matrix m1, Matrix m2)
        {

            Matrix result = new Matrix();

            // loop through columns and rows
            for(int i = 0; i < m1.mat.GetLength(0); i++)
            {
                for(int j = 0; j < m1.mat.GetLength(1); j++)
                {
                    // multiply each element of the row, by each element of the column and sum this up.
                    for (int k = 0; k < m1.mat.GetLength(1); k++)
                        result.mat[i, j] += m1.mat[i, k] * m2.mat[k, j];
                }
            }

            m1.mat = result.mat;

            return m1;
        }

        public static Vector operator *(Matrix m1, Vector v)
        {
            Vector result = new Vector();
            Matrix tempRes = m1 * new Matrix(v);

            result.x = tempRes.mat[0, 0];
            result.y = tempRes.mat[1, 0];
            result.z = tempRes.mat[2, 0];

            return result;
        }
        

        public static Matrix Identity()
        {
            return new Matrix(
                1, 0, 0,
                0, 1, 0,
                0, 0, 1
            );
        }

        public static Matrix ScaleMatrix(float s)
        {
            Matrix v = Identity() * s;
            v.mat[3, 3] = 1;
            return v;
        }

        public static Matrix TranslateMatrix(Vector v)
        {
            Matrix matrix = Identity();
            matrix.mat[0, 3] = v.x;
            matrix.mat[1, 3] = v.y;
            matrix.mat[2, 3] = v.z;
            return matrix;
        }

        public static Matrix RotateMatrix(Rotation rotation, float degrees)
        {
            switch (rotation)
            {
                case Rotation.X:
                    return RotateMatrixX(degrees);
                case Rotation.Y:
                    return RotateMatrixY(degrees);
                case Rotation.Z:
                    return RotateMatrixZ(degrees);
            }

            return null;
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

        public override string ToString()
        {
            return $"[{mat[0, 0]}, {mat[0, 1]}\r\n{mat[1, 0]}, {mat[1, 1]}]";
        }

        public bool Equals(Matrix other)
        {
            if (other == null) return false;
            
            for (int i = 0; i < this.mat.GetLength(0); i++)
            {
                for (int j = 0; j < this.mat.GetLength(1); j++)
                {
                    if (this.mat[i, j] != other.mat[i, j])
                        return false;
                }
            }

            return true;
        } 

        public static float DegreesToRadians(float degrees)
            => (float) ((Math.PI / 180) * degrees);

    }
}
