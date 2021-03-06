let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = (~heading=?, children) => {
  ...component,
  render: _self =>
    <div className="box">
      {
        heading
        ->Belt.Option.map(text =>
            <Subheading> text->ReasonReact.string </Subheading>
          )
        ->Belt.Option.getWithDefault(ReasonReact.null)
      }
      <div> ...children </div>
    </div>,
};