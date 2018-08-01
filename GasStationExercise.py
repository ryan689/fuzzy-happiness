from math import inf

# function
def lowest_cost(C, L, tank_size):
    # C[i] is the cost per liter of petrol at checkpoint i
    # L[i] is the minimum number of liters of petrol needed at checkpoint i to get to next checkpoint
    # the current_tank level cannot ever exceed the tank_size
    
    total_dollars_spent = 0
    current_tank = 0
    
    for current_checkpoint in range(len(C)):
        # decide how much petrol to get at this checkpoint
        #print('\nI arrived at station ' + str(current_checkpoint + 1) + ' with ' + str(current_tank) + ' liters of fuel.')
        
        if current_tank < L[current_checkpoint]:
            # find next checkpoint which has lower cost
            for i in range(current_checkpoint + 1, len(C)):
                if C[i] < C[current_checkpoint]:
                    #print('The gas at station ' + str(i + 1) + ' is cheaper (' + str(C[i]) + ') than where I am now (' + str(C[current_checkpoint]) + ').')
                    next_cheaper_checkpoint = i
                    break
                #else:
                    #print('The gas at station ' + str(i + 1) + ' is more expensive (' + str(C[i]) + ') than my where I am now (' + str(C[current_checkpoint]) + ').')
            else:
                #print('This is the last, cheapest station.')
                next_cheaper_checkpoint = len(C)
                
            # find how many liters are needed to get to this checkpoint
            
            liters_needed = sum(L[current_checkpoint:next_cheaper_checkpoint])
            #print('I need ' + str(liters_needed) + ' liters to get there.')
        
            # buy that many liters
            dollars_spent = liters_needed * C[current_checkpoint]
            #print('I spent $' + str(dollars_spent) + ' on ' + str(liters_needed) + ' liters of fuel.')
            total_dollars_spent += dollars_spent
            current_tank += liters_needed
            #print('I am leaving station ' + str(current_checkpoint + 1) + ' with ' + str(current_tank) + ' liters of fuel.')
        
        current_tank -= L[current_checkpoint]

    #print('\nI arrived at my destination with ' + str(current_tank) + ' liters of fuel.')
    return total_dollars_spent

# get input
test_cases = int(input())

for _ in range(test_cases):
    num_checkpoints = int(input())
    cost_line = input()
    costs = cost_line.split(' ')
    petrol_needed_line = input()
    petrol_needed = petrol_needed_line.split(' ')
    
    # fix dumb input issue
    costs = [cost for cost in costs if cost != '']
    
    for i in range(len(costs)):
        costs[i] = int(costs[i])
            
    for i in range(len(petrol_needed)):
        petrol_needed[i] = int(petrol_needed[i])
    
    print(lowest_cost(costs, petrol_needed, inf))
