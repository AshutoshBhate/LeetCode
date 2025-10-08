import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(customers, orders, how = 'left', left_on = 'id', right_on = 'customerId')
    test_df = pd.DataFrame()
    test_df['Customers'] = df[df.notna()['id_y'] == False]['name']
    
    return test_df