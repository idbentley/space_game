import Image
import ImageDraw
import sys
import os

def loadImage(name):
	try:
		img = Image.open(name)
		return img
	except IOError:
		print 'File ' + name + ' not an image.'
		exit(0)


if len(sys.argv) < 4:
	print 'Usage:'
	print 'python spritemap_creator.py <outputname> <number of sprites to generate> <inputfile1> [<inputfile2> ...]'
	exit(0)
try:
	int(sys.argv[2])
except ValueError:
	print 'Usage:'
	print 'python spritemap_creator.py <outputname> <number of sprites to generate> <inputfile1> [<inputfile2> ...]'
	exit(0)
	
if 360 % int(sys.argv[2]) != 0:
	print 'Invalid number of sprites.  Must be a factor of 360.'
	exit(0)
img = loadImage(sys.argv[3]).convert('RGBA');
imsize = (img.size[0], img.size[1])
imbg = Image.new('RGB',imsize,'#FF008F')
tempsize = imsize[0]*int(sys.argv[2]), imsize[0]*(len(sys.argv) - 3)
imfinal = Image.new('RGB',tempsize)
for i in range(3, len(sys.argv)):
	if i > 3:
		img = loadImage(sys.argv[i]).convert('RGBA')
	if(img.size != imsize):
		print 'File ' + sys.argv[i] + ' invalid.  All files must be the same size.'
		exit(0);
	else:
		for j in range(0,int(sys.argv[2])):
				tmp = img.rotate(360-(j*(360/int(sys.argv[2]))))
				tmp = Image.composite(tmp,imbg,tmp).convert('RGB')
				imfinal.paste(tmp, (j*imsize[0], (i-3)*imsize[1], (j+1)*imsize[0], (i-2)*imsize[1]))
imfinal.save(sys.argv[1])


