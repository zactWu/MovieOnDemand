using movie_on_demand.Model;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Text.Json;
using System.Threading;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.EntityFrameworkCore;
using MySqlX.XDevAPI.Common;
using Newtonsoft.Json.Linq;
using Newtonsoft.Json;
using System.Runtime.InteropServices;
using Microsoft.AspNetCore.Cors;

namespace movie_on_demand.Controllers
{
    [ApiController]
    [Route("api")]
    public class MovieController : ControllerBase
    {
        private readonly Context _context;

        public MovieController(Context context)
        {
            this._context = context;
        }
        
        [DllImport("Win32DLL.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int Add(int x, int y);
        
        // GET: /api/query_movie_single/5
        [HttpGet("query_movie_single/{id}")]
        public async Task<ActionResult<Movie>> GetMovieSingle(int id) {

            // 调用win32dll
            int win32result = Add(1,2);
            System.Console.WriteLine("Win32dll结果为："+win32result);
            
            
            var share_result = Encoder.MD5Encoder("abcdtest");
            DateTimeUtils.Hello();
            System.Console.WriteLine("共享程序集结果为："+share_result);
            
            
            // var op = new FileMaintain.FileOperator("../a", "s.txt");
            // op.CleanFiles();
            
            var movie = await _context.Movies.FindAsync(id);
            if (movie == null) {
                return NotFound();
            }
            return movie;
        }
        
        // Post: /api/query_movie/1292225
        [HttpPost("query_movie/{id}")]
        public async Task<CompleteMovie> GetMovie(int id)
        {
            
            var queryMovie = from movie in _context.Set<Movie>()
                where movie.movie_id == id
                select movie;
            var curMovie = await queryMovie.SingleOrDefaultAsync();

            var queryReview = from review in _context.Set<Review>()
                where review.movie_id == id
                select review;
            var listReview = await queryReview.ToListAsync();

            // 封装结果
            CompleteMovie completeMovie = new CompleteMovie();
            completeMovie.movie_id = curMovie.movie_id;
            completeMovie.name = curMovie.name;
            completeMovie.price = curMovie.price;
            completeMovie.ranking = curMovie.ranking;
            completeMovie.information = curMovie.information;
            completeMovie.reviews = listReview;
            var result = JsonConvert.SerializeObject(completeMovie);
            return completeMovie;
        }
        
        // GET: /api/query_movie_all
        [HttpGet("query_movie_all")]
        public async Task<ActionResult<List<Movie>>> GetMovieAll()
        {
            var query =  from p in _context.Set<Movie>()
                select p;
            var result = await query.Take(20).ToListAsync();
            return result ;
        }
        
        // Post: /api/query_movie_list?start_from=0&limitation=10&search_key=闪灵 The Shining
        [HttpPost("query_movie_list")]
        public async Task<ActionResult<IEnumerable<CompleteMovie>>> GetMovieList(int start_from, int limitation,
            string search_key)
        {
            IQueryable<Movie> query;
            List<CompleteMovie> completeMovie = new List<CompleteMovie>(20);
            List<string> result = new List<string>();

            if (search_key != null)
            {
                Console.WriteLine("---search_key received---");
                Console.WriteLine("searchkey is: "+ search_key);
                query = from movie in _context.Set<Movie>()
                    where movie.name.Contains(search_key)
                    orderby movie.price ascending
                    select movie;
                var querylist = await query.Skip(start_from).Take(limitation).ToListAsync();
                var queryReview = from review in _context.Set<Review>()
                    where review.movie_id == querylist[0].movie_id
                    select review;
                
                for (int i = 0; i < querylist.Count; i++)
                {

                    completeMovie.Add(new CompleteMovie
                    {
                        movie_id = querylist[i].movie_id,
                        name = querylist[i].name,
                        price = querylist[i].price,
                        ranking = querylist[i].ranking,
                        information = querylist[i].information,
                        reviews = queryReview.ToList()
                    });
                }
                return completeMovie;
            }
            else
            {
                query = from movie in _context.Set<Movie>() 
                    orderby movie.price ascending 
                    select movie;
                var querylist = await query.Skip(start_from).Take(limitation).ToListAsync();
                var queryReview = from review in _context.Set<Review>()
                    where review.movie_id == querylist[0].movie_id
                    select review;
                
                for (int i = 0; i < querylist.Count; i++)
                {

                    completeMovie.Add(new CompleteMovie
                    {
                        movie_id = querylist[i].movie_id,
                        name = querylist[i].name,
                        price = querylist[i].price,
                        ranking = querylist[i].ranking,
                        information = querylist[i].information,
                        reviews = queryReview.ToList()
                    });
                }
                return completeMovie;
            }
        }
        
        // Post: /api/recommend_movie_list?start_from=0&limitation=10
        [HttpPost("recommend_movie_list")]
        public async Task<ActionResult<IEnumerable<Movie>>> GetRecommendMovieList(int startFrom, int limitation)
        {
            IQueryable<Movie> query;
            query = from movie in _context.Set<Movie>()
                 where ! Nullable<double>.Equals(movie.ranking, null)
                 orderby movie.ranking descending 
                 select movie; 
            var result = await query.Skip(startFrom).Take(limitation).ToListAsync(); 
            return result;
        }
    }

    public class CompleteMovie
    {
        public int movie_id { get; set; }
        
        public string name { get; set; }
        
        public double price { get; set; }
        
        public double ranking { get; set; }
        
        public string information { get; set; }
        public List<Review> reviews { get; set; }
    }
}
