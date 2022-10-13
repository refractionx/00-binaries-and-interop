using System.Runtime.InteropServices;

[DllImport("greetings-bg")]
static extern IntPtr getGreetingMessage();

try {
    Console.WriteLine(Marshal.PtrToStringAuto(getGreetingMessage()));
} catch (Exception ex) {
    Console.WriteLine(ex);
}
