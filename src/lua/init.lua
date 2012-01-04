require("luavoce")


function init(params)
	--e.g. voce.init(synthesis = true, recognition = true, grammar = "~/voce/grammer.gram")

	if params.synthesis == nil then
		params.synthesis = false
	end
	
	if params.recognition == nil then
		params.recognition = false
	end
	
	if params.grammar == nil then
		--no grammar specified
		print("No grammar specified, defaulting to no recognition!")
		params.recognition = false
	else
		--grammar was passed in
		--split up the path
		
	end
	
	--find JAR files
	
	
	--call bound init function
	

end
