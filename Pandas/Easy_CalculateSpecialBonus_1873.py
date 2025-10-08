import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    df = employees
    
    df['bonus'] = 0

    condition = (df['employee_id'] % 2 != 0) & (~df['name'].str.startswith('M'))
    df.loc[condition, 'bonus'] = df['salary']

    result_df = df[['employee_id', 'bonus']].sort_values('employee_id')

    return result_df