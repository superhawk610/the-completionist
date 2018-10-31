let component = ReasonReact.statelessComponent("Button");

let make = (~text, ~onClick, _children) => {
  ...component,
  render: _self =>
    <button onClick className="button"> (ReasonReact.string(text)) </button>,
};