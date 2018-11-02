type theme =
  | None
  | White
  | Light
  | Dark
  | Black
  | Text
  | Primary
  | Link
  | Info
  | Success
  | Warning
  | Danger;

let string_of_theme = th =>
  switch (th) {
  | None => ""
  | White => "is-white"
  | Light => "is-light"
  | Dark => "is-dark"
  | Black => "is-black"
  | Text => "is-text"
  | Primary => "is-primary"
  | Link => "is-link"
  | Info => "is-info"
  | Success => "is-success"
  | Warning => "is-warning"
  | Danger => "is-danger"
  };