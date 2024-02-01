# Raycaster

This is a raycaster project that I am implementing in C++. I took the code from this [video](https://www.youtube.com/watch?v=ECqUrT7IdqQ) which implemented a basic raycaster in python. I tried to convert it from python to C using the CSFML library but the CSFML library was too outdated and wasn't compatible with my machine.

I then decided to make it in C++ mainly because the SFML library sort of works on my machine and it was easier to implement with classes and vectors. Currently this is a work in progress after getting SFML to work.

## Images

Here are some images of the raycaster in the python code. I implemented a fog effect which makes the walls darker the further away you are from them:
<img width="1200" alt="hallway" src="https://github.com/melvinczyk/Raycaster-project/assets/78186753/4c810916-92ee-4a01-b0d7-b3982c04bbf0">

Here is another image of some basic walls as well:
<img width="1200" alt="door" src="https://github.com/melvinczyk/Raycaster-project/assets/78186753/1e88f027-864a-4ebc-a649-d2aaa869a987">


## Future plans

The main reason why I wanted to create this raycaster was to implement custom maps. I plan on adding a feature to read a file and convert it into a custom map later on after I finish the basics. Right now the map is stored in a hardcoded 2d array but I would like it to be dynamicly read from a file. I am more knowledgeable in C than in C++ but I'm lucky that SFML has a ton of documentation which really made things a lot smoother.
