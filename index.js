'use strict'
const pgn = require('./build/Release/pg-query');
const fs = require('fs');

console.log(pgn.normalize(data).replace(/\?(, \?)+/g, "?"));
