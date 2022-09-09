using System.Collections;
using UnityEngine;

public class BlockScript : MonoBehaviour 
{
    public int hitsToKill;
    public int points;
    private int numberOfHits;
   
	void Start () 
    {
        numberOfHits = 0;	
	}


    
        
	    
    void OnCollisionEnter2D(Collision2D collision)
        {
        
        //проверка тега объекта с которым столкнулся шарик 
             if(collision.gameObject.tag=="Ball")
            {
                 numberOfHits++;
                 if (numberOfHits == hitsToKill - 1)
                 {
                     Color color = new Color(128, 45, 32, 5);
                     var renderer = this.gameObject.GetComponent<Renderer>();
                     renderer.material.color = color * 0.6f;
                 }
                    
                    if(numberOfHits==hitsToKill)
                    {
                              //получаем ссылку на платформу
                                 GameObject player = GameObject.FindGameObjectsWithTag("Player")[0];
                            //выполнение метода из друго скрипта

                                 player.SendMessage("addPoints",points);
                             //уничтожаем блок
                             Destroy(this.gameObject);
                    }   
	        }
       
 }

}
