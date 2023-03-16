import imageio.v2 as imageio

gif_original = 'bubble_sort.gif'
gif_speed_up = 'speed_up.gif'

gif = imageio.mimread(gif_original)

imageio.mimsave(gif_speed_up, gif, fps=240)