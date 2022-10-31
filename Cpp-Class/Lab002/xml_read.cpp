

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string find_first_element(const string &xml, string tag_name);
vector<string> find_all_elements(const string &xml, string tag_name);


int main() {
	string page, line, location, temperature, tag, result;
	vector<string> results;
	ifstream inputFile("day-ahead-prices.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}
	// Now page is a string that contains the whole xml page
	
	// Here you need to write a loop that asks user to enter tag name
	// and if tag name is "stop" the program stops
	// otherwise program calls function of 2A or 2B with the tag name
	// and prints the result

	while (true)
	{
		std::cout << "Give tag: " << std::endl;
		std::cin >> tag;

		if(tag == "stop"){
			break;
		} else{
			//case 1
			/* std::cout << tag << ":" << find_first_element(page, tag) << std::endl; */
			//case 2
			results = find_all_elements(page,tag);
			std::cout << tag << ": "; 
			for (int i = 0; i < results.size(); i++)
			{
				std::cout << results[i] <<","; 
			}
			std::cout << std::endl;
			
		}
	}
	

	return 0;
}

// Exercise 2A
string find_first_element(const string &xml, string tag_name)
{
	string start, end, result;
	int startPos = 0, endPos = 0;
	start = "<" + tag_name + ">";
	end = "</" + tag_name + ">";
	// construct start and end tags from from the tag name 
	// add angle brackets to both tags and also slash to end tag
	// then search for tags 
	// if both are found then return the substring between the tags
	startPos = xml.find(start);
	endPos = xml.find(end);
	if (startPos > 0 && endPos > 0){
		for(int i = startPos + start.size(); i<endPos; i++){
			result += xml[i];
		}
		return result;
	} else{
		return "not found"; // return this if tag is not found
	}
	
}

// Exercise 2B
vector<string> find_all_elements(const string &xml, string tag_name)
{
	string start, end, line;
	vector<string> result;
	start = "<" + tag_name + ">";
	end = "</" + tag_name + ">";
	int startPos = 0, endPos = 0;
	startPos = xml.find(start);
	endPos = xml.find(end);
	if (startPos > 0 && endPos > 0){
		while(true){
			for(int i = startPos + start.size(); i<endPos; i++){
				line += xml[i];
			}
			result.push_back(line);
			line = "";
			if(xml.find(end, endPos+1) == -1){
				break;
			} else{
				startPos = xml.find(start, endPos);
				endPos = xml.find(end, endPos+1);
			}
		}
		return result;
	} else{
		return result; // return this if tag is not found
	}
}