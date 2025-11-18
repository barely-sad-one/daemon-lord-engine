local dap = require("dap")

dap.configurations.cpp = {
  {
    name = "DaemonLord Engine",
    type = "gdb",
    request = "launch",
    program = vim.fn.getcwd() .. "/testbed/build/Debug/testbed",
    cwd = "${workspaceFolder}",
    args = {},
    stopAtBeginningOfMainSubprogram = false,
  },
}

dap.configurations.c = dap.configurations.cpp
dap.configurations.rust = dap.configurations.cpp

