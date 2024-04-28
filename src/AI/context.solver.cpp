#include "../../library/AI/context.solver.h"

Vector2 ContextSolver::GetDirectionToMove(double *danger, double *interest){
    vector<Vector2> directions = EightDirections::directions();

    for (int i = 0; i < directions.size(); i++){
        interest[i] = std::clamp(interest[i] - danger[i], 0.0, 1.0);
    }

    Vector2 result;
    for (int i = 0; i < directions.size(); i++){
        result = result + directions[i] * interest[i];
    }
    return result.normalize();
}