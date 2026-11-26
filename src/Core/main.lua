local interpreter = require("interpreter")
local parser = require("parser")
local lexer = require("lexer")

local DEBUG = false
io.write("Debug mode (y/n): ")
if io.read() == 'y' then
   DEBUG = true
end

---@param fileName string
local function compile(fileName)
   local file, err = io.open(fileName, "r")
   if file == nil then
      print(err)
      return
   end

   local context = file:read("a")
   lexer.DEBUG = DEBUG
   lexer.tokenize(context)
end

compile("test.eh")