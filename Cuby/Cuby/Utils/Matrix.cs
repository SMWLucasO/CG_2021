using System;

namespace Cuby.Utils
{
    
    public class Matrix
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
            InternalMatrix[0, 0] = v.X;
            InternalMatrix[1, 0] = v.Y;
            InternalMatrix[2, 0] = v.Z;
            InternalMatrix[3, 0] = 1;
        }

        /// <summary>
        /// Add two matrices together to form a new matrix.
        /// </summary>
        /// <param name="m1">The left matrix</param>
        /// <param name="m2">The right matrix</param>
        /// <returns></returns>
        /// <exception cref="Exception">Exception thrown if the matrices cant be multiplied.</exception>
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

        /// <summary>
        /// Subtract the values of matrix m2 from matrix m1.
        /// </summary>
        /// <param name="m1">The left matrix</param>
        /// <param name="m2">The right matrix</param>
        /// <returns>New matrix with the result</returns>
        /// <exception cref="Exception">Matrices must be of the same size.</exception>
        public static Matrix operator -(Matrix m1, Matrix m2)
        {
            Matrix result = ZeroMatrix();
            
            
            if (m1.InternalMatrix.GetLength(0) != m1.InternalMatrix.GetLength(1))
                throw new Exception();

            for (int i = 0; i < m1.InternalMatrix.GetLength(0); i++)
                for (int j = 0; j < m1.InternalMatrix.GetLength(1); j++)
                    result.InternalMatrix[i,j] = m1.InternalMatrix[i, j] - m2.InternalMatrix[i, j];

            return result;
        }
        
        /// <summary>
        /// Multiply a matrix by a scalar
        /// </summary>
        /// <param name="m1">Left matrix</param>
        /// <param name="f">scalar float value</param>
        /// <returns>New matrix with the multiplication applied</returns>
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
            return m1 * f; // refer to the other operator overload
        }
        
        /// <summary>
        /// Apply matrix multiplication
        /// </summary>
        /// <param name="m1">The left matrix</param>
        /// <param name="m2">The right matrix</param>
        /// <returns>A new matrix with the result</returns>
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

        /// <summary>
        /// Multiply a matrix by a vector
        /// </summary>
        /// <param name="m1">Leftside matrix</param>
        /// <param name="v">Vector to be multiplied</param>
        /// <returns>Vector with the result</returns>
        public static Vector operator *(Matrix m1, Vector v)
        {
            Vector result = new Vector();
            Matrix tempRes = m1 * new Matrix(v);

            result.X = tempRes.InternalMatrix[0, 0];
            result.Y = tempRes.InternalMatrix[1, 0];
            result.Z = tempRes.InternalMatrix[2, 0];

            return result;
        }
        

        /// <summary>
        /// Identity matrix.
        /// </summary>
        /// <returns>The identity matrix</returns>
        public static Matrix Identity() =>
            new Matrix(
                1, 0, 0,
                0, 1, 0,
                0, 0, 1
            );

        /// <summary>
        /// Zero matrix
        /// </summary>
        /// <returns>A matrix with just zeroes</returns>
        public static Matrix ZeroMatrix() => new Matrix()
            {
                InternalMatrix = new[,]
                {
                    {0f, 0f, 0f, 0f},
                    {0f, 0f, 0f, 0f},
                    {0f, 0f, 0f, 0f},
                    {0f, 0f, 0f, 0f}
                }
            };

        /// <summary>
        /// Scaling transformation for the matrix
        /// </summary>
        /// <param name="s">The multiplier for the matrix</param>
        /// <returns>Scale matrix</returns>
        public static Matrix ScaleMatrix(float s)
        {
            Matrix v = Identity() * s;
            v.InternalMatrix[3, 3] = 1;
            return v;
        }

        /// <summary>
        /// Matrix to move a vector to a specified location
        /// </summary>
        /// <param name="v">The specified location</param>
        /// <returns>Translation Matrix</returns>
        public static Matrix TranslateMatrix(Vector v)
        {
            Matrix matrix = Identity();
            matrix.InternalMatrix[0, 3] = v.X;
            matrix.InternalMatrix[1, 3] = v.Y;
            matrix.InternalMatrix[2, 3] = v.Z;
            return matrix;
        }

        /// <summary>
        /// Matrix transformation to rotate across the Z-axis.
        /// </summary>
        /// <param name="degrees">The rotation degree</param>
        /// <returns>Rotation matrix</returns>
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

        /// <summary>
        /// Matrix transformation to rotate across the X-axis.
        /// </summary>
        /// <param name="degrees">The rotation degree</param>
        /// <returns>Rotation matrix</returns>
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

        /// <summary>
        /// Matrix transformation to rotate across the Y-axis.
        /// </summary>
        /// <param name="degrees">The rotation degree</param>
        /// <returns>Rotation matrix</returns>
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
                (float) ((-Math.Cos(thetaRad)) * Math.Cos(phiRad)),          (float) ((-Math.Cos(phiRad)) * Math.Sin(thetaRad)), (float) Math.Sin(phiRad),
                (float) (Math.Cos(thetaRad) * Math.Sin(phiRad)),           (float) (Math.Sin(thetaRad) * Math.Sin(phiRad)),  (float) Math.Cos(phiRad)
            ) {InternalMatrix = {[2, 3] = -camera.R, [3, 3] = 1}};
            
            return viewTransformation;
        }

        /// <summary>
        /// Generate a projection matrix for the vector.
        /// </summary>
        /// <param name="camera">The camera which is being projected for</param>
        /// <param name="vector">The vector to project</param>
        /// <returns>Projection Matrix</returns>
        public static Matrix ProjectionMatrix(Camera camera, Vector vector)
        {
            float vecZ = vector.Z;
            
            Matrix projectionMatrix = new Matrix(
            
                 camera.D/-vecZ,  0,                    0,
                 0,                    camera.D/-vecZ,  0,
                 0,                  0,                 1
            );

            projectionMatrix.InternalMatrix[3, 3] = 1;

            return projectionMatrix;
        }

        /// <summary>
        /// Convert degrees into radians.
        /// </summary>
        /// <param name="degrees">The degrees to convert.</param>
        /// <returns>The degrees converted to radian.</returns>
        public static float DegreesToRadians(float degrees)
            => (float) ((Math.PI / 180) * degrees);

    }
}
