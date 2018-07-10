/* Transparent logger for debugging in pipelines */
let logMe = x => {
  Js.log(x);
  x;
};

module Int = {
  let add = (x, y) => x + y;
  let subtract = (l, r) => l - r;
  let areEvenlyDivisible = (dividend, divisor) => dividend mod divisor == 0;
};

module List = {
  let last = x => x |> List.rev |> List.hd;
};

module Fn = {
  module Binary = {
    let apply = (f, (x, y)) => f(x, y);
  };
};