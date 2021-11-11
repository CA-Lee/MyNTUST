#include <stdio.h>

int DEBUG = 0;

double validate(int raw[], int len)
{
    int min = raw[0], max = raw[0];
    for (int i = 1; i < len; i++)
    {
        if (raw[i] < min)
            min = raw[i];
        else if (raw[i] > max)
            max = raw[i];
    }
    if (DEBUG)
        printf("min: %d, max: %d, ", min, max);
    if (min == max)
        return 0;

    // showtime!
    // double target = x
    // raw[i] ((>= x*0.95 && <=x*1.05)||(>=x*1.9 && <=x*2.1 ))
    double high = (max + min) / 2.0, low = min;
    double mid;
    while (1)
    {
        mid = (high + low) / 2.0;
        if (DEBUG)
            printf("low: %lf, high: %lf, mid: %lf, ", low, high, mid);

        int match_flag = 1;
        int lower_flag = 1;
        int higher_flag = 1;
        for (int i = 0; i < len; i++)
        {
            if (!(((double)raw[i] >= (0.95 * mid) && (double)raw[i] <= (1.05 * mid)) || ((double)raw[i] >= (1.9 * mid) && (double)raw[i] <= (2.1 * mid))))
            {
                match_flag = 0;
                // mid > x => some will lower than lower threshold,
                // none will more than high threshold.
                if (!((double)raw[i] <= (2.1 * mid)))
                    higher_flag = 0;
                if (((double)raw[i] > (1.05 * mid)) &&
                    ((double)raw[i] < ((max + min) / 2.0)))
                    higher_flag = 0;

                // mid < x => none will lower than lower threshold,
                // some will more than high threshold.
                if (!((double)raw[i] >= (0.95 * mid)))
                    lower_flag = 0;
                if (((double)raw[i] < (1.9 * mid)) &&
                    ((double)raw[i] > ((max + min) / 2.0)))
                    lower_flag = 0;
            }
        }
        if (DEBUG)
            printf("\nlower_flag: %d, higher_flag: %d, match_flag: %d, ", lower_flag, higher_flag, match_flag);
        if (match_flag)
            return mid;
        if (high == low)
            return 0;
        if ((!lower_flag) && (!higher_flag))
            return 0;
        else if (higher_flag && !lower_flag)
            high = mid;
        else if (!higher_flag && lower_flag)
            low = mid;
        else if (higher_flag && lower_flag)
            return 0;
    }
}

void decode(int raw[], int len, double x)
{
    // transform into bit array
    for (int i = 0; i < len; i++)
    {
        if ((double)raw[i] > (1.5 * x))
            raw[i] = 1;
        else
            raw[i] = 0;
    }

    // decode
    char map[2][2][2][2][2] =
        {{{{{//0000
             '?', '7'},
            {//0001
             '?', '0'}},
           {{//0010
             '-', '5'},
            {//0011
             '*', '0'}}},
          {{{//0100
             '?', '1'},
            {//0101
             '?', '?'}},
           {{//0110
             '6', '?'},
            {//0111
             '?', '?'}}}},
         {{{{//1000
             '2', '9'},
            {//1001
             '8', '?'}},
           {{//1010
             '3', '?'},
            {//1011
             '?', '?'}}},
          {{{//1100
             '4', '?'},
            {//1101
             '?', '?'}},
           {{//1110
             '?', '?'},
            {//1111
             '?', '?'}}}}};
    if (DEBUG)
    {
        char *nums[] = {
            "00011",
            "01001",
            "10000",
            "10100",
            "11000",
            "00101",
            "01100",
            "00001",
            "10010",
            "10001",
            "00100",
            "00110"};
        for (int i = 0; i < 12; i++)
            printf("%c\n", map[nums[i][0] - '0'][nums[i][1] - '0'][nums[i][2] - '0'][nums[i][3] - '0'][nums[i][4] - '0']);
    }
    if (
        raw[0] == 0 &&
        raw[1] == 1 &&
        raw[2] == 1 &&
        raw[3] == 0 &&
        raw[4] == 0)
    {
        //reverse array
        int temp[len];
        for (int i = 0; i < len; i++)
            temp[i] = raw[i];
        for (int i = 0, j = len - 1; i < len; i++, j--)
            raw[i] = temp[j];
    }

    if (!(
            raw[0] == 0 &&
            raw[1] == 0 &&
            raw[2] == 1 &&
            raw[3] == 1 &&
            raw[4] == 0 &&
            raw[len - 5] == 0 &&
            raw[len - 4] == 0 &&
            raw[len - 3] == 1 &&
            raw[len - 2] == 1 &&
            raw[len - 1] == 0))
    {
        puts("bad code");
        if (DEBUG)
            puts("bad start/stop");
        return;
    }

    char result[50];
    int c = 0;
    for (int i = 0; i < len - 5; i += 6)
    {
        result[c] = map[raw[i + 0]][raw[i + 1]][raw[i + 2]][raw[i + 3]][raw[i + 4]];
        if ((raw[i + 5]) || (result[c] == '?'))
        {
            puts("bad code");
            if (DEBUG)
                printf("%c\n", result[c]);
            return;
        }
        if (result[c] == '*')
            continue;
        if (DEBUG)
            printf("%c ", result[c]);
        c++;
    }
    result[c] = '\0';
    if (DEBUG)
        printf("c: %d\n", c);

    // check checksum
    int weight[128];
    weight['0'] = 0;
    weight['1'] = 1;
    weight['2'] = 2;
    weight['3'] = 3;
    weight['4'] = 4;
    weight['5'] = 5;
    weight['6'] = 6;
    weight['7'] = 7;
    weight['8'] = 8;
    weight['9'] = 9;
    weight['-'] = 10;

    // C check
    int c_check = 0;
    for (int i = 0; i < (c - 2); i++)
    {
        c_check += (((c - 2) - (i + 1)) % 10 + 1) * weight[result[i]];
        if (DEBUG)
            printf("%d ", c_check);
    }
    c_check %= 11;
    if (c_check != result[c - 2] - '0')
    {
        puts("bad C");
        if (DEBUG)
            printf("cal-C: %d, given-C: %d, ", c_check, result[c - 2] - '0');
        return;
    }

    //K check
    int k_check = 0;
    for (int i = 0; i < (c - 1); i++)
    {
        k_check += (((c - 1) - (i + 1)) % 9 + 1) * weight[result[i]];
    }
    k_check %= 11;
    if (k_check != result[c - 1] - '0')
    {
        puts("bad K");
        if (DEBUG)
            printf("cal-K: %d, given-K: %d\n", k_check, result[c - 1] - '0');
        return;
    }

    // show result
    result[c - 2] = '\0';
    printf("%s\n", result);
}

int main()
{
    // get test case from file
    char filename_str[256];
    printf("Enter filename: ");
    scanf("%255s", (char *)filename_str);

    FILE *file = fopen(filename_str, "r");
    int n;
    int case_count = 1;

    while (fscanf(file, "%d", &n) != EOF)
    {
        int len = n;
        if (!len)
            break;
        printf("Case %d: ", case_count);
        // transform into array type
        int raw[len];
        for (int i = 0; i < len; i++)
        {
            fscanf(file, "%d", &(raw[i]));
        }

        // validation
        if ((len - 11) / 6.0 == (len - 11) / 6)
        {
            double x = validate(raw, len);
            if (x != 0)
            {
                // decode
                decode(raw, len, x);
            }
            else
                puts("bad code");
        }
        else
            puts("bad code");
        case_count++;
    }
}