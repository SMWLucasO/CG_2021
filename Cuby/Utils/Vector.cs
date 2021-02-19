using System;
using System.Runtime.CompilerServices;
using System.Text;

namespace Cuby.Utils
{
    public class Vector : IEquatable<Vector>
    {
        public float x, y, z, w;

        public Vector()
        {
            x = 0;
            y = 0;
            z = 0;
            w = 1;
        }

        public Vector(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = 1;
        }

        public static Vector operator +(Vector v1, Vector v2)
        {
            Vector nVec = v1.Clone();
            nVec.x += v2.x;
            nVec.y += v2.y;
            nVec.z += v2.z;
            return nVec;
        }

        public static Vector operator -(Vector v1, Vector v2)
        {
            Vector nVec = v1.Clone();
            nVec.x -= v2.x;
            nVec.y -= v2.y;
            nVec.z -= v2.z;
            return nVec;
        }

        public static Vector operator *(Vector v1, float value)
        {
            Vector nVec = v1.Clone();
            nVec.x *= value;
            nVec.y *= value;
            nVec.z *= value;
            return nVec;
        }

        public static Vector operator *(Vector v1, Vector v2)
        {
            Vector nVec = v1.Clone(); 
            nVec.x *= v2.x;
            nVec.y *= v2.y;
            nVec.z *= v2.z;
            return nVec;
        }

        public override string ToString() => $"({x}, {y})";

        public Vector Clone() => new Vector(this.x, this.y, this.z);

        public bool Equals(Vector other) => this.x == other.x && this.y == other.y && this.z == other.z;
    }
}
