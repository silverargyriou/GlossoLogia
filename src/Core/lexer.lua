local lexer = {}

lexer.DEBUG = false
lexer.Tokens = {}

local keywords = {
    use    = "USE",
    fn     = "FN",
    if_    = "IF",
    ["if"] = "IF",
    ["else"] = "ELSE",
    ["return"] = "RETURN",
    free   = "FREE",
}

---@param source string
---@return string
local function removeComments(source)
    source = string.gsub(source, "%-%-[^\n\r]*", ""):gsub("//.-//%s*", "")
    return source
end

---@param source string
---@return string
local function removeEmptyLines(source)
    source = source:gsub("\r?\n%s*\r?\n", "\n"):gsub("^%s*\r?\n", ""):gsub("\r?\n%s*$", "")
    return source
end

local function addToken(tokenType, value, line)
    lexer.Tokens[#lexer.Tokens + 1] = {
        type = tokenType,
        value = value,
        line = line
    }
end

---@param source string
---@return string
local function line_split(source)
    if not string.match(source, "\n$") then
        source = source .. '\n'
        print([[[DEBUG]: Added \n in source."]])
    end
end

---@param source string
function lexer.tokenize(source)
    local text = removeComments(source)
    if lexer.DEBUG then
        print(string.format("[LEXER] Removed Comments."))
    end

    text = removeEmptyLines(text)
    if lexer.DEBUG then
        print(string.format("[LEXER]: Removed Empty Lines successfully.\n\nCurrent Text:\n%s", text))
    end

    line_split(text)

    return text
end

return lexer