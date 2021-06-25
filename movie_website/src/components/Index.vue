<template>
  <div class = "el-header">
    <el-form ref="form" :model="form" label-width="80px" class="login-form">
      <h2 class="login-title">电影点播系统</h2>
      <!-- <el-main> -->
        <el-button round @click="goToMovieList" class = "button">我是用户</el-button>
<!--        <br />-->
        <el-button round @click="goToOrderList" >我是管理员</el-button>
      <!-- </el-main> -->
    </el-form>
  </div>
</template>

<script>
  export default {
    name: "OrderList",
    data() {
      return {
        form: {
        }
      };
    },
    methods: {
      goToMovieList() {
        this.$router.push({name: "movie-list"})
      },
      goToOrderList() {
        this.$router.push({name: "order-list"})
      }
    }
  }
</script>

<style scoped >
</style>

<style scoped>
  .login-form {
    width: 350px;
    margin: 500px auto; /* 上下间距160px，左右自动居中*/
    /*background-color: rgb(233, 238, 243, 0.8); /* 透明背景色 */
     padding: 20px;
    border-radius: 20px; /*圆角 */
  }
  .login-title {
    color: #303133;
    text-align: center;
  }
  .login-container{
    width:100%;
    height:100%;  /**宽高100%是为了图片铺满屏幕 */
    z-index:-1;
    position: absolute;
    background: url("../assets/bg.jpg");
    background-size: cover;
    background-repeat: no-repeat;
  }
  .button{
    margin-right: 50px;
  }
  .el-header {
    background-color:  #409EFF;
    color: white;
    font-size: 18px;
    text-align: center;
    line-height: 60px;
  }
  .el-main {
    text-align: center;
    line-height: 130px;
  }
</style>
