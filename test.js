const assert = require("assert");
const pgn = require('./index.js');

describe('correct query', function() {
  it('column', function(){
    assert.equal(pgn("SELECT a FROM A;"), "SELECT a FROM A;");
  });

  it('WHERE', function(){
    assert.equal(pgn("SELECT * FROM A WHERE id = 1;"), "SELECT * FROM A WHERE id = ?;");
  });

  it('LIMIT', function(){
    assert.equal(pgn("SELECT * FROM A LIMIT 20;"), "SELECT * FROM A LIMIT ?;");
  });

  it('WHERE IN', function(){
    assert.equal(pgn("SELECT * FROM A WHERE id IN(1, 2, 3);"), "SELECT * FROM A WHERE id IN(?);");
  });

  it('not semicolon', function(){
    assert.equal(pgn("SELECT * FROM A"), "SELECT * FROM A");
  });
});

describe('illegal query', function() {
  it('not selected', function(){
    assert.equal(pgn("SELECT FROM A;"), "SELECT FROM A;");
  });

  it('not choise', function(){
    assert.equal(pgn("SELECT FROM"), "");
  });

  it('only FROM', function(){
    assert.equal(pgn("FROM"), "");
  });

  it('illegal format', function(){
    assert.equal(pgn("JOIN SELECT * FROM A;"), "");
  });
});
