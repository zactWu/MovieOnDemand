<template>
  <!--这里直接用style里面的board-->
  <div class="board">
    <el-col class="sub-header">口碑榜</el-col>
    <div class=boarding-list>
      <!--这里会生成recommend_movies长度个p :key是为每一个p加索引，更快地生成这些p-->
      <!--@click是绑定监听，调用函数-->
      <p v-for="(movie, index) in recommend_movies" :key="index" @click="selectMovie(movie.information)" class="title">
         {{movie.name}}
         {{movie.movie_id}}
         </p>
    </div>
  </div>
</template>

<script>
  import axios from 'axios'
  export default {
    name: "Boarding",
    props: ["movieList"],
    data(){
      return {
        recommend_movies:[]
      }
    },
    mounted:function(){
      this.recommends();
    },
    methods: {
      selectMovie: function(movie) {
        console.log(movie)
        //使用 this.$router.push(location) 来修改 url，完成跳转
        this.$router.push({name: "movie-detail", params: {id: JSON.parse(movie)._id}})
      },
      recommends() {
        //直接对应后端接口，后面是参数
        axios.post(`/api/recommend_movie_list?start_from=0&limitation=15`, {
          start_from: 0,
          limitation: 15
        })
          .then((res) => {
            this.recommend_movies=res.data
          })
      }
    }
  }
</script>

<style scoped>
  .board {
    -webkit-user-select: none
  }
  .sub-header {
    text-align: left;
    padding-left: 12px;
    padding-top: 25px;
    font-size: 20px;
    opacity: 1;
    line-height: 1.4;
    font-weight: 500;
    color: darkcyan
  }
  .boarding-list {
    opacity: 1;
    line-height: 1.4;
    font-weight: 500;
    text-align: left;
    float: left;
    padding: 12px;
  }
  .title {
    cursor: pointer;
  }
</style>
