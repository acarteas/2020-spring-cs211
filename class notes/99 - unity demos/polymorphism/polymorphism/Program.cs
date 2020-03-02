using System;

namespace polymorphism
{
    class Program
    {
        static Card GenerateRandomPokerCard()
        {
            Random rng = new Random();
            int value = rng.Next(2, 10);
            Card c = new PokerCard()
            {
                Name = value.ToString(),
                Value = value
            };
            return c;
        }

        static void Main(string[] args)
        {
            Card card = GenerateRandomPokerCard();
            Console.WriteLine(card.Name);
            PokerCard specific = card as PokerCard;
            Console.WriteLine(specific.Value);
        }
    }
}
