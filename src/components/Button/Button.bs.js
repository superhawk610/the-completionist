// Generated by BUCKLESCRIPT VERSION 4.0.7, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Bulma$ReactTemplate = require("../../Bulma.bs.js");

import './Button.styl'
;

var component = ReasonReact.statelessComponent("Button-ReactTemplate");

function make(text, onClick, $staropt$star, $staropt$star$1, _children) {
  var theme = $staropt$star !== undefined ? $staropt$star : /* Dark */2;
  var block = $staropt$star$1 !== undefined ? $staropt$star$1 : false;
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              var theme$1 = Bulma$ReactTemplate.string_of_theme(theme);
              var width = block ? " is-fullwidth" : "";
              return React.createElement("button", {
                          className: "Button button " + (theme$1 + width),
                          onClick: onClick
                        }, text);
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/*  Not a pure module */
