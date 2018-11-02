%bs.raw
{|import { hot } from 'react-hot-loader'|};

type route =
  | Dashboard
  | Detail(int);

type state = {
  showMessage: bool,
  showNotification: bool,
  nowShowing: route,
};

type action =
  | ShowDashboard
  | ShowDetail(int)
  | ToggleMessage
  | ToggleNotification;

let component = __MODULE__ |> ReasonReact.reducerComponent;

let make = _children => {
  ...component,
  initialState: () => {
    showMessage: false,
    showNotification: false,
    nowShowing: Dashboard,
  },
  reducer: (action, state) => {
    Js.log(action);
    switch (action) {
    | ShowDashboard => ReasonReact.Update({...state, nowShowing: Dashboard})
    | ShowDetail(id) =>
      ReasonReact.Update({...state, nowShowing: Detail(id)})
    | ToggleMessage =>
      ReasonReact.Update({...state, showMessage: !state.showMessage})
    | ToggleNotification =>
      ReasonReact.Update({
        ...state,
        showNotification: !state.showNotification,
      })
    };
  },
  didMount: self => {
    Js.log("mounted");
    let watcherId =
      ReasonReact.Router.watchUrl(url => {
        Js.log(url);
        switch (url.path) {
        | ["dashboard"] => self.send(ShowDashboard)
        | ["show", id] => self.send(ShowDetail(int_of_string(id)))
        | _ => self.send(ShowDashboard)
        };
      });
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  },
  render: self =>
    <div>
      {
        switch (self.state.nowShowing) {
        | Dashboard => <Dashboard />
        | Detail(id) => <Detail id />
        }
      }
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