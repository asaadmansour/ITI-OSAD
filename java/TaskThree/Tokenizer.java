import java.util.StringTokenizer;

class Tokenizer {
    public static void main(String[] args) {
        String sent = "ITI develops people and ITI house of developers and ITI fo people";
        StringTokenizer st = new StringTokenizer(sent, "ITI"); 
        while (st.hasMoreTokens()) {
            System.out.println(st.nextToken());
        }
    }
}
