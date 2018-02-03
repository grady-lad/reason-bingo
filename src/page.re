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

type action =
  | NewGame
  | Mark (int);

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
  let make = (~title: string, _children) => {
    ...component,
    render: (_) =>
      <div>
        <h1> (str(title)) </h1>
      </div>
  };
};

module ViewPlayer = {
  let createTitle = (name: string, gameNum: int) : string => name ++ " - Game " ++ string_of_int(gameNum);
  let gameTitle = (name: string, gameNum: int ) : string => createTitle(name, gameNum) |> String.uppercase;
  let component = ReasonReact.statelessComponent("ViewPlayer");
  let make = (~name: string, ~gameNumber: int, _children) => {
    ...component,
    render: (_) =>
      <div>
        <h2 id="info" className="classy"> (str(gameTitle(name, gameNumber))) </h2>
      </div>
  };
};

module EntryItem = {
  let component = ReasonReact.statelessComponent("EntryItem");
  let make = (~entryItem: entry, ~handleClick: (int) => unit, _children) => {
  let click = (_) => handleClick(entryItem.id);
  let isMarked = if (entryItem.marked) "marked" else "";
    {
    ...component,
    render: (_) =>
      <li className={isMarked} onClick={click}>
        <span className="phrase"> (str(entryItem.phrase)) </span>
        <span className="points"> (str(string_of_int(entryItem.points))) </span>
      </li>
  };
  };
};

module EntryItems = {
  let component = ReasonReact.statelessComponent("EntryItems");
  let make = (~entries: list(entry), ~handleClick: (int) => unit, _children) => {
    ...component,
    render: (_) =>
      <ul>
        (
          ReasonReact.arrayToElement(Array.of_list(
            List.map((entryItem) => <EntryItem entryItem handleClick={handleClick}/>, entries)
          ))
        )
      </ul>
  };
};

module GameScore = {
  let component = ReasonReact.statelessComponent("GameScore");
  let make = (~score: int, _children) => {
    ...component,
    render: (_) =>
    <div className="score">
      <span className="label"> (str("Score")) </span>
      <span className="value"> (str(string_of_int(score))) </span>
    </div>
  };
};

/* This is our Page (or App) component. */
let pageComponent = ReasonReact.reducerComponent("Page");
let markEntry = (entries: list(entry), id: int) : list(entry) => {
  entries
    |> List.map((item) => if (id == item.id) {...item, marked: not (item.marked) } else item)
};

let make = (_children) => {
{
  ...pageComponent,
  initialState: () => {
    initialModel
  },
  reducer: (action, state) =>
    switch (action) {
    | NewGame => ReasonReact.Update({...state, entries: initialEntries, gameNumber: (state.gameNumber + 1)})
    | Mark (id) => ReasonReact.Update({...state, entries: markEntry(state.entries, id)})
    },
  render: ({state: {name, entries, gameNumber}, send}) => {
    <div className="content">
      <Header title="BUZZWORD BING"/>
      <ViewPlayer name={name} gameNumber={gameNumber}/>
      <EntryItems entries={entries} handleClick={{_id => send (Mark(_id))}}/>
      <GameScore score={summedScore(entries)}/>
      <button onClick={_event => send(NewGame)}>(str("New Game"))</button>
    </div>
  }
  };
};
