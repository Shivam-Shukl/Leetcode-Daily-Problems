class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int thousand = 0, fiveHund = 0, hund = 0, fifty = 0, ten = 0, five = 0, one = 0;
        int nineHund = 0, fourHund = 0, ninety = 0, fourty = 0, nine = 0, four = 0;
        
        while (num) {
            thousand = num / 1000;
            num = num % 1000;

            nineHund = num / 900;
            num = num % 900;

            fiveHund = num / 500;
            num = num % 500;

            fourHund = num / 400;
            num = num % 400;

            hund = num / 100;
            num = num % 100;

            ninety = num / 90;
            num = num % 90;

            fifty = num / 50;
            num = num % 50;

            fourty = num / 40;
            num = num % 40;

            ten = num / 10;
            num = num % 10;

            nine = num / 9;
            num = num % 9;

            five = num / 5;
            num = num % 5;

            four = num / 4;
            num = num % 4;

            one = num / 1;
            num = num % 1;
        }

        if (thousand != 0) {
            while (thousand) {
                ans += 'M';
                thousand--;
            }
        }
        if (nineHund != 0) {
            while (nineHund) {
                ans += "CM";
                nineHund--;
            }
        }
        if (fiveHund != 0) {
            while (fiveHund) {
                ans += 'D';
                fiveHund--;
            }
        }
        if (fourHund != 0) {
            while (fourHund) {
                ans += "CD";
                fourHund--;
            }
        }
        if (hund != 0) {
            while (hund) {
                ans += 'C';
                hund--;
            }
        }
        if (ninety != 0) {
            while (ninety) {
                ans += "XC";
                ninety--;
            }
        }
        if (fifty != 0) {
            while (fifty) {
                ans += 'L';
                fifty--;
            }
        }
        if (fourty != 0) {
            while (fourty) {
                ans += "XL";
                fourty--;
            }
        }
        if (ten != 0) {
            while (ten) {
                ans += 'X';
                ten--;
            }
        }
        if (nine != 0) {
            while (nine) {
                ans += "IX";
                nine--;
            }
        }
        if (five != 0) {
            while (five) {
                ans += 'V';
                five--;
            }
        }
        if (four != 0) {
            while (four) {
                ans += "IV";
                four--;
            }
        }
        if (one != 0) {
            while (one) {
                ans += 'I';
                one--;
            }
        }

        return ans;
    }
};
