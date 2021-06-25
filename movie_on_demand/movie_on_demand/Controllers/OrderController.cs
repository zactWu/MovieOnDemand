using movie_on_demand.Model;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Text.Json;
using System.Threading;
using Microsoft.AspNetCore.Cors;
using Microsoft.AspNetCore.Http;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.EntityFrameworkCore;
using MySqlX.XDevAPI.Common;
using Newtonsoft.Json.Linq;
using Newtonsoft.Json;
using Org.BouncyCastle.Asn1.Cms;

namespace movie_on_demand.Controllers
{
    [ApiController]
    [Route("api")]
    public class OrderController : ControllerBase
    {
        private readonly Context _context;

        public OrderController(Context context)
        {
            this._context = context;
        }
        
        // GET: /api/query_order/5
        [HttpGet("query_order/{id}")]
        public async Task<ActionResult<Order>> GetOrderSingle(int id) {
            var order = await _context.Orders.FindAsync(id);
            if (order == null) {
                return NotFound();
            }
            return order;
        }
        
        // GET: /api/query_order_all
        [HttpGet("query_order_all")]
        public async Task<ActionResult<IEnumerable<Order>>> GetOrderAll()
        {
            var query =  from p in _context.Set<Order>()
                select p;
            var result = await query.Take(20).ToListAsync();
            return result ;
        }
        
        // Post: /api/query_order_list?start_from=0&limitation=10&search_time
        [HttpPost("query_order_list")]
        public async Task<ActionResult<IEnumerable<Order>>> GetOrderList(int start_from, int limitation, string time_limitation)
        {
            IQueryable<Order> query;
            if (time_limitation != null)
            {
                Console.WriteLine("---time_limitation received---");
                Console.WriteLine("time_limitation is: "+ time_limitation);
                query = from order in _context.Set<Order>()
                    where order.create_time.Contains(time_limitation)
                    select order;
                
                var result = await query.ToListAsync();
                return result;
            }
            else
            {
                query = from order in _context.Set<Order>() 
                    select order;
                var result = await query.Skip(start_from).Take(limitation).ToListAsync();
                return result;
            }
            
        }
        
        // Post: /api/insert_order
        [HttpPost("insert_order")]
        public async Task<ActionResult<Order>> PostOrder(Order order)
        {
            Console.WriteLine("id is: " + order.order_id + "movie_id is" + order.movie_id + "name is" + order.movie_name);
            order.create_time = DateTime.Now.ToString();
            var year = DateTimeUtils.GetYear(order.create_time);
            Console.WriteLine("year is"+year);
            _context.Orders.Add(order);
            await _context.SaveChangesAsync();
            return CreatedAtAction("GetOrderSingle", new { id = order.order_id }, order);
        }
    }
}
