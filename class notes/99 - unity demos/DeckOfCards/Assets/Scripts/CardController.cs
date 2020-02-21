using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CardController : MonoBehaviour
{
    private const string CARD_FACE_TAG = "CardFace";
    private const string CARD_BACK_TAG = "CardBack";

    public Material FaceMaterial;
    public Material BackMaterial;
    public Card Card;

    public void Start()
    {
        UpdateFaceMaterial();
        if(BackMaterial != null)
        {
            MeshRenderer mesh = gameObject.FindComponentInChildWithTag<MeshRenderer>(CARD_BACK_TAG);
            mesh.material = BackMaterial;
        }
    }

    public void UpdateFaceMaterial()
    {
        if (FaceMaterial != null)
        {
            MeshRenderer mesh = gameObject.FindComponentInChildWithTag<MeshRenderer>(CARD_FACE_TAG);
            mesh.material = FaceMaterial;
        }
    }

}
