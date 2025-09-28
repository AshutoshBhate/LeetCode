import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    df = (world['area'] >= 3000000) | (world['population'] >= 25000000)
    big_world = world[df]
    big_world_selected = big_world[['name', 'population', 'area']]
    return big_world_selected