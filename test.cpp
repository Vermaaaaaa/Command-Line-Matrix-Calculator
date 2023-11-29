void determinant(std::shared_ptr<std::unordered_map<std::string, Matrix>> &map){
    bool found_flag = false;
    Matrix mat;

    do{
        mat = select(map, found_flag);
    }
    while(!found_flag);

    Matrix l(mat.get_row(), mat.get_col());
    Matrix u(mat.get_row(), mat.get_col());

    int n = mat.size();
    int i = 0, j = 0, k = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (j < i)
                    l.set_index(j,i,0);
                else
                {
                    l.set_index(j,i,mat.get_index(j,i));
                    for (k = 0; k < i; k++)
                    {
                        int val = l.get_index(j,i) - l.get_index(j,k) * u.get_index(k,i);
                        l.set_index(j,i,val);
                    }
                }
            }
            for (j = 0; j < n; j++)
            {
                if (j < i)
                    u.set_index(i,j,0);
                else if (j == i)
                    u.set_index(i,j,1);
                else
                {
                    int value = mat.get_index(i,j) / l.get_index(i,i);
                    u.set_index(i,j,value);
                    for (k = 0; k < i; k++)
                    {
                        int value2 = u.get_index(i,j) - (l.get_index(i,k) * u.get_index(k,j) / l.get_index(i,i));
                        u.set_index(i,j,value2);
                    }
                }
            }
        }
    
    double det = 1;
    
    for(int q = 0; q < n; q++){
        det *= u.get_index(q,q) * l.get_index(q,q);
    }

    std::cout << "The determinant is: " << det << std::endl;
        
}

        for (int current_row = 0; current_row < n - 1; current_row++) {
            if(!mat.get_index(current_row, col) || !mat.get_index(current_row + 1, col)){continue;}
            double factor = mat.get_index(current_row, col) / mat.get_index(current_row + 1 , col);
            double mat_index = mat.get_index(current_row + 1, col);
            mat_index -= mat.get_index(current_row,col) * factor;
            mat.set_index(current_row + 1,col,mat_index);
        }  