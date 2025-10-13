import pandas as pd
import numpy as np

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    df = employees.copy()
    
    # Calculate bonus
    df['bonus'] = np.where(
        (df['employee_id'] % 2 == 1) & (~df['name'].str.startswith('M')),
        df['salary'],
        0
    )
    
    # Return only required columns, sorted by employee_id
    return df[['employee_id', 'bonus']].sort_values(by='employee_id').reset_index(drop=True)
