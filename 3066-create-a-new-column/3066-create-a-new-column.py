import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    df = employees
    bonus = [i*2 for i in df['salary']]
    df['bonus'] = bonus
    return df