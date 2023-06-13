#include <iostream>
using namespace std;
class BrowserHistory {
private:
    string historyArr[9000];                  //maximum number of tabs in google chrome
    int ptr, top;
public:

    BrowserHistory(string homepage) {
        historyArr[ptr = top = 0] = homepage;  //initialize arr[0] to homepage
    }

    void visit(string url) {
        historyArr[top = ++ptr] = url;       //adding new visited tabs to the next place in array, current tab is top
    }

    string backk(int steps) {
        return historyArr[ptr = max(0, ptr-steps)];       //returning the pointer to the required tab, maximum backs is homepage
    }

    string forwardd(int steps) {
        return historyArr[ptr = min(top, ptr+steps)];      //moving the pointer forward in array, minimum move is the top of array
    }
};
int main()
{
    BrowserHistory bh("abc.com");
    bh.visit("xyz.com");
    bh.visit("def.com");
    bh.visit("ijk.com");
    cout << bh.backk(1) << endl;
    cout << bh.backk(1) << endl;
    cout << bh.forwardd(1) << endl;
    bh.visit("mno.com");
    cout << bh.forwardd(2) << endl;
    cout << bh.backk(2) << endl;
    cout << bh.backk(7) << endl;

    return 0;

}
