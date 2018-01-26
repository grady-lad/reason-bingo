/* Lets create some models*/
type entry = {
  id: int,
  phrase: string,
  points: int,
  marked: bool,
};

type model = {
  gameNumber: int,
  name: string,
  entries: list(entry),
};

let initialEntries = [
  { id: 1, phrase: "Future Proof", points: 100, marked: false },
  { id: 2, phrase: "Doing Agile", points: 200, marked: false },
  { id: 3, phrase: "In the cloud", points: 300, marked: false },
  { id: 4, phrase: "Rockstar Ninja", points: 400, marked: false }
];

let initialModel = {
  gameNumber: 1,
  name: "Martin",
  entries: initialEntries,
};

/* Helpers */
let str = ReasonReact.stringToElement;

let rec summarize = (l: list(int)) =>
  switch l {
  | [] => 0
  | [head, ...tail] => head + summarize(tail)
  };

let summedScore = (entries: list(entry)) : int => {
  entries
    |> List.filter((item) => item.marked)
    |> List.map((item)=> item.points)
    |> summarize
};

/* Components */
module Header = {
  let component =  ReasonReact.statelessComponent("Header");
  let make = (~title, _children) => {
    ...component,
    render: (self) =>
      <div>
        <h1> (str(title)) </h1>
      </div>
  };
};

module ViewPlayer = {
  let createTitle = (name: string, gameNum: int) : string => name ++ " - Game " ++ string_of_int(gameNum);
  let gameTitle = (name: string, gameNum: int ) : string => createTitle(name, gameNum) |> String.uppercase;
  let component = ReasonReact.statelessComponent("ViewPlayer");
  let make = (~name, ~gameNumber, _children) => {
    ...component,
    render: (self) =>
      <div>
        <h2 id="info" className="classy"> (str(gameTitle(name, gameNumber))) </h2>
      </div>
  };
};

module EntryItem = {
  let component = ReasonReact.statelessComponent("EntryItem");
  let make = (~entryItem, _children) => {
    ...component,
    render: (self) =>
      <li>
        <span className="phrase"> (str(entryItem.phrase)) </span>
        <span className="points"> (str(string_of_int(entryItem.points))) </span>
      </li>
  };
};

module EntryItems = {
  let component = ReasonReact.statelessComponent("EntryItems");
  let make = (~entries, _children) => {
    ...component,
    render: (self) =>
      <ul>
        (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((entryItem) => <EntryItem entryItem/>, entries)
          ))
        )
      </ul>
  };
};

module GameScore = {
  let component = ReasonReact.statelessComponent("GameScore");
  let make = (~score, _children) => {
    ...component,
    render: (self) =>
    <div className="score">
      <span className="label"> (str("Score")) </span>
      <span className="value"> (str(string_of_int(score))) </span>
    </div>
  };
};

/* This is our Page (or App) component. */
let pageComponent = ReasonReact.statelessComponent("Page");
let make = (_children) => {
  ...pageComponent,
  render: (self) =>
    <div className="content">
      <Header title="BUZZWORD BING"/>
      <ViewPlayer name={initialModel.name} gameNumber={initialModel.gameNumber}/>
      <EntryItems entries={initialEntries} />
      <GameScore score={summedScore(initialEntries)}/>
      <button>(str("New Game"))</button>
    </div>
};
