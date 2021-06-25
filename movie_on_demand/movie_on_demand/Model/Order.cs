using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations.Schema;

namespace movie_on_demand.Model
{
    [Table("order_info")]
    public class Order
    {
        [Key]
        [Column("order_id")]
        public int order_id { get; set; }
        
        [Column("movie_id")]
        public int movie_id { get; set; }

        [Column("movie_name")]
        public string movie_name { get; set; }

        [Column("movie_num")]
        public int movie_num { get; set; }
        
        [Column("price_sum")]
        public double price_sum { get; set; }

        [Column("create_time")]
        public string create_time { get; set; }
    }
}
