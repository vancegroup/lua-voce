require("luavoce")

for name, value in pairs(voce) do
	print(name, "\t\t", value)
end


print("Initializing luavoce...")
voce.init([[C:\Users\carlsonp\Desktop\src\lua-voce\submodules\voce\lib]], true, true, [[C:\Users\carlsonp\Desktop\src\lua-voce\submodules\voce\lib\gram]], "digits.gram")


voce.init("C:\Users\carlsonp\Desktop\src\lua-voce\submodules\voce\lib", true, false, "", "")
	

while (voce.getRecognizerQueueSize() > 0) do
	local you_said = voce.popRecognizedString()
	print("You said: " .. you_said)
end