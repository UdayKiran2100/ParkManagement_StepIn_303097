# TEST PLAN:

## High level test plan

| **Test ID** | **Description** | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test** 
|-------------|-----------------|-------------|-------------|----------------|-----------------
|H_01|Checking The working of the whole System |As Prompted by the System |Operations are executed as expected|Obtained the required results|Requirement based |
|H_02|Checking whether all the required data given being captured| Providing appropriate Input Data  | All the functions are executed and correct results are obtained|Same as Expected Output|Scenario based|
|H_03|Checking for invalid choices |  Anything except the given Options| "Invalid Input" |"Invalid Input" | Boundary based    |

## Low level test plan

| **Test ID** | **Description** | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|-----------------|-------------|-------------|----------------|------------------|
|  L_01       |Working of submodule Multithread  |    By giving pointer value of linked list| Writing the updated list to file |Obtained the required results for the operations|Requirement based    |
|  L_02       |Working of submodule parkAdd   |    By giving different names and pointer value of linked list | The name added to list as well as file |Obtained the required results as required |Requirement based    |
|  L_03       |Working of submodule parkDelete  |    By giving different token values as required and pointer value of linked list| Correct answer according to the input values |Obtained the required results for the operations|Requirement based    |
|  L_04       |Working of submodule parkPrint_tofile  |    By giving pointer value of linked list| Returns 1 if values are successfully written to file else 0 |Obtained the required results for the operations|Requirement based    |
|  L_05       |Working of submodule parkPrint_tofile  |    By giving pointer value of linked list| Returns 1 if values are successfully written to file else 0 |Obtained the required results for the operations|Requirement based    |
|  L_06       |Working of submodule push_token  |    By giving different values| Returns 0 if stack is full else index |Obtained the required results for the operations|Requirement based    |
|  L_07       |Working of submodule pop_token  |    By giving different values| Returns -1 if stack is empty else popped value |Obtained the required results for the operations|Requirement based    |

