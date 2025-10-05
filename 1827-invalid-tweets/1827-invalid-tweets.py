import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    df = tweets
    df = df[df['content'].str.len() > 15][['tweet_id']]
    return df
