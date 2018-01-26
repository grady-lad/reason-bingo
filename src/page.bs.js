// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var List        = require("bs-platform/lib/js/list.js");
var $$Array     = require("bs-platform/lib/js/array.js");
var React       = require("react");
var $$String    = require("bs-platform/lib/js/string.js");
var Pervasives  = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var initialEntries = /* :: */[
  /* record */[
    /* id */1,
    /* phrase */"Future Proof",
    /* points */100,
    /* marked : false */0
  ],
  /* :: */[
    /* record */[
      /* id */2,
      /* phrase */"Doing Agile",
      /* points */200,
      /* marked : false */0
    ],
    /* :: */[
      /* record */[
        /* id */3,
        /* phrase */"In the cloud",
        /* points */300,
        /* marked : false */0
      ],
      /* :: */[
        /* record */[
          /* id */4,
          /* phrase */"Rockstar Ninja",
          /* points */400,
          /* marked : false */0
        ],
        /* [] */0
      ]
    ]
  ]
];

var initialModel = /* record */[
  /* gameNumber */1,
  /* name */"Martin",
  /* entries */initialEntries
];

function str(prim) {
  return prim;
}

function summarize(l) {
  if (l) {
    return l[0] + summarize(l[1]) | 0;
  } else {
    return 0;
  }
}

function summedScore(entries) {
  return summarize(List.map((function (item) {
                    return item[/* points */2];
                  }), List.filter((function (item) {
                          return item[/* marked */3];
                        }))(entries)));
}

var component = ReasonReact.statelessComponent("Header");

function make(title, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, React.createElement("h1", undefined, title));
    });
  return newrecord;
}

var Header = /* module */[
  /* component */component,
  /* make */make
];

function createTitle(name, gameNum) {
  return name + (" - Game " + Pervasives.string_of_int(gameNum));
}

function gameTitle(name, gameNum) {
  return $$String.uppercase(createTitle(name, gameNum));
}

var component$1 = ReasonReact.statelessComponent("ViewPlayer");

function make$1(name, gameNumber, _) {
  var newrecord = component$1.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, React.createElement("h2", {
                      className: "classy",
                      id: "info"
                    }, $$String.uppercase(createTitle(name, gameNumber))));
    });
  return newrecord;
}

var ViewPlayer = /* module */[
  /* createTitle */createTitle,
  /* gameTitle */gameTitle,
  /* component */component$1,
  /* make */make$1
];

var component$2 = ReasonReact.statelessComponent("EntryItem");

function make$2(entryItem, _) {
  var newrecord = component$2.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("li", undefined, React.createElement("span", {
                      className: "phrase"
                    }, entryItem[/* phrase */1]), React.createElement("span", {
                      className: "points"
                    }, Pervasives.string_of_int(entryItem[/* points */2])));
    });
  return newrecord;
}

var EntryItem = /* module */[
  /* component */component$2,
  /* make */make$2
];

var component$3 = ReasonReact.statelessComponent("EntryItems");

function make$3(entries, _) {
  var newrecord = component$3.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("ul", undefined, $$Array.of_list(List.map((function (entryItem) {
                            return ReasonReact.element(/* None */0, /* None */0, make$2(entryItem, /* array */[]));
                          }), entries)));
    });
  return newrecord;
}

var EntryItems = /* module */[
  /* component */component$3,
  /* make */make$3
];

var component$4 = ReasonReact.statelessComponent("GameScore");

function make$4(score, _) {
  var newrecord = component$4.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  className: "score"
                }, React.createElement("span", {
                      className: "label"
                    }, "Score"), React.createElement("span", {
                      className: "value"
                    }, Pervasives.string_of_int(score)));
    });
  return newrecord;
}

var GameScore = /* module */[
  /* component */component$4,
  /* make */make$4
];

var pageComponent = ReasonReact.statelessComponent("Page");

function make$5() {
  var newrecord = pageComponent.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", {
                  className: "content"
                }, ReasonReact.element(/* None */0, /* None */0, make("BUZZWORD BING", /* array */[])), ReasonReact.element(/* None */0, /* None */0, make$1("Martin", 1, /* array */[])), ReasonReact.element(/* None */0, /* None */0, make$3(initialEntries, /* array */[])), ReasonReact.element(/* None */0, /* None */0, make$4(summedScore(initialEntries), /* array */[])), React.createElement("button", undefined, "New Game"));
    });
  return newrecord;
}

exports.initialEntries = initialEntries;
exports.initialModel   = initialModel;
exports.str            = str;
exports.summarize      = summarize;
exports.summedScore    = summedScore;
exports.Header         = Header;
exports.ViewPlayer     = ViewPlayer;
exports.EntryItem      = EntryItem;
exports.EntryItems     = EntryItems;
exports.GameScore      = GameScore;
exports.pageComponent  = pageComponent;
exports.make           = make$5;
/* component Not a pure module */