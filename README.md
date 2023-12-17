Currently building a simple 2D Engine to create small 2D games for various devices. Building a small retro space shooter on top of the engine to figure out whats still missing. 

### Core.h - Utilities
| Engine Keyword | use / internal works |
-----------------|----------------
| unique | std::unique_ptr<T> |
| shared | std::shared_ptr<T> |
| weak | std::weak_ptr<T> |
| List | std::vector<T> |
| Map | std::map<keyType, valueType, Pr> |
| Dictionary | std::unordered_map<keyType, valueType, hasher> |
| LOG("LOGGING TEXT %s", variable) | Just to log text to the console |

### MathUtilities.h - Math Utilities
| Code | Explanation |
------- | --------
| RotationToVector(float rotation) | Translating a rotation to a vector |
| DegreesToRadians(float degrees) | Translating degrees to radians |
| RadiansToDegrees(float radians) | Translating radians to degrees |

The LightYearsEngine folder is the only folder needed to create a game.
The Folder LightYearsGame is just the Demo game to show the capabilities of the Engine.

Documentation will (probably) be provided in the future.
