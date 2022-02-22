/*

A group of cows grabbed a truck and ventured on an expedition deep into the jungle. The truck leaks 1 unit of fuel per unit of distance traveled. 

To repair the truck, the cows need to drive to the nearest town on the way there are N  fuel stops where they can aquire additional fuel(1- 100 units).

The cows need to make the minimum number of stops to get to the town.

capacity of truck is infinite.

Initial unit of fuel is P 
Initial distance from town is D

Determine the minimum number of stops needed to get to the town.

SOLUTION:

- create a max heap storing the fuels available at the stops that we have traversed

- sort stops on basis of distance based on initaial distance from truck

- iterate on stops, and when truck becomes empty take fuel from maxheap and add to the truck

- maintain count of steps from which we have taken fuel
*/