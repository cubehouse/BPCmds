# Blueprint Console Commands

This plugin lets you setup console commands in Blueprint quickly.

Make a function starting with "Cmd" and it'll be called when you run the function name from the console!

## Example

Create a Blueprint function called "CmdTest"

Press \` to open the console in-game, and type the command "test". Your Blueprint function will now run!

## Install

* Create a folder called "Plugins" in your project (if it doesn't exist already).
* Clone this project into Plugins so you get Plugins/BPCmds/BPCmds.uplugin
* Re-generate your project files (usually via right-click your .uproject)
* Re-compile your game (plugin is automatically enabled by default)

## Caveats

* Your Cmd* function must not return any value.
* Commands won't auto-complete
