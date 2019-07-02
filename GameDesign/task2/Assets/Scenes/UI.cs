using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UI : MonoBehaviour
{
    public Text score;
    public GameObject gameover;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        score.text = "Score:" + GM.score;

        if (!GM.isActive)
        {
            gameover.SetActive(true);
        }
    }
}
