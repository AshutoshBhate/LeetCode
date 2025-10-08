import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    df_DIAB = patients['conditions'].str.split(' ')
    condition = df_DIAB.apply(lambda x : any(element.startswith("DIAB1") for element in x))

    ans_df = patients[condition]


    return ans_df