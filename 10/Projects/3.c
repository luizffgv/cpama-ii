#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables*/
int hand[NUM_CARDS][2];

bool straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */

/* prototypes */
bool card_exists(int rank, int suit);
void read_cards(void);
void analyze_hand(void);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

bool card_exists(int rank, int suit)
{
    int card;

    for (card = 0; card < NUM_CARDS; card++)
        if (hand[0][0] == rank && hand[0][1] == suit)
            return true;

    return false;
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(void)
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    int card;
    bool bad_card;
    int cards_read = 0;

    for (card = 0; card < NUM_CARDS; card++)
        hand[card][0] = hand[card][1] = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (card_exists(rank, suit))
            printf("Duplicate card; ignored.\n");
        else {
            hand[cards_read][0] = rank;
            hand[cards_read++][1] = suit;
        }
    }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand()
{
    int card, rank;
    int rank_count;
    int difference;

    straight = true;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    /* check for flush */
    for (card = 1; card < NUM_CARDS; card++)
        if (hand[card][1] != hand[card - 1][1])
            break;
    if (card == NUM_CARDS)
        flush = true;

    /* check for straight */
    for (card = 1; card < NUM_CARDS; card++)
    {
        int i;
        for (i = 0; i < NUM_CARDS; i++)
        {
            difference =  hand[card][0] - hand[i][0];
            difference *= difference;
            if (difference == 1) break;
        }
        if (i == NUM_CARDS) {
            straight = false;
            return;
        }
    }

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (rank = 0; rank < NUM_RANKS; rank++) {
        rank_count = 0;
        for (card = 0; card < NUM_CARDS; card++)
            rank_count++;
        if (rank_count == 4) four = true;
        if (rank_count == 3) three = true;
        if (rank_count == 2) pairs++;

    }
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void)
{
    if (straight && flush) printf("Straight flush");
    else if (four)         printf("Four of a kind");
    else if (three &&
             pairs == 1)   printf("Full house");
    else if (flush)        printf("Flush");
    else if (straight)     printf("Straight");
    else if (three)        printf("Three of a kind");
    else if (pairs == 2)   printf("Two pairs");
    else if (pairs == 1)   printf("Pair");
    else                   printf("High card");

    printf("\n\n");
}
