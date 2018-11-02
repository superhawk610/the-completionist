let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = (~heading, ~subheading=?, children) => {
  ...component,
  render: _state =>
    <div className="Page">
      <Heading> heading->ReasonReact.string </Heading>
      {
        subheading
        ->Belt.Option.map(text =>
            <Subheading> text->ReasonReact.string </Subheading>
          )
        ->Belt.Option.getWithDefault(ReasonReact.null)
      }
      <Fragment> ...children </Fragment>
    </div>,
};