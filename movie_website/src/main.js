const Vue = require('vue')
const ElementUI = require('element-ui')
const VueResource = require('vue-resource')
const VueRouter = require('vue-router')
import App from './App.vue'
import routers from './router/routers'
import VideoPlayer from 'vue-video-player'
import Video from 'video.js'
import 'video.js/dist/video-js.css'
import 'vue-video-player/src/custom-theme.css'

Vue.use(VideoPlayer)

const router = new VueRouter({
  routes: routers
 })


new Vue({
  el: '#app',
  router,
  render: h => h(App)
})
