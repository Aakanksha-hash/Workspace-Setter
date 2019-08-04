# Workspace Setter

### A tool to quickly set up your workspace for competitive programming.

### Note: Make sure you have the template file names "cp" inside home/Templates/ folder.

Sample template :
```
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		
	}
}
```

# Usage :

## __setws -h__
Help section.

## __setws__
Calls the default values. Folder name - "Contest" and count = 1.

## __setws -n name_of_folder__
Creates the folder from where the program is called named name_of_folder.

## __setws -c count_of_subfolders__
Creates that many folders, named from 1-count_of_subfolders.
This will have a empty in file and a Main.cpp file with skeleton text.

# Currently in development. Lots of improvements needed.