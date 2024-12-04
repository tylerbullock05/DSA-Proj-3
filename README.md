<H1> COP3530 - Project 3 </h1>
Joshuah Pribell, Ross Jackson, Tyler Bullock
<h2> Project Description </h2>
This project utilizes Dijkstra's Algorithm and Bellman-Ford's Algorithm to find the best path between two airports. The project uses data from a dataset called

[US Airline Flight Routes and Fares 1993-2024](www.kaggle.com/datasets/bhavikjikadara/us-airline-flight-routes-and-fares-1993-2024)
. The dataset consists of 245,955 rows and 23 columns, although we only use 3 columns. The project contains a parseCSV file to collect all the data in the dataset and adds it into our adjaceceny list, which is our graphical representation of the airports and their connecting flights. The user is given an option to look at available airports by inputting a letter and displaying all airport codes that begin with that letter. Finally, once you are done, you will be prompted to input the starting and ending airports. The two algorithms will run, and an output will show if there is a route possible, the total distance, as well as the run times of each algorithm.
