type state = {
  count: int,
  show: bool,
};

type action =
  | Increment
  | Decrement
  | Toggle;

let component = ReasonReact.reducerComponent("Stateful");

let make = (~greeting, _children) => {
  ...component,
  initialState: () => {count: 0, show: true},
  reducer: (action, state) =>
    switch (action) {
    | Increment => ReasonReact.Update({...state, count: state.count + 1})
    | Decrement => ReasonReact.Update({...state, count: state.count - 1})
    | Toggle => ReasonReact.Update({...state, show: !state.show})
    },
  render: self => {
    let message = "You've clicked this " ++ string_of_int(self.state.count) ++ " times(s)";
    <div>
      <button onClick=(_event => self.send(Increment))>
        (ReasonReact.string("-"))
      </button>
      <button onClick=(_event => self.send(Decrement))>
        (ReasonReact.string("+"))
      </button>
      <button onClick=(_event => self.send(Toggle))>
        (ReasonReact.string("Toggle greeting"))
      </button>
      (
        self.state.show
        ? ReasonReact.string(greeting)
        : ReasonReact.null
      )
    </div>;
  },
};