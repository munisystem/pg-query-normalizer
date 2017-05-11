{
  "targets": [
    {
      "target_name": "pg-query",
      "sources": [ "pg-query.cc" ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}
