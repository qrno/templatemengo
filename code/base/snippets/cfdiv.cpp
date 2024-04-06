int cdiv(int a, int b) { return a/b+((a^b)>0&&a%b); }
int fdiv(int a, int b) { return a/b-((a^b)<0&&a%b); }
