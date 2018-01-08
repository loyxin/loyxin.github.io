# socket
### get ip
```java
import java.net.InetAddress;
import java.net.UnknownHostException;

public class GetIP {
    public static void main(String[] args) {
        InetAddress address = null;
        try {
            address = InetAddress.getByName
                    ("rafrozen.cn");
        }
        catch (UnknownHostException e) {
            System.exit(2);
        }
        System.out.println(address.getHostName() + "="
                + address.getHostAddress());
        System.exit(0);
    }
}
```
socket
```java
InetAddress addr;
Socket sock = new Socket("rafrozen.cn", 80);
addr = sock.getInetAddress();
System.out.println("Connected to " + addr);
sock.close();
			
InetAddress addr=InetAddress.getByName("rafrozen.cn");
Socket socket = new Socket(addr,80);
System.out.println("connected to "+ socket.getInetAddress()+ "on port" +
                    ":" + socket.getPort()+ " of "+ socket.getLocalPort() + " of " +
socket.getLocalAddress());
```