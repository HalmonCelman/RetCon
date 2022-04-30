How to create animation for this system?
1. Create animation in gimp or another program.
2. Export to *gif
3. Convert to *.wbmp with https://convertio.co/pl/gif-wbmp/ or any similiar converter
4. Download zip
5. Unpack to animacje/frames/
and from now you have two options
A. to do automatically:
6. run from terminal ./manima.sh
7. write how your gif was named ->f.e your gif - a.gif then you write a
8. copy prefix (if you have files in frame/a f.e. abc0.wbmp abc1.wbmp then you should copy abc) and paste it
9. give how you would name your animation
10. done! your animation is in folder exported/

OR

B. manually
6. run from terminal ./rrator.sh
7. write how your gif was named ->f.e your gif - a.gif then you write a
8. copy prefix (if you have files in frame/a f.e. abc0.wbmp abc1.wbmp then you should copy abc) and paste it
9. give how you would name your animation
10. run ./condator.sh
11. write this same as in 7 point
12. write this same as in 9 point
13. run ./exportator.sh
14. write this same as in point 9 and 12
10. done! your animation is in folder exported/
