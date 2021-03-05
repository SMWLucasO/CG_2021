using System.Linq.Expressions;

namespace Cuby.Shapes.Information
{
    /// <summary>
    /// Interface for specifying that a shape is scalable.
    /// </summary>
    public interface IScalable : ITransformable
    {
        public float Scale { get; set; }
    }
}