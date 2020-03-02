using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


public class Card
{
    public string Name { get; set; }

    public Card()
    {
        Name = "";
    }

    public bool IsFaceUp { get; private set; }
    

public void flip()
    {
        IsFaceUp = !IsFaceUp; 
    }

}

