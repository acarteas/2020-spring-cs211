using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PokerDeck : Deck
{
    public PokerDeck()
    {
        var materials = PokerCardFactory.GetInstance().Materials;
        foreach (var material in materials)
        {
            AddToTop(
                new Card()
                {
                    Name = material.Key
                }
                );
        }
    }
}
