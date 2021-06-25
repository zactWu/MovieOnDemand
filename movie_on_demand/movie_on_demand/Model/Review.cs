using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations.Schema;

namespace movie_on_demand.Model
{
    [Table("review")]
    public class Review
    {
        [Key]
        [Column("review_id")]
        public int review_id { get; set; }
        
        [Column("movie_id")]
        public int movie_id { get; set; }
        
        [Column("ranking")]
        public double ranking { get; set; }

        [Column("content")]
        public string content { get; set; }
    }
}
