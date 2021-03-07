using System.Collections.Generic;
using System.Linq;

namespace Cuby
{
    public class WatchedObject
    {
        private IList<WatchedProperty> _properties = new List<WatchedProperty>();
        public object Object { get; set; }
        public string LongestName = "";

        public IList<WatchedProperty> Properties
        {
            get => _properties;
            set
            {
                _properties = value;

                //find the longest name and save it
                LongestName = _properties.Aggregate("", (max, cur) => max.Length > cur.Name.Length ? max : cur.Name);
            }
        }
    }
}