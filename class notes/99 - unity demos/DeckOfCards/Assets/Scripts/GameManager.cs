using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public GameObject CardPrefab;

    private PokerDeck _deck;

    // Start is called before the first frame update
    void Start()
    {
        _deck = new PokerDeck();
        DrawTopCard();
        
    }

    //Draws top card from deck and displays it on the screen
    void DrawTopCard()
    {
        if (CardPrefab != null)
        {
            var card = GameObject.Instantiate<GameObject>(CardPrefab, Vector3.zero, Quaternion.identity);
            var controller = card.GetComponent<CardController>();

            //attach card C# object to card Unity object
            controller.Card = _deck.RemoveFromTop();

            if (controller != null)
            {
                controller.FaceMaterial = PokerCardFactory.GetInstance().Materials[controller.Card.Name];
                controller.UpdateFaceMaterial();
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
