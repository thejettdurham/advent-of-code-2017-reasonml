// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Fs = require("fs");
var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Caml_int32 = require("bs-platform/lib/js/caml_int32.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");
var Util$Aoc2017Reasonml = require("./Util.bs.js");

var nums = List.map(Caml_format.caml_int_of_string, $$Array.to_list(Fs.readFileSync("input/Day1.txt", "utf8").split("")));

var numsCount = List.length(nums);

function solveCaptchaGivenIdxTrasformer(xform) {
  return List.fold_left(Util$Aoc2017Reasonml.intAdd, 0, List.mapi((function (idx, num) {
                    var nextNum = List.nth(nums, Caml_int32.mod_(Curry._1(xform, idx), numsCount));
                    var match = num === nextNum;
                    if (match) {
                      return num;
                    } else {
                      return 0;
                    }
                  }), nums));
}

var part1 = solveCaptchaGivenIdxTrasformer((function (param) {
        return Util$Aoc2017Reasonml.intAdd(1, param);
      }));

var partial_arg = numsCount / 2 | 0;

var part2 = solveCaptchaGivenIdxTrasformer((function (param) {
        return Util$Aoc2017Reasonml.intAdd(partial_arg, param);
      }));

console.log("Part 1: " + String(part1));

console.log("Part 2: " + String(part2));

exports.nums = nums;
exports.numsCount = numsCount;
exports.solveCaptchaGivenIdxTrasformer = solveCaptchaGivenIdxTrasformer;
exports.part1 = part1;
exports.part2 = part2;
/* nums Not a pure module */
