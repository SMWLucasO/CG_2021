namespace Cuby.Shapes.Information
{
    /// <summary>
    /// Interface for specifying that a shape is translatable.
    /// </summary>
    public interface ITranslatable : ITransformable
    {
        
        /// <summary>
        /// The translation across the X-axis
        /// </summary>
        public float TranslationX { get; set; }
        
        /// <summary>
        /// The translation across the Y-axis
        /// </summary>
        public float TranslationY { get; set; }
        
        /// <summary>
        /// The translation across the Z-axis
        /// </summary>
        public float TranslationZ { get; set; }
        
    }
}