let component = "App" |> ReasonReact.statelessComponent;

let make = _children => {
  ...component,
  render: _self => <div> <Greeting name="Aaron" /> <Stateful /> </div>,
};