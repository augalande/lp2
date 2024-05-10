def ask_questions(questions : str)->bool:
    response=input(questions+" :").lower().strip()[0]
    return response=="y"

def diagnose_pneumonia()->bool:
    return (ask_questions("Does you cough frequently??")
    and ask_questions("Does your throat and chest pain a lot while coughing??")
    and ask_questions("Do you have shortness of breath??"))

def diagnose_migrane()->bool:
    return (ask_questions("Do you have a headache in one side of head??")
    or ask_questions("Do you feel nauseous while having a headache??")
    or "Do you get irritated to light and sound??")

def diagnose_fever()->bool:
    return (ask_questions("Does you body temperature go above 38 Degree Celcius??")
    or ask_questions("Do you feel chills in the body??"))
   
def diagnose_cold()->bool:
    return (ask_questions("Does you sneeze frequently??")
    or ask_questions("Does your throat pain while sneezing??")
    or ask_questions("Do you have a runny nose"))

def diagnose_uti()->bool:
    return (ask_questions("Does you feel to urinate frequently??")
    and ask_questions("Do you get a burning sensation while urinating??")
    and ask_questions("Does your urine have foul smell??"))

def diagnose_appendicitis()->bool:
    return (ask_questions("Does you have intense abdominal pain??")
    and ask_questions("Have you lost your apetite??")
    and ask_questions("Do you frequently vomit??"))

def diagnose_flu()->bool:
    return (ask_questions("Does you feel tired??")
    and ask_questions("Does your body ache??")
    and ask_questions("Do you have fever??"))

def diagnose_constipation()->bool:
    return (ask_questions("Do you feel pain while passing stools??")
    or ask_questions("Do you pass blood while passing stools??"))

def diagnose_conjuctivitis()->bool:
    return (ask_questions("Do you have eye pain??")
    or ask_questions("Do you have redness of eyes??")
    or ask_questions("Does your eye water a lot??"))

def diagnose_allergies()->bool:
    return (ask_questions("Do you have itching all over body??")
    or ask_questions("Do you have redness of skin??")
    or ask_questions("Do you have swelling in any part of body??"))

def diagnose_sorethroat()->bool:
    return (ask_questions("Do you have pain in throat??")
    and ask_questions("Are your tonsills swollen and are hurting??"))

def diagnose_foodpoising()->bool:
    return (ask_questions("Do you have abdominal pain??")
    or ask_questions("Do you have loose motions??")
    or ask_questions("Do you frequnetly vomit??"))

print("Welcome to Expert System for diagnosing of ailments !!")

if diagnose_pneumonia():
    print("You have Pneunomia")

if diagnose_migrane():
    print("You have Migrane")

if diagnose_fever():
    print("You have Fever")

if diagnose_cold():
    print("You have Cold")

if diagnose_appendicitis():
    print("You have Appendicitis")

if diagnose_uti():
    print("You have Urinary Track Infection")

if diagnose_flu():
    print("You have Flu")

if diagnose_constipation():
    print("You have Constipation")

if diagnose_conjuctivitis():
    print("You have Conjuctivitis")

if diagnose_allergies():
    print("You have Skin Allergy")

if diagnose_sorethroat():
    print("You have Sore Throat")

if diagnose_foodpoising():
    print("You have Food Poisoning")

# Welcome to Expert System for diagnosing of ailments !!
# Does you cough frequently?? :y
# Does your throat and chest pain a lot while coughing?? :y
# Do you have shortness of breath?? :n
# Do you have a headache in one side of head?? :y
# You have Migrane
# Does you body temperature go above 38 Degree Celcius?? :y
# You have Fever
# Does you sneeze frequently?? :n
# Does your throat pain while sneezing?? :n
# Do you have a runny nose :y
# You have Cold
# Does you have intense abdominal pain?? :n
# Does you feel to urinate frequently?? :y
# Do you get a burning sensation while urinating?? :y
# Does your urine have foul smell?? :y
# You have Urinary Track Infection
# Does you feel tired?? :n
# Do you feel pain while passing stools?? :n
# Do you pass blood while passing stools?? :y
# You have Constipation
# Do you have eye pain?? :n
# Do you have redness of eyes?? :y
# You have Conjuctivitis
# Do you have itching all over body?? :n
# Do you have redness of skin?? :y
# You have Skin Allergy
# Do you have pain in throat?? :n
# Do you have abdominal pain?? :y
# You have Food Poisoning

'''
Time Complexity :- O(1)
''' 




