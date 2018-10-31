let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = _children => {
  ...component,
  render: _self => <div className="box"> ..._children </div>,
};