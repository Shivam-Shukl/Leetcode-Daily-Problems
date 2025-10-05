import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    df = products
    df = df[(df['low_fats'] == 'Y') & (df['recyclable'] == 'Y')][['product_id']]
    return df
