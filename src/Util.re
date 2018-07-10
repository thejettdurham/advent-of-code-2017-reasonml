/* Transparent logger for debugging in pipelines */
let logMe = x => {
  Js.log(x);
  x;
};

let intAdd = (x, y) => x + y;