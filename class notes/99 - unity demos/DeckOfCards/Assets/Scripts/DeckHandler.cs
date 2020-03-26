using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeckHandler : MonoBehaviour
{
    // Start is called before the first frame update

    public Deck deck = new Deck();

    public void DrawFromTop()
    {
        Card card = deck.DrawFromTop();
        Debug.Log(card);
    }

    public void DrawFromBottom()
    {
        Card card = deck.DrawFromBottom();
        Debug.Log(card);
    }

    public void AddDeck()
    {
        Deck anotherDeck = new Deck();
        deck.Merge(anotherDeck);
    }

    public void Shuffle()
    {
         deck.Shuffle();
        
    }
    void Start()
    {
       
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
