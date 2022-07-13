local wrapper = require "lua_wrapper"

for i = 1, 5 do
    local o = wrapper.Object(tostring(i))
    o:say_hello();
end
