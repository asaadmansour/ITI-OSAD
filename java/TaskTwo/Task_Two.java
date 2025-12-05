import java.util.Random;
class Task_Two {
	public static void main(String[] args) {
		int arr[] = new int[1000];
		Random rand = new Random();
		for(int i=0;i<arr.length;i++) {
			arr[i] = rand.nextInt(1000);
		}
		long startTime = System.nanoTime();
		int min=arr[0],max=arr[0];
		for(int i=1;i<arr.length;i++){
			if(arr[i] < min) 
				min = arr[i];
			if(arr[i]> max) 
				max = arr[i];
		}
		long endTime = System.nanoTime();
		long Timetaken = endTime - startTime;
		System.out.println("startTime: " + startTime);
		System.out.println("startTime: " + startTime);
		System.out.println("TimeTaken: " + Timetaken);
		System.out.println("Min: " + min);
		System.out.println("Max: " + max); 
	}
}


