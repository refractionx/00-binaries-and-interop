{
  "targets": [
    {
      "target_name": "greetings",
      "include_dirs": [
        "../../1-libraries/include",
      ],
      "libraries": [
        "-lgreetings-it",
        "-L<(module_root_dir)/lib64/macOS"
      ],
      "sources": [ "greetings.cc" ]
    }
  ]
}