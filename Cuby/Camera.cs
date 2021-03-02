using Cuby.Utils;

namespace Cuby
{
    public class Camera
    {

        public const int ThetaDefault = -100;
        public const int PhiDefault = -10;
        public const int DDefault = 800;
        public const int RDefault = 10;

        /// <summary>
        /// The angle with the x-axis
        /// </summary>
        public int Theta { get; set; } = ThetaDefault;
        
        /// <summary>
        /// The angle with the z-axis
        /// </summary>
        public int Phi { get; set; } = PhiDefault;
        
        /// <summary>
        /// 
        /// </summary>
        public int D { get; set; } = DDefault;
        
        /// <summary>
        ///  The length of 'our vector'
        /// </summary>
        public int R { get; set; } = RDefault;

        public void ResetTransformations()
        {
            Theta = ThetaDefault;
            Phi = PhiDefault;
            D = DDefault;
            R = RDefault;
        }
        
    }
}