import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df1 = customers
    df2 = orders
    df3 = df1[~df1['id'].isin(df2['customerId'])][['name']]
    df3.rename(columns={'name': 'Customers'}, inplace=True)
    return df3
