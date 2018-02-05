# reason-bingo

## What is this ?

When learning ELM, I found this course by pragmatic studio very helpful and wanted to apply it to ReasonML.

The app contains a simple sever running on port '3000', It will return some randomEntries.

The game is a basic UI which renders the random entries and calculates a score for entry clicked.

## Run this project locally:

```
npm install
npm start
# in another tab
npm run webpack
# and in another tab !! :P
cd /server && npm start
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up the nested html files in `src/*` (**no server needed!**). Then modify whichever file in `src` and refresh the page to see the changes.


## TODOS

- [] Introduce error handling loading etc.
- [] Deploy on Heroku would be nice :)
- [] Recored the score of every game to make a high score board.
- [] Introduce ability to remove/add players. (Some text field to record user inputs)
- [] Rewrite the sever implementation in ReasonML ?
- [] Make into a PWA (Might be useful to see how to link the bindings between js and reason)
- [] Possibly release an article
