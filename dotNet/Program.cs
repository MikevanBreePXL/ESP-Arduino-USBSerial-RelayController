using System.IO.Ports;

if (args.Length == 0)
    // Silently exit when no port is specified in starting the executable.
    return;

try
{
    using var port = new SerialPort(args[0], 115200)
    {
        DtrEnable = false,
        RtsEnable = false,
        WriteTimeout = 1000
    };
    port.Open(); // Connect to the relay control board.
    port.Write("TOGGLE\n"); // Toggle the relay. (command is case insensitive)
}
catch (Exception ex)
{
    Console.Error.WriteLine(ex);
    // In case of an error, print the error message to the console before exiting.
    // Run the executable from a command prompt to see the error message.
}
