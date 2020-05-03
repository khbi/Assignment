package procject4;

import java.util.Scanner;

public class RockPaperScissors {
	private String userSelect = null;
	private String comSelect;
	
	public RockPaperScissors() {
		this.userSelect = null;
		this.comSelect = null;
	}
	
	public String getuserSelect() { //get userSelect
		return userSelect;
	}
	
	public void setuserSelect(String userSelect) { //set userSelect
		this.userSelect = userSelect;
	}
	
	public String getcomSelect() { //get comSelect
		return comSelect;
	}
	
	public void setcomSelect(String comSelect) { //set comSelect
		this.comSelect = comSelect;
	}
	
	public void startInfo(Scanner input) { //show start Information 
		System.out.println("Play rock-paper-scissors with the computer");
		System.out.println("(Please enter a \"stop\" if you want to close.)");
		System.out.print("Enter one of the rock-paper-scissors>>");
	}
	
	public void userInput(Scanner input) { //get user Input
		userSelect = input.nextLine();
		setuserSelect(userSelect);
		System.out.println("User = "+userSelect);
	}
	
	public void comInput() { //get com Select
		String com[] = {"scissors", "rock", "paper"};
		int select =(int)(Math.random()*3);
		comSelect = com[select];
		setcomSelect(comSelect);
		System.out.println("Computer =  "+comSelect);
	}
	
	
	static void checkInput(String userSelect, String comSelect) { //check Input
		if(userSelect.equals("paper")||userSelect.equals("scissors")||userSelect.equals("rock")) {
			win(userSelect, comSelect);
			}
		else if(userSelect.equals("stop")) {
			System.out.println("\n Exit Rock-paper-scissors \n Thank you for using! ");
			System.exit(0);
		}
			else {
				System.out.println("\n\nInvalid input. Enter one of the rock-paper-scissors!");
				System.out.println("Exit Rock-paper-scissors.");
				System.exit(0);
			}
	}
	
	static void win(String userSelect, String comSelect) { //Select Winner
		if(userSelect.equals("scissors")) {
       	 if(comSelect.equals("scissors")) {
       		 System.out.println("It's a tie.\n");
       	 }
       	 else if(comSelect.equals("rock")) {
       		 System.out.println("User has lost..\n");
       	 }
       	 else if(comSelect.equals("paper")) {
       		 System.out.println("User won!\n");
       	 }
        }
        
        else if(userSelect.equals("rock")) {
       	 if(comSelect.contentEquals("scissors")) {
       		 System.out.println("User won!\n");
       	 }
       	 else if(comSelect.equals("rock")) {
       		 System.out.println("It's a tie.\n");
       	 }
       	 else if(comSelect.equals("paper")) {
       		 System.out.println("User has lost..\n");
       	 }
        }
        
        else if(userSelect.equals("paper")) {
       	 if(comSelect.contentEquals("scissors")) {
       		 System.out.println("User has lost..\n");
       	 }
       	 else if(comSelect.equals("rock")) {
       		 System.out.println("User won!\n");
       	 }
       	 else if(comSelect.equals("paper")) {
       		 System.out.println("It's a tie.\n");
       	 }
       
        }
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		RockPaperScissors rps = new RockPaperScissors();
		
		while(true) {
			rps.startInfo(input);
			rps.userInput(input);
			rps.comInput();
			rps.checkInput(rps.userSelect, rps.comSelect);
		}	   
	}

}
