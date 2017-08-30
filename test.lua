local M = {}

local c_add = require("c_test")

function M.add(a, b)
	return a + b
end

function M.add_times(a, b, times)
	for i = 1, times do
		M.add(a, b)
	end
end

function M.test_c_add(a, b, times)
	for i = 1, times do
		c_add.add(a, b)
	end
end

function M.test_c_add_times(a, b, times)
	c_add.add_times(a, b, times)
end

return M
