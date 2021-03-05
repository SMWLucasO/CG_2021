using Cuby.Utils;
using NUnit.Framework;

namespace Tests
{
    public class VectorTest
    {
        [Test]
        public void TestVectorMultiplyScalar()
        {
            var v = new Vector(1, 3, 2);
            v *= 5;
            Assert.AreEqual(5, v.X);
            Assert.AreEqual(15, v.Y);
            Assert.AreEqual(10, v.Z);
        }
        
        [Test]
        public void TestVectorMultiplyVector()
        {
            var v = new Vector(1, 3, 2);
            v *= new Vector(-1, -1, 0);
            Assert.AreEqual(-1, v.X);
            Assert.AreEqual(-3, v.Y);
            Assert.AreEqual(0, v.Z);
        }

        [Test]
        public void TestVectorAddVector()
        {
            var v = new Vector(1, 3, 2);
            v += new Vector(2, 1, 0);
            Assert.AreEqual(3, v.X);
            Assert.AreEqual(4, v.Y);
            Assert.AreEqual(2, v.Z);
        }
        
        [Test]
        public void TestVectorSubVector()
        {
            var v = new Vector(1, 3, 2);
            v -= new Vector(1, 2, 3);
            Assert.AreEqual(0, v.X);
            Assert.AreEqual(1, v.Y);
            Assert.AreEqual(-1, v.Z);
        }
    }
}