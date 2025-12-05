class IpAddress {

    public boolean isValid(String ip) {
        if (ip == null || ip.isEmpty()) {
            return false;
        }
        String IPv4_REGEX =
            "^((25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)\\.){3}"
          + "(25[0-5]|2[0-4]\\d|1\\d\\d|[1-9]?\\d)$";

        return ip.matches(IPv4_REGEX);
    }

    public static void main(String[] args) {
        IpAddress checker = new IpAddress(); 

        String ip = "192.168.1.0"; 

        if (checker.isValid(ip)) {
            String[] parts = ip.split("\\.");
            for (String part : parts) {
                System.out.println(part);
            }
        } else {
            System.out.println("Not a valid IP address!");
        }
    }
}
