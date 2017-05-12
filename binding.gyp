{
  "targets": [
    {
      "target_name": "pg-query",
      "sources": [ "pg-query.cc", "normalize.cc" ],
      "include_dirs": ["<!(node -e \"require('nan')\")", "ext/libpg_query/include"],
      'conditions': [
              ['OS=="mac"', { "libraries": ["-L<!(pwd)/ext/libpg_query/osx", "-lpg_query"] }],
              ['OS=="linux"', { "libraries": ["-L<!(pwd)/ext/libpg_query/linux", "-lpg_query"] }]
      ]
    }
  ]
}
