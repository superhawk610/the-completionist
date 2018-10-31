type state = {count: int};

type action =
  | Increment
  | Decrement;

let component = ReasonReact.reducerComponent("Stateful");

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
      <Button text="-" onClick=(_event => self.send(Decrement)) />
      <div className="foo">
        (ReasonReact.string(string_of_int(self.state.count) ++ "foo"))
      </div>
      <Button text="+" onClick=(_event => self.send(Increment)) />
    </div>,
};