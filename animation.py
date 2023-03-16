import imageio.v2 as imageio

filenames = []
for i in range(1, 2390):
    filenames.append(f"/home/egor/frames/frame_{i}.png")

with imageio.get_writer('/home/egor/bubble_sort.mp4') as writer:
    for i, filename in enumerate(filenames):
        print(i)
        image = imageio.imread(filename)
        writer.append_data(image)

