let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = children => {
  ...component,
  render: _self => <h2 className="subtitle"> ...children </h2>,
};