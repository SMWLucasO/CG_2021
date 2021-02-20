namespace Cuby.Shapes.Information
{
    public class ShapeInfo
    {

        /// <summary>
        /// The scale of the shape
        /// </summary>
        public float Scale { get; set; } = 1;

        /// <summary>
        /// The translation across the X-axis
        /// </summary>
        public float TranslationX { get; set; } = 0;
        
        /// <summary>
        /// The translation across the Y-axis
        /// </summary>
        public float TranslationY { get; set; } = 0;
        
        /// <summary>
        /// The translation across the Z-axis
        /// </summary>
        public float TranslationZ { get; set; } = 0;

        /// <summary>
        /// The rotation across the X-axis
        /// </summary>
        public int RotationX { get; set; } = 0;
        
        /// <summary>
        /// The rotation across the Y-axis
        /// </summary>
        public int RotationY { get; set; } = 0;
        
        /// <summary>
        /// The rotation across the Z-axis
        /// </summary>
        public int RotationZ { get; set; } = 0;
        
    }
}