using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using Cuby;
using Cuby.Shapes;
using Cuby.Utils;
using NUnit.Framework;

namespace Tests
{
    public class TransformationUtilTest
    {
        [Test]
        public void TestScale()
        {
            var cube = new Cube(Color.Black)
            {
                Scale = 1.1f
            };
            var v = TransformationUtil.ApplyEffects(cube, new List<Vector>() {new Vector(0, 3, 4)}).First();

            Assert.AreEqual(0, v.X);
            Assert.AreEqual(3.3f, v.Y, 0.01);
            Assert.AreEqual(4.4f, v.Z, 0.01);
        }
        
        [Test]
        public void TestTransform()
        {
            var cube = new Cube(Color.Black)
            {
                TranslationX = 1.1f,
                TranslationY = -2f,
                TranslationZ = 3f
            };
            var v = TransformationUtil.ApplyEffects(cube, new List<Vector>() {new Vector(0, 3, 4)}).First();

            Assert.AreEqual(1.1f, v.X, 0.01);
            Assert.AreEqual(1f, v.Y, 0.01);
            Assert.AreEqual(7f, v.Z, 0.01);
        }

        [Test]
        public void TestRotate()
        {
            var cube = new Cube(Color.Black)
            {
                RotationX = 5,
                RotationY = 3,
                RotationZ = 30
            };
            var v = TransformationUtil.ApplyEffects(cube, new List<Vector>() {new Vector(0, 3, 4)}).First();

            Assert.AreEqual(-1.28860044f, v.X, 0.01);
            Assert.AreEqual(2.23320222f, v.Y, 0.01);
            Assert.AreEqual(4.28396034f, v.Z, 0.01);
        }

        [Test]
        public void TestViewpointTransformation()
        {
            var cube = new Cube(Color.Black)
            {
                RotationX = 5,
                RotationY = 3,
                RotationZ = 30
            };
            var camera = new Camera()
            {
                D = 800,
                Theta = 100,
                R = 10,
                Phi = -10
            };
            
            var v = TransformationUtil.ViewpointTransformation(cube, new List<Vector>() {new Vector(0, 3, 4)}, camera, 800, 800).First();
            
            Assert.AreEqual(399.479065f, v.X, 0.01);
            Assert.AreEqual(403.604126f, v.Y, 0.01);
            Assert.AreEqual(-6.57379913f, v.Z, 0.01);
        }
    }
}