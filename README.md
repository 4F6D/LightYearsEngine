Currently building a simple 2D Engine to create small 2D games for various devices. Building a small retro space shooter on top of the engine to figure out whats still missing. 

Core.h keyword alias -> real keyword. 
- unique -> std::unique_ptr<T>
- shared -> std::shared_ptr<T>
- weak -> std::weak_ptr<T>
- List -> std::vector<T>
- Map -> std::map<keyType, valueType, Pr>
- Dictionary -> std::unordered_map<keyType, valueType, hasher>
- LOG("LOGGING TEXT", variable)

The LightYearsEngine folder is the only one need to create a game.
The Folder LightYearsGame is just the Demo game to show the capabilities of the Engine.

Documentation will (probably) be provided in the future.
