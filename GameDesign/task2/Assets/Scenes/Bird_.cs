using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Bird_ : MonoBehaviour
{
    Rigidbody2D rg;
    public float upforce = 200f;
    // Start is called before the first frame update
    void Start()
    {
        rg = GetComponent<Rigidbody2D>();
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown("escape"))
        {
            Application.Quit();
        }
        if (Input.GetKeyDown("space")&&GM.isActive)
        {
            // rg.AddForce(new Vector2(0, upforce));
            rg.AddForce(Vector2.up * upforce);
        }
        
    }
}
