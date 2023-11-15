global.a = 2;
(function IIFE(def) {
  def(global);
})(function def(ctx) {
  var a = 3;
  console.log(a);
  console.log( ctx.a );
})