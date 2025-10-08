import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    full_email_regex = r'^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\.com$'
    
    condition = users['mail'].str.match(full_email_regex)
    
    df = users[condition][['user_id', 'name', 'mail']]
    
    return df