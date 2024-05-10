class ChatBot:

    def __init__(self):
        self.responses={}

    def add_responses(self,keyword,response):
        self.responses[keyword]=response

    def interact(self):
        best_response="PICTy : I'm not able to understand you !! Could you please rephrase ??"

        input_text=input("You : ")

        if(input_text == "exit"):
            print("You were a wonderful visitor !! Loved helping you, Good Bye !!")
            response="exit"
            return response

        for keyword,response in self.responses.items():
            if keyword in input_text:
                return response

        return best_response;

print("PICTy : Welcome to PICT !!")
print("PICTy : Please press 'exit' if you get bored by me !!")
print("PICTy : I am PICTy!!")
print("PICTy : How can I assist you for today??")

bot=ChatBot();
bot.add_responses("about","PICT is Pune Institute of Computer Technology which is the best Engineering Colleges in Pune established in year 1983.For more information visit https://pict.edu/about-us/")
bot.add_responses("cutoff","All admissions in PICT are merit bases.The cutoff for General Category in 99 percentile in MHT-CET and 95 percentile in JEE-Mains.For more infomation visit https://pict.edu/cutoff/")
bot.add_responses("branches","PICT offers Engineering Courses in CE,IT,ENTC,ECE,AIDS.For more infomation visit https://pict.edu/branches/")
bot.add_responses("hostel","PICT offers hostel facilities to both boys and girls equipped with all modern time facilities.For more information visit https://pict.edu/hostel/")
bot.add_responses("placement","PICT has sucessfully placed 851 students in the year of 2024.For more information visit https://pict.edu/placements/")
bot.add_responses("placements","PICT has sucessfully placed 851 students in the year of 2024.For more information visit https://pict.edu/placements/")
bot.add_responses("syllabus","The course curriculum of students is desinged to meet the industy needs of top tech Product Companies.To have a look at year wise syllabus visit https://pict.edu/syllabus/")
bot.add_responses("curricular","PICT offers many co-curricular and extra-curricular activities through many technical and cultural fest.For more information visit https://pict.edu/curricular/")
bot.add_responses("fees","For General Category Students the fees for one year is 95,000 rupees.For more inforamtion visit https://pict.edu/fees/")

while True:
    result=bot.interact();
    if(result == "exit"):
        break
    else:
        print("PICTy : ",result)
        
'''
PICTy : Welcome to PICT !!
PICTy : Please press 'exit' if you get bored by me !!
PICTy : I am PICTy!!
PICTy : How can I assist you for today??
You : tell me something about PICT 
PICTy :  PICT is Pune Institute of Computer Technology which is the best Engineering Colleges in Pune established in year 1983.For more information visit https://pict.edu/about-us/
You : what is the cutoff for the institute
PICTy :  All admissions in PICT are merit bases.The cutoff for General Category in 99 percentile in MHT-CET and 95 percentile in JEE-Mains.For more infomation visit https://pict.edu/cutoff/
You : how many branches are there in the college
PICTy :  PICT offers Engineering Courses in CE,IT,ENTC,ECE,AIDS.For more infomation visit https://pict.edu/branches/
You : tell me something about its placements
PICTy :  PICT is Pune Institute of Computer Technology which is the best Engineering Colleges in Pune established in year 1983.For more information visit https://pict.edu/about-us/
You : what is the placement record of the instutite
PICTy :  PICTy : I'm not able to understand you !! Could you please rephrase ??
You : how are placements in pict
PICTy :  PICT has sucessfully placed 851 students in the year of 2024.For more information visit https://pict.edu/placements/
You : what are fees of the institute
PICTy :  For General Category Students the fees for one year is 95,000 rupees.For more inforamtion visit https://pict.edu/fees/
You : what is syllabus 
PICTy :  The course curriculum of students is desinged to meet the industy needs of top tech Product Companies.To have a look at year wise syllabus visit https://pict.edu/syllabus/
You : exit
You were a wonderful visitor !! Loved helping you, Good Bye !!
'''

'''
Time Complexity :- O(n^2)
'''    

