using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class Deck 

{
    List<Card> cards = new List<Card>();
    public int CardCount
    {
        get
        {
            if (cards == null)
            {
                return 0;
            }
            else
            {
                return cards.Count;
            }
        }
    }
    protected LinkedList<Card> Cards { get; set; }

    public Deck()
    {
        Cards = new LinkedList<Card>();
    }

    public void AddToTop(Card card)
    {
        Cards.AddLast(card);
    } 

    public Card RemoveFromTop()
    {
        Card topCard = Cards.Last();
        Cards.RemoveLast();
        return topCard;

    }

    public void Shuffle()
    {
        cards = Cards.ToList();
        int n = cards.Count;
        while (n > 1)
        {
            n--;
            int k = Random.Range(0, n + 1);
            Card temp = cards[k];
            cards[k] = cards[n];
            cards[n] = temp;
        }

        Cards.Clear();
        foreach(Card c in cards)
        {
            Cards.AddFirst(c);
        }

    }


}
