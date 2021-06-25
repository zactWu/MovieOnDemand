using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using movie_on_demand.Model;
using Microsoft.EntityFrameworkCore;

namespace movie_on_demand
{
    public class Context : DbContext
    {
        public Context(DbContextOptions<Context> options) : base(options)
        {
        }

        public DbSet<Movie> Movies { get; set; }
        public DbSet<Order> Orders { get; set; }
        public DbSet<Review> Reviews { get; set; }
    }
}
