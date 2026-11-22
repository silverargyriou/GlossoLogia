---@param fileName string
local function compile(fileName)
   local file, err = io.open(fileName, "r")
   if file == nil then
      print(err)
      return
   end

   local context = file:read("a")
   
   local lines = 0
   local left, middle, right = string.match(context, "([%w_]+)%s*([%+%-%*/])%s*([%w_]+)")
   print(left)
   print(middle)
   print(right)
end

compile("test.eh")