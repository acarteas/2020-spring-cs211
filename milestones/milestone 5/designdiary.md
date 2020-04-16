****Design Diary*****


04/07/2020

Before I even started programming the algorithm, I close my laptop and got a piece of paper to see what it was I was actually trying to accomplish with my tiles. 
I wasn't ready for pseduo code because I wanted to see the behavior. After spening some time getting the alogrithim worked out on the paper, I started to familiarize
myself with the code that was provided with the assignment. I still feel like even though the code was there, trying to decipher what it is doing, was the hardest part.
I'm still not comfortable witht the different part in unity, so I'm struggling testing to see if the code I have produced so far is actually behaving the way that I would like.
I was introducted to stub functions in Sharon's class and have seen several classmates use them in their code while they are writing out their program. This was 
helpful for creating the function getNeighbors because I wasn't sure what need to go in the block, but it gave me the chance to continue throught the code, and not waste
time. 


04/13/2020

Today I spend a good amount of time reviewing what I was working on and how the algorthim worked because it had been a few days since I had looked at Milestone 5. 
I was able to program the different tiles position by manipulating the x and y coordinates, and also add them to the neighbors list. I created some conditional statments
that checked if we were at the "found" tile, and if that condition was met, then we break from the while loop and continue the code. I feel like I have most of the algorithm programmed
right now, but I'm having the hardest time getting the Unity UI properly configured, so that I can test and verify that my code is working logically. The other
issue that I'm having is handling the mouse clicks. I see in the TileSelectionManager script that there are functions that will handle this, but I'm not sure how to
get my sceen properly connected. I'm also unsure about how we are supposed to load the tiles that are given in the sprites section. I'm going to do some googling
to see if I can deepen my understading on how to get the game to test properly. I feel that, overall, I have a better understanding of this algorithim, and I'm thankful
in the homework instructions that the instructions were explicit in a way that could be identiifed when trying to approach the problem programatically after doing it 
on paper.


04/15/2020

After writing what I though was most of my code, I couldn't get it to run because it was not displaying the pre-loaded game scene. I misunderstood what was avaible in terms of the 
project being set up for us, and I had a classmate take a look, and they instantly noticed that I was on an older version of unity, and that the scene should populate with the click of
playing the game. Once I installed the newest version, I tried to run my project, but it still wouldn't work when I was trying to get it to load. I deleted my files recommited them, and re-cloned 
your repo, so that I could get a fresh version of project 5. I copied my existing code, and thankfully I was able to start testing the code and seeing where my logical flaws were. I have narrowed it down
to two lines of code, but I need to figure out in the getNeighbor function how to move the positions of the tile, so that I'm not returning the same tile each time. As of right now, I feel like I have made good
progress in getting my code interfaced with Unity, and I'm excited to finish the project, ahd hopefully have a fully function game like the GIF shows on git. '
