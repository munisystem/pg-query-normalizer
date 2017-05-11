'use strict'
const pgn = require('./build/Release/pg-query');

module.exports = function(data) {
  return pgn.normalize(data).replace(/\?(, \?)+/g, "?");
}
