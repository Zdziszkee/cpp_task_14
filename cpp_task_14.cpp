#include <iostream>

//Stein’s Algorithm for finding GCD
int gcd(int a, int b)
{
    /* GCD(0, b) == b; GCD(a, 0) == a,
       GCD(0, 0) == 0 */
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    /*Finding K, where K is the
      greatest power of 2
      that divides both a and b. */
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k)
    {
        a >>= 1;
        b >>= 1;
    }
    /* Dividing a by 2 until a becomes odd */
    while ((a & 1) == 0)
        a >>= 1;
    /* From here on, 'a' is always odd. */
    do
    {
        /* If b is even, remove all factor of 2 in b */
        while ((b & 1) == 0)
            b >>= 1;

        /* Now a and b are both odd.
           Swap if necessary so a <= b,
           then set b = b - a (which is even).*/
        if (a > b)
            std::swap(a, b); // Swap u and v.
        b = (b - a);
    }while (b != 0);
    /* restore common factors of 2 */
    return a << k;
}

int encrypt(int x,int publicKey){

}

int decrypt(int x, int publicKey){

}

int main() {
    // Two (large) random prime numbers
    double p = 3;
    double q = 7;

    // First part of public key:
    double n = p * q;

    // Finding other part of public key.
    // e stands for encrypt
    double e = 2;
    double phi = (p - 1) * (q - 1);
    while (e < phi) {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    // Private key (d stands for decrypt)
    // choosing d such that it satisfies
    // d*e = 1 + k * totient
    int k = 2; // A constant value
    double d = (1 + (k * phi)) / e;

    // Message to be encrypted
    double msg = 12;

    printf("Message data = %lf", msg);

    // Encryption c = (msg ^ e) % n
    double c = pow(msg, e);
    c = fmod(c, n);
    printf("\nEncrypted data = %lf", c);

    // Decryption m = (c ^ d) % n
    double m = pow(c, d);
    m = fmod(m, n);
    printf("\nOriginal Message Sent = %lf", m);
}
