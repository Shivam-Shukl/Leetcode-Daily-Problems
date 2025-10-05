import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    df = views[views['author_id']==views['viewer_id']]
    df = df[['author_id']].drop_duplicates()
    df=df.sort_values(by='author_id')
    df=df.rename({'author_id':'id'},axis=1)
    return df
