using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PokerCardFactory
{
    private static PokerCardFactory _instance = null;
    private static string _cardFacePath = "PokerCards";
    public Dictionary<string, Material> Materials = new Dictionary<string, Material>();
    private PokerCardFactory()
    {
        Object[] resources = Resources.LoadAll<Texture2D>(_cardFacePath);
        foreach (var resource in resources)
        {
            Texture2D texture = resource as Texture2D;
            if (texture != null)
            {
                Material material = new Material(Shader.Find("Standard"));
                material.SetTexture("_MainTex", texture);
                Materials.Add(resource.name, material);
            }

        }
    }

    public static PokerCardFactory GetInstance()
    {
        if(_instance == null)
        {
            _instance = new PokerCardFactory();
        }
        return _instance;
    }




}