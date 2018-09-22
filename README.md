# tmspbp
Travelling Management System using Preferential Behaviour Patterns

This was a minor project created during a very hectic semester. As such the project doesn't exactly work as intended, and the code is ridiculously bad. I mean like really really bad. However, if you want to build upon it, or just destroy the damn thing here's the code.

The principle behind this project is the usage of preferences while travelling to book the required ticket using minimal effort from the user and at the same time, requiring less time to make the decision.

Let's take an example. Supposing you want to book a flight from City A to City B. Now when you type in the required parameters such as Destination. Source and Date of Journey etcetera, what most travel websites or travel companies do is give you the entire list of flights available on that particular day. Our project takes a step further by using the preferences given by the customer to filter this list, thereby reducing the amout of time required by the customer to traverse/browse the given options. The said "preferences" are input by the customer during the creation of his/her account. The list of preferences include Travelling during the day/night, Budget range etcetera. We've even incorporated a "travel package" generator just for the heck of it.

FUNCTIONING:
1) Say you want to book a flight from Dehradun to Delhi (cities in India). So what the program does is read the flightdb.csv, checks if any flight is present in the .csv file that satisfies the given parameters and prints it out. 
2) The package generator takes certain parameters from the user like Source, Destination, Stops in between, the dates on which the customer wishes to depart from a particular city etcetera. The program again reads all the .csv files and concocts a travel package which is written into another .csv file.

PROS: 

1) The program works, just not as expected.
2) It uses C language, so its simple enough to understand.

CONS: This is a pretty long list.
1) The program uses static databases. It reads the data from a .csv file. So if you were thinking of using this program on any dynamic related topics, I'm sorry to disappoint you.
2) We've taken a bunch of preferences from the user to filter out the options. But in reality we've only used two preferences to filter out the results.
3) The package generator is for shit. We wanted to implement backpropogation for this, but due to time constraints (created this project in like 8 hours :/), we couldn't.
4) The code is really bad. We haven't used function where we should have. There's a lot of code that just repeats itself, couple of dead variables that don't do anything. Possibilities of code crashing during the creation of package. Also for some reason, the package being written into the file might contain some NULL values (idk why).
