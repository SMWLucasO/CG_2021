using Cuby.Utils;
using NUnit.Framework;

namespace Tests
{
    public class MatrixTest
    {
        [Test]
        public void TestMatrixAdd()
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
            
            var m2 = new Matrix
            {
                InternalMatrix =
                    new [,] {
                        {1f, 0f, 0f, 0f},
                        {0f, 0f, 0f, 0f},
                        {0f, 0f, 0f, 0f},
                        {0f, 0f, 0f, 1f},
                    }
            };

            var result = m + m2;
            
            Assert.AreEqual(new [,] {
                {6f, 0f, 0f, 0f},
                {0f, 4f, 0f, 0f},
                {0f, 0f, 2f, 0f},
                {0f, 0f, 0f, 2f},
            }, result.InternalMatrix);
        }
        
        [Test]
        public void TestMatrixMultiplyMatrix()
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
            
            var m2 = new Matrix
            {
                InternalMatrix =
                    new [,] {
                        {4f, 0f, 0f, 0f},
                        {0f, 0f, 0f, 0f},
                        {0f, 3f, 3f, 0f},
                        {0f, 0f, 0f, 1f},
                    }
            };

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
            
            var result = m * 3;
            Assert.AreEqual(new [,] {
                {15f, 0f, 0f, 0f},
                {0f, 12f, 0f, 0f},
                {0f, 0f, 6f, 0f},
                {0f, 0f, 0f, 3f},
            }, result.InternalMatrix);
        }
        
        
    }
}