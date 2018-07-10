let rows =
  Node.Fs.readFileAsUtf8Sync("input/Day2.txt")
  |> Js.String.split("\n")
  |> Array.to_list
  |> List.map(row =>
       row
       |> Js.String.split("\t")
       |> Array.to_list
       |> List.map(int_of_string)
     );

let maxAndMinOfRow = row =>
  row
  |> List.sort(compare)
  |> (sorted => (Util.List.last(sorted), List.hd(sorted)));

let part1 =
  rows
  |> List.map(row =>
       row |> maxAndMinOfRow |> Util.Fn.Binary.apply(Util.Int.subtract)
     )
  |> List.fold_left(Util.Int.add, 0);

let findNumInListEvenlyDivisibleBy = (row, dividend) =>
  List.fold_left(
    (optPair, divisor) =>
      switch (optPair) {
      | Some(_) => optPair
      | None =>
        dividend != divisor && Util.Int.areEvenlyDivisible(dividend, divisor) ?
          Some((dividend, divisor)) : None
      },
    None,
    row,
  );

let findEvenlyDivisibleNumInRow = row =>
  List.fold_left(
    (optPair, num) =>
      switch (optPair) {
      | Some(_) => optPair
      | None => findNumInListEvenlyDivisibleBy(row, num)
      },
    None,
    row,
  );

let part2 =
  rows
  |> List.map(r =>
       r
       |> findEvenlyDivisibleNumInRow
       |> (
         pair =>
           switch (pair) {
           | Some((l, r)) => l / r
           | None => 0
           }
       )
     )
  |> List.fold_left(Util.Int.add, 0);

Js.log("Part 1: " ++ string_of_int(part1));
Js.log("Part 2: " ++ string_of_int(part2));