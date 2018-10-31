type state = {count: int};

type action =
  | Increment
  | Decrement;

let component = __MODULE__ |> ReasonReact.reducerComponent;

let make = _children => {
  ...component,
  initialState: () => {count: 0},
  reducer: (action, state) =>
    switch (action) {
    | Increment => ReasonReact.Update({count: state.count + 1})
    | Decrement => ReasonReact.Update({count: state.count - 1})
    },
  render: self =>
    <div>
      <Button
        theme=Bulma.Danger
        text="-"
        onClick={_event => self.send(Decrement)}
      />
      <div
        className="foo"
        style={
          ReactDOMRe.Style.make(
            ~display="inline-block",
            ~margin="5px 10px 5px 0",
            (),
          )
        }>
        {ReasonReact.string(string_of_int(self.state.count))}
      </div>
      <Button
        theme=Bulma.Success
        text="+"
        onClick={_event => self.send(Increment)}
      />
    </div>,
};