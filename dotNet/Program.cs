using System.IO.Ports;

if (args.Length == 0)
    return;

try
{
    using var port = new SerialPort(args[0], 115200)
    {
        DtrEnable = false,
        RtsEnable = false,
        WriteTimeout = 1000
    };

    port.Open();
    port.Write("TOGGLE\n");
}
catch (Exception ex)
{
    Console.Error.WriteLine(ex);
    // Not so silently exit.
}
