using System;
using Cuby;
using Cuby.Utils;
using NUnit.Framework;

namespace Tests
{
    public class MatrixTest
    {
        private Matrix GetMatrix1()
        {
            return new Matrix
            {
                InternalMatrix =
                    new [,] {
                        {5f, 0f, 0f, 0f},
                        {0f, 4f, 0f, 0f},
                        {0f, 0f, 2f, 0f},
                        {0f, 0f, 0f, 1f},
                    }
            };
        }

        private Matrix GetMatrix2()
        {
            return new Matrix
            {
                InternalMatrix =
                    new [,] {
                        {1f, 0f, 0f, 0f},
                        {0f, 0f, 0f, 0f},
                        {0f, 0f, 0f, 0f},
                        {0f, 0f, 0f, 1f},
                    }
            };
        }

        private Matrix GetMatrix3()
        {
            return new Matrix
            {
                InternalMatrix =
                    new [,] {
                        {4f, 0f, 0f, 0f},
                        {0f, 0f, 0f, 0f},
                        {0f, 3f, 3f, 0f},
                        {0f, 0f, 0f, 1f},
                    }
            };
        }

        [Test]
        public void TestMatrixAdd()
        {
            var m = GetMatrix1();

            var m2 = GetMatrix2();

            var result = m + m2;
            
            Assert.AreEqual(new [,] {
                {6f, 0f, 0f, 0f},
                {0f, 4f, 0f, 0f},
                {0f, 0f, 2f, 0f},
                {0f, 0f, 0f, 2f},
            }, result.InternalMatrix);
        }
        
        [Test]
        public void TestMatrixSubtract()
        {
            var m = GetMatrix1();

            var m2 = GetMatrix2();

            var result = m - m2;
            
            Assert.AreEqual(new [,] {
                {4f, 0f, 0f, 0f},
                {0f, 4f, 0f, 0f},
                {0f, 0f, 2f, 0f},
                {0f, 0f, 0f, 0f},
            }, result.InternalMatrix);
        }
        
        [Test]
        public void TestMatrixMultiplyMatrix()
        {
            var m = GetMatrix1();

            var m2 = GetMatrix3();

            var result = m * m2;
            
            Assert.AreEqual(new [,] {
                {20f, 0f, 0f, 0f},
                {0f, 0f, 0f, 0f},
                {0f, 6f, 6f, 0f},
                {0f, 0f, 0f, 1f},
            }, result.InternalMatrix);
        }
        
        [Test]
        public void TestMultiplyByVector()
        {
            var m = new Matrix
            {
                InternalMatrix =
                new [,] {
                    {5f, 0f, 0f, 0f},
                    {0f, 4f, 0f, 0f},
                    {0f, 0f, 2f, 0f},
                    {0f, 0f, 0f, 1f},
                }
            };

            var v = new Vector(1, 4, 2);

            var result = m * v;
            var expected = new Vector(5, 16, 4);
            
            Assert.AreEqual(expected.X, result.X);
            Assert.AreEqual(expected.Y, result.Y);
            Assert.AreEqual(expected.Z, result.Z);
        }
        
        [Test]
        public void TestMultiplyByScalar()
        {
            var m = GetMatrix1();
            
            var result = m * 3;
            Assert.AreEqual(new [,] {
                {15f, 0f, 0f, 0f},
                {0f, 12f, 0f, 0f},
                {0f, 0f, 6f, 0f},
                {0f, 0f, 0f, 3f},
            }, result.InternalMatrix);
        }

        [Test]
        public void TestScale()
        {
            var scale = 1.1f;
            var m = Matrix.ScaleMatrix(scale);

            var expect = new Matrix()
            {
                InternalMatrix = new[,]
                {
                    {scale, 0f, 0f, 0f},
                    {0f, scale, 0f, 0f},
                    {0f, 0f, scale, 0f},
                    {0f, 0f, 0f, 1f},
                }
            };
            
            Assert.AreEqual(expect.InternalMatrix, m.InternalMatrix);
        }
        
        [Test]
        public void TestTransform()
        {
            var translate = new Vector(1, 2, 3);
            var m = Matrix.TranslateMatrix(translate);

            var expect = new Matrix()
            {
                InternalMatrix = new[,]
                {
                    {1f, 0f, 0f, translate.X},
                    {0f, 1f, 0f, translate.Y},
                    {0f, 0f, 1f, translate.Z},
                    {0f, 0f, 0f, 1f},
                }
            };
            
            Assert.AreEqual(expect.InternalMatrix, m.InternalMatrix);
        }

        [Test]
        public void TestRotateX()
        {
            var degrees = 45;
            var cos = 0.707106781186548f;
            var sin = 0.707106781186547f;
            var m = Matrix.RotateMatrixX(45);

            var expect = new Matrix()
            {
                InternalMatrix = new[,]
                {
                    {1f, 0f, 0f, 0f},
                    {0f, cos, -sin, 0f},
                    {0f, sin, cos, 0f},
                    {0f, 0f, 0f, 1f},
                }
            };
            
            Assert.AreEqual(expect.InternalMatrix, m.InternalMatrix);
        }


        [Test]
        public void TestRotateY()
        {
            var degrees = 45;
            var cos = 0.707106781186548f;
            var sin = 0.707106781186547f;
            var m = Matrix.RotateMatrixY(45);

            var expect = new Matrix()
            {
                InternalMatrix = new[,]
                {
                    {cos, 0f, sin, 0f},
                    {0f, 1, 0f, 0f},
                    {-sin, 0f, cos, 0f},
                    {0f, 0f, 0f, 1f},
                }
            };
            
            Assert.AreEqual(expect.InternalMatrix, m.InternalMatrix);
        }


        [Test]
        public void TestRotateZ()
        {
            var degrees = 45;
            var cos = 0.707106781186548f;
            var sin = 0.707106781186547f;
            var m = Matrix.RotateMatrixZ(45);

            var expect = new Matrix()
            {
                InternalMatrix = new[,]
                {
                    {cos, -sin, 0f, 0f},
                    {sin, cos, 0f, 0f},
                    {0f, 0f, 1f, 0f},
                    {0f, 0f, 0f, 1f},
                }
            };
            
            Assert.AreEqual(expect.InternalMatrix, m.InternalMatrix);
        }

        [Test]
        public void TestViewTransform()
        {
            var cam = new Camera
            {
                Theta = 100, 
                Phi = -10, 
                R = 10
            };

            var m = Matrix.ViewTransformationMatrix(cam);
            
            var thetaCosSin = (-0.173648186364537, 0.984807751478585);
            var phiCosSin = (0.98480775389387, -0.173648172666779);

            var expected = new Matrix()
            {
                InternalMatrix = new[,]
                {
                    {(float)-thetaCosSin.Item2, (float)thetaCosSin.Item1, 0f, 0f},
                    {(float)(-thetaCosSin.Item1 * phiCosSin.Item1), (float)(-phiCosSin.Item1 * thetaCosSin.Item2), (float)phiCosSin.Item2, 0f},
                    {(float)(thetaCosSin.Item1 * phiCosSin.Item2), (float)(thetaCosSin.Item2 * phiCosSin.Item2), (float)phiCosSin.Item1, -10},
                    {0f, 0f, 0f, 1f},
                }
            };
            
            Assert.AreEqual(expected.InternalMatrix, m.InternalMatrix);
        }

        [Test]
        public void TestProjection()
        {
            var cam = new Camera
            {
                D = 800
            };


            var pos = new Vector(0, 0, 20);
            
            var m = Matrix.ProjectionMatrix(cam, pos);
            var d = -40f;

            var expected = new Matrix()
            {
                InternalMatrix = new[,]
                {
                    {d, 0f, 0f, 0f},
                    {0f, d, 0f, 0f},
                    {0f, 0f, 1f, 0f},
                    {0f, 0f, 0f, 1f}
                }
            };
            
            Assert.AreEqual(expected.InternalMatrix, m.InternalMatrix);
        }

        [Test]
        [TestCase(45, 0.785398163397448f)]
        [TestCase(90, 1.5707963267949f)]
        [TestCase(63, 1.09955742875643f)]
        [TestCase(276, 4.81710873550435f)]
        public void TestDegreesToRadians(float value, float result)
        {
            Assert.AreEqual(result, Matrix.DegreesToRadians(value));
        }
    }
}