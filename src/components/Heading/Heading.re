let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = children => {
  ...component,
  render: _self => <h1 className="title"> ...children </h1>,
};