# Merge config plus

Tool for Kconfig's config fragments merge inspired by `merge_config.sh`, extending it's capabilities.

## Features

* `=` create new var or replace old value with new
* `include`, `oinclude` include config fragment to the flow
* `+=`, `=+` prepend or append value for previous (for string vars)
* `$(NAME)` replace with existing var value immidiately
* `${NAME}` eplace with existing var value at the end of processing

## Usage
