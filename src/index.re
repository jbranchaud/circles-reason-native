open Reprocessing;

let colors = [
  ("NAVY", "#001f3f"),
  ("BLUE", "#0074D9"),
  ("AQUA", "#7FDBFF"),
  ("TEAL", "#39CCCC"),
  ("OLIVE", "#3D9970"),
  ("GREEN", "#2ECC40"),
  ("LIME", "#01FF70"),
  ("YELLOW", "#FFDC00"),
  ("ORANGE", "#FF851B"),
  ("RED", "#FF4136"),
  ("MAROON", "#85144b"),
  ("FUCHSIA", "#F012BE"),
  ("PURPLE", "#B10DC9"),
  ("BLACK", "#111111"),
  ("GRAY", "#AAAAAA"),
  ("SILVER", "#DDDDDD"),
];

let width = 450;
let height = 450;

let setup = env => {
  Env.size(~width, ~height, env);
  colors;
};

let draw_circles = (colors, env) => {
  let xSpacing = width / 9;
  let ySpacing = height / 9;

  for (xCoord in 0 to 3) {
    for (yCoord in 0 to 3) {
      let colorIndex = xCoord + 4 * yCoord;
      let (_, hex_color) = List.nth(colors, colorIndex);
      let (r, g, b, a) = ColorConverter.hex_to_rgba(hex_color);

      let xCenter = (xCoord * 2 + 1) * xSpacing + xSpacing / 2;
      let yCenter = (yCoord * 2 + 1) * ySpacing + ySpacing / 2;

      Draw.fill(Utils.color(~r, ~g, ~b, ~a), env);
      Draw.ellipse(
        ~center=(xCenter, yCenter),
        ~radx=xSpacing / 2,
        ~rady=ySpacing / 2,
        env,
      );
    };
  };
};

let draw = (colors, env) => {
  Draw.background(Utils.color(~r=255, ~g=255, ~b=255, ~a=255), env);
  draw_circles(colors, env);

  if (Env.mousePressed(env)) {
    ListUtils.shuffle(colors);
  } else {
    colors;
  };
};

run(~setup, ~draw, ());