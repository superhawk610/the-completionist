let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = (~id, _children) => {
  ...component,
  render: _self =>
    <Page heading={"Detail for " ++ string_of_int(id)}>
      "foo"->ReasonReact.string
    </Page>,
};