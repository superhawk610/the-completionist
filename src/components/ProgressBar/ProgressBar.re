let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = (~theme=Bulma.Link, ~value, ~max=100, _children) => {
  ...component,
  render: _self => {
    let theme = Bulma.string_of_theme(theme);
    let percent =
      Js.Float.toFixedWithPrecision(
        float(value) /. float(max) *. 100.,
        ~digits=2,
      )
      ++ "%";
    let value = string_of_int(value);
    let max = string_of_int(max);
    <progress value max className={"progress " ++ theme}>
      percent->ReasonReact.string
    </progress>;
  },
};