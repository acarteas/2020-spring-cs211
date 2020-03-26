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
        _deck.Shuffle();
        Debug.Log("");
        
    }

    //Draws top card from deck and displays it on the screen
    void DrawTopCard()
    {
        if (CardPrefab != null)
        {
            var card = GameObject.Instantiate<GameObject>(CardPrefab, Vector3.zero, Quaternion.identity);
            var controller = card.GetComponent<CardController>();

            //attach card C# object to card Unity object
            controller.Card = _deck.DrawFromTop();

            if (controller != null)
            {
                controller.FaceMaterial = PokerCardFactory.GetInstance().Materials[controller.Card.Name];
                controller.UpdateFaceMaterial();
            }
        }
    }

    void DrawBottomCard()
    {
        if (CardPrefab != null)
        {
            var card = GameObject.Instantiate<GameObject>(CardPrefab, Vector3.zero, Quaternion.identity);
            var controller = card.GetComponent<CardController>();

            //attach card C# object to card Unity object
            controller.Card = _deck.DrawFromTop();

            if (controller != null)
            {
                controller.FaceMaterial = PokerCardFactory.GetInstance().Materials[controller.Card.Name];
                controller.UpdateFaceMaterial();
            }
        }
    }

    void Shuffle()
    {
        float Choose(float[] probs)
        {

            float total = 0;

            foreach (float elem in probs)
            {
                total += elem;
            }

            float randomPoint = Random.value * total;

            for (int i = 0; i < probs.Length; i++)
            {
                if (randomPoint < probs[i])
                {
                    return i;
                }
                else
                {
                    randomPoint -= probs[i];
                }
            }
            return probs.Length - 1;
        }
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
