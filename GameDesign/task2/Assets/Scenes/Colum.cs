using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Colum : MonoBehaviour
{
    public float speed = 2f;
    // Start is called before the first frame update
    void Start()
    {
        Destroy(gameObject, 10f);
    }

    // Update is called once per frame
    void Update()
    {
        if (GM.isActive)
        {
            transform.Translate(Vector3.left * speed * Time.deltaTime);
        }
       
    }
    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            //Debug.Log(+1);
            GM.score += 1;
            Debug.Log(GM.score);
           // score++;
        }
    }
}
