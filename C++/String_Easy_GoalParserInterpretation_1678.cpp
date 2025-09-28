class Solution {
public:
    void findAndReplace(string& sourceString, string targetString, string replacementString)
    {
        int pos = 0;
        while ((pos = sourceString.find(targetString, pos)) != string::npos)
        {
            sourceString.replace(pos, targetString.length(), replacementString);
            pos += replacementString.length();
        }
    }

    string interpret(string command)
    {
        findAndReplace(command, "()", "o");
        findAndReplace(command, "(al)", "al");

        return command;
    }
};