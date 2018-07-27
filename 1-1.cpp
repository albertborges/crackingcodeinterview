bool isUnique1( string str )
{
	unordered_set<char> characters;
	for(int i=0; i<str.length(); i++)
	{
		if(characters.find(str[i]) == characters.end())
		characters.insert(str[i]);
		else
		return false;
	}
	return true;
}

bool isUnique2( string str )
{
	int asciitable[256] = {0};

	for(int i=0; i<str.length(); i++)
	{
		if(asciitable[(int)str[i]] != 0) {
			return false;
		}
		else {
			asciitable[(int)str[i]]++;
		}
	}
	return true;
}

int main(int argc, const char * argv[]) {
	string str( "Heowrd" );
	printf("%d\n", isUnique2(str));
	return 0;
}
