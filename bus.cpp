#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Trim leading/trailing spaces
string trim(string s) {
    s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
    s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);
    return s;
}

// Convert string to lowercase
string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c){ return tolower(c); });
    return s;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "<p style='color:red;'>Error: Please provide start and destination as arguments.</p>";
        return 1;
    }

    // Read inputs, trim spaces, convert to lowercase
    string start = toLower(trim(argv[1]));
    string destination = toLower(trim(argv[2]));

    cout << "<div class='result-data'>";

    // Najafgarh → Gurgaon
    if ((start == "najafgarh") && (destination == "gurgaon")) {

        cout << "<h3>Najafgarh &rarr; Gurgaon</h3>";

        for (int i = 1; i <= 4; i++) {
            if (i == 1) cout << "<p>Nangli Stand &mdash; Bus 825 &mdash; &#8377;20</p>";
            if (i == 2) cout << "<p>Kapashera Border &mdash; Bus 844 &mdash; &#8377;25</p>";
            if (i == 3) cout << "<p>Huda City Centre &mdash; Bus 218 &mdash; &#8377;30</p>";
            if (i == 4) cout << "<p>Gurgaon Bus Stand &mdash; Bus 218 &mdash; &#8377;35</p>";
        }
    }

    // Najafgarh → KRMU
    else if ((start == "najafgarh") && (destination == "krmu")) {

        cout << "<h3>Najafgarh &rarr; KRMU</h3>";

        for (int i = 1; i <= 3; i++) {
            if (i == 1) cout << "<p>Bus 733 &mdash; 18 minutes &mdash; &#8377;15</p>";
            if (i == 2) cout << "<p>Bus 742 &mdash; 27 minutes &mdash; &#8377;20</p>";
            if (i == 3) cout << "<p>Bus 760 &mdash; 33 minutes &mdash; &#8377;25</p>";
        }
    }

    // Bahadurgarh → KRMU
    else if ((start == "bahadurgarh") && (destination == "krmu")) {

        cout << "<h3>Bahadurgarh &rarr; KRMU</h3>";

        for (int i = 1; i <= 3; i++) {
            if (i == 1) cout << "<p>Bus 921 &mdash; 20 minutes &mdash; &#8377;18</p>";
            if (i == 2) cout << "<p>Bus 950 &mdash; 29 minutes &mdash; &#8377;22</p>";
            if (i == 3) cout << "<p>Bus 966 &mdash; 38 minutes &mdash; &#8377;30</p>";
        }
    }

    // Bahadurgarh → Gurgaon
    else if ((start == "bahadurgarh") && (destination == "gurgaon")) {

        cout << "<h3>Bahadurgarh &rarr; Gurgaon</h3>";

        for (int i = 1; i <= 3; i++) {
            if (i == 1) cout << "<p>Bus 871 &mdash; 26 minutes &mdash; &#8377;28</p>";
            if (i == 2) cout << "<p>Bus 884 &mdash; 34 minutes &mdash; &#8377;32</p>";
            if (i == 3) cout << "<p>Bus 905 &mdash; 42 minutes &mdash; &#8377;40</p>";
        }
    }

    else {
        cout << "<p>No route found. Try different locations.</p>";
    }

    cout << "</div>";
    return 0;
}
