class TaskThreeTwo {
    public int countWords(String word, String sentence) {
        if (word == null || sentence == null || word.isEmpty() || sentence.isEmpty()) {
            return 0;
        }
        String[] parts = sentence.split(word);
        return parts.length - 1;
    }

    public static void main(String[] args) {
        String text = "asabasabasa";
        String word = "asa";
        TaskThreeTwo task = new TaskThreeTwo();
        System.out.println(task.countWords(word, text));
    }
}
