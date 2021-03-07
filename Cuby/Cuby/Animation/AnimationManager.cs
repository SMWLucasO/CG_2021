using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Timers;
using System.Windows.Forms;
using Timer = System.Timers.Timer;

namespace Cuby.Animation
{
    public class AnimationManager
    {

        private static Lazy<AnimationManager> _instance = new Lazy<AnimationManager>(() => new AnimationManager());

        public static AnimationManager Instance => _instance.Value;
        
        public bool AnimationHasStarted { get; set; }


        private int _animationPartIndex = 0;
        public List<IAnimationPart> AnimationParts { get; set; }
        
        public Form Form { get; set; }
        
        public Timer Timer { get; set; }


        public void Start()
        {
            Timer = new Timer() {Interval = 50};
            Timer.Elapsed += TimerOnElapsed;
            
            Timer.AutoReset = true;
            Timer.Enabled = true;

            _animationPartIndex = 0;
        }


        public void Execute()
        {
            AnimationParts[_animationPartIndex].Execute();
        }
        
        public void End()
        {
            if (Timer != null)
                Timer.Stop();
            
            _animationPartIndex = 0;
            AnimationParts = null;
            AnimationHasStarted = false;
        }

        private void TimerOnElapsed(object sender, ElapsedEventArgs e)
        {
            if (_animationPartIndex >= AnimationParts.Count)
                _animationPartIndex = 0;
            
            Execute();
            Form.Refresh();
        }

        public void Next()
        {
            ++_animationPartIndex;
        }
    }
}