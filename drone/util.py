def float_or(s, default):
  try:
    return float(s)
  except:
    return default
