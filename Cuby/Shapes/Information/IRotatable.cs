namespace Cuby.Shapes.Information
{
    /// <summary>
    /// Interface for specifying that a shape is rotatable.
    /// </summary>
    public interface IRotatable : ITransformable
    {
     
        /// <summary>
        /// The rotation across the X-axis
        /// </summary>
        public int RotationX { get; set; }
        
        /// <summary>
        /// The rotation across the Y-axis
        /// </summary>
        public int RotationY { get; set; }
        
        /// <summary>
        /// The rotation across the Z-axis
        /// </summary>
        public int RotationZ { get; set; }
        
    }
}