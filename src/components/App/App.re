let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => <div> <Greeting name="Aaron" /> <Stateful /> </div>,
};