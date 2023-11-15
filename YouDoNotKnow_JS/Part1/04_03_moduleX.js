
var ModuleX = (function Manager() {
  var modules = {};

  function define(name, deps, impl) {
    for (let i = 0; i < deps.length; i++) {
      deps[i] = modules[deps[i]];
    }
    modules[name] = impl.apply(impl, deps);
  }

  function get(name) {
    return modules[name];
  }

  return {
    define: define,
    get: get
  }
})();

ModuleX.define("bar", [], function() {
  function hello(who) {
    return "Let me introduce : " + who;
  }

  return {hello: hello};
});

ModuleX.define("foo", ["bar"], function(bar) {
  var username = "akai";

  function awesome() {
    console.log( bar.hello(username).toUpperCase() );
  }

  return {awesome: awesome}
});

var bar = ModuleX.get("bar");
var foo = ModuleX.get("foo");

console.log(bar.hello("meng"));
foo.awesome();
