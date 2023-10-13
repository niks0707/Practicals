struct strings {
    string str1<100>;
    string str2<100>;
};

program ADD_PROG {
    version ADD_VERS {
        bool add(strings) = 1;
        int count(strings) = 2;
    } = 1;
} = 0x23451111;
