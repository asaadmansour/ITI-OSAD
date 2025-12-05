class TaskThree {
	public int countWords(String word, String sentence) {
		if(word == null || sentence == null || word.isEmpty() || sentence.isEmpty()) {
			return 0;
		}
		int count =0,index =0;
		while((index = sentence.indexOf(word,index)) != -1) {
			count++;
			index += word.length();
		}
		return count;
	}
	public static void main(String[] args) {
    String text = "asabasabasa";
    String word = "asa";
    TaskThree task = new TaskThree(); 
    System.out.println(task.countWords(word, text));
	}
}