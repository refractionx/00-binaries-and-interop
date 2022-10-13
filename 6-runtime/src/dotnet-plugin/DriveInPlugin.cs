using System;
using System.Runtime.InteropServices;

namespace DriveInPlugin
{
    public static class DriveInPlugin
    {

        public static int Tick(IntPtr Data, int argLength)
        {
            string? message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
                ? Marshal.PtrToStringUni(Data)
                : Marshal.PtrToStringUTF8(Data);

            Console.Write($"C#: {message}");
            return 0;
        }
    }
}