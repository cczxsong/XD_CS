using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawn : MonoBehaviour
{
    public GameObject colum;
    public float colddown = 2f;
    float nextSpawn;


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if((Time.time > nextSpawn) && GM.isActive)
        {
            nextSpawn = Time.time + colddown;
            Vector3 spawnP = transform.position;
            spawnP.y += Random.Range(-3f, 3f);
            Instantiate(colum, spawnP, transform.rotation);
        }
        

    }
}
