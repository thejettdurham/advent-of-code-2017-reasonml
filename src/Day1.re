let nums =
  Node.Fs.readFileAsUtf8Sync("input/Day1.txt")
  |> Js.String.split("")
  |> Array.to_list
  |> List.map(int_of_string);

let numsCount = List.length(nums);

let solveCaptchaGivenIdxTrasformer = xform =>
  List.mapi(
    (idx, num) => {
      let nextNum = xform(idx) mod numsCount |> List.nth(nums);

      num == nextNum ? num : 0;
    },
    nums,
  )
  |> List.fold_left(Util.intAdd, 0);

let part1 = solveCaptchaGivenIdxTrasformer(Util.intAdd(1));
let part2 = solveCaptchaGivenIdxTrasformer(Util.intAdd(numsCount / 2));

Js.log("Part 1: " ++ string_of_int(part1));
Js.log("Part 2: " ++ string_of_int(part2));