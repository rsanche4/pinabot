# Sends message to ALIZA. No Gui.
# Author: Rafael Sanchez

import brain
print("")
print("")
print("*************************** ALIZA CHATBOT ***************************")
print("*********************** By Rafael Sanchez ***************************")
print("***************** To stop Aliza, type Bye ***************************")
print("")
print("-------------------- Conversation Started ---------------------------")
print("")
brain.start()
while True:
    m = input("User: ")
    print("Aliza: "+brain.aliza_says(m))
    if m.lower() == 'bye':
        break
print("")
print("-------------------- Conversation Ended -----------------------------")