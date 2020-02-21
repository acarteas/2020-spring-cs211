using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowScript : MonoBehaviour
{
    public GameObject ToFollow;

    // Start is called before the first frame update
    void Start()
    {
        if (ToFollow != null)
        {
            var followScript = ToFollow.GetComponent<MovementController>();
            if(followScript != null)
            {
                //to subscribe to an event
                followScript.ObjectMoved += FollowScript_ObjectMoved;

                //to unsubscribe from an event
                //followScript.ObjectMoved -= FollowScript_ObjectMoved;
            }
        }
    }


    private void FollowScript_ObjectMoved(object sender, System.EventArgs e)
    {
        if(ToFollow != null)
        {
            var followScript = ToFollow.GetComponent<MovementController>();
            transform.position = Vector3.Lerp(transform.position, ToFollow.transform.position, followScript.movementSpeed * Time.deltaTime);
        }
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
