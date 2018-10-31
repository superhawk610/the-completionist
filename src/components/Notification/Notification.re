%bs.raw
{|import './Notification.styl'|};

let component = __MODULE__ |> ReasonReact.statelessComponent;

let make = (~active, ~heading=?, ~message, ~theme=Bulma.Primary, _children) => {
  ...component,
  render: _self => {
    Js.log(theme);
    let theme = Bulma.string_of_theme(theme);
    let style = ReactDOMRe.Style.make(~opacity=active ? "1" : "0", ());
    Js.log(active ? "is_active" : "isnt_active");
    switch (heading) {
    | Some(text) =>
      <div
        style
        className={"Notification Notification__expanded message " ++ theme}>
        <div className="message-header">
          text->ReasonReact.string
          <button className="delete" />
        </div>
        <div className="message-body"> message->ReasonReact.string </div>
      </div>
    | None =>
      <div
        style
        className={"Notification Notification__basic notification " ++ theme}>
        <button className="delete" />
        message->ReasonReact.string
      </div>
    };
  },
};