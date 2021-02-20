using System;
using System.Runtime.CompilerServices;
using System.Text;

namespace Cuby.Utils
{
    public class Vector : IEquatable<Vector>
    {
        public float X, Y, Z, W;

        public Vector()
        {
            X = 0;
            Y = 0;
            Z = 0;
            W = 1;
        }

        public Vector(float x, float y, float z)
        {
            this.X = x;
            this.Y = y;
            this.Z = z;
            this.W = 1;
        }

        public static Vector operator +(Vector v1, Vector v2)
        {
            Vector nVec = v1.Clone();
            nVec.X += v2.X;
            nVec.Y += v2.Y;
            nVec.Z += v2.Z;
            return nVec;
        }

        public static Vector operator -(Vector v1, Vector v2)
        {
            Vector nVec = v1.Clone();
            nVec.X -= v2.X;
            nVec.Y -= v2.Y;
            nVec.Z -= v2.Z;
            return nVec;
        }

        public static Vector operator *(Vector v1, float value)
        {
            Vector nVec = v1.Clone();
            nVec.X *= value;
            nVec.Y *= value;
            nVec.Z *= value;
            return nVec;
        }

        public static Vector operator *(Vector v1, Vector v2)
        {
            Vector nVec = v1.Clone(); 
            nVec.X *= v2.X;
            nVec.Y *= v2.Y;
            nVec.Z *= v2.Z;
            return nVec;
        }

        public Vector Clone() => new Vector(this.X, this.Y, this.Z) { W = this.W };

        public bool Equals(Vector other) => this.X == other.X && this.Y == other.Y && this.Z == other.Z;
    }
}
