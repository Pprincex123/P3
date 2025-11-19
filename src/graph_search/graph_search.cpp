#include <iostream>
#include <cmath>
#include <queue>
#include <functional>

#include <path_planning/utils/math_helpers.h>
#include <path_planning/utils/graph_utils.h>

#include <path_planning/graph_search/graph_search.h>

/**
 * General graph search instructions:
 *
 * First, define the correct data type to keep track of your visited cells
 * and add the start cell to it. If you need to initialize any properties
 * of the start cell, do that too.
 *
 * Next, implement the graph search function. Save the result in the path
 * variable defined for you.
 *
 * To visualize which cells are visited in the navigation webapp, save each
 * visited cell in the vector in the graph struct as follows:
 *      graph.visited_cells.push_back(c);
 * where c is a Cell struct corresponding to the visited cell you want to
 * visualize.
 *
 * The tracePath() function will return a path (which you should assign to
 * the path variable above) given the goal index, if you have kept track
 * of the parent of each node correctly and have implemented the
 * getParent() function. If you do not find a path, return an empty path
 * vector.
*/

std::vector<Cell> depthFirstSearch(GridGraph &graph, const Cell &start, const Cell &goal)
{
    std::vector<Cell> path; // The final path should be placed here.

    initGraph(graph); // Make sure all the node values are reset.

    int start_idx = cellToIdx(start.i, start.j, graph);
    
    // *** Task: Implement this function if completing the advanced extensions *** //
    int goal_idx = cellToIdx(goal.i, goal.j, graph);
    std::stack<int> visit_stack;
    visit_stack.push(start_idx);
    graph.nodes[start_idx].queued = true;
    graph.nodes[start_idx].parent = -1;
    graph.nodes[start_idx].cost = 0;

    while (!visit_stack.empty()){
        int currentNode = visit_stack.top();
        
    }   
    // *** End student code *** //

    return path;
}

std::vector<Cell> breadthFirstSearch(GridGraph &graph, const Cell &start, const Cell &goal)
{
    std::vector<Cell> path; // The final path should be placed here.

    initGraph(graph); // Make sure all the node values are reset.
    int start_idx = cellToIdx(start.i, start.j, graph);
    int goal_idx = cellToIdx(goal.i, goal.j, graph);

    // *** Task: Implement this function *** //
    std::queue<int> visit_queue;
    visit_queue.push(start_idx);
    graph.nodes[start_idx].queued = true;
    graph.nodes[start_idx].parent = -1;
    graph.nodes[start_idx].cost = 0;

    while ((visit_queue.empty() == false)) {
        int currentNode = visit_queue.front();
        if (currentNode == goal_idx) {
            break;
        }
        // std::cout << "Current Node: " << currentNode << std::endl; 
        std::vector<int> temp_neighbors = findNeighbors(currentNode, graph);
        for (int i = 0; i < temp_neighbors.size(); i++) {
            if (checkCollision(temp_neighbors[i], graph)){
                continue;
            }
            if (!(graph.nodes[temp_neighbors[i]].visited) && !(graph.nodes[temp_neighbors[i]].queued)) {          
                visit_queue.push(temp_neighbors[i]);
                graph.nodes[temp_neighbors[i]].queued = true;
            }
                int dx = graph.nodes[currentNode].x - graph.nodes[temp_neighbors[i]].x;
                int dy = graph.nodes[currentNode].y - graph.nodes[temp_neighbors[i]].y;
                int Newcost = sqrt(pow(dx, 2) + pow(dy, 2));
 
            if (Newcost + graph.nodes[currentNode].cost < graph.nodes[temp_neighbors[i]].cost) {
                graph.nodes[temp_neighbors[i]].parent = currentNode;
                graph.nodes[temp_neighbors[i]].cost = Newcost + graph.nodes[currentNode].cost;
            }


        }
        // std::cout << "Parent Node: " << graph.nodes[currentNode].parent << std::endl; 
        graph.nodes[visit_queue.front()].visited = true;
        visit_queue.pop();
    }

    return path = tracePath(goal_idx, graph);
}


std::vector<Cell> iterativeDeepeningSearch(GridGraph &graph, const Cell &start, const Cell &goal)
{
    std::vector<Cell> path; // The final path should be placed here.

    initGraph(graph); // Make sure all the node values are reset.

    int start_idx = cellToIdx(start.i, start.j, graph);

    // *** Task: Implement this function if completing the advanced extensions *** //

    // *** End student code *** //

    return path;
}

std::vector<Cell> aStarSearch(GridGraph &graph, const Cell &start, const Cell &goal)
{
    std::vector<Cell> path; // The final path should be placed here.

    initGraph(graph); // Make sure all the node values are reset.

    int start_idx = cellToIdx(start.i, start.j, graph);

    // *** Task: Implement this function if completing the advanced extensions *** //

    // *** End student code *** //

    return path;
}
