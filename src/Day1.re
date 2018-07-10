let nums =
  Node.Fs.readFileAsUtf8Sync("input/Day1.txt")
  |> Js.String.split("")
  |> Array.to_list
  |> List.map(int_of_string);

let numsCount = List.length(nums);

let solveCaptchaGivenIdxTrasformer = xform =>
  nums
  |> List.mapi((idx, num) =>
       xform(idx)
       mod numsCount
       |> List.nth(nums)
       |> (next => num == next ? num : 0)
     )
  |> List.fold_left(Util.Int.add, 0);

let part1 = solveCaptchaGivenIdxTrasformer(Util.Int.add(1));
let part2 = solveCaptchaGivenIdxTrasformer(Util.Int.add(numsCount / 2));

Js.log("Part 1: " ++ string_of_int(part1));
Js.log("Part 2: " ++ string_of_int(part2));