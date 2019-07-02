# MY_Flappy_Bird设计说明文档

### 介绍

> ​	本程序模拟flappy_bird小游戏,完成了实验的要求。

### 实验要求

> ​	1、编程实现滚屏地图的显示与操作；
>
> ​	2、编写一个物体在某一场景中运动的动画程序，要求带有碰撞检测和避让功能。

### 思想

​	1、滚动地图的实现，一种情况下是画整个地图，让镜头随着物体的运动一直变化，还有一种是让地图动，物体保持不变，本程序采用了后者。整体上是在camera前面设置一个柱子的出生点，通过随机函数对柱子做一个上下的随机上下波动；若程序isActive==true就一直往左移动，10s后柱子自动销毁，防止爆内存；程序结束就不再创建柱子对象。

​	2、场景中运动物体（打上“Player”的标签），加上重力物理机，对所有的障碍物加上BoxCollider2D盒子碰撞器，点击空格键来躲避。物体碰到障碍物，整体地图停止；在柱子之间加一个触发器框，物体通过框就将分数+1；程序isActive==false，就显示GameOver的文本框。

​	3、在程序运行的任何时候，点击“esc”键就退出整个程序。

### 详细设计

```c#
//GM.cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GM : MonoBehaviour
{
    public static int score = 0; //计分系统

    public static bool isActive = true;//判断游戏结束标志


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}

```



```c#
//Bird_.cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bird_ : MonoBehaviour
{
    Rigidbody2D rg;
    public float upforce = 200f;
    // Start is called before the first frame update
    void Start()
    {
        rg = GetComponent<Rigidbody2D>();//首先获取游戏对象
        
    }

    // Update is called once per frame
    void Update()
    {
    	 if (Input.GetKeyDown("escape"))//在任何时候按下“esc”键就退出应用
        {
            Application.Quit();
        }
        if (Input.GetKeyDown("space")&&GM.isActive) 
        //在每一帧中按下“空格”键就将对象变更位置（向上一个力）
        {
            // rg.AddForce(new Vector2(0, upforce));
            rg.AddForce(Vector2.up * upforce);
        }
    }
}

```

```c#
//Colum.cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Colum : MonoBehaviour
{
    public float speed = 3f; //设置柱子向左移动的速度
    // Start is called before the first frame update
    void Start()
    {
        Destroy(gameObject, 10f);//游戏对象在10s后自动销毁，防止爆内存
    }

    // Update is called once per frame
    void Update()
    {
        if (GM.isActive)//游戏如果运行，就将该对象向左运动
        {
            transform.Translate(Vector3.left * speed * Time.deltaTime);//增量时间
        }
       
    }
    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Player") //Player这个标签的对象出了触发器的区域，score+1
        {
            //Debug.Log(+1);
            GM.score += 1;
            Debug.Log(GM.score);
           // score++;
        }
    }
}

```

```c#
//Hitted.cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Hitted : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
    
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Player") //游戏对象Player碰到障碍，就结束
        {
            GM.isActive = false;
        }
    }
}

```

```c#
//Spawn.cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawn : MonoBehaviour
{
    public GameObject colum;//游戏对象柱子
    public float colddown = 2f;
    float nextSpawn;


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if((Time.time > nextSpawn) && GM.isActive)//每隔2s并且程序运行就进行下面的操作
        {
            nextSpawn = Time.time + colddown;
            Vector3 spawnP = transform.position;//柱子的位置
            spawnP.y += Random.Range(-3f, 3f);//上下浮动
            Instantiate(colum, spawnP, transform.rotation);//在spawn这个对象的位置复制一个对象柱子
        }
        

    }
}

```



```c#
//UI.cs
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
        score.text = "Score:" + GM.score;//显示分数文本框

        if (!GM.isActive)//游戏结束，游戏结束的文本框显示出来
        {
            gameover.SetActive(true);
        }
    }
}

```

### 实验心得

​	本次实验还是较为简单的，因为之前有个这方面的练习，对unity基本操作还算比较熟悉，由于实验仓促，所用素材不是很好，希望下次运用更好的素材，做出更好的效果。