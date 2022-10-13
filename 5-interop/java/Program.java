public class Program {

    private native String getGreetingMessageNative();

    public static void main(String[] args) {
        System.out.println(new Program().getGreetingMessageNative());
    }

    static {
        System.loadLibrary("greetings-jni");
    }
}