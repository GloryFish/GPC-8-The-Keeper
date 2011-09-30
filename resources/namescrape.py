#!/usr/bin/python

import BeautifulSoup
import urllib2

print 'Loading male names...'

output_male = open('male-names.txt', 'w')

html = urllib2.urlopen('http://names.mongabay.com/male_names_alpha.htm')
soup = BeautifulSoup.BeautifulSoup(html)
items = soup.findAll('table', style='table1')[0].findAll('tr')

print 'Writing male names...'

for item in items[1:]:
    output_male.write(item.td.text.title() + "\n")

output_male.close()

print 'Loading female names... '

output_female = open('female-names.txt', 'w')

html = urllib2.urlopen('http://names.mongabay.com/female_names_alpha.htm')
soup = BeautifulSoup.BeautifulSoup(html)
items = soup.findAll('table', style='table1')[0].findAll('tr')

print 'Writing female names...'

for item in items[1:]:
    output_female.write(item.td.text.title() + "\n")

output_female.close()

print 'Done.'