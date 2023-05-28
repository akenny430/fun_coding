double calculateTax(int** brackets, int bracketsSize, int* bracketsColSize, int income){
    int paid = 0; 
    int prev_upper = 0; 
    for(int i = 0; i < bracketsSize; ++i)
    {
        if(brackets[i][0] > income)
        {
            paid += (income - prev_upper) * brackets[i][1]; 
            break; 
        }
        paid += (brackets[i][0] - prev_upper) * brackets[i][1]; 
        prev_upper = brackets[i][0]; 
    }
    return ( (double) paid) / 100.0; 
}