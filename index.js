'use strict'
const pgn = require('./build/Release/pg-query');

module.exports = function(data) {
  try {
    const normalized = pgn.normalize(data)
    return normalized.replace(/\?(, \?)+/g, "?");
  } catch(e) {
    return ""
  }
}
