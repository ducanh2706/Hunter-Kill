import matplotlib.pyplot as plt

# Parse the CSV data into a 2D list
data = """
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
""".strip().split('\n')

data = [[int(num) for num in row.split(',')] for row in data]

# Create a figure and a subplot
fig, ax = plt.subplots()

# Display the data as an image

cax = ax.imshow(data, cmap='viridis')

# Add a colorbar to the subplot
fig.colorbar(cax)

# Display the plot
plt.show()