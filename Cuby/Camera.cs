using Cuby.Utils;

namespace Cuby
{
    public class Camera
    {
        

        /// <summary>
        /// The angle with the x-axis
        /// </summary>
        public int Theta { get; set; } = 100;
        
        /// <summary>
        /// The angle with the z-axis
        /// </summary>
        public int Phi { get; set; } = -10;
        
        /// <summary>
        /// 
        /// </summary>
        public int D { get; set; } = 800;
        
        /// <summary>
        ///  The length of 'our vector'
        /// </summary>
        public int R { get; set; } = 10;

    }
}