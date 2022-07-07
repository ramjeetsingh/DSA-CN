class complexNum {
    private:

        int realPart;
        int imaginaryPart;

    public:
        complexNum(int real, int imag) {
            this -> realPart = real;
            this -> imaginaryPart = imag;
        }

        void print() {
            if (imaginaryPart < 0) {
                cout << realPart << " " << imaginaryPart << "i" << endl;
            } else {
                cout << realPart << " + " << imaginaryPart << 'i' << endl;
            }
        }


        void plus (complexNum c2) {
            realPart += c2.realPart;
            imaginaryPart += c2.imaginaryPart;
        }

        void multiply (complexNum c2) {
            int nowrealPart = realPart*c2.realPart - (imaginaryPart*c2.imaginaryPart);
            int nowimaginaryPart = ((realPart*c2.imaginaryPart) + (imaginaryPart*c2.realPart));
            realPart = nowrealPart;
            imaginaryPart = nowimaginaryPart;
        }
};