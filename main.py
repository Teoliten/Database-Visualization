import matplotlib.pyplot as plt
import os
from PyPDF2 import PdfReader
#----------------------------------------------------
startPath = "./deviceHistoryRecord"
information = []
for systemFolder in os.listdir(startPath):
    if systemFolder.isdigit() and 99 < int(systemFolder) < 1000:
        filePath = os.path.join(startPath, systemFolder, "System", "data.txt")
        #print(filePath)
        
        with open(filePath, 'r') as file:
            # Read the contents of the file
            file_contents = file.read()
            
        print(file_contents)
        info_parts = file_contents.split(" ")
        info_parts.append(systemFolder)
        
        information.append(info_parts)
print(information)

#----------------------------------------------------

# creating a pdf reader object
reader = PdfReader('data.pdf')
# getting a specific page from the pdf file
page = reader.pages[0]
# extracting text from page
text = page.extract_text()
# split the text into a list of values
values = text.split('\n')

# convert each value to a float, removing '%'
data = [float(value.replace("%", "")) for value in values if value]

# x-axis labels (assuming one label per data point)
x_labels = [f'{i+1}' for i in range(len(data))]

#----------------------------------------------------

avg = round(sum(data)/len(data), 2)
maxValue = max(data)
minValue = min(data)

print("Average: ", avg)
print("Max Value: ", maxValue)
print("Min Value: ", minValue)

#----------------------------------------------------

# Plotting with style
plt.figure(figsize=(10, 6))  # Adjust figure size as needed
plt.plot(x_labels, data, marker='o', linestyle='-', color='b', label='Non-Deviant data point percentage')
plt.title('Non-Deviant data point percentage')
plt.xlabel('Data Points')
plt.ylabel('Percentage')
plt.grid(True)
plt.legend()
plt.show()

#----------------------------------------------------