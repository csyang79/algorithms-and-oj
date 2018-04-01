class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        int num;
        string site;
        for (string & str : cpdomains)
        {
            istringstream is(str);
            is >> num;
            is >> site;
            int t;
            mp[site] += num;
            while (site.find_first_of(".") != string::npos)
            {
                site = site.substr(site.find_first_of('.') + 1, site.size());
                mp[site] += num;
            }
        }
        vector<string> res;
        for (auto it = mp.begin(); it != mp.end(); ++it)
            res.push_back(to_string(it->second) + " " + it->first);
        return res;
    }
};
