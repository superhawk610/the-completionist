type state = {query: string};

type action =
  | UpdateQuery(string);

let component = __MODULE__ |> ReasonReact.reducerComponent;

let make = _children => {
  ...component,
  initialState: () => {query: ""},
  reducer: (action, _state) =>
    switch (action) {
    | UpdateQuery(query) => ReasonReact.Update({query: query})
    },
  render: self =>
    <Page heading="Dashboard">
      <Box heading="Search">
        <SearchBar
          value={self.state.query}
          onChange={
            event =>
              self.send(UpdateQuery(ReactEvent.Form.target(event)##value))
          }
        />
        <Button
          text="Home"
          theme=Bulma.Primary
          onClick={_event => ReasonReact.Router.push("/dashboard")}
        />
        <Button
          text="View Details"
          theme=Bulma.Warning
          onClick={_event => ReasonReact.Router.push("/show/10")}
        />
      </Box>
    </Page>,
};