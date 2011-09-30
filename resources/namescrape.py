#!/usr/bin/python

import BeautifulSoup
import urllib2

print 'Loading site...'

output = open('male-names.txt', 'w')

html = urllib2.urlopen('http://names.mongabay.com/male_names_alpha.htm')
soup = BeautifulSoup.BeautifulSoup(html)
items = soup.findAll('table', style='table1')[0].findAll('tr')

print 'Writing names...'

for item in items[1:]:
    output.write(item.td.text.title() + "\n")

output.close()

print 'Done.'