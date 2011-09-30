#!/usr/bin/python



male_file = open('male-names.txt', 'r')
male_names = male_file.readlines()

female_file = open('female-names.txt', 'r')
female_names = female_file.readlines()


unique_male_names = [name for name in male_names if not name in female_names]
unique_female_names = [name for name in female_names if not name in male_names]
     
     
print "There are %i male names before filtering." % len(male_names)
print "There are %i male names after filtering." % len(unique_male_names)
print ""
print "There are %i female names before filtering." % len(female_names)
print "There are %i female names after filtering." % len(unique_female_names)


male_file_unique = open('male-names-unique.txt', 'w')

for name in unique_male_names:
    male_file_unique.write("%s\n" % name)

male_file_unique.close()

female_file_unique = open('female-names-unique.txt', 'w')

for name in unique_female_names:
    female_file_unique.write("%s\n" % name)

female_file_unique.close()
