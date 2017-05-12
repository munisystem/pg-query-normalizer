# pg-query-normalizer
Normalize PostgreSQL Query.

This is using C library of [libpg_query](https://github.com/lfittl/libpg_query).

Thanks [Lukas Fittl](https://github.com/lfittl).

## Install

```bash
$ npm install --save pg-query-normalizer
```

## Usage
```js
'use strict';
const pgn = require('pg-query-normalizer');

const query = "SELECT username FROM Users WHERE id IN(1, 2, 3, 5, 8, 11);"
console.log(pgn(query));
/* "SELECT username FROM Users WHERE id IN(?);" */

const illegal = "SELECT SELECT SELECT;"
console.log(pgn(illegal));
/* "" */
```

## License
MIT © munisystem
