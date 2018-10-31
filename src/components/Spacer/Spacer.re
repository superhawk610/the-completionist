let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = (~height=10, _children) => {
  ...component,
  render: _self =>
    <div
      style={
        ReactDOMRe.Style.make(~height=string_of_int(height) ++ "px", ())
      }
    />,
};