using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class Deck 
{
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
    }

    
}
