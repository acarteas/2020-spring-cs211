
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PokerDeck : Deck
{
    public PokerDeck()
    {



        for (int i = 1; i < 14; i++)
        {
            List<string> suits = new List<string>();
            suits.Add("Spades");
            suits.Add("Diamond");
            suits.Add("Club");
            suits.Add("Heart");

            foreach (string suit in suits)
            {
                PokerCard card = new PokerCard();
                card.Suit = suit;
                card.Value = i;
                AddToTop(card);
            }


        }


    }
}