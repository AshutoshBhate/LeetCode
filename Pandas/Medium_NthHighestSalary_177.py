import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:

    df = pd.DataFrame()
    employee_salary = employee['salary'].drop_duplicates().sort_values(ascending = False)

    if N > employee_salary.nunique() or N <= 0:
        df = pd.DataFrame({f'getNthHighestSalary({N})' : [np.nan]})
    else:
        df[f'getNthHighestSalary({N})'] = pd.Series(employee_salary.iloc[N - 1])

    return df