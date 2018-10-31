%bs.raw
{|import './Button.styl'|};

let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = (~text, ~onClick, ~theme=Bulma.Dark, ~block=false, _children) => {
  ...component,
  render: _self => {
    let theme = Bulma.string_of_theme(theme);
    let width = block ? " is-fullwidth" : "";
    <button onClick className={"Button button " ++ theme ++ width}>
      {ReasonReact.string(text)}
    </button>;
  },
};