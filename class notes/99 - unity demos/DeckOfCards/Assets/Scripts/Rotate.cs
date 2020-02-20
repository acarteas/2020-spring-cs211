using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotate : MonoBehaviour
{
    public GameObject ToRotate;

    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        ToRotate.transform.Rotate(0, 100 * Time.deltaTime, 0, Space.World);
    }
}
