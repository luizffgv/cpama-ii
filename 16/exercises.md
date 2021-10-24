# Chapter 16 exercises

1. Yes. The `struct` names don't conflict with their members, and members of a
   `struct` don't conflict with members of another `struct`.

2. a)

   ```c
   struct {
       double real;
       double imaginary;
   } c1, c2, c3;
   ```

   b)

   ```c
   struct {
       double real;
       double imaginary;
   } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;
   ```

   c)

   ```c
   c1 = c2;
   // Yes, was done in only one statement.
   ```

   d)

   ```c
   c3.real = c1.real + c2.real;
   c3.imaginary = c1.imaginary + c2.imaginary;
   ```c

3. a)

   ```c
   struct complex {
       double real;
       double imaginary;
   };
   ```c

   b)

   ```c
   struct complex c1, c2, c3;
   ```

   c)

   ```c
   struct complex make_complex(double real, double imaginary)
   {
       return (struct complex) {real, imaginary};
   }
   ```

   d)

   ```c
   struct complex add_complex(struct complex a, struct complex b)
   {
       struct complex temp;

       temp.real = a.real + b.real;
       temp.double = a.double + b.double;

       return temp;
   }
   ```

4. a)

   ```c
   typedef struct {
       double real;
       double imaginary;
   } Complex;
   ```

   b)

   ```c
   Complex c1, c2, c3;
   ```

   c)

   ```c
   Complex make_complex(double real, double imaginary)
   {
       return (Complex) {real, imaginary};
   }
   ```

   d)

   ```c
   Complex add_complex(Complex a, Complex b)
   {
       Complex temp;

       temp.real = a.real + b.real;
       temp.double = a.double + b.double;

       return temp;
   }
   ```

5. a)

   ```c
   int day_of_year(struct date d)
   {
       int days_num = 0;

       short dpm[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
       if (!(d.year % 4) && ((d.year % 100) || !(d.year % 400)))
           dpm[1] = 29;

       for (int month_i = 0; month_i < d.month - 1; ++month_i)
       {
           days_num += dpm[month_i];
       }
       days_num += dpm[d.month - 1];

       return days_num;
   }
   ```

   b)

   ```c
   int compare_dates(struct date d1, struct date d2)
   {
       if (d1.year != d2.year)
           return d1.year < d2.year ? -1: 1;
       if (d1.month != d2.month)
           return d1.month < d2.month ? -1: 1;
       if (d1.day != d2.day)
           return d1.day < d2.day ? -1: 1;
       return 0;
   }
   ```

6. ```c
   struct time split_time(long total_seconds)
   {
       int hours, minutes, seconds;

       hours = total_seconds / 3600;
       minutes = total_seconds % 3600 / 60;
       seconds = total_seconds % 3600 % 60;

       return (struct time) {hours, minutes, seconds};
   }
   ```

7. a)

   ```c
   struct fraction fraction_reduce(struct fraction f)
   {
       int n1 = f.numerator;
       int n2 = f.denominator;
       int remainder = n2 % n1;

       while (remainder)
       {
           remainder = n2 % n1;
           n2 = n1;
       }

       f.numerator /= n2;
       f.denominator /= n2;

       return f;
   }
   ```

   b)

   ```c
   struct fraction fractions_add(struct fraction f1, struct fraction f2)
   {
       return fraction_reduce((struct fraction) {f1.numerator * f2.denominator +
           f2.numerator * f1.denominator, f1.denominator * f2.denominator});
   }
   ```

   c)

   ```c
   struct fraction fractions_sub(struct fraction f1, struct fraction f2)
   {
       return fraction_reduce((struct fraction) {f1.numerator * f2.denominator -
           f2.numerator * f1.denominator, f1.denominator * f2.denominator});
   }
   ```

   d)

   ```c
   struct fraction fractions_mult(struct fraction f1, struct fraction f2)
   {
       return fraction_reduce((struct fraction) {f1.numerator * f2.numerator,
           f1.denominator * f2.denominator});
   }
   ```

   e)

   ```c
   struct fraction fractions_divide(struct fraction f1, struct fraction f2)
   {
       return fraction_reduce((struct fraction) {f1.numerator * f2.denominator,
           f1.denominator * f2.numerator});
   }
   ```

8. a) `const struct color MAGENTA = {255, 0, 255};`

   b) `const struct color MAGENTA = {.red = 255, .blue = 255};`

9. a)

   ```c
   struct color make_color(int red, int green, int blue)
   {
       struct color temp;

       for (int *color_p = &temp.red; color_p < &temp.red + 3; ++color_p)
       {
           if (*color_p > 255)
               *color_p = 255;
           else if (*color_p < 0)
               *color_p = 0;
       }

       return temp;
   }
   ```

   b)

   ```c
   int getRed(struct color c)
   {
       return c.red;
   }
   ```

   c)

   ```c
   bool equal_color(struct color color1, struct color color2)
   {
       if (color1.red != color2.red)
           return false;
       if (color1.green != color2.green)
           return false;
       if (color1.blue != color2.blue)
           return false;
       return true;
   }
   ```

   d)

   ```c
   struct color brighter(struct color c)
   {
       if (!c.red && !c.green && !c.blue)
           return (struct color) {3, 3, 3};
       
       for (int *color_p = &c.red; color_p < &c.red + 3; ++color_p)
       {
           if (*color_p < 3)
               *color_p = 3;

           *color_p /= 0.7;

           if (*color_p > 255)
               *color_p = 255;
       }

       return c;
   }
   ```

   e)

   ```c
   struct color darker(struct color c)
   {
       for (int *color_p = &c.red; color_p < &c.red + 3; ++color_p)
       {
           *color_p *= 0.7;
       }

       return c;
   }
   ```

10. This one works for Y counting from bottom to top and top to bottom.

    a)

    ```c
    int rect_area(struct rectangle r)
    {
        int area;
        int height_signed, width_signed;

        width_signed = r.upper_left.x - r.lower_right.x;
        height_signed = r.upper_left.y - r.lower_right.y;
        return (area = height_signed * width_signed) >= 0 ? area : -area;
    }
    ```

    b)

    ```c
    struct point rect_center(struct rectangle r)
    {
        int x_center, y_center;

        x_center = (x_center = r.upper_left.x - r.lower_right.x)
            >= 0 ? x_center : -x_center;

        y_center = (y_center = r.upper_left.y - r.lower_right.y)
            >= 0 ? y_center : -y_center;

        return (struct point) {x_center, y_center};
    }
    ```

    c)

    ```c
    struct rectangle rect_move(struct rectangle r, int x, int y)
    {
        r.upper_left.x  += x;
        r.upper_left.y  += y;
        r.lower_right.x += x;
        r.lower_right.y += y;

        return r;
    }
    ```

    d)

    ```c
    bool rect_haspoint(struct rectangle r, struct point p)
    {
        enum {kTopBottom, kBottomTop} coords_mode;

        if (p.x < r.upper_left.x || p.x > r.lower_right.x)
            return false;

        coords_mode = (r.upper_left.y < r.lower_right.y) ? kTopBottom : kBottomTop;

        if (coords_mode == kTopBottom)
            return (p.y >= r.upper_left.y && p.y <= r.lower_right.y);
        else
            return (p.y <= r.upper_left.y && p.y >= r.lower_right.y);
    }
    ```

11. 20 bytes.

12. 16 bytes.

13. a) LEGAL.  
    b) LEGAL.  
    c) ILLEGAL. `s` has no member named `height`. Fix: `s.u.rectangle.height`  
    d) LEGAL.  
    e) ILLEGAL. `circle` is a `struct`, not an integer. Fix: `s.u.circle.radius`  
    f) ILLEGAL. `u` has no member named `radius`. Fix: `s.u.circle.radius`

14. ``` c
    #include <math.h>

    #define RECTANGLE 0
    #define CIRCLE 1

    struct point { int x, y; };

    struct shape {
        int shape_kind;       /* RECTANGLE or CIRCLE   */
        struct point center;  /* coordinates of center */
        union {
            struct {
                int height, width;
            } rectangle;
            struct {
                int radius;
            } circle;
        } u;
    } s;

    // a)
    double shape_area(struct shape s)
    {
        switch (s.shape_kind)
        {
        case RECTANGLE:
            return s.u.rectangle.height * s.u.rectangle.width;

        case CIRCLE:
            return M_PI * pow(s.u.circle.radius, 2);

        default:
            return 0;
        }
    }

    // b)
    struct shape shape_move(struct shape s, int x, int y)
    {
        s.center.x += x;
        s.center.y += y;

        return s;
    }

    // c)
    struct shape shape_scale(struct shape s, double c)
    {
        switch (s.shape_kind)
        {
        case RECTANGLE:
            s.u.rectangle.height *= c;
            s.u.rectangle.width  *= c;
            break;

        case CIRCLE:
            s.u.circle.radius *= c;
            break;
        }

        return s;
    }
    ```

15. ```c
    // a)
    enum week_days { kSunday, kMonday, kTuesday, kWednesday,
                     kThursday, kFriday, kSaturday };

    // b)
    typedef enum week_days WeekDay;
    ```

16. a) True.  
    b) False. Enumerations are integers and have their scopes.  
    c) True.  
    d) False. Two constants might have the same values.  
    e) True.

17. a) Safe.  
    b) Legal. Value might not represent an `enum` constant.  
    c) Legal. Value might not represent an `enum` constant.  
    d) Safe.  
    e) Safe.

18. ```c
    // a)
    typedef enum { empty, kPawn, kKnight, kBishop, kRook, kQueen, kKing } Piece;
    typedef enum { kBlack, kWhite } Color;

    // b)
    typedef struct
    {
        Piece piece;
        Color color;
    } Square;

    // c)
    Square board[8][8];

    // d)
    Square board_initialized[8][8] =
    { [0][0] = {kRook, kBlack}, {kKnight, kBlack}, {kBishop, kBlack}, {kQueen, kBlack},
               {kKing, kBlack}, {kBishop, kBlack}, {kKnight, kBlack}, {kRook, kBlack},
      [1][0] = {kPawn, kBlack}, {kPawn, kBlack},   {kPawn, kBlack},   {kPawn, kBlack},
               {kPawn, kBlack}, {kPawn, kBlack},   {kPawn, kBlack},   {kPawn, kBlack},
      [6][0] = {kPawn, kWhite}, {kPawn, kWhite},   {kPawn, kWhite},   {kPawn, kWhite},
               {kPawn, kWhite}, {kPawn, kWhite},   {kPawn, kWhite},   {kPawn, kWhite},
      [7][0] = {kPawn, kWhite}, {kPawn, kWhite},   {kPawn, kWhite},   {kPawn, kWhite},
               {kPawn, kWhite}, {kPawn, kWhite},   {kPawn, kWhite},   {kPawn, kWhite},
    };
    ```

19. ```c
    struct pinball_machine
    {
        char name[40];
        int year;
        enum { EM, SS } type;
        int players;
    };
    ```

20. ```c
    switch (direction)
    {
        case EAST:  ++x;
                    break;
        case WEST:  --x;
                    break;
        case NORTH: --y;
                    break;
        case SOUTH: ++y;
                    break;
    }
    ```

21. a) 0, 1, 2, 3  
    b) 11, 12, 13  
    c) 14, 15, 16, 24, 25  
    d) 45, 46, 47, 37, 38, 39

22. ```c
    enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
    
    // a)
    const int piece_value[] = {200, 9, 5, 3, 3, 1};
    
    // b)
    const int piece_value_c99[] = { [KING] = 200, [QUEEN] = 9,  [ROOK] = 5,
                                    [BISHOP] = 3, [KNIGHT] = 3, [PAWN] = 1 };
    ```
