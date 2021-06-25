using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations.Schema;

namespace movie_on_demand.Model
{
    [Table("movie")]
    public class Movie
    {
        [Key]
        [Column("movie_id")]
        public int movie_id { get; set; }

        [Column("name")]
        public string name { get; set; }

        [Column("price")]
        public double price { get; set; }

        [Column("ranking")]
        public double ranking { get; set; }

        [Column("information")]
        public string information { get; set; }
    }
}
