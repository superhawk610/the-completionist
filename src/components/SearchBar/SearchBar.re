let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = (~value, ~onChange, ~placeholder=?, _children) => {
  ...component,
  render: _self => <input className="input" ?placeholder value onChange />,
};