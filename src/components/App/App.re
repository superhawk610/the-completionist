%bs.raw
{|import { hot } from 'react-hot-loader'|};

type state = {
  showMessage: bool,
  showNotification: bool,
};

type action =
  | ToggleMessage
  | ToggleNotification;

let component = __MODULE__ |> ReasonReact.reducerComponent;

let make = _children => {
  ...component,
  initialState: () => {showMessage: false, showNotification: false},
  reducer: (action, state) =>
    switch (action) {
    | ToggleMessage =>
      ReasonReact.Update({...state, showMessage: !state.showMessage})
    | ToggleNotification =>
      ReasonReact.Update({
        ...state,
        showNotification: !state.showNotification,
      })
    },
  render: self =>
    <div>
      <Heading> "Bulma + ReasonReact"->ReasonReact.string </Heading>
      <Subheading> "Playground"->ReasonReact.string </Subheading>
      <Spacer height=30 />
      <Box> <Stateful /> </Box>
      <Box>
        <Button
          onClick={_event => self.send(ToggleMessage)}
          theme=Bulma.Info
          text="Toggle Message"
        />
        <Button
          onClick={_event => self.send(ToggleNotification)}
          theme=Bulma.Warning
          text="Toggle Notification"
        />
      </Box>
      <Notification
        active={self.state.showMessage}
        theme=Bulma.Info
        heading="I'm a notification"
        message="Body"
      />
      <Notification
        active={self.state.showNotification}
        theme=Bulma.Warning
        message="Body"
      />
    </div>,
};

let comp = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));

%bs.raw
{|export default hot(module)(comp)|};